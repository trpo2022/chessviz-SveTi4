#pragma once

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
