#include "game_logic.hpp"
#include "constants.hpp"

vector<bool> getNeighborStates(vector<int> g, int pos){
    vector<bool> neighbors;

    neighbors.push_back(g[pos-WIDTH-1]);
    neighbors.push_back(g[pos-WIDTH]);
    neighbors.push_back(g[pos-WIDTH+1]);
    neighbors.push_back(g[pos-1]);
    neighbors.push_back(g[pos+1]);
    neighbors.push_back(g[pos+WIDTH-1]);
    neighbors.push_back(g[pos+WIDTH]);
    neighbors.push_back(g[pos+WIDTH+1]);

    return neighbors;
}

vector<int> emptyGrid(){
    vector<int> g;
    g.assign(HEIGHT*WIDTH, false);
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
    return g = g;
}

void logic(vector<int>* prev_grid, vector<int>* grid){
    int pos = 0;

    for(int i=1; i<HEIGHT-1; i++){
        for(int j=1; j<WIDTH-1; j++){
            pos = i*WIDTH + j;
            vector<bool> states = getNeighborStates(*prev_grid, pos);

            int nb_alive = 0;
            int nb_dead = 0;
            bool val = false;
            for(int idv=0; idv < (int) states.size(); idv++){
                val = states[idv];
                if (val==true) nb_alive += 1;
                else nb_dead += 1;
            }


            if ((*prev_grid)[pos] == false){
                if (nb_alive == 3) (*grid)[pos] = true;
                else (*grid)[pos] = false;
            } 
            if ((*prev_grid)[pos] == true){
                if ( (nb_alive == 2) || (nb_alive == 3) ) (*grid)[pos] = true;
                else (*grid)[pos] = false;  
            }

        }
    }
    *prev_grid = *grid;
    // (*grid).assign(HEIGHT*WIDTH, false);
    *grid = emptyGrid();
}

void displayGridInTerminal(vector<int> grid){
    char alive = 'X';
    char dead = '.';

    if (grid.empty()) std::cout << "Grid is empty" << std::endl;
    else {
        for(int i=0; i<HEIGHT; i++){
            bool val = false;
            for(int j=0; j<WIDTH; j++){
                val = grid[i*WIDTH+j];
                if (val) std::cout << alive << " ";
                else std::cout << dead << " ";
            }
            std::cout << std::endl;
        }
    }
}



