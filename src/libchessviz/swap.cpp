#include <libchessviz/swap.h>

void swap(
        int posLine1,
        int posColumn1,
        int posLine2,
        int posColumn2,
        char board[N1][N2])
{
    char buf = board[posLine1][posColumn1];
    board[posLine1][posColumn1] = ' ';
    board[posLine2][posColumn2] = buf;
}