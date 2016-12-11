#ifndef COMMANDLINESCRABBLE_BOARDPLACEMENT_H
#define COMMANDLINESCRABBLE_BOARDPLACEMENT_H

#include <string>

class boardPlacement {
private:
    int startRow;
    int startColumn;
    bool horizontalAlignment;
    bool validity;
public:
    boardPlacement();
    void setPlacement(std::string, std::string);
    bool getValidity();
    int getStartRow();
    int getStartColumn();
    bool getHorizontalAlignment();
};


#endif //COMMANDLINESCRABBLE_BOARDPLACEMENT_H
