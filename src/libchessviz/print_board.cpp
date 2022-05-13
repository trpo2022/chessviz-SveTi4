#include "chess.h"

void PrintBoard(char (*board)[N])
{
    clearm();
    for (int i = 0; i < N; i++)
    {
        cout << Column[i] << "|";
        for (int j = 0; j < N; j++)
        {
            cout << " " << board[i][j];
        }
        cout << endl;
    }
    cout << " +—————————————————\n   a b c d e f g h\n" << endl;
}