#include <iostream>
#include "Game.h"

using namespace std;


int main() {

    cout << "Welcome to Command Line Scrabble\n" << endl;
    cout << "How to play:" << endl;
    cout << "- Each Player is randomly given tiles from the bag and takes turns to place words on the Board." << endl;
    cout << "- Type in the word you want to place when prompted." << endl;
    cout << "- Then give the position and direction of the word." << endl;
    cout << "- The position is the coordinates for the first letter of the word (eg. \"C10\")." << endl;
    cout << "- The direction is \"A\" for across or \"D\" for down." << endl;
    cout << "- So for example to place a word going down from C7, enter \"C7 D\".\n" << endl;
    cout << "- To swap all your letters (and miss a go) enter \"X\"" << endl;
    cout << "- To end the Game enter \"Q\"\n" << endl;


    Game activeGame;

    int activePlayer = 1;

    while (activeGame.continuePlaying) {
        if (activePlayer == 0) activePlayer = 1;
        else activePlayer = 0;
        for (int i = 0; i < 100; i++) {
            cout << endl;
        }
        activeGame.getBoard()->displayBoard(&cout);
        activeGame.printPlayerTiles();
        activeGame.showScores(&cout);
        activeGame.getWord(activePlayer);
    }
    activeGame.exportGameResult();

    return 0;
}