#pragma once
#include <ncursesw/ncurses.h>
void create_menu(chtype box[3][5]){
  for(int i=0;i<3;i++){
      for(int j=0;j<5;j++){
            if((i==0) && j==0){
            box[i][j]=ACS_BSSB;
            }
            else if((i==0 || i==2)&&(j<4 && j>0)){
              box[i][j]=ACS_HLINE;
            }
            else if((i==0) && j==4){
              box[i][j]=ACS_BBSS;
            }
            else if((i==1) && (j==0 || j == 4)){
              box[i][j]=ACS_VLINE;
            }
            else if((i==1) && (j>0 && j<4)){
              box[i][j]=' ';
            }
            else if((i==2) && j==0){
              box[i][j]=ACS_SSBB;
            } 
            else if((i==2) && j==4){
              box[i][j]=ACS_SBBS;
            }
          }
          }
}
void menu_fallback(){
  int x,y;
  getyx(stdscr,y,x);
  move(0,6);
  for(int i=0;i<7;i++){
    if(i<3)
    mvprintw(i,6,"                 ");
    else 
      mvprintw(i,0,"                                             ");
  }
  move(y,x);
}
void menu_action(){
  int x,y,counter=0;
  getyx(stdscr,y,x);
  nodelay(stdscr,TRUE);
  move(y,x);

  while(getch()==ERR && counter<300){
    napms(10);
    counter+=1;
  }
  menu_fallback();

  nodelay(stdscr,FALSE);
  move(y,x);
}
void print_menu(int key){
  int x,y;
  getyx(stdscr,y,x);
  chtype box[3][5];
  create_menu(box);
  char menu[]={'M','E','N','U'};
  int loop=0;
  move(0,0);
  if(key==0){
    for(int i=0;i<3;i++){
      for(int j=0;j<5;j++){
        if(i==1 && j==2){
          addch(menu[loop]);
        }
        else addch(box[i][j]);
      }
      move(i+1,loop*6);
    }
  }
  else if(key==1){
    loop=0;
    while(loop<4){
      for(int i=0;i<3;i++){
        for(int j=0;j<5;j++){
          if(i==1 && j==2){
            addch(menu[loop]);
          }
          else addch(box[i][j]);
        }
        move(i+1,loop*6);
      }
      loop+=1;
      move(0,loop*6);
    }
    mvprintw(4,0,"Either arrows, vi keys or WASD keys to move");
    mvprintw(5,0,"Enter or 'o' or 'x' or space to mark the grid");
    mvprintw(6,0,"'Q' to exit at any time.");
    move(y,x);
    menu_action();
  }
  move(y,x);
}
