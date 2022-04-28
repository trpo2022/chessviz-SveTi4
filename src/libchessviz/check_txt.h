#pragma once
#include <libchessviz/structs.h>
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
            N1 = line.find("-") * 2 + 1;
            AddSpisElm(tail, line, 0, N1);
            N2 = line.size();
            if (N1 < N2)
                AddSpisElm(tail, line, N1 + 1, N2);
        }
    }
    fin.close(); // закрываем файл
}
