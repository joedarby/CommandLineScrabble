#ifndef COMMANDLINESCRABBLE_BOARD_H
#define COMMANDLINESCRABBLE_BOARD_H

#include "boardPlacement.h"
#include <string>
#include <fstream>

class board {
private:
    char squares[15][15];
public:
    board();
    void displayBoard(std::ostream*);
    std::string getAlreadyPlaced(boardPlacement *, int);
    void placeWord(std::string, boardPlacement*);

};


#endif //COMMANDLINESCRABBLE_BOARD_H
