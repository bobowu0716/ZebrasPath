#include <iostream>
#include "ZebrasPath.h"
using namespace std;

ZebrasPath::ZebrasPath(int r,int c){
  //Initialize the board with value -1 except the starting position with value 0.
  for(int i=0;i<=7;i++){
    for(int j=0;j<=7;j++){
      if(i==r&&j==c){
        board[i][j]=0;
      }
      else{
        board[i][j]=-1;
      }
    }
  }
  //Set the currentC, currentR and let the original step be 0.
  currentR=r;
  currentC=c;
  steps=0;
}

void ZebrasPath::print(){
  cout<<"  0 1 2 3 4 5 6 7\n";
  int row_num=0;
  for(i=0;i<=7;i++){
    cout<<row_num;
    row_num++;
    for (j=0;j<=7;j++){
      cout<<" ";
      if(board[i][j]==-1)
        cout<<".";
      else if(board[i][j]==0)
        cout<<"z";
      else if(board[i][j]==steps)
        cout<<"Z";
      else
        cout<<board[i][j];
    }
    cout<<endl;
  }
  cout<<"Steps: "<<steps<<endl;
} 

bool ZebrasPath::isValid(int r,int c){
  if(r>=0&&r<=7&&c>=0&&c<=7){
    if(board[r][c]==-1){
      if((r+3==R&&c+2==C)||(r+3==R&&c-2==C)||(r-3==R&&c+2==C)||(r-3==R&&c-2==C)||(r+2==R&&c+3==C)||(r+2==R&&c-3==C)||(r-2==R&&c+3==C)||(r-2==R&&c-3==C))
        return true;
      else
        return false;
    }
    else
      return false;
  }
  else
    return false;
}

bool ZebrasPath::hasMoreMoves(){
  int num_of_movable_position=0;
  for(int i=0;i<=7;i++){
    for(int j=0;j<=7;j++){
      if (board[i][j]==-1&&isValid(i,j)==true)
        num_of_movable_position++;
    }
  }
  if (num_of_movable_position!=0)
    return true;
  else
    return false;
}

bool ZebrasPath::move(int r, int c){
  if (board[r][c]==-1&&isValid(r,c)==true){
    R=r;
    C=c;
    steps++;
    board[r][c]=steps;
    return true;
  }
  else
    return false;
}