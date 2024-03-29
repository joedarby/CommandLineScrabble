#ifndef COMMANDLINESCRABBLE_PLAYERTILESET_H
#define COMMANDLINESCRABBLE_PLAYERTILESET_H

#include <string>
#include "LetterBag.h"
#include "TileSet.h"

class PlayerTileSet: public TileSet {
private:
    int letterValues[7];
    int wildCount;

public:
    PlayerTileSet();
    void setLetters(LetterBag*);
    void setLetterValues();
    int* getLetterValues();
    bool wordValid(std::string, std::string);
    void removeLetters(std::string);
    void removeLetters();
    int getWildCount();



};


#endif //COMMANDLINESCRABBLE_PLAYERTILESET_H
