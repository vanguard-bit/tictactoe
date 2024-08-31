#pragma once
#include "include.h"
void create_game_intro(char game[3][3],int mode){
  if(mode ==1){
    game[0][0]='O';
    game[0][1]='O';
    game[0][2]='X';
    game[1][0]='X';
    game[1][1]='O';
    game[1][2]='X';
    game[2][0]='O';
    game[2][1]='X';
    game[2][2]='O';
  }
}
void outro_animation(char game[3][3], int xyz[5][2][3],char **grid,int mode){
  move(xyz[1][0][0]-1,xyz[1][1][0]-2);
  for(int i=0;i<11;i++){
    for(int j=0;j<17;j++){
      printw("%c",grid[i][j]); 
    }
    // printw("\n");
    move(i+xyz[1][0][0],xyz[1][1][0]-2);
  }
  int flag=0;
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      if(game[i][j]!=' '){
        flag++;
      }
    }
  }
  if(flag<5){
  }
  create_game_intro(game,mode);
  move(xyz[1][0][1],xyz[1][1][1]);
  refresh();
  napms(400);
  refresh();
  move(xyz[1][0][1],xyz[1][1][1]);
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      mvprintw(xyz[1][0][j],xyz[1][1][i],"%c",game[j][i]);
    }
  }
  move(xyz[1][0][1],xyz[1][1][1]);
  refresh();
}
void intro(int xyz[5][2][3],char **grid,int mode){
  int x,y;
  getyx(stdscr,y,x);
  char game[3][3];
  move(y,x);
  refresh();
  napms(250);
  refresh();
  outro_animation(game,xyz,grid,mode);
  refresh();
  napms(500);
  refresh();
  move(y,x);
}
int intro_animation(int xyz[5][2][3],char **grid){
  move(xyz[1][0][1],xyz[1][1][1]);
  intro(xyz,grid,1);
  int pos=0;
  while(!_kbhit()){
    if(_kbhit()) break;
    int _pos[]={0,4,2,3,1};
     pos=0;
    while(pos<4){
      for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
          if(_kbhit()) break;
          if(pos==0 && i==j && i!=0){
            if(_kbhit()) break;
            refresh();
            move(xyz[_pos[pos]][0][i],xyz[_pos[pos]][1][j]);
          if(_kbhit()) break;
            refresh();
            napms(35);
          }
          if(pos==1 && i==j && i!=2){
            if(_kbhit()) break;
            refresh();
            move(xyz[_pos[pos]][0][i],xyz[_pos[pos]][1][j]);
          if(_kbhit()) break;
            refresh();
            napms(35);
          }
          if(pos==1 && i==j && i==2){
            if(_kbhit()) break;
            refresh();
            move(xyz[_pos[pos]][0][i-2],xyz[_pos[pos]][1][j]);
          if(_kbhit()) break;
            refresh();
            napms(35);
          }
          if(pos ==2 && 2-i==j && i!=2){
            if(_kbhit()) break;
            int ii=2-i,jj=2-j;
            move(xyz[_pos[pos]][0][ii],xyz[_pos[pos]][1][jj]);
          if(_kbhit()) break;
            refresh();
            napms(35);
          }
          if(pos ==2 && 2-i==j && i==2){
            if(_kbhit()) break;
            refresh();
            move(xyz[_pos[pos]][0][0],xyz[_pos[pos]][1][0]);
          if(_kbhit()) break;
            refresh();
            napms(35);
          }
          if(pos==3 && i==j && i!=2){
            if(_kbhit()) break;
            int ii=2-i,jj=2-j;
            refresh();
            move(xyz[_pos[pos]][0][ii],xyz[_pos[pos]][1][jj]);
          if(_kbhit()) break;
            refresh();
            napms(35);
          }
        }
      }
      if(_kbhit()) break;
      pos++;
    }
    refresh();
    move(xyz[3][0][2],xyz[3][1][0]);
    if(_kbhit()) break;
    refresh();
    napms(35);
    if(_kbhit()) break;
    move(xyz[0][0][0],xyz[0][1][2]);
    refresh();
    if(_kbhit()) break;
    napms(35);
    if(_kbhit()) break;
  }
  char a=getch();
  fflush(stdin);
  if(pos<4){
    pos++;
  }
  return pos;
}
