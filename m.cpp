#include <fstream>
#include <iostream>
#include <string>
using namespace std;

//void FillBoard1(string board1[8][8]) {
//    int n = 8, i, j;
//   board1[n][n];
//    for (int i = n - 1; i >= 0; i--) {
//        for (int j = 0; j < n; j++) {
//            board1[i][j] += bot[j];
//            board1[i][j] += left[i];
//             cout << board1[i][j] << " | ";
//        }
//         cout<< "\n" <<endl;
//    }
//}

// void FillBoard(string board[8][8], char** board1[8][8]) {
//}


// функция ниже выводит шахматную доску
void PrintBoard(char board1[8][9], char bot[9], char left[9]) {
    int n = 8, i, j;
    for (i = 0; i < n; i++) {
	cout << left[i] << " ";
        for (j = 0; j < n; j++) {
            cout << board1[i][j] << " ";
        }
        cout << endl;
    }	
    cout << " ";
    for (i = 0; i < n; i++) {
    	cout << " " << bot[i];
    }
    cout << endl;
}
// функция ниже проходится по файлу для чтения комманд
void check_list(string file_name) {
    ifstream fin("1.txt");
    if (!fin) {
        std::cerr << "Ошибка, невозможно открыть файл : text.txt" << std::endl;
    }
    int i_number_line_now = 0;  //счётчик строк
    string line;                //Хранение строки
    string line_file_text;      //Хранение теста файла
    while (getline(fin, line)) {
        i_number_line_now++;
        line_file_text.insert(line_file_text.size(), line);
        line_file_text.insert(line_file_text.size(), "\r\n");
	
        cout << line << endl;
    }
    fin.close();  // закрываем файл
}

int main() {
    setlocale(LC_ALL, "rus");
    char board1[9][9] = {
        "rnbqkbnr","pppppppp","        ","        ","        ","        ","PPPPPPPP","RNBKQBNR"
    };
    char left[9] = "87654321";
    char bot[9] = "abcdefgh";
    string file = "1.txt";
    int i, j, n = 8;
    check_list(file);
    //PrintBoard(board1, bot, left);
    return 0;
}
