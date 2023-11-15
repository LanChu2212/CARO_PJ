#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <stdbool.h>
#include <vector>
#include <Windows.h>
#include <mmsystem.h>
#include <iostream>
#include <string.h>
#include "_Common.h"
#include "_Play.h"
#include "PlayervsPlayer.h"
using namespace std; 
// Hàm nhóm view
void FixConsoleWindow() {
    HWND consoleWindow = GetConsoleWindow();
    LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
    style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
    SetWindowLong(consoleWindow, GWL_STYLE, style);
}
void GotoXY(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
/*
Giải thích hàm GotoXY
Ta sử dụng cấu trúc dữ liệu COORD - một kiểu dữ liệu trong lập trình Windows được sử dụng để
đại diện cho một cặp tọa độ hai chiều,bao gồm tọa độ X (ngang) và tọa độ Y (dọc).
Ta gán hoành và tung độ cho biến coord rồi thiết lập vị trí lên màn hình bằng hàm SetConsoleCursorPosition
Khi đó, nếu ta gọi hàm GotoXY với các tham số x và y, nó sẽ di chuyển con trỏ đến vị trí được chỉ định bởi x và y trên
cửa sổ console.

*/

// Hằng số
#define BOARD_SIZE 12
#define LEFT 3
#define TOP 1
/*
Ý nghĩa của các hằng số trên:
BOARD_SIZE: bàn cờ sẽ có kích thước 12x12
LEFT 3: là khoảng cách từ lề trái màn hình console bàn cờ
TOP 1: Bàn cờ được đặt từ dòng thứ 1 tính từ trên của màn hình console
*/
// Khai báo kiểu dữ liệu
struct _POINT { int x, y, c; };// _POINT là một cấu trúc dữ liệu tự định nghĩa, trong đó: x: hoành độ, y: tung độ, c: cho biết ô đó đã đc đánh dấu chưa
// c=-1: X, c=0: trống, c=1: O
struct _POINT _A[BOARD_SIZE][BOARD_SIZE];// Ma trận bàn cờ, đoạn này nhớ thêm 'struct' vào, ô thầy chắc cố tình làm sai :V
bool _TURN; // Dùng để theo dõi lượt đánh của người chơi, true cho người chơi 1 và false cho người chơi 2
int _COMMAND;// Lưu trữ lựa chọn của người chơi từ bàn phím
int _X, _Y;// Biến _X và _Y đại diện cho tọa độ hiện tại trên bàn cờ mà người chơi đánh.
// Hàm khởi tạo dữ liệu mặc định ban đầu cho ma trận bàn cờ
void ResetData() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            _A[i][j].x = 4 * j + LEFT + 2;
            _A[i][j].y = 2 * i + TOP + 1;
            _A[i][j].c = 0;
        }
    }
    _TURN = true;
    _COMMAND = -1;
    _X = _A[0][0].x;
    _Y = _A[0][0].y;
}
/*Giải thích hàm ResetData()
- Hàm này dùng để đặt lại trạng thái ban đầu của bàn cờ khi qua ván mới
- Hàm sử dụng 2 vòng lặp lồng nhau để duyệt hết các ô trong bàn cờ
_A[i][j].x = 4 * j + LEFT + 2;
j: Biến j là chỉ số của cột trong ma trận _A, nó xác định vị trí cột của ô caro hiện tại trên bàn cờ.

4 * j: Phần này nhân j với 4 để tạo ra một khoảng cách ngang giữa các cột caro. Mỗi cột sẽ cách nhau 4 ký tự.

LEFT: Đây là hằng số đã được định nghĩa trước đó, nó xác định khoảng cách từ lề trái của màn hình console đến bàn cờ. Khi bạn thêm giá trị của LEFT vào biểu thức, bạn đang xác định vị trí bắt đầu của bàn cờ trên trục x.

2: Số 2 được cộng vào để điều chỉnh vị trí của ô caro. Việc này giúp căn giữa ô caro trên cột của nó và tạo ra một khoảng trống giữa các cột.
Tương tự với _A[i][j].y = 2 * i + TOP + 1
- Sau khi tính toán vị trí x và y của mỗi ô caro, hàm gán giá trị 0 cho thành phần c của ô _A[i][j].
Thành phần c này được sử dụng để lưu trạng thái của ô caro, trong trường hợp này, 0 đại diện cho ô caro chưa được đánh dấu bởi bất kỳ người chơi nào.
- Cuối cùng, hàm ResetData() đặt giá trị _TURN bằng true để bắt đầu lượt đi của người chơi đầu tiên, đặt _COMMAND bằng -1 để xác định rằng không có lựa chọn từ bàn phím ban đầu, và đặt _X và _Y bằng vị trí của ô caro đầu tiên _A[0][0].

*/

// Hàm nhóm view
void DrawBoard(int pSize) {
    for (int i = 0; i <= pSize; i++) {
        for (int j = 0; j <= pSize; j++) {
            GotoXY(LEFT + 4 * i, TOP + 2 * j);
            printf(".");
        }
    }
}
/* Giải thích hàm DrawBoard
Ta thấy hàm này có tham số truyền vào là pSize(Thực chất là BoardSize đó :V)
 Nó sẽ vẽ bàn cờ bằng những dấu chấm. Ta thấy nó gọi hàm GotoXY, nghĩa là nó sẽ di chuyển đến những vị trí đã được chỉ định
 trong tham số truyền vào để vẽ dấu chấm.


*/

// Hàm nhóm Control
void StartGame() {
    system("cls");
    ResetData();
    DrawBoard(BOARD_SIZE);
}
/*Giải thích hàm StartGame
- system("cls"): Dòng lệnh này được sử dụng để xóa màn hình console, làm cho màn hình trống trải trước khi bắt đầu một trò chơi mới.
Điều này giúp xóa đi mọi nội dung trước đó trên màn hình.
- Ta gọi lại hàm ResetData rồi ta vẽ bàn cờ.

*/

void GabageCollect() {
    // Dọn dẹp tài nguyên nếu có khai báo con trỏ
}

void ExitGame() {
    system("cls");
    GabageCollect();
}




//Hàm nhóm Model
int TestBoard() {
    int rowCount, colCount;

    // Kiểm tra hàng ngang và hàng dọc
    for (rowCount = 0; rowCount < BOARD_SIZE; rowCount++) {
        for (colCount = 0; colCount < BOARD_SIZE; colCount++) {
            // Kiểm tra hàng ngang
            if (colCount <= BOARD_SIZE - 5) {
                if (_A[rowCount][colCount].c != 0 &&
                    _A[rowCount][colCount].c == _A[rowCount][colCount + 1].c &&
                    _A[rowCount][colCount].c == _A[rowCount][colCount + 2].c &&
                    _A[rowCount][colCount].c == _A[rowCount][colCount + 3].c &&
                    _A[rowCount][colCount].c == _A[rowCount][colCount + 4].c) {
                    playSound(4);
                    return (_A[rowCount][colCount].c == 1) ? -1 : 1; // Người chơi 1 thắng hoặc người chơi 2 thắng
                }
            }

            // Kiểm tra hàng dọc
            if (rowCount <= BOARD_SIZE - 5) {
                if (_A[rowCount][colCount].c != 0 &&
                    _A[rowCount][colCount].c == _A[rowCount + 1][colCount].c &&
                    _A[rowCount][colCount].c == _A[rowCount + 2][colCount].c &&
                    _A[rowCount][colCount].c == _A[rowCount + 3][colCount].c &&
                    _A[rowCount][colCount].c == _A[rowCount + 4][colCount].c) {
                    playSound(4);
                    return (_A[rowCount][colCount].c == 1) ? -1 : 1; // Người chơi 1 thắng hoặc người chơi 2 thắng
                }
            }
        }
    }// Tương tự kiểm tra hàng ngang

    // Kiểm tra hàng chéo chính
    for (rowCount = 0; rowCount < BOARD_SIZE - 4; rowCount++) {
        for (colCount = 0; colCount < BOARD_SIZE - 4; colCount++) {
            if (_A[rowCount][colCount].c != 0 &&
                _A[rowCount][colCount].c == _A[rowCount + 1][colCount + 1].c &&
                _A[rowCount][colCount].c == _A[rowCount + 2][colCount + 2].c &&
                _A[rowCount][colCount].c == _A[rowCount + 3][colCount + 3].c &&
                _A[rowCount][colCount].c == _A[rowCount + 4][colCount + 4].c) {
                playSound(4);
                return (_A[rowCount][colCount].c == 1) ? -1 : 1; // Người chơi 1 thắng hoặc người chơi 2 thắng
            }
        }
    }

    // Kiểm tra hàng chéo phụ
    for (rowCount = 0; rowCount < BOARD_SIZE - 4; rowCount++) {
        for (colCount = 4; colCount < BOARD_SIZE; colCount++) {
            if (_A[rowCount][colCount].c != 0 &&
                _A[rowCount][colCount].c == _A[rowCount + 1][colCount - 1].c &&
                _A[rowCount][colCount].c == _A[rowCount + 2][colCount - 2].c &&
                _A[rowCount][colCount].c == _A[rowCount + 3][colCount - 3].c &&
                _A[rowCount][colCount].c == _A[rowCount + 4][colCount - 4].c) {
                playSound(4);
                return (_A[rowCount][colCount].c == 1) ? -1 : 1; // Người chơi 1 thắng hoặc người chơi 2 thắng
            }
        }
    }
    // 4 vòng for trên duyệt qua từng ô ngang, dọc, chéo xem có 5 ô liên tiếp X hoặc O hay không, trả về -1 nếu người chơi X thắng và 1 nếu người chơi O thắng
    // Kiểm tra nếu bàn cờ đã đầy
    for (int rowCount = 0; rowCount < BOARD_SIZE; rowCount++) {
        for (int colCount = 0; colCount < BOARD_SIZE; colCount++) {
            if (_A[rowCount][colCount].c == 0) {
                return 2; // Trò chơi chưa kết thúc
            }
        }
    }
    /*them sound*/playSound(5);
    return 0;

    return 0; // Hòa
}// Duyệt qua từng vòng ô xem có ô nào có c có bằng 0  hay không, nếu không return 0 cho ra hòa.

/*void CheckBoard(int pX, int pY) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (_A[i][j].x == pX && _A[i][j].y == pY && _A[i][j].c == 0) {
                _A[i][j].c = -1;


            }
        }
    }

}*/

int Minimax(int depth, bool isMaximizing) {
    int score = TestBoard(); // Kiểm tra trạng thái bàn cờ

    if (score != 2) {
        // Trò chơi đã kết thúc (X thắng, O thắng, hoặc hòa)
        return score;
    }

    if (isMaximizing) {
        int bestScore = -1000;
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                if (_A[i][j].c == 0) {
                    _A[i][j].c = 1; // 1 đại diện cho máy tính
                    int currentScore = Minimax(depth + 1, false);
                    _A[i][j].c = 0;
                    bestScore = max(bestScore, currentScore);
                }
            }
        }
        return bestScore;
    }
    else {
        int bestScore = 1000;
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                if (_A[i][j].c == 0) {
                    _A[i][j].c = -1; // -1 đại diện cho người chơi
                    int currentScore = Minimax(depth + 1, true);
                    _A[i][j].c = 0;
                    bestScore = min(bestScore, currentScore);
                }
            }
        }
        return bestScore;
    }
}
void ComputerMove() {
    int bestScore = -1000; // Điểm tốt nhất của máy tính
    int bestMoveX, bestMoveY; // Tọa độ của nước đi tốt nhất

    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (_A[i][j].c == 0) {
                // Thử đánh thử nước đi tại ô này
                _A[i][j].c = 1; // 1 đại diện cho máy tính
                int score = Minimax(0, false); // Gọi thuật toán Minimax để đánh giá nước đi

                // Đặt lại bàn cờ sau khi thử nước đi
                _A[i][j].c = 0;

                // Kiểm tra xem nước đi này có điểm tốt hơn không
                if (score > bestScore) {
                    bestScore = score;
                    bestMoveX = i;
                    bestMoveY = j;
                }
            }
        }
    }

    // Đánh nước đi tốt nhất của máy tính
    printf("May tinh danh tai (%d, %d)\n", bestMoveX, bestMoveY);
    _A[bestMoveX][bestMoveY].c = 1;// 1 đại diện cho máy tính
    GotoXY(_A[bestMoveX][bestMoveY].x, _A[bestMoveX][bestMoveY].y);
    printf("O");

}

void MoveRight() {
    if (_X < _A[BOARD_SIZE - 1][BOARD_SIZE - 1].x) {
        _X += 4;
        GotoXY(_X, _Y);
    }
}
/*Giải thích hàm MoveRight:
Nếu vị trí X đang xét nhỏ hơn tọa độ x cuối cùng bên phải, nếu gọi lệnh này thì vị trí X dịch sang 1 ô

*/
void MoveLeft() {
    if (_X > _A[0][0].x) {
        _X -= 4;
        GotoXY(_X, _Y);
    }
}


void MoveDown() {
    if (_Y < _A[BOARD_SIZE - 1][BOARD_SIZE - 1].y) {
        _Y += 2;
        GotoXY(_X, _Y);
    }
}



void MoveUp() {
    if (_Y > _A[0][0].y) {
        _Y -= 2;
        GotoXY(_X, _Y);
    }
}



void PlayervsPlayer() {
    StartGame();
    int playturn = 1;
    while (1) {
        _COMMAND = toupper(_getch());

        if (_COMMAND == 27) {
            ExitGame();
            system("cls");
            ScreenStartGame(99);
        }

        else if (playturn == 1) {
            if (_COMMAND == 'A') MoveLeft();
            else if (_COMMAND == 'W') MoveUp();
            else if (_COMMAND == 'S') MoveDown();
            else if (_COMMAND == 'D') MoveRight();
            else if (_COMMAND == 13) {
                CheckBoard(_X, _Y);
                playturn = 0;
                GotoXY(_X, _Y);
                printf("X");

            }
        }
        else if (playturn == 0) {
            ComputerMove();
            playturn = 1;
        }
        int result = TestBoard();
        if (result == -1) {
            GotoXY(0, _A[BOARD_SIZE - 1][BOARD_SIZE - 1].y + 2);
            printf("X thang");
            break;
        }
        if (result == 1) {
            GotoXY(0, _A[BOARD_SIZE - 1][BOARD_SIZE - 1].y + 2);
            printf("O thang");
            break;
        }
        if (result == 0) {
            GotoXY(0, _A[BOARD_SIZE - 1][BOARD_SIZE - 1].y + 2);
            printf("Hoa");
            break;
        }
    }
}