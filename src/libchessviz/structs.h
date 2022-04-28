#pragma once

struct f {
    int color;
    char name[1];
};
struct item {
    char row[1];
    int column;
    f figure;
};
struct list_command {
    string Cmd;
    list_command *next, *prev;
};
