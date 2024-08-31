#pragma once
#include"include.h"
void print_grid(char **grid, chtype __grid[GRID_LENTH][GRID_WIDTH],int xyz[5][2][3],char turn, wins *win,int key){
  int curr_grid=0;
  if(key==0){
  while(curr_grid<5){
    move(xyz[curr_grid][0][0]-1,xyz[curr_grid][1][0]-2);
    for(int i=0;i<GRID_LENTH;i++){
      for(int j=0;j<GRID_WIDTH;j++){
        printw("%c",grid[i][j]); 
      }
      printw("\n");
      move(i+xyz[curr_grid][0][0],xyz[curr_grid][1][0]-2);
    }
    curr_grid++;
  }
  }
  else  if(key==1){
    curr_grid=0;
  while(curr_grid<5){
    move(xyz[curr_grid][0][0]-1,xyz[curr_grid][1][0]-2);
  for(int i=0;i<GRID_LENTH;i++){
    for(int j=0;j<GRID_WIDTH;j++){
      addch(__grid[i][j]);
    }
    printw("\n");
      move(i+xyz[curr_grid][0][0],xyz[curr_grid][1][0]-2);
    }
    curr_grid++;
  }
  }
  print_turn(turn,0);
  print_table(0,win);
  print_menu(0);
}

void create_grid(char **grid){                 //                   //4                  
  *grid=(char*)malloc(sizeof(char*));          //                                        
  grid[0] = "     |     |     ";               //             18   | 18  | 18            
  grid[1] = "     |     |     ";               //             75   | 81  | 86            
  grid[2] = "     |     |     ";               //                  |     |               
  grid[3] = "-----------------";               //            ------------------          
  grid[4] = "     |     |     ";               //             22   | 22  | 22            
  grid[5] = "     |     |     ";               //      //9    76   | 81  | 86       //9  
  grid[6] = "     |     |     ";               //                  |     |               
  grid[7] = "-----------------";               //            -------------------         
  grid[8] = "     |     |     ";               //             26   | 26  | 26            
  grid[9] = "     |     |     ";               //             76   | 81  | 87            
  grid[10]= "     |     |     ";               //                  |     |              
                                               //                                        
                                               //                  //4                   

}

void centre_grid(int xyz[5][2][3]){

int half_rows,half_coloums,maxx,maxy;

initscr();
half_rows=(LINES-TOTAL_GRID_LENGHT)/2;
half_coloums=(COLS-TOTAL_GRID_WIDTH)/2;  
endwin();
  int _CENTER_ROWS[5]={3,0,1,2,4};
  int _CENTER_COLS[5]={0,1,3,4,2};

  for(int i=0;i<5;i++){
    for(int j=0;j<3;j++){
      if(i==0 && j==0){
        xyz[_CENTER_ROWS[i]][0][j]=half_rows;
      }
      else if(i==0 && j!=0){
        xyz[_CENTER_ROWS[i]][0][j]=xyz[_CENTER_ROWS[i]][0][j-1]+4;
      }
      else if(i>0 && i<4 && j==0){
        xyz[_CENTER_ROWS[i]][0][j]=xyz[_CENTER_ROWS[0]][0][j]+15;
      }
      else if(i>0 && i<4 && j!=0){
        xyz[_CENTER_ROWS[i]][0][j]=xyz[_CENTER_ROWS[i]][0][j-1]+4;
      }
      else if(i==4 && j==0){
        xyz[_CENTER_ROWS[i]][0][j]=xyz[_CENTER_ROWS[0]][0][j]+(15*2);
      }
      else if(i==4 && j!=0){
        xyz[_CENTER_ROWS[i]][0][j]=xyz[_CENTER_ROWS[i]][0][j-1]+4;
      }
    }
  }

  for(int i=0;i<5;i++){
    for(int j=0;j<3;j++){
      if(i==0 && j==0){
        xyz[_CENTER_COLS[i]][1][j]=half_coloums;
      }
      else if(i==0 && j!=0){
        xyz[_CENTER_COLS[i]][1][j]=xyz[_CENTER_COLS[i]][1][j-1]+6;
      }
      else if(i>0 && i<4 && j==0){
        xyz[_CENTER_COLS[i]][1][j]=xyz[_CENTER_COLS[0]][1][j]+26;
      }
      else if(i>0 && i<4 && j!=0){
        xyz[_CENTER_COLS[i]][1][j]=xyz[_CENTER_COLS[i]][1][j-1]+6;
      }
      else if(i==4 && j==0){
        xyz[_CENTER_COLS[i]][1][j]=xyz[_CENTER_COLS[0]][1][j]+(26*2);
      }
      else if(i==4 && j!=0){
        xyz[_CENTER_COLS[i]][1][j]=xyz[_CENTER_COLS[i]][1][j-1]+6;
      }
    }
  }
}
