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
    if (tileRef[0] >= 65 && tileRef[0] <=79) {
        startRow = tileRef[0] - 65;
    } else {
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
