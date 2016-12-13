#include <iostream>
#include "letterBag.h"

using namespace std;

letterBag::letterBag() {
    letters = "--EEEEEEEEEEEEAAAAAAAAAIIIIIIIIIOOOOOOOONNNNNNRRRRRRTTTTTTLLLLSSSSUUUUDDDDGGGBBCCMMPPFFHHVVWWYYKJXQZ";
}

string letterBag::getLetters() {
    return letters;
}

int letterBag::getLettersRemaining() {
    return letters.length();
}

void letterBag::removeLetter(int index) {
    int previousSize = letters.length() ;
    string remainingLetters = "";
    for (int i = 0; i < index; i++) {
        remainingLetters = remainingLetters + letters[i];
    }
    for (int j = index + 1; j < previousSize; j++) {
        remainingLetters = remainingLetters + letters[j];
    }
    letters = remainingLetters;
}

void letterBag::putLettersBack(string returnedLetters) {
    letters = letters + returnedLetters;
}








/*letterBag::letterBag(letterBag* oldBag, int removedTileIndex) {

    tile* oldTiles = oldBag->getBag();
    int size = oldBag->getTilesRemaining() - 1;
    tiles = new tile[size];

    for (int i = 0; i < removedTileIndex; i++) {
        tiles[i] = oldTiles[i];
    }

    for (int j = removedTileIndex + 1; j < size + 1; j++) {
        tiles[j-1] = oldTiles[j];
    }
    tilesRemaining = size;
}



int letterBag::getTilesRemaining() {
    return tilesRemaining;
}

tile* letterBag::getBag() {
    return tiles;
}*/

