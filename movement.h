#pragma once
#include <ncursesw/ncurses.h>

void disp(int input, int xx, int yy,int xyz[5][2][3],int pos){
  if((input==KEY_LEFT ||input=='a' ||input=='h'||input=='A' ||input=='H') && (xx>xyz[pos][1][0] || xx==xyz[pos][1][0])){
    if(xx==xyz[pos][1][0]){
      move(yy,xx+12);
    }
    else move(yy,xx-6);
  }
  if((input==KEY_RIGHT ||input=='d' ||input=='l'||input=='D' ||input=='L') && (xx<xyz[pos][1][2] || xx==xyz[pos][1][2])){
    if(xx==xyz[pos][1][2]){
      move(yy,xx-12);
    }
    else move(yy,xx+6);
  }
  if((input==KEY_UP ||input=='w' ||input=='k'||input=='W' ||input=='K') && (yy>xyz[pos][0][0] ||yy==xyz[pos][0][0])){
    if(yy==xyz[pos][0][0]){
      move(yy+8,xx);
    }
    else move(yy-4,xx);
  }
  if((input==KEY_DOWN ||input=='j' ||input=='s'||input=='S' ||input=='J') && (yy<xyz[pos][0][2] ||yy==xyz[pos][0][2])){
    if(yy==xyz[pos][0][2]){
      move(yy-8,xx);
    }
    else move(yy+4,xx);
  }
}
