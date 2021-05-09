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

//print the board.
void ZebrasPath::print(){
  cout<<"  0 1 2 3 4 5 6 7\n";
  int row_num=0;
  for(i=0;i<=7;i++){
    cout<<row_num;
    row_num++;
    for (j=0;j<=7;j++){
      cout<<" ";
      //print the empty place as ".".
      if(board[i][j]==-1)
        cout<<".";
      else if(board[i][j]==0)
      //print the starting position as "z".
        cout<<"z";
      else if(board[i][j]==steps)
      //print the current position as "Z".
        cout<<"Z";
      else
      //print the place that the zebra crossed before.
        cout<<board[i][j];
    }
    cout<<endl;
  }
  //Show out the no. of steps used.
  cout<<"Steps: "<<steps<<endl;
} 

//check the move that the player entered is valid or not.
bool ZebrasPath::isValid(int r,int c){
  //check that the row and column is inside the range of 0-7 or not.
  if(r>=0&&r<=7&&c>=0&&c<=7){
    //check that the position the user choose is empty or not.
    if(board[r][c]==-1){
      //check the pervious position is 3V2H or 2V3H or not.
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
//Determine is there any avaliable move.
bool ZebrasPath::hasMoreMoves(){
  int num_of_movable_position=0;
  //check all the empty place in the board is avaliable or not
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

//Check the move is valid or not by isValid() function, then revalue currentC, currentR and steps.
bool ZebrasPath::move(int r, int c){
  if (board[r][c]==-1&&isValid(r,c)==true){
    currentR=r;
    currentC=c;
    steps++;
    board[r][c]=steps;
    return true;
  }
  else
    return false;
}