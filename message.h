#pragma once
#include "include.h"
void ini_game(char game[3][3]){
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      game[i][j]=' ';
    }
  }
}

void print_message(int *input, int *plays, char game[3][3],char _turn, int *pos, char turn ,int xyz[5][2][3],char **grid,chtype __grid[GRID_LENTH][GRID_WIDTH],int _pos[5],int key,wins *win){
  if(key==0){
    mvprintw(LINES-2,0,"Player '%c' wins!!",_turn);
    mvprintw(LINES-1,0,"Press 'c' to play again or 'q' to quit:  ");
    if(_turn=='X'){
      win->X+=1;
    }
    else if(_turn=='O'){
      win->O+=1;
    }
    refresh();
    while(1){
      move(LINES-1,40);
      char a=getch();
      move(LINES-1,40);
      if(a=='q'){
        *input=0;
        *plays=0;
        move(xyz[1][0][1],xyz[1][1][1]);
        break;
      }
      if(a=='c'){
        *plays=0;
        mvprintw(LINES-1,0,"                                       ");
        mvprintw(LINES-2,0,"                                       ");
        ini_game(game);
        *pos+=1;
        if(*pos==5){
          clear();
          print_grid(grid,__grid,xyz,turn,win,0);
          *pos=0;
          move(xyz[_pos[*pos]][0][1],xyz[_pos[*pos]][1][1]);
        }
        move(xyz[_pos[*pos]][0][1],xyz[_pos[*pos]][1][1]);
        break;
      }
    }
  }
  else if(key==1){
    mvprintw(LINES-2,0,"Match Tied.");
    mvprintw(LINES-1,0,"Press 'c' to continue or 'q' to quit:  ");
    while(1){
      move(LINES-1,38);
      char a=getch();
      move(LINES-1,38);
      if(a=='q'){ 
        *input=0;
        break;
      }
      if(a=='c'){
        *plays=0;
        mvprintw(LINES-2,0,"            ");
        mvprintw(LINES-1,0,"                                       ");
        ini_game(game);
        *pos+=1;
        if(*pos==5){
          clear();
          print_grid(grid,__grid,xyz,turn,win,0);
          *pos=0;
          move(xyz[_pos[*pos]][0][1],xyz[_pos[*pos]][1][1]);
        }
        move(xyz[_pos[*pos]][0][1],xyz[_pos[*pos]][1][1]);
        break;
      }
    }
  }
  print_table(1,win);
}
