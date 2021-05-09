#include <iostream>
#include "ZebrasPath.h"
using namespace std;

int main(){
  int startingrow,startingcolumn,zebrar,zebrac;
  bool startgame=false;
  bool endgame==false;
  while(startgame==false){
    //Ask the user to enter the starting position.
    cout<<"Zebra's starting position (row col): ";
    cin>>startingrow>>startingcolumn;
    //Determine whether the row and column that the player enter is in range 0-7. 
    if (startingrow>=0&&startingrow<=7&&startingcolumn>=0&&startingcolumn<=7){
      startgame=true;
    }
    else{
      //If the row and column entered are not in the range ask user to enter again.
      cout<<"Invalid. Try again!\n";
    }
  }
  ZebrasPath book(startingrow,startingcolumn);
  book.print();
  while (endgame==false){
    //Ask the player to enter a move.
    cout<<"Make a move (row col): "
    cin<<zebrar<<zebrac;
    book.move(zebrar,zebrac);
    //Check the move of the zebra the player entered is valid or not. If not then warn and ask the player to enter a new one.
    if(book.move(zebrar,zebrac)==false){
      cout<<"Invalid move. Try again!\n";
    }
    else{
      book.print();
      //To check the zebra has more moves or not.If no, then end the game.
      book.hasMoreMoves();
      if(book.hasMoreMoves==false){
        cout<<"No more moves!\n;
        endgame=true;
      }
    }
  }
}