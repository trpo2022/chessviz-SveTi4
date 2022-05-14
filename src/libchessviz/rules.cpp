#include "chess.h"

int king(char chess_board[N][N], motion motion, int error_output)
{
    if (!((chess_board[motion.yStart][motion.xStart] == 'K')
          || (chess_board[motion.yStart][motion.xStart] == 'k'))) {
        if (error_output == 1)
            Errors(11);
        return 0;
    }
    if ((abs(motion.yEnd - motion.yStart) > 1)
        || (abs(motion.xEnd - motion.xStart) > 1)
        || ((motion.xEnd - motion.xStart == 0)
            && (motion.yEnd - motion.yStart == 0))) {
        if (error_output == 1)
            Errors(12);
        return 0;
    }
    return 1;
}

int queen(char chess_board[N][N], motion motion, int error_output)
{
    if (!((chess_board[motion.yStart][motion.xStart] == 'Q')
          || (chess_board[motion.yStart][motion.xStart] == 'q'))) {
        if (error_output == 1)
            Errors(11);
        return 0;
    }
    if (!((abs(motion.xStart - motion.xEnd) == abs(motion.yStart - motion.yEnd))
          || ((motion.yEnd - motion.yStart == 0)
              && (abs(motion.xStart - motion.xEnd) > 0))
          || ((motion.xEnd - motion.xStart == 0)
              && (abs(motion.yStart - motion.yEnd) > 0)))) {
        if (error_output == 1)
            Errors(12);
        return 0;
    }
    if ((motion.yEnd - motion.yStart == 0)
        && (abs(motion.xStart - motion.xEnd) > 0)) {
        if (motion.xEnd > motion.xStart) {
            motion.xStart++;
            while (motion.xEnd > motion.xStart) {
                if (chess_board[motion.yStart][motion.xStart] != ' ') {
                    if (error_output == 1)
                        Errors(13);
                    return 0;
                }
                motion.xStart++;
            }
        }
        if (motion.xStart > motion.xEnd) {
            motion.xEnd++;
            while (motion.xStart > motion.xEnd) {
                if (chess_board[motion.yEnd][motion.xEnd] != ' ') {
                    if (error_output == 1)
                        Errors(13);
                    ;
                    return 0;
                }
                motion.xEnd++;
            }
        }
    }
    if ((motion.xEnd - motion.xStart == 0)
        && (abs(motion.yStart - motion.yEnd) > 0)) {
        if (motion.yEnd > motion.yStart) {
            motion.yStart++;
            while (motion.yEnd > motion.yStart) {
                if (chess_board[motion.yStart][motion.xStart] != ' ') {
                    if (error_output == 1)
                        Errors(13);
                    return 0;
                }
                motion.yStart++;
            }
        }
        if (motion.yStart > motion.yEnd) {
            motion.yEnd++;
            while (motion.yStart > motion.yEnd) {
                if (chess_board[motion.yEnd][motion.xEnd] != ' ') {
                    if (error_output == 1)
                        Errors(13);
                    return 0;
                }
                motion.yEnd++;
            }
        }
    }
    if (abs(motion.xStart - motion.xEnd) == abs(motion.yStart - motion.yEnd)) {
        if ((motion.xStart > motion.xEnd) && (motion.yStart > motion.yEnd)) {
            motion.xEnd++;
            motion.yEnd++;
            while ((motion.xStart > motion.xEnd)
                   && (motion.yStart > motion.yEnd)) {
                if (chess_board[motion.yEnd][motion.xEnd] != ' ') {
                    if (error_output == 1)
                        Errors(13);
                    return 0;
                }
                motion.xEnd++;
                motion.yEnd++;
            }
        }
        if ((motion.xStart > motion.xEnd) && (motion.yStart < motion.yEnd)) {
            motion.xEnd++;
            motion.yEnd--;
            while ((motion.xStart > motion.xEnd)
                   && (motion.yStart < motion.yEnd)) {
                if (chess_board[motion.yEnd][motion.xEnd] != ' ') {
                    if (error_output == 1)
                        Errors(13);
                    return 0;
                }
                motion.xEnd++;
                motion.yEnd--;
            }
        }
        if ((motion.xStart < motion.xEnd) && (motion.yStart > motion.yEnd)) {
            motion.xEnd--;
            motion.yEnd++;
            while ((motion.xStart < motion.xEnd)
                   && (motion.yStart > motion.yEnd)) {
                if (chess_board[motion.yEnd][motion.xEnd] != ' ') {
                    if (error_output == 1)
                        Errors(13);
                    return 0;
                }
                motion.xEnd--;
                motion.yEnd++;
            }
        }
        if ((motion.xStart < motion.xEnd) && (motion.yStart < motion.yEnd)) {
            motion.xStart++;
            motion.yStart++;
            while ((motion.xStart < motion.xEnd)
                   && (motion.yStart < motion.yEnd)) {
                if (chess_board[motion.yStart][motion.xStart] != ' ') {
                    if (error_output == 1)
                        Errors(13);
                    return 0;
                }
                motion.xStart++;
                motion.yStart++;
            }
        }
    }
    return 1;
}

int rook(char chess_board[N][N], motion motion, int error_output)
{
    if (!((chess_board[motion.yStart][motion.xStart] == 'R')
          || (chess_board[motion.yStart][motion.xStart] == 'r'))) {
        if (error_output == 1)
            Errors(11);
        return 0;
    }
    if (!(((motion.yEnd - motion.yStart == 0)
           && (abs(motion.xStart - motion.xEnd) > 0))
          || ((motion.xEnd - motion.xStart == 0)
              && (abs(motion.yStart - motion.yEnd) > 0)))) {
        if (error_output == 1)
            Errors(12);
        return 0;
    }
    if ((motion.yEnd - motion.yStart == 0)
        && (abs(motion.xStart - motion.xEnd) > 0)) {
        if (motion.xEnd > motion.xStart) {
            motion.xStart++;
            while (motion.xEnd > motion.xStart) {
                if (chess_board[motion.yStart][motion.xStart] != ' ') {
                    if (error_output == 1)
                        Errors(13);
                    return 0;
                }
                motion.xStart++;
            }
        }
        if (motion.xStart > motion.xEnd) {
            motion.xEnd++;
            while (motion.xStart > motion.xEnd) {
                if (chess_board[motion.yEnd][motion.xEnd] != ' ') {
                    if (error_output == 1)
                        Errors(13);
                    return 0;
                }
                motion.xEnd++;
            }
        }
    }
    if ((motion.xEnd - motion.xStart == 0)
        && (abs(motion.yStart - motion.yEnd) > 0)) {
        if (motion.yEnd > motion.yStart) {
            motion.yStart++;
            while (motion.yEnd > motion.yStart) {
                if (chess_board[motion.yStart][motion.xStart] != ' ') {
                    if (error_output == 1)
                        Errors(13);
                    return 0;
                }
                motion.yStart++;
            }
        }
        if (motion.yStart > motion.yEnd) {
            motion.yEnd++;
            while (motion.yStart > motion.yEnd) {
                if (chess_board[motion.yEnd][motion.xEnd] != ' ') {
                    if (error_output == 1)
                        Errors(13);
                    return 0;
                }
                motion.yEnd++;
            }
        }
    }
    return 1;
}

int knight(char chess_board[N][N], motion motion, int error_output)
{
    if (!((chess_board[motion.yStart][motion.xStart] == 'N')
          || (chess_board[motion.yStart][motion.xStart] == 'n'))) {
        if (error_output == 1)
            Errors(11);
        return 0;
    }
    if (!(((abs(motion.yEnd - motion.yStart) == 2)
           && (abs(motion.xStart - motion.xEnd) == 1))
          || ((abs(motion.xEnd - motion.xStart) == 2)
              && (abs(motion.yStart - motion.yEnd) == 1)))) {
        if (error_output == 1)
            Errors(12);
        return 0;
    }
    return 1;
}

int bishop(char chess_board[N][N], motion motion, int error_output)
{
    if (!((chess_board[motion.yStart][motion.xStart] == 'B')
          || (chess_board[motion.yStart][motion.xStart] == 'b'))) {
        if (error_output == 1)
            Errors(11);
        return 0;
    }
    if (!(abs(motion.xStart - motion.xEnd)
          == abs(motion.yStart - motion.yEnd))) {
        if (error_output == 1)
            Errors(12);
        return 0;
    }
    if (abs(motion.xStart - motion.xEnd) == abs(motion.yStart - motion.yEnd)) {
        if ((motion.xStart > motion.xEnd) && (motion.yStart > motion.yEnd)) {
            motion.xEnd++;
            motion.yEnd++;
            while ((motion.xStart > motion.xEnd)
                   && (motion.yStart > motion.yEnd)) {
                if (chess_board[motion.yEnd][motion.xEnd] != ' ') {
                    if (error_output == 1)
                        Errors(13);
                    return 0;
                }
                motion.xEnd++;
                motion.yEnd++;
            }
        }
        if ((motion.xStart > motion.xEnd) && (motion.yStart < motion.yEnd)) {
            motion.xEnd++;
            motion.yEnd--;
            while ((motion.xStart > motion.xEnd)
                   && (motion.yStart < motion.yEnd)) {
                if (chess_board[motion.yEnd][motion.xEnd] != ' ') {
                    if (error_output == 1)
                        Errors(13);
                    return 0;
                }
                motion.xEnd++;
                motion.yEnd--;
            }
        }
        if ((motion.xStart < motion.xEnd) && (motion.yStart > motion.yEnd)) {
            motion.xEnd--;
            motion.yEnd++;
            while ((motion.xStart < motion.xEnd)
                   && (motion.yStart > motion.yEnd)) {
                if (chess_board[motion.yEnd][motion.xEnd] != ' ') {
                    if (error_output == 1)
                        Errors(13);
                    return 0;
                }
                motion.xEnd--;
                motion.yEnd++;
            }
        }
        if ((motion.xStart < motion.xEnd) && (motion.yStart < motion.yEnd)) {
            motion.xStart++;
            motion.yStart++;
            while ((motion.xStart < motion.xEnd)
                   && (motion.yStart < motion.yEnd)) {
                if (chess_board[motion.yStart][motion.xStart] != ' ') {
                    if (error_output == 1)
                        Errors(13);
                    return 0;
                }
                motion.xStart++;
                motion.yStart++;
            }
        }
    }
    return 1;
}

int pawn(char chess_board[N][N], motion motion, int error_output)
{
    if (!((motion.move == '-') || (motion.move == 'x'))) {
        if (error_output == 1)
            Errors(3);
        return 0;
    }
    if (motion.move == '-') {
        if (motion.xStart != motion.xEnd) {
            if (error_output == 1)
                Errors(4);
            return 0;
        }
        if (chess_board[motion.yEnd][motion.xEnd] != ' ') {
            if (error_output == 1)
                Errors(5);
            return 0;
        }
        if (chess_board[motion.yStart][motion.xStart] == 'P') {
            if (motion.yStart == 6) {
                if ((motion.yStart - motion.yEnd > 2)
                    || (motion.yStart - motion.yEnd < 1)) {
                    if (error_output == 1)
                        Errors(6);
                    return 0;
                }
                if ((motion.yStart - motion.yEnd == 2)
                    && (chess_board[(motion.yStart + motion.yEnd) / 2]
                                   [motion.xStart]
                        != ' ')) {
                    if (error_output == 1)
                        Errors(7);
                    return 0;
                }
            } else {
                if (motion.yStart - motion.yEnd != 1) {
                    if (error_output == 1)
                        Errors(8);
                    return 0;
                }
            }
        }
        if (chess_board[motion.yStart][motion.xStart] == 'p') {
            if (motion.yStart == 1) {
                if ((motion.yEnd - motion.yStart > 2)
                    || (motion.yEnd - motion.yStart < 1)) {
                    if (error_output == 1)
                        Errors(6);
                    return 0;
                }
                if ((motion.yEnd - motion.yStart == 2)
                    && (chess_board[(motion.yStart + motion.yEnd) / 2]
                                   [motion.xStart]
                        != ' ')) {
                    if (error_output == 1)
                        Errors(7);
                    return 0;
                }

            } else {
                if (motion.yEnd - motion.yStart != 1) {
                    if (error_output == 1)
                        cout << "\nError: After the first move, pawns can "
                                "only move 1 square forward"
                             << endl;
                    return 0;
                }
            }
        }
    }
    if (motion.move == 'x') {
        if (chess_board[motion.yEnd][motion.xEnd] == ' ') {
            if (error_output == 1)
                Errors(9);
            return 0;
        }
        if (abs(motion.xStart - motion.xEnd) != 1) {
            if (error_output == 1)
                Errors(10);
            return 0;
        }
        if (abs(motion.yStart - motion.yEnd) != 1) {
            if (error_output == 1)
                Errors(10);
            return 0;
        }
        if ((chess_board[motion.yStart][motion.xStart] == 'P')
            && (motion.yStart - motion.yEnd != 1)) {
            if (error_output == 1)
                Errors(10);
            return 0;
        }
        if ((chess_board[motion.yStart][motion.xStart] == 'p')
            && (motion.yEnd - motion.yStart != 1)) {
            if (error_output == 1)
                Errors(10);
            return 0;
        }
    }
    return 1;
}

int Rules(std::string step, motion*& motion, char (*board)[N])
{
    int err = 1;
    char c = step[0];
    if (step.length() == 6
        || (step.length() == 7 && (step[6] == ' ' || step[6] == '#'))) {
        motion->move = step[3];
        motion->yStart = 8 - ((int)step[2] - '0');
        motion->xStart = (int)step[1] - 'a';
        motion->yEnd = 8 - ((int)step[5] - '0');
        motion->xEnd = (int)step[4] - 'a';
        if (!(motion->xEnd < 0 || motion->xEnd > 7 || motion->yEnd < 0
              || motion->yEnd > 7 || motion->xStart < 0 || motion->xStart > 7
              || motion->yStart < 0 || motion->yStart > 7)) {
            switch (c) {
            case 'K':
                return king(board, *motion, err);
                break;
            case 'Q':
                return queen(board, *motion, err);
                break;
            case 'R':
                return rook(board, *motion, err);
                break;
            case 'N':
                return knight(board, *motion, err);
                break;
            case 'B':
                return bishop(board, *motion, err);
                break;
            default:
                Errors(1);
                break;
            }
        } else
            Errors(2);
    } else if (step.length() < 6) {
        motion->move = step[2];
        motion->yStart = 8 - ((int)step[1] - '0');
        motion->xStart = (int)step[0] - 'a';
        motion->yEnd = 8 - ((int)step[4] - '0');
        motion->xEnd = (int)step[3] - 'a';

        if (!(motion->xEnd < 0 || motion->xEnd > 7 || motion->yEnd < 0
              || motion->yEnd > 7 || motion->xStart < 0 || motion->xStart > 7
              || motion->yStart < 0 || motion->yStart > 7)) {
            return pawn(board, *motion, err);
        } else
            Errors(2);
    } else {
        cout << step.length() << endl;
        Errors(1);
    }
    return 0;
}
