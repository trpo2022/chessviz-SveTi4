#include <iostream>
#include <libchessviz/print_board.h>

using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    char left[N2] = "87654321";
    char bot[N2] = "abcdefgh";
    char board[N1][N2]
            = {"rnbqkbnr",
               "pppppppp",
               "        ",
               "        ",
               "        ",
               "        ",
               "PPPPPPPP",
               "RNBKQBNR"};
    print_board(board, bot, left);
    return 0;
}