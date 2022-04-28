#pragma once

#include <fstream>
#include <iostream>

using namespace std;

const int N = 8;
const char Row[N + 1] = "abcdefgh";
const int Column[N + 1] = {8, 7, 6, 5, 4, 3, 2, 1};

struct f {
    int color;
    char name[1];
};

struct item {
    char row[1];
    int column;
    f figure;
};

struct list_command {
    std::string Cmd;
    list_command *next, *prev;
};

void PrintBoard(item (*board)[N], int flag);
void AddSpisElm(list_command*& tail, std::string line, int L, int R);
void FillBoard(item (*board)[N]);
void ReadSpis(list_command* head);
void check_txt(std::string file_name, list_command* tail);
