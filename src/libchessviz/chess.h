#pragma once

#include <fstream>
#include <iostream>

using namespace std;

// константы
const int N = 8;
const char Row[N + 1] = "abcdefgh";
const int Column[N + 1] = {8, 7, 6, 5, 4, 3, 2, 1};

// структура, хранящая начальное и конечное положение фигуры во время хода и оператор
struct motion {
    int yStart = 0;
    int xStart = 0;
    int yEnd = 0;
    int xEnd = 0;
    char move;
};
// очередь, чодержащая ходы
struct list_command {
    std::string Cmd;
    list_command *next, *prev;
};
//очистка консоли
void clearm();
// вывод ошибок
void Errors(int error);
// вывод доски
void PrintBoard(char (*board)[N]);
// внесение хода в очередь
void AddSpisElm(list_command*& tail, std::string line, int L, int R);
// изначальное заполнение доски
void FillBoard(char (*board)[N]);
// перемещение фигуры
void GetStep(motion* stp, char (*board)[N]);
// правила хода
int Rules(std::string step, motion*& stp, char (*board)[N]);
// очистка памяти (списка после окончания программы)
void ClearSpis(list_command* head);
// считывание txt файла и пополнение списка ходов
void check_txt(std::string file_name, list_command* tail);
