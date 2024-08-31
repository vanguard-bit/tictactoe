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
  char *text[8][11];
  int arr[9]={1,2,3,0,5,4,1,6,7};

  // printf("\033[1;1H\e[2J");
text[0][0]="OOOOOOOOOOOOOOOO";
text[0][1]="       O        ";
text[0][2]="       O        ";
text[0][3]="       O        ";
text[0][4]="       O        ";
text[0][5]="       O        ";
text[0][6]="       O        ";
text[0][7]="       O        ";
text[0][8]="       O        ";
text[0][9]="       O        ";
text[0][10]="       O        ";

text[1][0]="XXXXXXXXXXXXXXXX";
text[1][1]="       X        ";
text[1][2]="       X        ";
text[1][3]="       X        ";
text[1][4]="       X        ";
text[1][5]="       X        ";
text[1][6]="       X        ";
text[1][7]="       X        ";
text[1][8]="       X        ";
text[1][9]="       X        ";
text[1][10]="       X        ";

text[2][0]="XXXXXXXXXXXXXXXX";
text[2][1]="       X        ";
text[2][2]="       X        ";
text[2][3]="       X        ";
text[2][4]="       X        ";
text[2][5]="       X        ";
text[2][6]="       X        ";
text[2][7]="       X        ";
text[2][8]="       X        ";
text[2][9]="       X        ";
text[2][10]="XXXXXXXXXXXXXXXX";

text[3][0]=" OOOOOOOOOOOOOOO";
text[3][1]="O               ";
text[3][2]="O               ";
text[3][3]="O               ";
text[3][4]="O               ";
text[3][5]="O               ";
text[3][6]="O               ";
text[3][7]="O               ";
text[3][8]="O               ";
text[3][9]="O               ";
text[3][10]=" OOOOOOOOOOOOOOO";

text[4][0]=" XXXXXXXXXXXXXXX";
text[4][1]="X               ";
text[4][2]="X               ";
text[4][3]="X               ";
text[4][4]="X               ";
text[4][5]="X               ";
text[4][6]="X               ";
text[4][7]="X               ";
text[4][8]="X               ";
text[4][9]="X               ";
text[4][10]=" XXXXXXXXXXXXXXX";

text[5][0]="    OOOOOOOO    ";
text[5][1]="   O        O   ";
text[5][2]="  O          O  ";
text[5][3]=" O            O ";
text[5][4]="O              O";
text[5][5]="O              O";
text[5][6]="OOOOOOOOOOOOOOOO";
text[5][7]="O              O";
text[5][8]="O              O";
text[5][9]="O              O";
text[5][10]="O              O";

text[6][0]=" OOOOOOOOOOOOOO ";
text[6][1]="O              O";
text[6][2]="O              O";
text[6][3]="O              O";
text[6][4]="O              O";
text[6][5]="O              O";
text[6][6]="O              O";
text[6][7]="O              O";
text[6][8]="O              O";
text[6][9]="O              O";
text[6][10]=" OOOOOOOOOOOOOO ";

text[7][0]="XXXXXXXXXXXXXXXX";
text[7][1]="X               ";
text[7][2]="X               ";
text[7][3]="X               ";
text[7][4]="X               ";
text[7][5]="XXXXXXXXXXXXXXXX";
text[7][6]="X               ";
text[7][7]="X               ";
text[7][8]="X               ";
text[7][9]="X               ";
text[7][10]="XXXXXXXXXXXXXXXX";

printf("\033[1;1H\e[2J\e[032;031m");
for(int i=0;i<9;i++){
  for(int j=0;j<11;j++){
    printf("\033[%d;%dH",((LINES-10)/2)+j,((COLS-152)/2)+(i*17));
     printf("%s",text[arr[i]][j]); 
  }
    // printf("\033[%d;%dH",0,17*i);
  }
napms(3400);
nodelay(stdscr, TRUE);
  move(xyz[1][0][1],xyz[1][1][1]);
char aa=getch();
nodelay(stdscr, FALSE);
  printf("\e[0m");

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
