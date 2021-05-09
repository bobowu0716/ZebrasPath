#include <iostream>
#include "ZebrasPath"
using namespace std;

int main(){
  int startingrow,startingcolumn,zebrar,zebrac;
  bool startgame=false;
  bool endgame==false;
  while(startgame==false){
    cout<<"Zebra's starting position (row col): ";
    cin>>startingrow>>startingcolumn;
    if (startingrow>=0&&startingrow<=7&&startingcolumn>=0&&startingcolumn<=7){
      startgame=true;
    }
    else{
      cout<<"Invalid. Try again!\n";
    }
  }
  ZebrasPath book(startingrow,startingcolumn);
  book.print();
  while (endgame==false){
    cout<<"Make a move (row col): "
    cin<<zebrar<<zebrac;
    book.move(zebrar,zebrac);
    if(book.move(zebrar,zebrac)==false){
      cout<<"Invalid move. Try again!\n";
    }
    else{
      book.print();
      book.hasMoreMoves();
      if(book.hasMoreMoves==false){
        cout<<"No more moves!\n;
        endgame=true;
      }
    }
  }
}