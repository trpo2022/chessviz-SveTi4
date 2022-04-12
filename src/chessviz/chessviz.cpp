#include <libchessviz/const.h>
#include <libchessviz/check_txt.h>
#include <libchessviz/print_board.h>

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
