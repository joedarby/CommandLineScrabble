#include <iostream>
#include "game.h"


using namespace std;

game::game() {

    players[0].setTileSet(&gameBag);
    players[1].setTileSet(&gameBag);
    players[0].setName(1);
    players[1].setName(2);

    //runGame();

}

/*game::runGame() {
    while (true) {
        printBoard();
        printTiles();
        getPlayerInput();
        validateInput();
    }

}*/

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

void game::getWord(int p) {
    cout << players[p].getName() << ", enter a word..." << endl;
    cin >> activeWord;
    for (int i = 0; i < activeWord.length(); i ++) {
        activeWord[i] = toupper(activeWord[i]);
    }

    if (inDictionary(activeWord)) {
        setBoardPlacement();
        activeSquares = gameBoard.getActiveSquares(&activePosition, activeWord.length());
        if ((*(players[p].getTileSet())).wordValid(activeWord, activeSquares)) {
            cout << "Word can be made and placed" << endl;
            gameBoard.placeWord(activeWord, &activePosition);
        } else {
            cout << "You don't have the right letters or the word doesn't fit. Try again." << endl;
            getWord(p);
        }
    } else {
        cout << "That's not in the dictionary. Try again." << endl;
        getWord(p);
    }

/*
    for (int i = 0; i < input.length(); i ++) {
        input[i] = toupper(input[i]);
    }
    bool check = players[p].getTileSet()->wordValid(input);
    if (check) {
        if (inDictionary(input)) {
            cout << "Word valid" << endl;
            return input;
        } else {
            cout << input << " is not in the dictionary" << endl;
            getWord(p);
        }

    } else {
        cout << "You don't have the right letters" << endl;
        getWord(p);
    }*/
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
    cout << "Enter starting tile and direction (H or V) eg. \"D7 V\":";
    string tileRef;
    string direction;
    cin >> tileRef;
    cin >> direction;
    if (tileRef.length() < 4 && tileRef.length() > 1) {
        if (direction.length() == 1) {
            direction[0] = toupper(direction[0]);
            if (direction == "V" || direction == "H") {
                for (int i = 0; i < 3; i++) {
                    tileRef[i] = toupper(tileRef[i]);
                }
                activePosition.setPlacement(tileRef, direction);
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

