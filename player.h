#ifndef COMMANDLINESCRABBLE_PLAYER_H
#define COMMANDLINESCRABBLE_PLAYER_H

#include <string>
#include "playerTileSet.h"

using namespace std;

class player {
private:
    string name;
    int score;
    playerTileSet tileSet;
    int wildcardsJustUsed;

public:
    player();
    void setName(int);
    string getName();
    void setTileSet(letterBag*);
    playerTileSet* getTileSet();
    void setScore(std::string);
    int getscore();







};


#endif //COMMANDLINESCRABBLE_PLAYER_H
