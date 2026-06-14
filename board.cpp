#include<iostream>
#include"board.h"
using namespace std;

void Board::displayBoard(){
    for (int i=0 ; i<9 ; i++){
        cout<<grid[i]<<" | "; 
         if(i==2 || i==5 ||i ==8){
            
            cout<<endl;
         }
      
    }

}
bool Board::updateSpace(int position, char symbol) {
    int index = position -1 ;
    if (index >= 0 && index < 9 && isSpaceFree(index)) {
       
        grid[index] = symbol;
        return true ; // when move was true and valid
    }
    return false ; // when move was ot of bound or space was already filled 
}

bool Board::isSpaceFree(int index){
    if (grid[index] =='X' || grid[index] == 'O'){
        return false;
    }
    return true;
}

bool Board::checkWin(){
// for  Rows
     if (grid[0] == grid[1] && grid[1] == grid[2]) 
     return true;
     if (grid[3] == grid[4] && grid[4] == grid[5]) 
     return true;
     
     if (grid[6] == grid[7] && grid[7] == grid[8]) 
     return true;
     
     
     //for columns 
     if (grid[0] == grid[3] && grid[3] == grid[6]) 
     return true; 
     if (grid[1] == grid[4] && grid[4] == grid[7]) 
     return true;
     if (grid[2] == grid[5] && grid[5] == grid[8]) 
     return true;
     
     // for diagonals 
     if (grid[0] == grid[4] && grid[4] == grid[8]) 
     return true;
     if (grid[2] == grid[4] && grid[4] == grid[6]) 
     return true;
   return false ;

}

// to check if board is full
bool Board::isBoardFull(){
    for(int index =0 ; index <9 ; index ++){
      if(isSpaceFree(index)){
        return false ; // means board is nto full 
      }
    }
   return true ;// means board is full  
}


// commom approach 
// bool Board ::isBoardFull(){
//     for (int index =0 ; index <9 ; index++){
//        if( grid[index] !='X' || grid[index] !='O'){
//         return false;
//        } 
//     }
//     return true ;
// }

