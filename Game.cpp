#include <iostream>
#include <fstream>
#include "Game.h"

//This class contains the major functions and variables of the Game

using namespace std;

Game::Game() {
    continuePlaying = true; //Set to false by gameEnd function if getWord receives input "Q"
    players[0].setTileSet(&gameBag);
    players[1].setTileSet(&gameBag);
    players[0].setName(1);
    players[1].setName(2);
    isFirstWord = true; //Set to false after first valid word is entered, to make sure first word crosses centre tile

}

Board* Game::getBoard() {
    return &gameBoard;
}

void Game::printPlayerTiles() {
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

//Accept a word as input from Player. Convert to upper case. Check for X, Q and validity.
void Game::getWord(int player) {
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
//Check word is in dictionary.txt, a standard scrabble dictionary file found online
bool Game::inDictionary(string input) {
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

//Take the starting tile (eg. C7) and direction (A or D) where Player wants to place word
void Game::setBoardPlacement() {
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
                if (!activePosition.getValidity()) {
                    cout << "Invalid placement. Try again.\n" << endl;
                    setBoardPlacement();
                }
            }  else {
                cout << "Invalid direction. Try again.\n" << endl;
                setBoardPlacement();
            }
        } else {
            cout << "Invalid direction. Try again.\n" << endl;
            setBoardPlacement();
        }
        for (int i = 0; i < 2; i ++) {
            tileRef[i] = toupper(tileRef[i]);
        }
    } else {
        cout << "Invalid starting tile. Try again.\n" << endl;
        setBoardPlacement();
    }

}


void Game::showScores(ostream* file) {
    *file << "The scores are:   " << players[0].getName() << ": " << players[0].getscore() << "    " << players[1].getName() << ": " << players[1].getscore() << endl;
}


void Game::gameEnd(int player) {
    cout << "Are you sure you want to finish? (Y/N) " << endl;
    char choice;
    cin >> choice;
    if (toupper(choice) == 'Y') {
        continuePlaying = false;
    } else if (toupper(choice) == 'N') {
        getWord(player);
    } else gameEnd(player);
}

void Game::exportGameResult() {
    ofstream file("ScrabbleResult.txt");
    gameBoard.displayBoard(&file);
    showScores(&file);
    file << endl;
    cout << "The result is saved in ScrabbleResult.txt" << endl;





}