#include <iostream>
#include <libchessviz/print_board.h>
using namespace std;

void print_board(char board[N1][N2], char bot[N2], char left[N2])
{
    int n = 8, i, j;
    for (i = 0; i < n; i++) {
        cout << left[i] << " ";
        for (j = 0; j < n; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << " ";
    for (i = 0; i < n; i++) {
        cout << " " << bot[i];
    }
    cout << endl;
}