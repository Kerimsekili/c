// Author : ks
// Ogrenilenler
// -Isimlendirme her seyden onemli !
// -Isi kucuk parcalara ayir ve coz.
// -Degiskenler ve fonksiyonlar yapmasi gereken disinda baska bir is yapmamali!

#include <stdio.h>
#include <stdlib.h>

int cols;
int rows;
int cursor_row = 0;
int cursor_col = 0;

char grid[32][32];

void read_grid_size(){
  printf("Enter columns and rows :");
  scanf("%d %d",&rows,&cols);
  if((rows > 32 || cols > 32) || (rows < 2 || cols < 2)){
    puts("Grid cannot be smaller than 2x2 and bigger than 32x32");
    exit(1);
  }
}

void create_grid(){
  for(int row = 0; row < rows; row++){
    for(int col = 0; col < cols; col++){
      grid[row][col] = '.';
    }
  }
}

void print_grid(){
  for(int row = 0; row < rows; row++){
    for(int col = 0; col < cols; col++){
      if(cursor_row == row && cursor_col == col){
        if(grid[row][col] != '.'){
          printf("%c_ ",grid[row][col]);
        } 
        else{
          printf("_  ");
        }
      } else{
        printf("%c  ",grid[row][col]);
      }
    }
    puts("");
  }
}


void read_operation(){
  char key;
  printf("Give an operation (w,a,s,d,q or key):");
  scanf(" %c",&key);
  if(key == 'w' && cursor_row >= 0){
    cursor_row--;
  }
  else if(key == 's' && cursor_row < rows){
    cursor_row++;
  }
  else if(key == 'a' && cursor_col >= 0){
    cursor_col--;
  }
  else if(key == 'd' && cursor_col < cols){
    cursor_col++;
  }
  else if(key == 'q'){
    exit(0);
  }
  else{
    grid[cursor_row][cursor_col] = key;
  }
}

int main()
{
  read_grid_size();
  create_grid();
  
  while(1){
    print_grid();
    read_operation();
  }
}
