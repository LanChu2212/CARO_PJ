#include "PLAYERVSBOTEasy.h"
#include <Windows.h>;
#include "Textfile.h"
using namespace std;

#define SIZE 14
#define LEFT 0
#define TOP 0

struct _POINT {
    int x, y;
    char c;
};

_POINT board[SIZE][SIZE];
int cursorX, cursorY;
int bestMoveX, bestMoveY;
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x * 4 + 2;
    coord.Y = y * 2 + 1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void initializeBoard() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j].x = i;
            board[i][j].y = j;
            board[i][j].c = ' ';
        }
    }
}
void Gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void DrawBoardBOT()
{
    system("cls");
    int BOARD_SIZE = SIZE;
    for (int i = 0; i < BOARD_SIZE * 2; i++)
    {
        Gotoxy(BOARD_SIZE * 4, i + 1);
        
        if ((i + 1) % 2 == 1)
        {
            
            cout << char(186); }//186
        else 
            
            cout << char(182);  //182
    }

    // vẽ dòng ngang
    for (int i = 0; i < BOARD_SIZE * 2; i = i + 2)
    {
        Gotoxy(0, i);
        
        for (int j = 0; j < BOARD_SIZE * 4; j++)
        {
            if (j % 4 == 0)
                cout << char(197);
            else
                cout << char(196);
        }
    }

    // vẽ cột trái
    for (int i = 0; i < BOARD_SIZE * 2; i++)
    {
        Gotoxy(0, i + 1);
        
        if ((i + 1) % 2 == 1)
            cout << char(186);
        else
            cout << char(199);
    }

    // vẽ cột dọc
    for (int i = 1; i < BOARD_SIZE * 2; i = i + 2)
    {
        for (int j = 0; j < BOARD_SIZE * 4; j = j + 4)
        {
            Gotoxy(j, i);
            
            if (j == 0)
                continue;
            cout << char(179);
        }
    }

    // vẽ dòng đầu
    Gotoxy(0, 0);
    
    for (int i = 0; i < BOARD_SIZE * 4; i++)
    {
        if (i % 4 == 0)
            cout << char(209);
        else
            cout << char(205);
    }
    Gotoxy(0, 0); cout << char(201);
    Gotoxy(BOARD_SIZE * 4, 0); cout << char(187);
    //vẽ Giao Dien
    KhungGiaoDien();
    // vẽ dòng cuối
    Gotoxy(0, BOARD_SIZE * 2);
    for (int i = 0; i < BOARD_SIZE * 4; i++)
    {
        if (i % 4 == 0)
            cout << char(207);
        else
            cout << char(205);
    }
    Gotoxy(0, BOARD_SIZE * 2); cout << char(200);
    Gotoxy(BOARD_SIZE * 4, BOARD_SIZE * 2);
    cout << char(188);
}
void printBoard() {

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            gotoxy(j, i);
            cout << board[i][j].c;
        }
        cout << endl;
    }
}


bool checkWin(int x, int y, char player) {
    int directions[4][2] = { {1, 0}, {0, 1}, {1, 1}, {1, -1} };
    for (int d = 0; d < 4; ++d) {
        int count = 0;
        for (int i = -4; i <= 4; ++i) {
            int CheckX = x + i * directions[d][0];
            int CheckY = y + i * directions[d][1];
            if (CheckX >= 0 && CheckX < SIZE && CheckY >= 0 && CheckY < SIZE && board[CheckX][CheckY].c == player) {
                count++;
                if (count == 5) return true;
            }
            else {
                count = 0;
            }

        }
    }
    return false;
}

bool isDraw() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (board[i][j].c == ' ') {
                return false; // Còn ô trống, chưa hòa
            }
        }
    }
    return true; // Không còn ô trống, hòa
}
int evaluateCell(int x, int y) {
    int score = 0;
    char players[2] = { 'X', 'O' };
    int weights[2] = { 1000, 1000 }; // Trọng số cho X và O

    for (int p = 0; p < 2; ++p) {
        board[x][y].c = players[p];

        // Kiểm tra chiến thắng
        if (checkWin(x, y, players[p])) {
            score += weights[p];
        }

        int directions[4][2] = { {1, 0}, {0, 1}, {1, 1}, {1, -1} };
        for (int d = 0; d < 4; ++d) {
            // Đánh giá dựa trên các quân cờ xung quanh và cơ hội tạo hàng thắng
            int cnt = 0;
            for (int i = -4; i <= 4; ++i) {
                int newX = x + i * directions[d][0];
                int newY = y + i * directions[d][1];
                if (newX >= 0 && newX < SIZE && newY >= 0 && newY < SIZE) {
                    if (board[newX][newY].c == players[p]) {
                        cnt++;
                        if (cnt >= 3) {
                            score += weights[p] / 2; // Tăng điểm nếu có 3 quân liền kề
                        }
                    }
                    else {
                        cnt = 0;
                    }
                }
            }
        }
       
       
        // Thuật toán leo đồi: đánh giá dựa trên cải thiện tình hình
        int improvementScore = 0;
        for (int d = 0; d < 4; ++d) {
            int playerCount = 0;
            // Kiểm tra quân cờ liên tiếp trong mỗi hướng
            for (int i = 1; i <= 4; ++i) {
                int newX = x + i * directions[d][0];
                int newY = y + i * directions[d][1];
                if (newX >= 0 && newX < SIZE && newY >= 0 && newY < SIZE && board[newX][newY].c == players[p]) {
                    playerCount++;
                }
                else {
                    break;
                }
            }
            // Càng nhiều quân liên tiếp, điểm cải thiện càng cao
            improvementScore += playerCount * playerCount; // Ví dụ: ưu tiên dài hơn chuỗi
        }
        score += improvementScore;
    }
    board[x][y].c = ' '; // Đặt lại ô trống sau đánh giá
    return score;
}





void computerMove() {
    bestMoveX = -1;
    bestMoveY = -1;
    int bestScore = -1;

    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (board[i][j].c == ' ') {
                int score = evaluateCell(i, j);
                if (score > bestScore) {
                    bestMoveX = i;
                    bestMoveY = j;
                    bestScore = score;
                }
            }
        }
    }

    board[bestMoveX][bestMoveY].c = 'X';
}
int AskContinueBOTEasy() {
    /*GotoXY(LEFT + 85, TOP + 22);
    DrawBoardAbout(5, 50, 50);
    printf("Nhan 'y/n' de tiep tuc/dung: ");
    return toupper(_getch());*/
    SetConsoleCP(437);
    SetConsoleOutputCP(437);
    char s[30] = " ";
    int check = 1;
    int x = LEFT + 66, y = TOP + 21;
    DrawBoardAbout(6, 60, 15);
    GotoXY(LEFT + 65, TOP + 20);
    printf("Nhan 'y/n' de ");
    GotoXY(LEFT + 65, TOP + 21);
    printf("tiep tuc/dung:");
    Textcolor(Red);
    GotoXY(LEFT + 66, TOP + 22); cout << "Y:CONTINUE";
    Textcolor(15);
    GotoXY(LEFT + 66, TOP + 23); cout << "N:EXIT";
    while (check) {
        if (_kbhit()) {
            switch (_getch()) {
            case'w':
                if (y > TOP + 22) {
                    y--;
                    GotoXY(x, y);
                }
                if (y == TOP + 22) {
                    Textcolor(Red);
                    GotoXY(LEFT + 66, TOP + 22); cout << "Y:CONTINUE";
                    Textcolor(7);
                    GotoXY(LEFT + 66, TOP + 23); cout << "N:EXIT";
                }
                if (y == TOP + 23) {
                    Textcolor(7);
                    GotoXY(LEFT + 66, TOP + 22); cout << "Y:CONTINUE";
                    Textcolor(Red);
                    GotoXY(LEFT + 66, TOP + 23); cout << "N:EXIT";

                }
                break;
            case 's':
                if (y < TOP + 23) {
                    y++;
                    GotoXY(x, y);
                }
                if (y == TOP + 22) {
                    Textcolor(Red);
                    GotoXY(LEFT + 66, TOP + 22); cout << "Y:CONTINUE";
                    Textcolor(7);
                    GotoXY(LEFT + 66, TOP + 23); cout << "N:EXIT";
                }
                if (y == TOP + 23) {
                    Textcolor(7);
                    GotoXY(LEFT + 66, TOP + 22); cout << "Y:CONTINUE";
                    Textcolor(Red);
                    GotoXY(LEFT + 66, TOP + 23); cout << "N:EXIT";

                }
                break;
            case 13:
                if (y == TOP + 22) {
                    system("cls");
                    PlayerVsBOTEasy();
                }
                if (y == TOP + 23) {
                    system("cls");
                    ScreenStartGame(99);

                }
            }

        }
    }


    return toupper(_getch());
}
void PlayerVsBOTEasy() {
    
    initializeBoard();
    DrawBoardBOT();
    printBoard();
    
    system("color F0");
    while (true) {
        gotoxy(cursorY, cursorX + SIZE + 1);

        char move;
        while (true) {
            gotoxy(cursorY, cursorX);
            cout << 'O';
            move = _getch();
            gotoxy(cursorY, cursorX);
            cout << board[cursorX][cursorY].c;
            if (move == 'w' && cursorX > 0) cursorX--;
            if (move == 's' && cursorX < SIZE - 1) cursorX++;
            if (move == 'a' && cursorY > 0) cursorY--;
            if (move == 'd' && cursorY < SIZE - 1) cursorY++;
            if (move == '\r' && board[cursorX][cursorY].c == ' ') {
                board[cursorX][cursorY].c = 'O';
                break;
            }
        }
       
        printBoard();

        if (checkWin(cursorX, cursorY, 'O')) {
            gotoxy(0, SIZE + 4);
            cout << "You win!" << endl;
            YOUWIN();
            AskContinueBOTEasy();
            break;
        }
        computerMove();
       
        printBoard();
        if (checkWin(bestMoveX, bestMoveY, 'X')) {
            gotoxy(0, SIZE + 4);
            cout << "Computer wins!" << endl;
            system("Cls");
            COMPUTERWIN();
            AskContinueBOTEasy();
            break;
        }
        /*else
            cout << "Draw" << endl;*/
        else if (isDraw()) {
            DRAW();
            break;
        }
    }

}