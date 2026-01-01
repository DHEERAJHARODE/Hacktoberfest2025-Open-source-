#include <iostream>
#include <set>
using namespace std;
int valid_row(int row, int grid[][9]){
  set<int> s;
  for(int i = 0; i < 9; i++){
    if(grid[row][i] < 0 || grid[row][i] > 9){
      cout<<"Invalid value"<<endl;
      return -1;
    }
    else
    {if(grid[row][i] != 0){
        if(s.insert(grid[row][i]).second == false){
          return 0;
        }
      }
    }
  }
  return 1;
}

int valid_col(int col, int grid[][9]){
  set<int> s;
  for(int i = 0; i < 9; i++){
    if(grid[i][col] < 0 || grid[i][col] > 9){
      cout<<"Invalid value"<<endl;
      return -1;
    }
    else
    {
      if(grid[i][col] != 0){
        if(s.insert(grid[i][col]).second == false){
          return 0;
        }
      }
    }
  }
  return 1;
}
int valid_subsquares(int grid [][9]){
  for(int row = 0; row < 9; row = row + 3){
    for(int col = 0; col < 9; col = col + 3){
        set<int> s;
        for(int r = row; r < row + 3; r++){
          for(int c = col; c < col + 3; c++){
            if(grid[r][c] < 0 || grid[r][c] > 9){
              cout<<"Invalid value"<<endl;
              return -1;
            }
            else{
              if(grid[r][c] != 0){
                if(s.insert(grid[r][c]).second == false){
                  return 0;
                }
              } 
            }
          }
        }    
    }
  }
  return 1;
}
void valid_board(int grid [][9]){
  for(int i = 0; i < 9; i++){
    int res1 = valid_row(i, grid);
    int res2 = valid_col(i, grid);
    // If a row or a column is invalid, then the board is invalid.
    if(res1 < 1 || res2 < 1){
      cout<<"The board is invalid"<<endl;
      return;
    }
  }
  int res3 = valid_subsquares(grid);
  if(res3 < 1){
    cout<<"The board is invalid"<<endl;
  }
  else{
    cout<<"The board is valid"<<endl;
  }
}
void print_board(int grid[] [9]){
  for( int row = 0; row < 9; row++){
    cout<<"[";
    for(int col = 0; col < 9; col++){
      cout<<grid[row][col]<<", ";
    }
    cout<<"]"<<endl;
  }
}
int main() {
  int board [9][9] = {
  {1, 2, 6, 0, 0, 0, 0, 0, 3},
  {2, 5, 0, 0, 0, 1, 0, 0, 0},
  {3, 0, 9, 0, 0, 0, 0, 0, 0},
  {0, 8, 0, 0, 2, 0, 0, 0, 4},
  {0, 0, 0, 4, 1, 0, 0, 2, 0},
  {9, 0, 0, 0, 0, 0, 6, 0, 0},
  {0, 0, 3, 0, 0, 0, 0, 0, 9},
  {4, 0, 0, 0, 0, 2, 0, 0, 0},
  {0, 0, 1, 0, 0, 8, 0, 0, 7},
  };
  print_board(board);
  valid_board(board);
  int board2 [9][9] = {
  {1, 4, 4, 0, 0, 0, 0, 0, 3},
  {2, 5, 0, 0, 0, 1, 0, 0, 0},
  {3, 0, 9, 0, 0, 0, 0, 0, 0},
  {0, 8, 0, 0, 2, 0, 0, 0, 4},
  {0, 0, 0, 4, 1, 0, 0, 2, 0},
  {9, 0, 0, 0, 0, 0, 6, 0, 0},
  {0, 0, 3, 0, 0, 0, 0, 0, 9},
  {4, 0, 0, 0, 0, 2, 0, 0, 0},
  {0, 0, 1, 0, 0, 8, 0, 0, 7},
  };
  print_board(board2);
  valid_board(board2);
  return 0;
}