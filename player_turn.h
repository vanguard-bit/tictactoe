#pragma once
#include <ncursesw/ncurses.h>

void print_turn(char turn, int key){
  int x,y;
  getyx(stdscr, y, x);
  if(key==0){
  mvprintw(LINES-1,COLS-15,"Player '%c' turn",turn);
  move(y,x);
  }
  else if(key==1){
    if(turn=='O')
    attron(COLOR_PAIR(5));
    else if(turn=='X')
    attron(COLOR_PAIR(4));
  mvprintw(LINES-1,COLS-7,"%c",turn);
  move(y,x);
  refresh();
  }
    if(turn=='O')
    attroff(COLOR_PAIR(5));
    else if(turn=='X')
    attroff(COLOR_PAIR(4));
  refresh();
}
