#ifndef COMMANDLINESCRABBLE_BOARD_H
#define COMMANDLINESCRABBLE_BOARD_H

#include "boardPlacement.h"
#include <string>

class board {
private:
    char squares[15][15];
public:
    board();
    void displayBoard();
    std::string getActiveSquares(boardPlacement*, int);
    void placeWord(std::string, boardPlacement*);
};


#endif //COMMANDLINESCRABBLE_BOARD_H
