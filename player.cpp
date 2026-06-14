#include<iostream>
#include"player.h"
using namespace std;

Player::Player() = default;
Player::Player(string playerName , char playerSymbol){
    name = playerName;
    symbol = playerSymbol;
}
string Player ::getName(){
   return name ;
}

char Player ::getSymbol(){
    return symbol;
}