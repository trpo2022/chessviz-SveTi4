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
CTEST(quiet_step_suite, quiet_running_true_p)
{
    stp = new motion;
    string step = "e2-e4";
    bool result;
    if (Rules(step, stp, board) == 1)
        result = true;
    else
        result = false;
    ASSERT_TRUE(result);
}
CTEST(quiet_step_suite, quiet_running_true_p2)
{
    stp = new motion;
    string step = "d2-d3";
    bool result;
    if (Rules(step, stp, board) == 1)
        result = true;
    else
        result = false;
    ASSERT_TRUE(result);
}

CTEST(quiet_step_suite, quiet_running_false_p)
{
    stp = new motion;
    string step = "d2-d5";
    bool result;
    if (Rules(step, stp, board) == 1)
        result = true;
    else
        result = false;
    ASSERT_FALSE(result);
}

CTEST(quiet_step_suite, quiet_running_false_N)
{
    string step = "Nb0-c3";
    bool result;
    if (Rules(step, stp, board) == 1)
        result = true;
    else
        result = false;

    ASSERT_FALSE(result);
}

CTEST(quiet_step_suite, quiet_running_true_N)
{
    string step = "Nb1-c3";
    bool result;
    if (Rules(step, stp, board) == 1)
        result = true;
    else
        result = false;

    ASSERT_TRUE(result);
}

CTEST(quiet_step_suite, quiet_running_false_Q)
{
    string step = "Qd1-c5";
    bool result;
    if (Rules(step, stp, board) == 1)
        result = true;
    else
        result = false;

    ASSERT_FALSE(result);
}

CTEST(quiet_step_suite, quiet_running_true_Q)
{
    string step = "Qd1-e2";
    bool result;
    if (Rules(step, stp, board) == 1)
        result = true;
    else
        result = false;

    ASSERT_TRUE(result);
}

CTEST(quiet_step_suite, quiet_running_false_K)
{
    string step = "Ke1-e4";
    bool result;
    if (Rules(step, stp, board) == 1)
        result = true;
    else
        result = false;

    ASSERT_FALSE(result);
}

CTEST(quiet_step_suite, quiet_running_true_K)
{
    string step = "Ke1-e2";
    bool result;
    if (Rules(step, stp, board) == 1)
        result = true;
    else
        result = false;

    ASSERT_TRUE(result);
}

CTEST(quiet_step_suite, quiet_running_false_R)
{
    string step = "Ra1-b4";
    bool result;
    if (Rules(step, stp, board) == 1)
        result = true;
    else
        result = false;

    ASSERT_FALSE(result);
}

CTEST(quiet_step_suite, quiet_running_true_R)
{
    string step = "Ra1-a3";
    bool result;
    if (Rules(step, stp, board) == 1)
        result = true;
    else
        result = false;

    ASSERT_TRUE(result);
}

CTEST(quiet_step_suite, quiet_running_false_B)
{
    string step = "Bf1-f4";
    bool result;
    if (Rules(step, stp, board) == 1)
        result = true;
    else
        result = false;

    ASSERT_FALSE(result);
}

CTEST(quiet_step_suite, quiet_running_true_B)
{
    string step = "Bf1-e2";
    bool result;
    if (Rules(step, stp, board) == 1)
        result = true;
    else
        result = false;

    ASSERT_TRUE(result);
}

CTEST(quiet_step_suite, quiet_running_false)
{
    string step = "e2/e4";
    bool result;
    if (Rules(step, stp, board) == 1)
        result = true;
    else
        result = false;

    ASSERT_FALSE(result);
}

CTEST(quiet_step_suite, quiet_running_false2)
{
    string step = "Be1'e4";
    bool result;
    if (Rules(step, stp, board) == 1)
        result = true;
    else
        result = false;

    ASSERT_FALSE(result);
}

CTEST(quiet_step_suite, small_type)
{
    string step = "nb1-c3";
    bool result;
    if (Rules(step, stp, board) == 1)
        result = true;
    else
        result = false;

    ASSERT_FALSE(result);
}

CTEST(take_step_suite, take_empty)
{
    string step = "e2xe4";
    bool result;
    if (Rules(step, stp, board) == 1)
        result = true;
    else
        result = false;

    ASSERT_FALSE(result);
}

CTEST(take_step_suite, friendly_fire)
{
    char board[N][N]
            = {{'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
               {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
               {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {' ', ' ', ' ', ' ', ' ', 'P', ' ', ' '},
               {'P', 'P', 'P', 'P', 'P', ' ', 'P', 'P'},
               {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}};
    string step = "e2xf3";
    bool result;
    if (Rules(step, stp, board) == 1)
        result = true;
    else
        result = false;

    ASSERT_FALSE(result);
}
