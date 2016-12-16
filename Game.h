#ifndef COMMANDLINESCRABBLE_GAME_H
#define COMMANDLINESCRABBLE_GAME_H

#include "Player.h"
#include "Board.h"
#include "BoardPlacement.h"
#include <fstream>
#include <ostream>



class Game {
private:
    Player players[2];
    Board gameBoard;
    LetterBag gameBag;
    ifstream dictionaryFile;
    BoardPlacement activePosition;
    string activeSquares;
    string activeWord;
    bool isFirstWord;
public:
    Game();
    void printPlayerTiles();
    void getWord(int);
    Board* getBoard();
    bool inDictionary(string);
    void setBoardPlacement();
    void showScores(ostream*);
    bool continuePlaying;
    void printBagLetters();
    void gameEnd(int);
    void exportGameResult();




};


#endif //COMMANDLINESCRABBLE_GAME_H
