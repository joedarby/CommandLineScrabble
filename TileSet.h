#ifndef COMMANDLINESCRABBLE_TILESET_H
#define COMMANDLINESCRABBLE_TILESET_H

#include <string>

//A general TileSet class, inherited by PlayerTileSet and LetterBag

class TileSet {
protected:
    std::string letters;

public:
    std::string getLetters();

};


#endif //COMMANDLINESCRABBLE_TILESET_H
