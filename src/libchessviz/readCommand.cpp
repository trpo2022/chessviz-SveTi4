#include <libchessviz/readCommand.h>

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