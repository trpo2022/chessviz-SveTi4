#include <ctest.h>
#include <iostream>
#include <libchessviz/chess.h>

using namespace std;

char board[N][N]
        = {{'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
           {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
           {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
           {'P', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
           {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
           {' ', ' ', ' ', ' ', 'P', ' ', ' ', ' '},
           {' ', 'P', 'P', 'P', ' ', 'P', 'P', 'P'},
           {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}};

motion* stp;
CTEST(quiet_step_suite, step_size_false)
{
    motion* stp;
    string step = "Nb1-c3B";
    bool result;
    if (Rules(step, stp, board) == 1)
        result = true;
    else
        result = false;

    ASSERT_FALSE(result);
}
