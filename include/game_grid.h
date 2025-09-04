#pragma once
#include "include.h"

void print_grid(char **grid, chtype __grid[GRID_LENTH][GRID_WIDTH],
                int xyz[5][2][3], char turn, wins *win, int key);

void create_grid(char **grid);
void centre_grid(int xyz[5][2][3]);
