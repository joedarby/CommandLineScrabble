#include "boardPlacement.h"

using namespace std;

boardPlacement::boardPlacement() {

}




void boardPlacement::setPlacement(string tileRef, string direction, int length, bool isFirstWord) {
    wordLength = length;
    setStartRow(tileRef);
    setStartColumn(tileRef);
    setHorizontalAlignment(direction);
    checkIsFirstWord(length, isFirstWord);
    checkLength(length);

}

bool boardPlacement::getValidity() {
    return validity;
}

int boardPlacement::getStartRow() {
    return startRow;
}

int boardPlacement::getStartColumn() {
    return startColumn;
}

bool boardPlacement::getHorizontalAlignment() {
    return horizontalAlignment;
}

void boardPlacement::setStartRow(string tileRef) {
    validity = true;
    switch (tileRef[0]) {
        case 'A':
            startRow = 0;
            break;
        case 'B':
            startRow = 1;
            break;
        case 'C':
            startRow = 2;
            break;
        case 'D':
            startRow = 3;
            break;
        case 'E':
            startRow = 4;
            break;
        case 'F':
            startRow = 5;
            break;
        case 'G':
            startRow = 6;
            break;
        case 'H':
            startRow = 7;
            break;
        case 'I':
            startRow = 8;
            break;
        case 'J':
            startRow = 9;
            break;
        case 'K':
            startRow = 10;
            break;
        case 'L':
            startRow = 11;
            break;
        case 'M':
            startRow = 12;
            break;
        case 'N':
            startRow = 13;
            break;
        case 'O':
            startRow = 14;
            break;
        default:
            startRow = 0;
            validity = false;

    }
}

void boardPlacement::setStartColumn(std::string tileRef){
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

void boardPlacement::setHorizontalAlignment(string direction) {
    if (direction == "A") {
        horizontalAlignment = true;
    } else if (direction == "D") {
        horizontalAlignment = false;
    } else {
        horizontalAlignment = true;
        validity = false;
    }
}

void boardPlacement::checkIsFirstWord(int length, bool isFirstWord) {
    if (isFirstWord) {
        if (horizontalAlignment) {
            if (startRow != 7) validity = false;
            else if (startColumn + length < 8) validity = false;
        } else {
            if (startColumn != 7) validity = false;
            else if (startRow + length < 8) validity = false;
        }
    }
}

void boardPlacement::checkLength(int length) {
    if (horizontalAlignment) {
        if (startColumn + length > 15) {
            validity = false;
        }
    } else if (startRow + length > 15) {
        validity = false;
    }
}
