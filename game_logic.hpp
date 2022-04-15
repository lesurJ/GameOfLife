#ifndef GAME_LOGIC
#define GAME_LOGIC

#include <vector>
#include <ctime>
#include <stdlib.h>
#include <iostream>
using namespace std;

#define NEIGHBORS 8
#define WIDTH 40
#define HEIGHT 20
#define NB_ITER 200

// Get the states of the 8 neighbors around pos in grid g 
vector<bool> getNeighborStates(vector<int> g, int pos);

// Creates and returns an empty grid
vector<int> emptyGrid();

// Create a random-configured grid
vector<int> randomGrid();

// Take a step according to the rules
void logic(vector<int>& prev_grid, vector<int>& grid);

// Display the grid in terminal
void displayGridInTerminal(vector<int> grid);

#endif