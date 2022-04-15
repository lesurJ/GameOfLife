#include "game_logic.hpp"

vector<bool> getNeighborStates(vector<int> g, int pos){
    vector<bool> neighbors(NEIGHBORS, false);
    int ids[NEIGHBORS] = {pos-WIDTH-1,pos-WIDTH,pos-WIDTH+1,pos-1,pos+1,pos+WIDTH-1,pos+WIDTH,pos+WIDTH+1};
    for (int i = 0; i < NEIGHBORS; i++){
        neighbors[i] = g[ids[i]];
    }
    return neighbors;
}

vector<int> emptyGrid(){
    vector<int> g(HEIGHT*WIDTH, false);
    return g;
}

vector<int> randomGrid(){
    vector<int> g = emptyGrid();
    unsigned seed = time(0);
    srand(seed);

    int size = HEIGHT * WIDTH;
    int pos = 0;

    for (int i = 0; i < size/4; i++){
        pos = rand() % size;
        g[pos] = true;
    }
    return g;
}

void logic(vector<int>& prev_grid, vector<int>& grid){
    int pos = 0;
    int nb_alive = 0;
    int nb_dead = 0;

    // If time, check border; for the moment = approx
    for(int i=1; i<HEIGHT-1; i++){
        for(int j=1; j<WIDTH-1; j++){
            pos = i*WIDTH + j;
            vector<bool> states = getNeighborStates(prev_grid, pos);
            nb_alive = 0;
            nb_dead = 0;
            for(int idv=0; idv < states.size(); idv++){
                (states[idv]) ? nb_alive++ : nb_dead++;
            }

            if (prev_grid[pos] == true){
                grid[pos] = ( (nb_alive == 2) || (nb_alive == 3) ) ? true : false;
            } else {
                grid[pos] = (nb_alive==3) ? true : false;
            } 
            

        }
    }
    prev_grid = grid;
    grid = emptyGrid();
}

void displayGridInTerminal(vector<int> grid){
    char alive = 'X';
    char dead = '.';

    if (grid.empty()) std::cout << "Grid is empty" << std::endl;
    else {
        for(int i=0; i<HEIGHT; i++){
            for(int j=0; j<WIDTH; j++){
                if (grid[i*WIDTH+j]) std::cout << alive << " ";
                else std::cout << dead << " ";
            }
            std::cout << std::endl;
        }
    }
}



