#include <string>
#include <iostream>
#include "player.h"


player::player() {
    score = 0;
}

void player::setTileSet(letterBag* bag) {
    tileSet.setLetters(bag);
    tileSet.setLetterValues();
}

void player::setName(int i) {
    cout << "Player " << i << ", enter name..." << endl;
    cin >> name;
    cout << "\nHello " << name << "\n" << endl;
}

string player::getName() {
    return name;
}

playerTileSet* player::getTileSet() {
    return &tileSet;
}

void player::swapLetters(letterBag* gameBag) {
    string oldLetters = tileSet.getLetters();
    (*gameBag).putLettersBack(oldLetters);
    tileSet.removeLetters();
    setTileSet(gameBag);
}

void player::setScore(std::string playedWord) {
    score = score - tileSet.getWildCount();
    for (int i=0; i < playedWord.length(); i++) {
        char letter = playedWord[i];
        switch(letter) {
            case '-':
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
                score = score + 1;
                break;
            case 'D':
            case 'G':
                score = score + 2;
                break;
            case 'B':
            case 'C':
            case 'M':
            case 'P':
                score = score + 3;
            case 'F':
            case 'H':
            case 'V':
            case 'W':
            case 'Y':
                score = score + 4;
                break;
            case 'K':
                score = score + 5;
                break;
            case 'J':
            case 'X':
                score = score + 8;
                break;
            case 'Q':
            case 'Z':
                score = score + 10;
                break;

        }
    }

}

int player::getscore() {
    return score;
}