#include <iostream>
#include "letterBag.h"

using namespace std;

letterBag::letterBag() {
    letters = "--EEEEEEEEEEEEAAAAAAAAAIIIIIIIIIOOOOOOOONNNNNNRRRRRRTTTTTTLLLLSSSSUUUUDDDDGGGBBCCMMPPFFHHVVWWYYKJXQZ";
}

string letterBag::getLetters() {
    return letters;
}

int letterBag::getLettersRemaining() {
    return letters.length();
}

void letterBag::removeLetter(int index) {
    int previousSize = letters.length() ;
    string remainingLetters = "";
    for (int i = 0; i < index; i++) {
        remainingLetters = remainingLetters + letters[i];
    }
    for (int j = index + 1; j < previousSize; j++) {
        remainingLetters = remainingLetters + letters[j];
    }
    letters = remainingLetters;
}

void letterBag::putLettersBack(string returnedLetters) {
    letters = letters + returnedLetters;
}


