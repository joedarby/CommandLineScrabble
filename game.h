#ifndef COMMANDLINESCRABBLE_GAME_H
#define COMMANDLINESCRABBLE_GAME_H

#include "player.h"
#include "board.h"
#include "boardPlacement.h"
#include <fstream>



class game {
private:
    player players[2];
    board gameBoard;
    letterBag gameBag;
    ifstream dictionaryFile;
    boardPlacement activePosition;
    string activeSquares;
    string activeWord;
    bool isFirstWord;
public:
    game();
    void printPlayerTiles();
    void getWord(int);
    board* getBoard();
    bool inDictionary(string);
    void setBoardPlacement();
    void firstWordPlaced();
    void showScores();
    bool continuePlaying;




};


#endif //COMMANDLINESCRABBLE_GAME_H
