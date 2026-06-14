#include<iostream>
#include"game.h"
using namespace std;


Game::Game(const Player &player1, const Player &player2 ){
    players[0] = player1;
    players[1] = player2;
    currentPlayerindex = 0;
}

void Game::switchPlayer()
{
    if (currentPlayerindex == 0) {
        currentPlayerindex = 1;
    }
    else {
        currentPlayerindex = 0;
    }
}

bool Game::isgameActive()
{
    if (!board.isBoardFull() && !board.checkWin()) {
        return true;
    }
    return false;
}

void Game::play()
{
    int choice ;
    while (isgameActive()) {
       board.displayBoard(); // so players can see board 
      
       bool moveSucessful = false;
       while(!moveSucessful){
       cout<<players[currentPlayerindex].getName()<<" ("<<players[currentPlayerindex].getSymbol()<<"),your move!"<<endl;
       cin>>choice ;

       // updating space 
       moveSucessful=board.updateSpace(choice, players[currentPlayerindex].getSymbol());
       
       if(!moveSucessful){
        cout<<"Invalid move ! \nPlease enter a number between 1 and 9 for a free space.\n"<<endl;
       }
    }
    
       if(board.checkWin()){
        board.displayBoard();
        cout<< players[currentPlayerindex].getName() << " wins!" << endl;
            return;
       }

       if(board.isBoardFull()){
        board.displayBoard();
        cout<<"🤝 It's a draw!"<<endl;
        return ;
       }

       //switch player once entire turn is complete
       switchPlayer();
    }
}



