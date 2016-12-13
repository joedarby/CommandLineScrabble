#ifndef COMMANDLINESCRABBLE_LETTERBAG_H
#define COMMANDLINESCRABBLE_LETTERBAG_H

#include <string>

using namespace std;

class letterBag {
private:
    string letters;

public:
    letterBag();
    string getLetters();
    void removeLetter(int);
    int getLettersRemaining();
    void putLettersBack(string);


};


#endif //COMMANDLINESCRABBLE_LETTERBAG_H
