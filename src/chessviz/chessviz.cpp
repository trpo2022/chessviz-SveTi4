
#include <cstring>
#include <fstream>
#include <iostream>
#include <libchessviz/const.h>
#include <libchessviz/structs.h>
#include <libchessviz/AddSpisElm.h>
#include <libchessviz/ReadSpis.h>
#include <libchessviz/check_txt.h>
#include <libchessviz/fill_board.h>
#include <libchessviz/print_board.h>

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
