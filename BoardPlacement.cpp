#include <iostream>
#include "BoardPlacement.h"

//Class to represent the position a word will occupy on the Board. If validity is true, getWord in Game will accept the word

using namespace std;

BoardPlacement::BoardPlacement() {

}


void BoardPlacement::setPlacement(string tileRef, string direction, int length, bool isFirstWord) {
    wordLength = length;
    setStartRow(tileRef);
    setStartColumn(tileRef);
    setHorizontalAlignment(direction);
    checkIsFirstWord(length, isFirstWord);
    checkLength(length);

}

bool BoardPlacement::getValidity() {
    return validity;
}

int BoardPlacement::getStartRow() {
    return startRow;
}

int BoardPlacement::getStartColumn() {
    return startColumn;
}

bool BoardPlacement::getHorizontalAlignment() {
    return horizontalAlignment;
}

void BoardPlacement::setStartRow(string tileRef) {
    validity = true;
    if (tileRef[0] >= 65 && tileRef[0] <=79) {
        startRow = tileRef[0] - 65;
    } else {
        startRow = 0;
        validity = false;
    }
}

void BoardPlacement::setStartColumn(std::string tileRef){
    int col = 0;
    if (tileRef.length() == 2) {
        col = tileRef[1] - '0';
    } else {
        col = 10 + (tileRef[2] -'0');
    }

    if (col >= 1 && col < 16) {
        startColumn = col - 1;
    } else {
        startColumn = 0;
        validity = false;
    }
}

void BoardPlacement::setHorizontalAlignment(string direction) {
    if (direction == "A") {
        horizontalAlignment = true;
    } else if (direction == "D") {
        horizontalAlignment = false;
    } else {
        horizontalAlignment = true;
        validity = false;
    }
}

void BoardPlacement::checkIsFirstWord(int length, bool isFirstWord) {
    if (isFirstWord) {
        if (horizontalAlignment) {
            if (startRow != 7) validity = false;
            else if (startColumn + length < 8) validity = false;
        } else {
            if (startColumn != 7) validity = false;
            else if (startRow + length < 8) validity = false;
        }
        if (!validity) cout << "\nFirst word must pass through H8" << endl;
    }
}

void BoardPlacement::checkLength(int length) {
    if (horizontalAlignment) {
        if (startColumn + length > 15) {
            validity = false;
        }
    } else if (startRow + length > 15) {
        validity = false;
    }
}
