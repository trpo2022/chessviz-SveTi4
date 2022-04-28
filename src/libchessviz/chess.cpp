#include "chess.h"

void PrintBoard(item (*board)[N], int flag)
{
    int i = 0, j = 0;
    if (flag == 1 || flag == 2)
        for (i = 0; i < N; i++) {
            cout << board[i][0].column << " ";
            for (j = 0; j < N; j++) {
                if (flag == 1)
                    cout << board[i][j].figure.name[0] << " ";
                if (flag == 2)
                    cout << board[i][j].row[0] << board[i][j].column << " ";
            }
            cout << "\n";
        }
    cout << "  ";
    for (i = 0; i < N; i++) {
        if (flag == 1)
            cout << board[0][i].row[0] << " ";
        if (flag == 2)
            cout << board[0][i].row[0] << "  ";
    }
    cout << endl;
}

void AddSpisElm(list_command*& tail, string line, int L, int R)
{
    list_command* p;
    string Step = "";
    for (int i = L; i < R; i++)
        Step += line[i];
    if (Step.size() > 0) {
        p = new list_command;
        p->Cmd = Step;
        p->next = NULL;
        p->prev = tail;
        tail->next = p;
        tail = p;
    }
}

void FillBoard(item (*board)[N])
{
    int i = 0, j;
    char figure[N + 1][N + 1]
            = {"rnbqkbnr",
               "pppppppp",
               "        ",
               "        ",
               "        ",
               "        ",
               "PPPPPPPP",
               "RNBKQBNR"};
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            board[i][j].column = Column[i];
            board[i][j].row[0] = Row[j];
            board[i][j].figure.name[0] = figure[i][j];
        }
    }
}

void ReadSpis(list_command* head)
{
    list_command* p;
    for (p = head->next; p; p = p->next) {
        cout << " |-> " << p->Cmd << endl;
        delete (p);
    }
}

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
