#include <fstream>
#include <iostream>
#include <libchessviz/print_board.h>
#include <string>
using namespace std;
// Функция узнаёт местоположение шахматной клетки в массиве до и после движения
// фигуры
void swap(
        int posLine1,
        int posColumn1,
        int posLine2,
        int posColumn2,
        char board[N1][N2])
{
    char buf = board[posLine1][posColumn1];
    board[posLine1][posColumn1] = ' ';
    board[posLine2][posColumn2] = buf;
}
void step(
        char* step,
        int& board_line_pos1,
        int& board_column_pos1,
        int& board_line_pos2,
        int& board_column_pos2)
{
    string left = "87654321";
    string bot = "abcdefgh";
    char line1 = step[1];
    char column1 = step[0];
    board_line_pos1 = left.find(line1);
    board_column_pos1 = bot.find(column1);
    char line2 = step[3];
    char column2 = step[2];
    board_line_pos2 = left.find(line2);
    board_column_pos2 = bot.find(column2);
}
// Функйция читает комманду из строки и разбивает на части,
// после чего передаёт в функцию step для получения местоположений
// клеток в массиве и переставляет фигуру
void readCommand(string line, char board[N1][N2])
{
    int posLine1, posColumn1, posLine2, posColumn2;
    int t = line.find("-");
    int s = line.find(" ");
    // команда e2-e4 e7-e5 состоит из двух шагом, поэтому делю её,
    // избавляясь от лишнего
    char step1[s - 1], step2[s - 1];
    for (int i = 0; i < t; i++)
        step1[i] = line[i];
    for (int i = t + 1, j = t; i < s; i++, j++)
        step1[j] = line[i];
    int t2 = line.find("-", s + 1);
    for (int i = s + 1, j = 0; i < t2; i++, j++)
        step2[j] = line[i];
    int s2 = line.length();
    for (int i = t2 + 1, j = t; i < s2; i++, j++)
        step2[j] = line[i];
    // получение местоположений в исходном массиве board и передмещение фигуры
    step(step1, posLine1, posColumn1, posLine2, posColumn2);
    swap(posLine1, posColumn1, posLine2, posColumn2, board);
    step(step2, posLine1, posColumn1, posLine2, posColumn2);
    swap(posLine1, posColumn1, posLine2, posColumn2, board);
}
// Функция перебирает строки с командами в .txt файле
void check_txt(string file_name, char board[N1][N2])
{
    ifstream fin(file_name);
    if (!fin) {
        cerr << "Ошибка, невозможно открыть файл : " << file_name << endl;
    }
    int i_number_line_now = 0; //счётчик строк
    string line;               //Хранение строки
    string line_file_text;     //Хранение теста файла
    while (getline(fin, line)) {
        i_number_line_now++;
        line_file_text.insert(line_file_text.size(), line);
        line_file_text.insert(line_file_text.size(), "\r\n");
        cout << i_number_line_now << " " << line << endl;
        readCommand(line, board);
    }
    fin.close(); // закрываем файл
}

int main()
{
    char board[N1][N2]
            = {"rnbqkbnr",
               "pppppppp",
               "        ",
               "        ",
               "        ",
               "        ",
               "PPPPPPPP",
               "RNBKQBNR"};
    string file = "board.txt";
    setlocale(LC_ALL, "rus");

    print_board(board); // Вывод доски
    cout << "\n";
    check_txt(file, board); // Обработка файла
    cout << "\n";
    print_board(board); // Вывод доски
    return 0;
}
