#ifndef COMMANDLINESCRABBLE_PLAYERTILESET_H
#define COMMANDLINESCRABBLE_PLAYERTILESET_H

#include <string>
#include "letterBag.h"

class playerTileSet {
private:
    std::string playerLetters;
    int letterValues[7];
    int wildCount;

public:
    playerTileSet();
    void setLetters(letterBag*);
    void setLetterValues();
    std::string getLetters();
    int* getLetterValues();
    bool wordValid(std::string, std::string);
    void removeLetters(std::string);
    void removeLetters();
    int getWildCount();



};


#endif //COMMANDLINESCRABBLE_PLAYERTILESET_H
