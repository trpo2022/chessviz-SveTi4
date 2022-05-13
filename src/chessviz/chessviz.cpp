#include <cstring>
#include <fstream>
#include <iostream>
#include <libchessviz/chess.h>
#include <stdio.h>

int main()
{
    
    list_command *head, *tail;
    head = tail = new list_command;
    head->next = head->prev = NULL;
    char board[N][N] = {0};
    FillBoard(board);
    PrintBoard(board);
    check_txt("board.txt", tail);
    ReadSpis(head);
    return 0;
}
