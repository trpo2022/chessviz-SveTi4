#include "chess.h"

void Errors(int error)
{
    switch (error) {
    case 1:
        cout << "An invalid command was entered!" << endl;
        break;
    case 2:
        cout << "going off the board" << endl;
        break;
    case 3:
        cout << "\nError: Unknown step type" << endl;
        break;
    case 4:
        cout << "\nError: Pawns only move straight ahead" << endl;
        break;
    case 5:
        cout << "\nError: You cannot make a silent move to another "
                "piece"
             << endl;
        break;
    case 6:
        cout << "\nError: From the first move, pawns can move "
                "1-2 squares"
             << endl;
        break;
    case 7:
        cout << "\nError: You can't step over" << endl;
        break;
    case 8:
        cout << "\nError: After the first move, pawns can only "
                "move 1 square forward"
             << endl;
        break;
    case 9:
        cout << "\nError: You can't take an empty cage" << endl;
        break;
    case 11:
        cout << "\nError: Wrong body type" << endl;
        break;
    case 12:
        cout << "\nError: Wrong move" << endl;
        break;
    case 13:
        cout << "Error: You cannot step over pieces" << endl;
        break;
    default:
        break;
    }
}
