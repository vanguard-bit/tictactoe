#pragma once
#include "include.h"
void print_table(int key,wins *win){
  int x,y;
  getyx(stdscr, y, x);
 if(key==0){
   char *table[2];
   table[0]="    O    |    X    ";
   table[1]="-------------------";
   for(int i=0;i<2;i++){
     mvprintw(i,COLS-19,"%s",table[i]);
   }
 } 
 else if(key==1){
   if(win->X<10){
   mvprintw(2,COLS-5,"%d",win->X);
   }
   else if(win->X>9){
   mvprintw(2,COLS-6,"%d",win->X);
   }
   if(win->O<10){
   mvprintw(2,COLS-15,"%d",win->O);
   }
   else if(win->O>9){
   mvprintw(2,COLS-16,"%d",win->O);
   }
 }
 move(y,x);
}
