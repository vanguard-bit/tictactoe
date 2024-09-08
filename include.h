#pragma once
#include <stdio.h>
// #include <conio.h>
#include <stdlib.h>
#include "ncursesw/ncurses.h"

// #include <ncurses> //linux env

#define  GRID_LENTH 11
#define  GRID_WIDTH 17
#define  TOTAL_GRID_LENGHT 41 
#define  TOTAL_GRID_WIDTH  69
#define  MODE 0
typedef struct wins{
  int X;
  int O;
}wins;
#include "menu.h"
#include "score_table.h"
#include "player_turn.h"
#include "game_grid.h"
#include "movement.h"
#include "animation.h"
#include "message.h"

