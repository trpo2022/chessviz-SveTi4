#include "chess.h"

void check_txt(string file_name, list_command* tail)
{
    ifstream fin(file_name);
    int N1, N2;

    if (!fin) {
        cerr << "Error, the file cannot be opened : " << file_name << endl;
    }
    string line; //Хранение строки
    while (getline(fin, line)) {
        if (line.size()) { // Заношу команды в список
            N1 = 0;
            N2 = line.find(' ');
            if (N2 == 5)
                AddSpisElm(tail, line, N1, N2);
            else if (N2 == 6)
                AddSpisElm(tail, line, N1, N2);
            N2 = line.size();
            if (N2 == 5)
                AddSpisElm(tail, line, N1, N2);
            else if (N2 == 6)
                AddSpisElm(tail, line, N1, N2);
            else if (N2 == 7 && line[6] == '#')
                AddSpisElm(tail, line, N1, N2);
            else if (N2 > 6) {
                N1 = line.find(' ') + 1;
                AddSpisElm(tail, line, N1, N2);
            }
        }
    }
    fin.close(); // закрываем файл
}
