#include <cstring>
#include <fstream>
#include <iostream>
#include <libchessviz/chess.h>
#include <stdio.h>

int main()
{
    motion* stp;
    stp = new motion;
    list_command *head, *tail;
    head = tail = new list_command;
    head->next = head->prev = NULL;
    char board[N][N] = {0};
    FillBoard(board);
    clearm();
    PrintBoard(board);
    check_txt("board.txt", tail);

    string cmd = {0};
    list_command* p;
    for (p = head->next; p; p = p->next) {
        cmd = p->Cmd;
        cout << p->Cmd << "\n" << endl;
        if (Rules(cmd, stp, board) == 0)
            break;
        else if (Rules(cmd, stp, board) == 1) {
            GetStep(stp, board);
            PrintBoard(board);
        }
    }

    ClearSpis(head);
    return 0;
}
