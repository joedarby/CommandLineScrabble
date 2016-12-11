#include <cstdlib>
#include "playerTileSet.h"
#include <ctime>
#include <algorithm>

using namespace std;

playerTileSet::playerTileSet() {}



void playerTileSet::setLetters(letterBag* bag) {
    playerLetters = "";
    for (int i = 0; i < 7; i++) {
        string availableTiles = (*bag).getLetters();
        srand(time(NULL));
        int randNum = rand()%((*bag).getLettersRemaining());
        playerLetters = playerLetters + availableTiles[randNum];
        (*bag).removeLetter(randNum);
    }


}

string playerTileSet::getLetters() {
    return playerLetters;
}

void playerTileSet::setLetterValues() {
    for (int i = 0; i < 7; i++) {
        char letter = playerLetters[i];
        switch(letter) {
            case '-':
                letterValues[i] = 0;
                break;
            case 'E':
            case 'A':
            case 'I':
            case 'O':
            case 'N':
            case 'R':
            case 'T':
            case 'L':
            case 'S':
            case 'U':
                letterValues[i] = 1;
                break;
            case 'D':
            case 'G':
                letterValues[i] = 2;
                break;
            case 'B':
            case 'C':
            case 'M':
            case 'P':
                letterValues[i] = 3;
            case 'F':
            case 'H':
            case 'V':
            case 'W':
            case 'Y':
                letterValues[i] = 4;
                break;
            case 'K':
                letterValues[i] = 5;
                break;
            case 'J':
            case 'X':
                letterValues[i] = 8;
                break;
            case 'Q':
            case 'Z':
                letterValues[i] = 10;
                break;

        }
    }
}

int* playerTileSet::getLetterValues() {
    return letterValues;
}


bool playerTileSet::wordValid(string playerWord, string activeSquares) {

    string lettersAvailable = playerLetters;
    for (int i = 0; i < activeSquares.length(); i++) {
        if (activeSquares[i] == ' ') {
            size_t pos = lettersAvailable.find_first_of(playerWord[i], 0);
            if (pos == -1) {
                return false;
            } else lettersAvailable[pos] = ' ';
        } else if (activeSquares[i] != playerWord[i]) {
            return false;
        }
    }
    return true;
}



