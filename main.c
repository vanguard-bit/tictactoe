#include "include.h"
int main(){

  // printf("\033[=19H");
  // printf("\033[1;1H\e[2J");
  // printf("\033[16;65H ");
  // for(int i=0;i<15;i++){
  //   printf("_ ");
  // }
  // int j=0;
  // printf("\n");
  // while(j<8){
  //   for(int i=0;i<28;i++){
  //     printf("\033[%d;%dH",17+j,65+i);
  //     if(i==0 || i%10==0)
  //       printf("| ");
  //     else printf("  ");
  //   }
  //   printf(" |\n");
  //   j++;
  // }
  // printf("\033[%d;%dH|",17+j,65);
  // printf("\033[%d;%dH",17+j,66);
  // for(int i=1;i<14;i++){
  //   if(i%5==0){
  //     printf(" |");
  //   }
  //   else printf(" _");
  // }
  // printf(" _");
  // printf(" |");
  // getchar();
  //

  char game[3][3],**grid=malloc(sizeof(char*)*GRID_LENTH),turn='O',_turn='X';
  int xyz[5][2][3],flag=1,input=1,plays=0,_pos[5],__pos[5]={1,3,2,4,0},pos=0;
  wins win;
  win.X=0;
  win.O=0;

  centre_grid(xyz);

  ini_game(game);
  chtype __grid[GRID_LENTH][GRID_WIDTH];
  create_grid(grid);
  for(int i=0;i<GRID_LENTH;i++){
    for(int j=0;j<GRID_WIDTH;j++){
      if(grid[i][j]==' '){
        __grid[i][j]=' ';
      }
      else if((i==3 || i==7)&& (j==5 || j==11)){
        __grid[i][j]=ACS_SSSS;
      }
      else if(grid[i][j]=='|'){
        __grid[i][j]=ACS_VLINE;
      }
      else if(grid[i][j]=='-'){
        __grid[i][j]=ACS_HLINE;
      }
    }
  }
  initscr();
  start_color();
  init_pair(3,COLOR_WHITE,COLOR_CYAN);
  init_pair(4,COLOR_BLACK,COLOR_CYAN);
  init_pair(5,COLOR_RED,COLOR_CYAN);
  bkgd(COLOR_PAIR(3));

  scrollok(stdscr, FALSE);

  curs_set(2);

  keypad(stdscr, TRUE);
  noecho();

  // print_grid(grid,xyz);
  // move(xyz[_pos[pos]][0][1],xyz[_pos[pos]][1][1]);
  if(MODE){
  print_grid(grid,__grid,xyz,turn,&win,MODE);
  }
  int ji= intro_animation(xyz,grid);  
  print_grid(grid,__grid,xyz,turn,&win,0);
  for(int i=0;i<5;i++){
    if(ji==4){
    _pos[i]=__pos[ji];
      ji=0;
      continue;
    }
    else {
      _pos[i]=__pos[ji];
    }
    ji++;
  }

  move(xyz[_pos[pos]][0][1],xyz[_pos[pos]][1][1]);
  print_menu(0);
  while(input){
    print_table(0,&win);
    input=getch();

    if(input=='Q' || input=='q'){
      input=0;
    }
    if(input=='m' || input=='M'){
      print_menu(1);
    }

    int xx,yy;
    getyx(stdscr,yy,xx);

    if(input == KEY_UP || input == KEY_DOWN || input == KEY_LEFT || input == KEY_RIGHT ||
       input=='D'||input=='d' ||input=='S' ||input=='s' ||input=='A' ||input=='a' ||
       input=='W' ||input=='w' ||input=='J' ||input=='j' ||input=='K' || input=='k'||
       input=='L' ||input=='l' ||input=='h' ||input=='H'
       ){
      disp(input,xx,yy,xyz,_pos[pos]);
      continue; 
    }

    else if(turn == 'O'&&(input == 'O'|| input=='o'|| input=='\n' || input==' ')){
      int i,j;
      for(int k=0;k<3;k++){
        if(xyz[_pos[pos]][1][k]==xx){
          i=k;
        }
        if(xyz[_pos[pos]][0][k]==yy){
          j=k;
        }
      }
      if(game[j][i]!='X' && game[j][i]!='O'){
        plays+=1;
        attron(COLOR_PAIR(5));
        printw("%c",'O');
        attroff(COLOR_PAIR(5));
        refresh();
        move(yy,xx);
        turn='X';
        _turn='O';
        game[j][i]='O';
      }
    }

    else if(turn =='X'&& (input=='X'|| input == 'x' || input =='\n'|| input==' ')){
      int i,j;
      for(int k=0;k<3;k++){
        if(xyz[_pos[pos]][1][k]==xx){
          i=k;
        }
        if(xyz[_pos[pos]][0][k]==yy){
          j=k;
        }
      }
      if(game[j][i]!='X' && game[j][i]!='O'){
        plays+=1;
        attron(COLOR_PAIR(4));
        printw("%c",'X');
        attroff(COLOR_PAIR(4));
        move(yy,xx);
        refresh();
        turn='O';
        _turn='X';
        game[j][i]='X';
      }
    }
    if(plays>=5){
      if(game[0][0]==_turn){
        if(game[1][1]==_turn){
          if(game[2][2]==_turn){
            print_message(&input,&plays,game,_turn,&pos,turn,xyz,grid,__grid,_pos,0,&win);
          }
        }

        if(game[0][1]==_turn){
          if(game[0][2]==_turn){
            print_message(&input,&plays,game,_turn,&pos,turn,xyz,grid,__grid,_pos,0,&win);
          }
        }
        if(game[1][0]==_turn){
          if(game[2][0]==_turn){
            print_message(&input,&plays,game,_turn,&pos,turn,xyz,grid,__grid,_pos,0,&win);
          }
        }
      }
      if(game[2][0]==_turn){
        if(game[1][1]==_turn){
          if(game[0][2]==_turn){
            print_message(&input,&plays,game,_turn,&pos,turn,xyz,grid,__grid,_pos,0,&win);
          }
        }

      }

      if(game[1][0]==_turn){
        if(game[1][1]==_turn){
          if(game[1][2]==_turn){
            print_message(&input,&plays,game,_turn,&pos,turn,xyz,grid,__grid,_pos,0,&win);
          }

        }

      }

      if(game[0][1]==_turn){
        if(game[1][1]==_turn){
          if(game[2][1]==_turn){
            print_message(&input,&plays,game,_turn,&pos,turn,xyz,grid,__grid,_pos,0,&win);
          }

        }

      }
      if(game[0][2]==_turn){
        if(game[1][2]==_turn){
          if(game[2][2]==_turn){
            print_message(&input,&plays,game,_turn,&pos,turn,xyz,grid,__grid,_pos,0,&win);
          }
        }
      }
      if(game[2][0]==_turn){
        if(game[2][1]==_turn){
          if(game[2][2]==_turn){
            print_message(&input,&plays,game,_turn,&pos,turn,xyz,grid,__grid,_pos,0,&win);
          }
        }
      }
    }
    if(plays==9){
      print_message(&input,&plays,game,_turn,&pos,turn,xyz,grid,__grid,_pos,1,&win);
    }
    print_turn(turn,1); 
  }

  clear();
  refresh();
  napms(250);
  refresh();
  outro_animation(game,xyz,grid,1);
  refresh();
  napms(500);
  refresh();
  move(xyz[1][0][1],xyz[1][1][1]);
  endwin();

  free(grid);
}


