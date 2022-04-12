#include <libchessviz/check_txt.h>

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