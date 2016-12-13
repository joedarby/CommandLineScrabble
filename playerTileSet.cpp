#include <cstdlib>
#include "playerTileSet.h"
#include <ctime>
#include <algorithm>

using namespace std;

playerTileSet::playerTileSet() {
    playerLetters = "";
    wildCount = 0;
}


void playerTileSet::setLetters(letterBag* bag) {
    int tilesAlready = playerLetters.length();
    for (int i = 0; i < (7 - tilesAlready); i++) {
        string availableTiles = (*bag).getLetters();
        srand(time(NULL));
        int randNum = rand()%((*bag).getLettersRemaining());
        playerLetters = playerLetters + availableTiles[randNum];
        (*bag).removeLetter(randNum);
    }
}

void playerTileSet::removeLetters(string playedWord) {
    string oldLetters = playerLetters;
    playerLetters = "";
    for (int i =0; i < playedWord.length(); i++) {
        for (int j=0; j < oldLetters.length(); j++) {
            if (oldLetters[j] == playedWord [i]) {
                oldLetters[j] = ' ';
                break;
            }
        }
    }
    for (int i=0; i < oldLetters.length(); i++) {
        if (oldLetters[i] != ' ') {
            playerLetters = playerLetters + oldLetters[i];
        }
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
                bool wildcardUsed = false;
                for (int j = 0; j < lettersAvailable.length(); j ++) {
                    if (lettersAvailable[j] == '-') {
                        lettersAvailable[j] = '.';
                        playerLetters[j] = playerWord[i];
                        wildcardUsed = true;
                        wildCount = wildCount +1;
                        break;
                    }
                }
                if (!wildcardUsed) return false;
            } else lettersAvailable[pos] = '.';
        } else if (activeSquares[i] != playerWord[i]) {
            return false;
        } else playerLetters = playerLetters + activeSquares[i];
    }
    return true;
}

int playerTileSet::getAndResetWildCount() {
    int val = wildCount;
    wildCount = 0;
    return val;
}



