#include "board.h"
#include <iostream>

using namespace std;

board::board() {
    for (int row = 0; row < 15; row++) {
        for (int col = 0; col < 15; col++) {
            squares[row][col] = ' ';
        }
    }
}


void board::displayBoard() {
    string rowLabels = "ABCDEFGHIJKLMNO";

    /*for (int i = 0; i < 250; i++) {
        cout << endl;
    }*/

    cout << "    1   2   3   4   5   6   7   8   9   10  11  12  13  14  15" << endl;
    cout << "  —————————————————————————————————————————————————————————————" << endl;
    for (int row = 0; row < 7; row++) {
        cout << rowLabels[row] << " ";
        for (int col = 0; col < 15; col++) {
            cout << "| " << squares[row][col] << " ";
        }
        cout << "|" << endl;
        cout << "  —————————————————————————————————————————————————————————————" << endl;
    }

    cout << rowLabels[7] << " ";
    for (int col = 0; col < 7; col++) {
        cout << "| " << squares[7][col] << " ";
    }
    if (squares[7][7] == ' ') {
        cout << "| " << '*' << " ";
    } else {
        cout << "| " << squares[7][7] << " ";
    }
    for (int col = 8; col < 15; col++) {
        cout << "| " << squares[7][col] << " ";
    }
    cout << "|" << endl;
    cout << "  —————————————————————————————————————————————————————————————" << endl;
    for (int row = 8; row < 15; row++) {
        cout << rowLabels[row] << " ";
        for (int col = 0; col < 15; col++) {
            cout << "| " << squares[row][col] << " ";
        }
        cout << "|" << endl;
        cout << "  —————————————————————————————————————————————————————————————" << endl;

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