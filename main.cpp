#include "game_logic.hpp"

#include <thread>
#include <chrono>

int main(){
    vector<int> grid = emptyGrid();
    vector<int> prev_grid = randomGrid();
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    for(int i=0; i<NB_ITER; i++){
        system("clear");
        cout << "Iteration : " << i+1 << "/" << NB_ITER << endl;
        displayGridInTerminal(prev_grid);
        logic(prev_grid, grid);
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }

    return 1;
}





