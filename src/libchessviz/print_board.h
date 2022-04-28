#pragma once

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
