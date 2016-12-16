#ifndef COMMANDLINESCRABBLE_BOARDPLACEMENT_H
#define COMMANDLINESCRABBLE_BOARDPLACEMENT_H

#include <string>

class BoardPlacement {
private:
    int startRow;
    int startColumn;
    int wordLength;
    bool horizontalAlignment;
    bool validity;
    void setStartRow(std::string);
    void setStartColumn(std::string);
    void setHorizontalAlignment(std::string);
    void checkIsFirstWord(int, bool);
    void checkLength(int);
public:
    BoardPlacement();
    void setPlacement(std::string, std::string, int, bool);
    bool getValidity();
    int getStartRow();
    int getStartColumn();
    bool getHorizontalAlignment();
};


#endif //COMMANDLINESCRABBLE_BOARDPLACEMENT_H
