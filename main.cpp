#include <iostream>
#include "game.h"

using namespace std;

//Construct the initial bag of 100 letter tiles

int main() {

    cout << "Welcome to Command Line Scrabble\n" << endl;
    game activeGame;

    activeGame.getBoard()->displayBoard();
    cout << "Let's get started!\n" << endl;
    activeGame.printPlayerTiles();
    activeGame.getWord(0);
    activeGame.getBoard()->displayBoard();
    activeGame.getWord(1);
    activeGame.getBoard()->displayBoard();

    return 0;
}