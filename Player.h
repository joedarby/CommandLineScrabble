#ifndef COMMANDLINESCRABBLE_PLAYER_H
#define COMMANDLINESCRABBLE_PLAYER_H

#include <string>
#include "PlayerTileSet.h"

using namespace std;

class Player {
private:
    string name;
    int score;
    PlayerTileSet tileSet;
    int wildcardsJustUsed;

public:
    Player();
    void setName(int);
    string getName();
    void setTileSet(LetterBag*);
    PlayerTileSet* getTileSet();
    void setScore(std::string);
    int getscore();
    void swapLetters(LetterBag*);







};


#endif //COMMANDLINESCRABBLE_PLAYER_H
