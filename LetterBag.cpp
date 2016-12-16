#include <iostream>
#include "LetterBag.h"

//Class to hold all of the Game letters and functions to add/remove letters

using namespace std;

LetterBag::LetterBag() {
    letters = "--EEEEEEEEEEEEAAAAAAAAAIIIIIIIIIOOOOOOOONNNNNNRRRRRRTTTTTTLLLLSSSSUUUUDDDDGGGBBCCMMPPFFHHVVWWYYKJXQZ";
}


int LetterBag::getLettersRemaining() {
    return letters.length();
}

void LetterBag::removeLetter(int index) {
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

void LetterBag::putLettersBack(string returnedLetters) {
    letters = letters + returnedLetters;
}


