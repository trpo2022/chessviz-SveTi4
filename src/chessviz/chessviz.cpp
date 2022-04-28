#include <cstring>
#include <fstream>
#include <iostream>
#include <libchessviz/chess.h>
#include <stdio.h>

int main()
{
    item board[N][N];
    list_command *head, *tail;
    head = tail = new list_command;
    head->next = head->prev = NULL;

    FillBoard(board);
    PrintBoard(board, 1);
    check_txt("board.txt", tail);
    ReadSpis(head);
    return 0;
}
