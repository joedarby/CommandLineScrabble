#include "board.h"
#include <iostream>
#include <string>

using namespace std;

board::board() {
    for (int row = 0; row < 15; row++) {
        for (int col = 0; col < 15; col++) {
            squares[row][col] = ' ';
        }
    }
}


void board::displayBoard(ostream* file) {
    string rowLabels = "ABCDEFGHIJKLMNO";


    *file << "    1   2   3   4   5   6   7   8   9   10  11  12  13  14  15" << endl;
    *file << "  —————————————————————————————————————————————————————————————" << endl;
    for (int row = 0; row < 7; row++) {
        *file << rowLabels[row] << " ";
        for (int col = 0; col < 15; col++) {
            *file << "| " << squares[row][col] << " ";
        }
        *file << "|" << endl;
        *file << "  —————————————————————————————————————————————————————————————" << endl;
    }

        *file << rowLabels[7] << " ";
    for (int col = 0; col < 7; col++) {
        *file << "| " << squares[7][col] << " ";
    }
    if (squares[7][7] == ' ') {
        *file << "| " << '*' << " ";
    } else {
        *file << "| " << squares[7][7] << " ";
    }
    for (int col = 8; col < 15; col++) {
        *file << "| " << squares[7][col] << " ";
    }
        *file << "|" << endl;
        *file << "  —————————————————————————————————————————————————————————————" << endl;
    for (int row = 8; row < 15; row++) {
        *file << rowLabels[row] << " ";
        for (int col = 0; col < 15; col++) {
            *file << "| " << squares[row][col] << " ";
        }
        *file << "|" << endl;
        *file << "  —————————————————————————————————————————————————————————————" << endl;

    }
}


string board::getAlreadyPlaced(boardPlacement *placement, int wordLength) {
    string alreadyPlaced = "";
    if ((*placement).getHorizontalAlignment()) {
        int row = (*placement).getStartRow();
        int startCol = (*placement).getStartColumn();
        for (int i = startCol; i < startCol + wordLength; i++) {
            alreadyPlaced += (squares[row][i]);
        }
    } else {
        int col = (*placement).getStartColumn();
        int startRow = (*placement).getStartRow();
        for (int i = startRow; i < startRow + wordLength; i++) {
            alreadyPlaced += (squares[i][col]);
        }
    }
    return alreadyPlaced;
}

void board::placeWord(string word, boardPlacement* placement) {
    int j = 0;
    if ((*placement).getHorizontalAlignment()) {
        int row = (*placement).getStartRow();
        int startCol = (*placement).getStartColumn();
        for (int i = startCol; i < startCol + word.length(); i++) {
            squares[row][i] = word[j];
            j++;
        }
    } else {
        int col = (*placement).getStartColumn();
        int startRow = (*placement).getStartRow();
        for (int i = startRow; i < startRow + word.length(); i++) {
            squares[i][col] = word[j];
            j++;
        }
    }
}