#ifndef COMMANDLINESCRABBLE_BOARD_H
#define COMMANDLINESCRABBLE_BOARD_H

#include "BoardPlacement.h"
#include <string>
#include <fstream>

class Board {
private:
    char squares[15][15];
public:
    Board();
    void displayBoard(std::ostream*);
    std::string getAlreadyPlaced(BoardPlacement *, int);
    void placeWord(std::string, BoardPlacement*);

};


#endif //COMMANDLINESCRABBLE_BOARD_H
