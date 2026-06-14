#pragma once
#include<vector>


/*
board class : manages playing field it does not care 
who is playing 
*/ 

class Board{
  public:
    // data members
   std:: vector <char> grid ={'1','2','3','4','5','6','7','8','9'};  // vector of size 9

   // methods 
   void displayBoard();
   bool updateSpace(int position , char symbol ); 
   bool isSpaceFree(int index);
   bool checkWin();
   bool isBoardFull();
};


