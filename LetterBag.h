#ifndef COMMANDLINESCRABBLE_LETTERBAG_H
#define COMMANDLINESCRABBLE_LETTERBAG_H

#include <string>
#include "TileSet.h"

using namespace std;

class LetterBag: public TileSet {

public:
    LetterBag();
    void removeLetter(int);
    int getLettersRemaining();
    void putLettersBack(string);


};


#endif //COMMANDLINESCRABBLE_LETTERBAG_H
