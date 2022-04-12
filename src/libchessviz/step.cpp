#include <libchessviz/step.h>


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