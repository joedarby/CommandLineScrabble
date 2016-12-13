#include <iostream>
#include "game.h"

using namespace std;

//Construct the initial bag of 100 letter tiles

int main() {

    cout << "Welcome to Command Line Scrabble\n" << endl;
    cout << "How to play:" << endl;
    cout << "- Each player is randomly given tiles from the bag and takes turns to place words on the board." << endl;
    cout << "- Type in the word you want to place when prompted." << endl;
    cout << "- Then give the position and direction of the word." << endl;
    cout << "- The position is the coordinates for the first letter of the word (eg. \"C10\")." << endl;
    cout << "- The direction is \"A\" for across or \"D\" for down." << endl;
    cout << "- So for example to place a word going down from C7, enter \"C7 D\".\n" << endl;

    game activeGame;

    int activePlayer = 1;

    while (activeGame.continuePlaying) {
        if (activePlayer == 0) activePlayer = 1;
        else activePlayer = 0;
        activeGame.getBoard()->displayBoard();
        activeGame.printPlayerTiles();
        activeGame.showScores();
        activeGame.getWord(activePlayer);
    }

    return 0;
}