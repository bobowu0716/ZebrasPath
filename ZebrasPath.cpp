#include <iostream>
#include "ZebrasPath"
using namespace std;

ZebrasPath::ZebrasPath(int r,int c){
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
  R=r;
  C=c;
  steps=0;
}

void ZebrasPath::print(){
  cout<<"  0 1 2 3 4 5 6 7\n";
  int row_num=0;
  for(i=0;i<=7;i++){
    cout<<row_num;
    row_num++;
    for (j=0;j<=7;j++){
      
    }
  }
} 

bool ZebrasPath::isValid(int r,int c){
  
}

bool ZebrasPath::hasMoreMoves(){
  
}

bool ZebrasPath::move(int r, int c){
  
}