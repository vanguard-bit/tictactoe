#pragma once
#include "include.h"

void ini_game(char game[3][3]);
void print_message(int *input, int *plays, char game[3][3], char _turn,
                   int *pos, char turn, int xyz[5][2][3], char **grid,
                   chtype __grid[GRID_LENTH][GRID_WIDTH], int _pos[5], int key,
                   wins *win);
