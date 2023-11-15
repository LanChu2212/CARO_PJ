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
#include "Textfile.h"
using namespace std;

void WINX1() {
    Textcolor(244);
    GotoXY(60, 1); cout << "     :::    :::        :::       ::: ::::::::::: ::::    ::: ";
    Textcolor(245);
    GotoXY(60, 2); cout << "     :+:    :+:        :+:       :+:     :+:     :+:+:   :+:";
    Textcolor(244);
    GotoXY(60, 3); cout << "     +:+  +:+         +:+       +:+     +:+     :+:+:+  +:+   ";
    Textcolor(245);
    GotoXY(60, 4); cout << "     +#++:+          +#+  +:+  +#+     +#+     +#+ +:+ +#+ ";
    Textcolor(244);
    GotoXY(60, 5); cout << "   +#+  +#+         +#+ +#+#+ +#+     +#+     +#+  +#+#+#  ";
    Textcolor(245);
    GotoXY(60, 5); cout << " #+#    #+#         #+#+# #+#+#      #+#     #+#   #+#+#  ";
    Textcolor(245);
    GotoXY(60, 5); cout << " ###    ###          ###   ###   ########### ###    ####  ";
    Textcolor(244);
    GotoXY(60, 5); cout << "";
}
void WINX2() {
    Textcolor(252);
    GotoXY(60, 1); cout << "     :::    :::        :::       ::: ::::::::::: ::::    ::: ";
    Textcolor(249);
    GotoXY(60, 2); cout << "     :+:    :+:        :+:       :+:     :+:     :+:+:   :+:";
    Textcolor(252);
    GotoXY(60, 3); cout << "     +:+  +:+         +:+       +:+     +:+     :+:+:+  +:+   ";
    Textcolor(249);
    GotoXY(60, 4); cout << "     +#++:+          +#+  +:+  +#+     +#+     +#+ +:+ +#+ ";
    Textcolor(244);
    GotoXY(60, 5); cout << "   +#+  +#+         +#+ +#+#+ +#+     +#+     +#+  +#+#+#  ";
    Textcolor(252);
    GotoXY(60, 5); cout << " #+#    #+#         #+#+# #+#+#      #+#     #+#   #+#+#  ";
    Textcolor(249);
    GotoXY(60, 5); cout << " ###    ###          ###   ###   ########### ###    ####  ";
    Textcolor(252);
    GotoXY(60, 5); cout << "";
}
void WINX() {
    int check = 1;
    while (check < 10)
    {
        WINX1();
        Sleep(100);
        WINX2();
        Sleep(100);
        check++;
    }
}
void WINO() {
    Textdecorate("OWIN.txt",5.0,10);
    
}
// Hàm nhóm view
void setConsoleWindow(int w, int h)
{
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r);

    MoveWindow(console, r.left, r.top, w, h, TRUE);
}
void FixConsoleWindow() {
    HWND consoleWindow = GetConsoleWindow();
    LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
    style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
    SetWindowLong(consoleWindow, GWL_STYLE, style);
}
/*
Giải thích hàm FixConsoleWindow:
1. Dòng đầu, ta khai báo hàm FixConsoleWindow với kiểu trả về là void và ko có tham số truyền vào
2. Dòng thứ hai, ta sẽ sử dụng hàm GetConsoleWindow() để lấy CON TRỎ consoleWindow có kiểu dữ liệu HWND (Handle to Windows) đến cửa sổ hiện tại.
   <Kiểu HWND được sử dụng để đại diện cho cửa sổ console trong window)
3. Ở dòng thứ ba, có thể hiểu style là biến lưu trữ các thông tin của cửa sổ(các cờ và các hằng số đại diện cho cửa sổ hiển thị), ta sử dụng
hàm GetWindowLong với hai tham số là consoleWindow và GWL_STYLE
<GWL_STYLE là hằng số sử dụng trong Windows AOI để chỉ định loại thông tin ta muốn lấy hoăc thiết lập cho cửa sổ>
4. Dòng thứ tư nghĩa là ta sẽ xóa đi các cờ WS_MAXIMIZEBOX và WS_THICKFRAME khỏi biến style, việc này giúp loại bỏ việc người dùng kéo giãn màn hình console dẫn đến vỡ màn hình.
5. Dòng thứ năm nghĩa là ta set lại cửa sổ console theo những thông tin ta đã định ở trc đó.





*/
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
#define RED_TEXT_ON_WHITE "\x1b[31;47m"
#define GREEN_TEXT_ON_WHITE "\x1b[32;47m"
#define AQUA_TEXT_ON_WHITE "\x1b[36;47m"
#define RESET_COLOR "\x1b[0m"
// Hằng số
#define BOARD_SIZE 14
#define LEFT 0
#define TOP 0
int countX = 0, countO = 0;
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
int cellX, cellY;
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
void DrawBoard()
{
   
    //if (SiZe == 0) return;
    
    // vẽ cột phải
    for (int i = 0; i < BOARD_SIZE * 2; i++)
    {
        
        GotoXY(BOARD_SIZE * 4, i + 1);
        Textcolor(245);
        if ((i + 1) % 2 == 1)
            cout<<char(186); //186
        else
            cout << char(182);  //182
    }

    // vẽ dòng ngang
    for (int i = 0; i < BOARD_SIZE * 2; i = i + 2)
    {
       
        GotoXY(0, i);
        Textcolor(Violet);
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
        
        GotoXY(0, i + 1);
        Textcolor(Violet);
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
            
            GotoXY(j, i);
            Textcolor(245);
            if (j == 0)
                continue;
            cout << char(179);
        }
    }

    // vẽ dòng đầu
    GotoXY(0, 0);
    Textcolor(245);
    for (int i = 0; i < BOARD_SIZE * 4; i++)
    {
        
        if (i % 4 == 0)
            cout << char(209);
        else
            cout << char(205);
    }
    GotoXY(0, 0);
    Textcolor(245);
    cout << char(201);
    GotoXY(BOARD_SIZE * 4, 0); 
    Textcolor(245);
    cout << char(187);

    // vẽ dòng cuối
    GotoXY(0, BOARD_SIZE * 2);
    Textcolor(245);
    for (int i = 0; i < BOARD_SIZE * 4; i++)
    {
        
        if (i % 4 == 0)
            cout << char(207);
        else
            cout << char(205);
    }
    GotoXY(0, BOARD_SIZE * 2);
    Textcolor(245); 
    cout << char(200);
    GotoXY(BOARD_SIZE * 4,BOARD_SIZE * 2);
    Textcolor(245);
    cout << char(188);
    //khung dao dien
    KhungGiaoDien();
    // về vị trí x y
    GotoXY(LEFT + 95, TOP + 7);
    cout << "So luot cua X la ";
    GotoXY(LEFT + 95, TOP + 9);
    cout << "So luot cua O la ";
    GotoXY(LEFT + 95, TOP + 10);
    //cout << "Luot cua ";
    GotoXY(2, 1);
}
/* Giải thích hàm DrawBoard
Ta thấy hàm này có tham số truyền vào là pSize(Thực chất là BoardSize đó :V)
 Nó sẽ vẽ bàn cờ bằng những dấu chấm. Ta thấy nó gọi hàm GotoXY, nghĩa là nó sẽ di chuyển đến những vị trí đã được chỉ định
 trong tham số truyền vào để vẽ dấu chấm.


*/

// Hàm nhóm Control
void StartGame(int* dX, int* dY) {
    system("cls");
    ResetData();
    Textcolor(245);
    DrawBoard();
    *dX = 0; *dY = 0;
}
/*Giải thích hàm StartGame
- system("cls"): Dòng lệnh này được sử dụng để xóa màn hình console, làm cho màn hình trống trải trước khi bắt đầu một trò chơi mới.
Điều này giúp xóa đi mọi nội dung trước đó trên màn hình.
- Ta gọi lại hàm ResetData rồi ta vẽ bàn cờ.

*/

void GabageCollect() {
    // Dọn dẹp tài nguyên nếu có khai báo con trỏ
}
//Hàm in nước đi
void in_nuoc_di() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            GotoXY(_A[i][j].x, _A[i][j].y);
            if (_A[i][j].c == -1)  cout << "X";
            if (_A[i][j].c == 1) cout << "O";
        }
    }
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
    } /*them sound*/playSound(5);

    return 0; // Hòa
}// Duyệt qua từng vòng ô xem c có bằng 0 hết hay không, nếu có return 0 cho ra hòa.
void get_locate(int pX, int pY) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (_A[i][j].x == pX && _A[i][j].y == pY)
            {
                cellX = i; cellY = j;
                break;
            }
        }
    }
}
int CheckBoard(int pX, int pY) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (_A[i][j].x == pX && _A[i][j].y == pY && _A[i][j].c == 0) {
                if (_TURN == true) {
                    countX++;  _A[i][j].c = -1;
                    return 1;
                }
                else {
                    countO++; _A[i][j].c = 1;
                    return 1;
                }
               
            }
        }
    }
    return 0;
}
/*Giải thích hàm CheckBoard:
Ta dùng hai vòng for để duyệt hết các ô trên bàn cờ
Ta kiểm tra xem tọa độ x và tọa độ y tại ô đó có phải là ô mà người chơi muốn đánh hay không, và
kiểm tra xem ô đó có trống hay không
Trong đó, ta sẽ kiểm tra tiếp: nếu TURN là true nghĩa là đang ở lượt người chơi X, ta cho ô đó bằng -1.
Nếu false thì đó là lượt của người chơi O, ta đánh bằng 1.
*/

void Xturn()
{
    Textcolor(252);
    GotoXY(83, 12);  cout << "xxx         xxx        " << endl;
    GotoXY(83, 13);  cout << "  xxx     xxx          " << endl;
    GotoXY(83, 14);  cout << "    xxx xxx            " << endl;
    GotoXY(83, 15);  cout << "      xxx              " << endl;
    GotoXY(83, 16);  cout << "    xxx xxx            " << endl;
    GotoXY(83, 17);  cout << "  xxx     xxx          " << endl;
    GotoXY(83, 18);  cout << "xxx         xxx        " << endl;
}

void Oturn()
{
    Textcolor(249);
    GotoXY(83, 12); cout << "   000000000            " << endl;
    GotoXY(83, 13); cout << " 000       000          " << endl;
    GotoXY(83, 14); cout << "000         000         " << endl;
    GotoXY(83, 15); cout << "000         000         " << endl;
    GotoXY(83, 16); cout << "000         000         " << endl;
    GotoXY(83, 17); cout << " 000       000          " << endl;
    GotoXY(83, 18); cout << "   000000000            " << endl;
}
int ProcessFinish(int pWhoWin, int countX, int countO) {
    if (_TURN == true) {
    Xturn();
   
    printf_s("");
    GotoXY(LEFT + 112, TOP + 7);
    printf_s("%d", countX);
    
}
else {
    Oturn();
    GotoXY(LEFT + 112, TOP + 9);
    printf_s("%d", countO);
}
    GotoXY(LEFT + 85, TOP + 20);// Nhảy đến vị trí thích hợp để in thắng, thua, hòa
    switch (pWhoWin) {
    case -1:
       
        printf("Nguoi choi %d da thang\n", true, false);
        system("cls");
        WINO();
       

        break;
    case 1:

        printf("Nguoi choi %d da thang \n", false, true);
        system("cls");
        WINX();
        break;
    case 0:
        printf("Nguoi choi %d da hoa nguoi choi %d\n", false, true);
        system("cls");
        DRAW();
        break;
    case 2:

        _TURN = !_TURN;
        GotoXY(_X, _Y);
    }

    return pWhoWin;
}
/* Ở hàm này, tham số truyền vào chính là kết quả trả về của hàm TestBoard(chính là pWhoWin)
Với kq là -1, X thắng
           1, O thắng
           0, hòa
           2, chưa chơi xong, TURN đổi ngược để cho người tiếp theo đánh
*/
int AskContinue() {
    system("color F0");
    /*GotoXY(LEFT + 85, TOP + 22);
    DrawBoardAbout(5, 50, 50);
    printf("Nhan 'y/n' de tiep tuc/dung: ");
    return toupper(_getch());*/
    SetConsoleCP(437);
    SetConsoleOutputCP(437);
    char s[30] = " ";
    int check = 1;
    int x = LEFT + 66, y = TOP + 21;
    system("color F0");
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
            case's':
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
            case 'w':
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
                    ScreenStartGame(99);
                    
                }
                if (y == TOP + 23) {
                    system("cls");
                    PlayervsPlayer();

                }
            }

        }
    }


    return toupper(_getch());
}
/*
Nhảy đến ô đc chỉ định và in ra hỏi người dùng có muốn tiếp tục hay không :
-Hàm _getch(): Hàm này trong thư viện <conio.h>, nó đọc ngay kí tự người dùng nhấp vào mà không cần nhấn enter,
ngay lập tức chuyển đổi thành mã ASCII đưa vào chương trình
- Hàm toupper(): Hàm này có trong thư viện <ctype.h> với chức năng chuyển đổi kí tự chữ cái thường thành kí tự chữ cái hoa,
Nếu kí tự ko phải chữ cái thì trả về kí tự ban đầu.
*/
void MoveRight() {
    if (_X < _A[BOARD_SIZE - 1][BOARD_SIZE - 1].x) {
        _X += 4;
        
    }
}
/*Giải thích hàm MoveRight:
Nếu vị trí X đang xét nhỏ hơn tọa độ x cuối cùng bên phải, nếu gọi lệnh này thì vị trí X dịch sang 1 ô

*/
void MoveLeft() {
    if (_X > _A[0][0].x) {
        _X -= 4;
       
    }
}

void MoveDown() {
    if (_Y < _A[BOARD_SIZE - 1][BOARD_SIZE - 1].y) {
        _Y += 2;
        
    }
}

void MoveUp() {
    if (_Y > _A[0][0].y) {
        _Y -= 2;
        
    }
}

void PlayervsPlayer() {
    system("color F0");
    
    FixConsoleWindow();
    StartGame(&countX, &countO);
    bool validEnter = true;
    HienTroChuot();
    while (1) {
        while (1) {
        GotoXY(_X, _Y);
        if (_TURN == true) cout << "X";
        else cout << "O";
        _COMMAND = toupper(_getch());
        GotoXY(_X, _Y);
        get_locate(_X, _Y);
        if (_A[cellX][cellY].c == 0) cout << " ";
        if (_A[cellX][cellY].c == -1) cout << "X";
        if (_A[cellX][cellY].c == 1) cout << "O";

        if (_COMMAND == 27) {
            ExitGame();

        }
        else {
            if (_COMMAND == 'A') MoveLeft();
            else if (_COMMAND == 'W') MoveUp();
            else if (_COMMAND == 'S') MoveDown();
            else if (_COMMAND == 'D') MoveRight();
            else if (_COMMAND == 13) { // Người chơi đánh dấu trên màn hình bàn cờ
                if (CheckBoard(_X, _Y) == 1) break;
                else validEnter = false;
            }
        }
    }
                // Tiếp theo là kiểm tra và xử lý thắng/thua/hòa/tiếp tục
                if (validEnter == true) {
                    int result = ProcessFinish(TestBoard(), countX, countO);
                    if (result == -1 || result == 1 || result == 0) {
                        if (AskContinue() != 'Y') {
                            ExitGame();

                        }
                        else {
                            StartGame(&countX, &countO);
                        }
                    }
                }
               
                validEnter = true; // Mở khóa
                in_nuoc_di();
            }
   

        }
    
    


/*
Giải thích cách hoạt động của hàm main():
- biến validenter để mở khóa/đóng khóa ô đánh: nếu ô chưa đc đánh thì validenter bằng true, ngược lại bằng false
Trong vòng while, biến COMMAND đại diện cho lệnh của người chơi, được xử lí bằng hàm toupper(_getch())
+ Nếu COMMAND bằng 27, tương ứng với phím Esc trên bàn phím, ta cho thoát game
+ Nếu COMMAND bằng một trong các lệnh A, W, S, D thì di chuyển
+ Nếu COMMAND bằng 13 tương ứng với phím Enter, ta cho người chơi đánh dấu X hoặc O, để làm được vậy, ta dùng switch
với kết quả của hàm CheckBoard, với các trường hợp case -1 hoặc case 1 ta cập nhật X hoặc O tương ứng, case bằng 0 nghĩa là
ô đó đã đánh rồi, ta cho validEnter = false.
Tiếp theo ta kiểm tra thắng/ thua/ hòa để hỏi xem người chơi có muốn tiếp tục chơi hay không, nếu vẫn chưa thắng, thua hay hòa
ta cập nhật lại ValidEnter = true.
*/
