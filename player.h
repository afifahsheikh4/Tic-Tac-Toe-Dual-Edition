#pragma once
#include <string>


class Player{ // represents individual playing game 
    private: 
     std::string name;
     char symbol;
     
    public: 
    Player();
    // parameterized constructor 
    Player(std::string playerName , char playerSymbol);
    // methhods 
     char getSymbol();
     std::string getName(); 
    
};