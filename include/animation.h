#pragma once
#include "include.h"

void create_game_intro(char game[3][3], int mode);
void outro_animation(char game[3][3], int xyz[5][2][3], char **grid, int mode);
void intro(int xyz[5][2][3], char **grid, int mode);
int intro_animation(int xyz[5][2][3], char **grid);
