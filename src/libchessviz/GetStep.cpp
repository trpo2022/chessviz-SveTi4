#include "chess.h"

void GetStep(motion* stp, char (*board)[N])
{
    char f = board[stp->yStart][stp->xStart];
    board[stp->yStart][stp->xStart] = ' ';
    board[stp->yEnd][stp->xEnd] = f;
}
