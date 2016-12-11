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

    cout << "    1   2   3   4   5   6   7   8   9   10  11  12  13  14  15" << endl;
    cout << "  —————————————————————————————————————————————————————————————" << endl;
    for (int row = 0; row < 15; row++) {
        cout << rowLabels[row] << " ";
        for (int col = 0; col < 15; col++) {
            cout << "| " << squares[row][col] << " ";
        }
        cout << "|" << endl;
        cout << "  —————————————————————————————————————————————————————————————" << endl;
    }


}

string board::getActiveSquares(boardPlacement* placement, int wordLength) {
    string activeSquares = "";
    if ((*placement).getHorizontalAlignment()) {
        int row = (*placement).getStartRow();
        int startCol = (*placement).getStartColumn();
        for (int i = startCol; i < startCol + wordLength; i++) {
            activeSquares += (squares[row][i]);
        }
    } else {
        int col = (*placement).getStartColumn();
        int startRow = (*placement).getStartRow();
        for (int i = startRow; i < startRow + wordLength; i++) {
            activeSquares += (squares[i][col]);
        }
    }
    return activeSquares;
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