#ifndef COMMANDLINESCRABBLE_GAME_H
#define COMMANDLINESCRABBLE_GAME_H

#include "player.h"
#include "board.h"
#include "boardPlacement.h"
#include <fstream>
#include <ostream>



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
    void showScores(ostream*);
    bool continuePlaying;
    void printBagLetters();
    void gameEnd(int);
    void exportGameResult();




};


#endif //COMMANDLINESCRABBLE_GAME_H
