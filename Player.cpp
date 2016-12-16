#include <string>
#include <iostream>
#include "Player.h"

//Class to represent each Player, holding their name, score, letters, etc.

Player::Player() {
    score = 0;
}

void Player::setTileSet(LetterBag* bag) {
    tileSet.setLetters(bag);
    tileSet.setLetterValues();
}

void Player::setName(int i) {
    cout << "Player " << i << ", enter name..." << endl;
    cin >> name;
    cout << "\nHello " << name << "\n" << endl;
}

string Player::getName() {
    return name;
}

PlayerTileSet* Player::getTileSet() {
    return &tileSet;
}

void Player::swapLetters(LetterBag* gameBag) {
    string oldLetters = tileSet.getLetters();
    (*gameBag).putLettersBack(oldLetters);
    tileSet.removeLetters();
    setTileSet(gameBag);
}

void Player::setScore(std::string playedWord) {
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
                score += 1;
                break;
            case 'D':
            case 'G':
                score += 2;
                break;
            case 'B':
            case 'C':
            case 'M':
            case 'P':
                score += 3;
            case 'F':
            case 'H':
            case 'V':
            case 'W':
            case 'Y':
                score += 4;
                break;
            case 'K':
                score += 5;
                break;
            case 'J':
            case 'X':
                score += 8;
                break;
            case 'Q':
            case 'Z':
                score += 10;
                break;

        }
    }

}

int Player::getscore() {
    return score;
}