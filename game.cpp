#include <iostream>
#include "game.h"


using namespace std;

game::game() {
    continuePlaying = true;
    players[0].setTileSet(&gameBag);
    players[1].setTileSet(&gameBag);
    players[0].setName(1);
    players[1].setName(2);
    isFirstWord = true;

    //runGame();

}


board* game::getBoard() {
    return &gameBoard;
}

void game::printPlayerTiles() {
    cout << players[0].getName() << "\'s tiles:                        " << players[1].getName() << "\'s tiles:" << endl;
    //print letters
    cout << "| ";
    for (int i = 0; i < 7; i++) {
        cout << (players[0].getTileSet()->getLetters())[i] << " | ";
    }
    cout << "           | ";
    for (int i = 0; i < 7; i++) {
        cout << (players[1].getTileSet()->getLetters())[i] << " | ";
    }
    cout << endl;

    //print values
    cout << "| ";
    for (int i = 0; i < 7; i++) {
        int val = players[0].getTileSet()->getLetterValues()[i];
        if (val <= 9)
            cout << val << " | ";
        else
            cout << val << "| ";
    }
    cout << "           | ";
    for (int i = 0; i < 7; i++) {
        int val = players[1].getTileSet()->getLetterValues()[i];
        if (val <= 9)
            cout << val << " | ";
        else
            cout << val << "| ";
    }
    cout << "\n" << endl;
}

void game::getWord(int player) {
    cout << players[player].getName() << ", enter a word..." << endl;
    cin >> activeWord;
    for (int i = 0; i < activeWord.length(); i ++) {
        activeWord[i] = toupper(activeWord[i]);
    }

    if (activeWord == "X") {
        players[player].swapLetters(&gameBag);

    } else if (activeWord == "Q"){
        gameEnd(player);
    } else if (inDictionary(activeWord)) {
        setBoardPlacement();
        activeSquares = gameBoard.getAlreadyPlaced(&activePosition, activeWord.length());
        if ((*(players[player].getTileSet())).wordValid(activeWord, activeSquares)) {
            gameBoard.placeWord(activeWord, &activePosition);
            players[player].getTileSet()->removeLetters(activeWord);
            players[player].setTileSet(&gameBag);
            players[player].setScore(activeWord);
            if (isFirstWord) isFirstWord = false;
        } else {
            cout << "You don't have the right letters or the word doesn't fit. Try again." << endl;
            getWord(player);
        }

    } else {
        cout << "That's not in the dictionary. Try again." << endl;
        getWord(player);
    }


}

bool game::inDictionary(string input) {
    dictionaryFile.open("dictionary.txt");
    bool match = false;
    string word;
    while (dictionaryFile >> word) {
        if (input.compare(word) == 0) {
            match = true;
            break;
        }
    }
    dictionaryFile.close();
    return match;

}

void game::setBoardPlacement() {
    cout << "Position/direction: ";
    string tileRef;
    string direction;
    cin >> tileRef;
    cin >> direction;
    if (tileRef.length() < 4 && tileRef.length() > 1) {
        if (direction.length() == 1) {
            direction[0] = toupper(direction[0]);
            if (direction == "D" || direction == "A") {
                for (int i = 0; i < 3; i++) {
                    tileRef[i] = toupper(tileRef[i]);
                }
                activePosition.setPlacement(tileRef, direction, activeWord.length(), isFirstWord);
                if (activePosition.getValidity()) {
                } else {
                    cout << "Invalid placement. Try again." << endl;
                    setBoardPlacement();
                }
            }  else {
                cout << "Invalid direction. Try again." << endl;
                setBoardPlacement();
            }
        } else {
            cout << "Invalid direction. Try again." << endl;
            setBoardPlacement();
        }
        for (int i = 0; i < 2; i ++) {
            tileRef[i] = toupper(tileRef[i]);
        }
    } else {
        cout << "Invalid starting tile. Try again." << endl;
        setBoardPlacement();
    }

}


void game::showScores() {
    cout << "The scores are:   " << players[0].getName() << ": " << players[0].getscore() << "    " << players[1].getName() << ": " << players[1].getscore() << endl;
}

void game::printBagLetters() {
    cout << gameBag.getLetters() << endl;
}

void game::gameEnd(int player) {
    cout << "Are you sure you want to finish? (Y/N) " << endl;
    char choice;
    cin >> choice;
    if (toupper(choice) == 'Y') {
        continuePlaying = false;
    } else if (toupper(choice) == 'N') {
        getWord(player);
    } else gameEnd(player);
}