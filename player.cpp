#include <string>
#include <iostream>
#include "player.h"


player::player() {

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
