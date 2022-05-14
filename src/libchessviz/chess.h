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

struct motion {
    int yStart = 0;
    int xStart = 0;
    int yEnd = 0;
    int xEnd = 0;
    char move;
};

struct list_command {
    std::string Cmd;
    list_command *next, *prev;
};
void clearm();
void Errors(int error);
void PrintBoard(char (*board)[N]);
void AddSpisElm(list_command*& tail, std::string line, int L, int R);
void FillBoard(char (*board)[N]);
void GetStep(motion* stp, char (*board)[N]);
int Rules(std::string step, motion*& stp, char (*board)[N]);
void ClearSpis(list_command* head);
void check_txt(std::string file_name, list_command* tail);
