#pragma once
#include"board.h"
#include"player.h"


class Game{
  private:
   Board board;
   Player players[2]; // array
   int currentPlayerindex;

  public: 
   Game(const Player& player1, const Player& player2 );

   void play(); //main control system 
   void switchPlayer();
   bool isgameActive();
};