#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

#define SIZE 14
#define LEFT 0
#define TOP 0

struct _POINT {
    int x, y;
    char c;
};
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
_POINT board[SIZE][SIZE];
int cursorX = 1, cursorY = 1;
int bestMoveX, bestMoveY;
int real_cellX, real_cellY;
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
void DrawBoard()
{
    
    
    int BOARD_SIZE = SIZE;
    for (int i = 0; i < BOARD_SIZE * 2; i++)
    {
        Gotoxy(BOARD_SIZE * 4, i + 1);
        if ((i + 1) % 2 == 1)
            cout << char(186); //186
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
int getCheck(int i, int j) {
    if (board[i][j].c == 'X') return 1;
    if (board[i][j].c == 'O') return -1;
    else return 0;
}
void printBoard() {
    
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            gotoxy(j, i);
            if (i == real_cellX && j == real_cellY) {
                
                CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
                GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
                WORD saved_attributes = consoleInfo.wAttributes;

                // Đặt màu của văn bản là màu xanh lá
                SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | (saved_attributes & 0x00F0));

                cout << "X";

                // Khôi phục lại các thuộc tính màu ban đầu
                SetConsoleTextAttribute(hConsole, saved_attributes);

            }
            else { 
                if (board[i][j].c == 'X') {
                    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
                    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
                    WORD saved_attributes = consoleInfo.wAttributes;
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | (saved_attributes & 0x00F0));
                    cout << board[i][j].c;
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                }
                else {
                    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
                    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
                    WORD saved_attributes = consoleInfo.wAttributes;
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | (saved_attributes & 0x00F0));
                    cout << board[i][j].c;
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                }
                
            }
        }
        cout << endl;
    }
}


bool checkWin(int x, int y, char player) {
    //Liệt kê các đường di chuyển có thể có tại một ô
    int directions[4][2] = { {1, 0}, {0, 1}, {1, 1}, {1, -1} }; //{dx,dy} với dx là số tăng chỉ số hàng và tăng chỉ số cột
    //{1,0}: Qua phải (Tăng số cột lên 1 và số hàng giữ nguyên)
    //{0,1}: Xuống dưới (Tăng chỉ số hàng lên 1, giảm chỉ số cột)
    //{1;1}: di chuyển chéo phải xuống dưới (Tăng chỉ số cột lên 1, tăng chỉ số hàng lên 1)
    //{1,-1}: di chuyển chéo phải lên trên (Tăng chỉ số cột lên 1, giảm chỉ số hàng xuống 1)
    for (int d = 0; d < 4; ++d) {
        int cnt = 0;
        //Kiểm tra 9 ô xung quanh (gồm 2 phía, mỗi phía 4 ô) của cả 4 đường di chuyển đã nêu trên
        for (int i = -4; i <= 4; ++i) {
  
            int newX = x + i * directions[d][0]; //d tương ứng với chỉ số hàng trong ma trận, 0 và 1 là chỉ số cột trong ma trận
            int newY = y + i * directions[d][1];
            if (newX >= 0 && newX < SIZE && newY >= 0 && newY < SIZE && board[newX][newY].c == player) {
                cnt++; //Nếu có các ô liên tiếp cùng X hoặc O thì biến đếm tăng
                if (cnt == 5) return true;
            }
            else {
                cnt = 0; //Nếu có ô không thỏa, biến đếm trở lại 0
            }
        }
    }
    return false; //Không đủ điều kiện chiến thắng
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
//Xử lý AI
const long Defend_Score1[7] = { 0, 72, 9216, 589824, 37748736, 2415919104 };
const long Attack_Score1[7] = { 0, 576, 73728, 4718592, 301989888, 19327352832 };
long SoDiemTanCong_DuyetNgang(long Dong, long Cot, const long Defend_Score[], const long Attack_Score[]) //Lấy từ trên xuống dưới
{
    long iScoreTempNgang = 0;
    long iScoreAttack = 0;
    int iSoQuanTa = 0;
    int iSoQuanDich = 0;
    int iSoQuanTa2 = 0;
    int iSoQuanDich2 = 0;
    //Phía trên ô đang xét. (Ta gọi là trường hợp 1).
    for (int iDem = 1; iDem < 6 && Cot + iDem < SIZE; iDem++)
    {
        //Nếu phía trên ô đang xét là quân ta, iSoQuanTa++; (số quân ta).
        if (getCheck(Dong, Cot + iDem) == 1)
            iSoQuanTa++;
        //Nếu phía trên ô đang xét là quân địch, iSoQuanDich++; (số quân địch) và thoát khỏi vòng lặp (Trường hợp 1).
        if (getCheck(Dong, Cot + iDem) == -1)
        {
            iSoQuanDich++;
            break;
        }
        //Nếu phía trên ô đang xét là ô trống, ta sẽ xét phía trên ô trống này.
        if (getCheck(Dong, Cot + iDem) == 0)
        {
            for (int iDem2 = 2; iDem2 < 7 && Cot + iDem2 < SIZE; iDem2++)
            {
                //Nếu phía trên ô trống là quân ta, iSoQuanTa2++; (Số quân ta 2).
                if (getCheck(Dong, Cot + iDem2) == 1)
                    iSoQuanTa2++;
                //Nếu phía trên ô trống là quân địch, iSoQuanDich2++; (Số quân địch 2) và thoát khỏi vòng lặp.
                if (getCheck(Dong, Cot + iDem2) == -1)
                {
                    iSoQuanDich2++;
                    break;
                }
                //Nếu phía trên ô trống là ô trống, thoát khỏi vòng lặp.
                if (getCheck(Dong, Cot + iDem2) == 0)
                    break;
            }
            //Thoát khỏi vòng lặp.
            break;
        }
    }
    //Phía dưới ô đang xét. (Ta gọi là trường hợp 2).
    for (int iDem = 1; iDem < 6 && Cot - iDem >= 0; iDem++)
    {
        //Nếu phía dưới ô đang xét là quân ta, iSoQuanTa++; (số quân ta).
        if (getCheck(Dong, Cot - iDem) == 1)
            iSoQuanTa++;
        //Nếu phía dưới ô đang xét là quân địch, iSoQuanDich++; (số quân địch) và thoát khỏi vòng lặp (Trường hợp 2).
        if (getCheck(Dong, Cot - iDem) == -1)
        {
            iSoQuanDich++;
            break;
        }
        //Nếu phía dưới ô đang xét là ô trống, ta sẽ xét phía trên ô trống này.
        if (getCheck(Dong, Cot - iDem) == 0)
        {
            for (int iDem2 = 2; iDem2 < 7 && Cot - iDem2 >= 0; iDem2++)
            {
                //Nếu phía dưới ô trống là quân ta, iSoQuanTa2++; (Số quân ta 2).
                if (getCheck(Dong, Cot - iDem2) == 1)
                    iSoQuanTa2++;
                //Nếu phía dưới ô trống là quân địch, iSoQuanDich2++; (Số quân địch 2).
                if (getCheck(Dong, Cot - iDem2) == -1)
                {
                    iSoQuanDich2++;
                    break;
                }
                //Nếu phía dưới ô trống là ô trống, thoát khỏi vòng lặp.
                if (getCheck(Dong, Cot - iDem2) == 0)
                    break;
            }
            //Thoát khỏi vòng lặp.
            break;
        }
    }
    //const long Defend_Score1[7] = { 0, 24, 3072, 196608, 12582912, 805306368 };
    //const long Attack_Score1[7] = { 0, 192, 24576, 1572864, 100663296, 6442450944 };
    //Giả sử X là quân ta, O là quân địch, E là ô trống, H là ô đang xét.

    //Cột: Bị địch chặn 2 đầu tại ô đang xét  -> Điểm tấn công của ô = 0.
    //Mô tả: ... O ... H ... O ... 
    if (iSoQuanDich == 2)
        return 0;
    //Cột: 5 ô phía trên và 5 ô phía dưới ô đang xét không có bất kì quân địch nào -> Điểm tấn công của ô phụ thuộc vào số quân ta trong khoảng đó.
    //Số điểm tấn công của ô cộng thêm Attack_Score[số quân ta]*2;
    if (iSoQuanDich == 0)
        iScoreTempNgang += Attack_Score[iSoQuanTa] * 2;
    //Cột: Bị duy nhất 1 địch chặn tại đầu trên hoặc đầu dưới tại ô đang xét.
    //Mô tả: ... O ... H ...... hoặc ...... H ... 0 ...
    //Số điểm tấn công của ô cộng thêm Attack_Score[số quân ta];
    else
        iScoreTempNgang += Attack_Score[iSoQuanTa];
    //Không tồn tại quân địch sao cho có ô trống ngay phía dưới quân địch (trường hợp 1) hoặc ngay phía trên quân địch (trường hợp 2) -> Tránh trường hợp đánh vào khoảng trống giữa ta và địch để tấn công, sau đó lại bị địch chặn 2 đầu.
    //Đây là trường hợp không có bất kì quân địch nào hoặc nếu có thì quân địch phải sát ngay với quân ta.
    //Số điểm tấn công của ô cộng thêm Attack_Score[số quân ta]*2;
    if (iSoQuanDich2 == 0)
        iScoreTempNgang += Attack_Score[iSoQuanTa2] * 2;
    //Tồn tại quân địch sao cho có ô trống ngay phía dưới quân địch (trường hợp 1) hoặc ngay phía trên quân địch (trường hợp 2) -> Trường hợp này dễ rơi vào tình huống đánh vào khoảng trống giữa ta và địch để tấn công, sau đó lại bị địch chặn 2 đầu.
    //Đây là trường hợp có tồn tại ô trống giữa ô đang xét và quân địch ở phía trên hoặc phía dưới ô đang xét.
    //Số điểm tấn công của ô cộng thêm Attack_Score[số quân ta];
    else
        iScoreTempNgang += Attack_Score[iSoQuanTa2];
    //Xét trên khoảng 10 ô xung quanh ô đang xét. Nếu số quân ta liền nhau nhiều hơn số quân ta trong khoảng đang xét nhưng không liền nhau thì:
    //Số điểm tấn công của ô -1 (Ưu tiên trường hợp quân ta liền nhau).
    if (iSoQuanTa >= iSoQuanTa2)
        iScoreTempNgang -= 1;
    //Nếu những ô liền nhau ít hơn thì:
    //Số điểm tấn công của ô -2 (Không ưu tiên hơn trường hợp những ô liền nhau).
    else
        iScoreTempNgang -= 2;
    //Nếu số quân liền nhau của ta là 4 -> Số điểm của ô nhân đôi (Số điểm tấn công của ô tăng cực nhiều) -> Chắc chắn thắng.
    if (iSoQuanTa == 4)
        iScoreTempNgang *= 2;
    //Đây là trường hợp 2 ô trên dưới ô đang xét không có ô nào là quân ta.
    //Số điểm tấn công của ô phụ thuộc vào số quân địch ở 2 ô này, số điểm tấn công của ô công thêm Defend_Score[số quân địch]*2; (Ưu tiên vì quân địch nhiều).
    if (iSoQuanTa == 0)
        iScoreTempNgang += Defend_Score[iSoQuanDich] * 2;
    //Đây là trường hợp trong khoảng đang xét có số quân ta bất kì.
    //Số điểm tân công của ô phụ thuộc vào số quân địch ở 2 ô này, số điểm tấn công của ô công thêm Defend_Score[số quân địch]; (Không ưu tiên vì quân ta đang nhiều, thiên về tấn công);
    else
        iScoreTempNgang += Defend_Score[iSoQuanDich];
    //Không tồn tại quân ta sao cho có ô trống ngay phía dưới quân ta (trường hợp 1) hoặc ngay phía trên quân ta (trường hợp 2) -> Các ô quân ta đang liền nhau, ưu tiên tấn công -> Số điểm tấn công của ô tăng nhiều.
    //Số điểm tấn công của ô phụ thuộc vào số quân địch chặn đầu, số điểm tấn công của ô công thêm Defend_Score[số quân địch]*2;
    if (iSoQuanTa2 == 0)
        iScoreTempNgang += Defend_Score[iSoQuanDich2] * 2;
    //Tồn tại quân ta sao cho có ô trống ngay phía dưới quân ta (trường hợp 1) hoặc ngay phía trên quân ta (trường hợp 2) -> Các ô quân ta đang không liền nhau, không ưu tiên -> Số điểm tấn công của ô tăng ít.
    //Số điểm tấn công của ô phụ thuộc vào số quân địch chặn đầu, số điểm tấn công của ô công thêm Defend_Score[số quân địch];
    else
        iScoreTempNgang += Defend_Score[iSoQuanDich2];
    return iScoreTempNgang;
}
long SoDiemTanCong_DuyetDoc(long Dong, long Cot, const long Defend_Score[], const long Attack_Score[])
{
    long iScoreTempDoc = 0;
    long iScoreAttack = 0;
    int iSoQuanTa = 0;
    int iSoQuanDich = 0;
    int iSoQuanTa2 = 0;
    int iSoQuanDich2 = 0;
    for (int iDem = 1; iDem < 6 && Dong + iDem < SIZE; iDem++)
    {
        if (getCheck(Dong + iDem, Cot) == 1)
            iSoQuanTa++;
        if (getCheck(Dong + iDem, Cot) == -1)
        {
            iSoQuanDich++;
            break;
        }
        if (getCheck(Dong + iDem, Cot) == 0)
        {
            for (int iDem2 = 2; iDem2 < 7 && Dong + iDem2 < SIZE; iDem2++)
            {
                if (getCheck(Dong + iDem2, Cot) == 1)
                    iSoQuanTa2++;
                if (getCheck(Dong + iDem2, Cot) == -1)
                {
                    iSoQuanDich2++;
                    break;
                }
                if (getCheck(Dong + iDem2, Cot) == 0)
                    break;
            }
            break;
        }
    }
    for (int iDem = 1; iDem < 6 && Dong - iDem >= 0; iDem++)
    {
        if (getCheck(Dong - iDem, Cot) == 1)
            iSoQuanTa++;
        if (getCheck(Dong - iDem, Cot) == -1)
        {
            iSoQuanDich++;
            break;
        }
        if (getCheck(Dong - iDem, Cot) == 0)
        {
            for (int iDem2 = 2; iDem2 < 7 && Dong - iDem2 >= 0; iDem2++)
            {
                if (getCheck(Dong - iDem2, Cot) == 1)
                    iSoQuanTa2++;
                if (getCheck(Dong - iDem2, Cot) == -1)
                {
                    iSoQuanDich2++;
                    break;
                }
                if (getCheck(Dong - iDem2, Cot) == 0)
                {
                    break;
                }
            }
            break;
        }
    }

    if (iSoQuanDich == 2)
        return 0;
    if (iSoQuanDich == 0)
        iScoreTempDoc += Attack_Score[iSoQuanTa] * 2;
    else
        iScoreTempDoc += Attack_Score[iSoQuanTa];
    if (iSoQuanDich2 == 0)
        iScoreTempDoc += Attack_Score[iSoQuanTa2] * 2;
    else
        iScoreTempDoc += Attack_Score[iSoQuanTa2];

    if (iSoQuanTa >= iSoQuanTa2)
        iScoreTempDoc -= 1;
    else
        iScoreTempDoc -= 2;
    if (iSoQuanTa == 4)
        iScoreTempDoc *= 2;
    if (iSoQuanTa == 0)
        iScoreTempDoc += Defend_Score[iSoQuanDich] * 2;
    else
        iScoreTempDoc += Defend_Score[iSoQuanDich];
    if (iSoQuanTa2 == 0)
        iScoreTempDoc += Defend_Score[iSoQuanDich2] * 2;
    else
        iScoreTempDoc += Defend_Score[iSoQuanDich2];
    return iScoreTempDoc;
}
long SoDiemTanCong_DuyetCheo1(long Dong, long Cot, const long Defend_Score[], const long Attack_Score[])
{
    long iScoreTempCheoNguoc = 0;
    long iScoreAttack = 0;
    int iSoQuanTa = 0;
    int iSoQuanDich = 0;
    int iSoQuanTa2 = 0;
    int iSoQuanDich2 = 0;
    for (int iDem = 1; iDem < 6 && Cot + iDem < SIZE && Dong + iDem < SIZE; iDem++)
    {
        if (getCheck(Dong + iDem, Cot + iDem) == 1)
            iSoQuanTa++;
        if (getCheck(Dong + iDem, Cot + iDem) == -1)
        {
            iSoQuanDich++;
            break;
        }
        if (getCheck(Dong + iDem, Cot + iDem) == 0)
        {
            for (int iDem2 = 2; iDem2 < 7 && Cot + iDem2 < SIZE && Dong + iDem2 < SIZE; iDem2++)
            {
                if (getCheck(Dong + iDem2, Cot + iDem2) == 1)
                    iSoQuanTa2++;
                if (getCheck(Dong + iDem2, Cot + iDem2) == -1)
                {
                    iSoQuanDich2++;
                    break;
                }
                if (getCheck(Dong + iDem2, Cot + iDem2) == 0)
                {
                    break;
                }
            }
            break;
        }
    }
    for (int iDem = 1; iDem < 6 && Cot - iDem >= 0 && Dong - iDem >= 0; iDem++)
    {
        if (getCheck(Dong - iDem, Cot - iDem) == 1)
            iSoQuanTa++;
        if (getCheck(Dong - iDem, Cot - iDem) == -1)
        {
            iSoQuanDich++;
            break;
        }
        if (getCheck(Dong - iDem, Cot - iDem) == 0)
        {
            for (int iDem2 = 2; iDem2 < 7 && Cot - iDem2 >= 0 && Dong - iDem2 >= 0; iDem2++)
            {
                if (getCheck(Dong - iDem2, Cot - iDem2) == 1)
                    iSoQuanTa2++;
                if (getCheck(Dong - iDem2, Cot - iDem2) == -1)
                {
                    iSoQuanDich2++;
                    break;
                }
                if (getCheck(Dong - iDem2, Cot - iDem2) == 0)
                    break;
            }
            break;
        }
    }
    if (iSoQuanDich == 2)
        return 0;
    if (iSoQuanDich == 0)
        iScoreTempCheoNguoc += Attack_Score[iSoQuanTa] * 2;
    else
        iScoreTempCheoNguoc += Attack_Score[iSoQuanTa];
    if (iSoQuanDich2 == 0)
        iScoreTempCheoNguoc += Attack_Score[iSoQuanTa2] * 2;
    else
        iScoreTempCheoNguoc += Attack_Score[iSoQuanTa2];

    if (iSoQuanTa >= iSoQuanTa2)
        iScoreTempCheoNguoc -= 1;
    else
        iScoreTempCheoNguoc -= 2;
    if (iSoQuanTa == 4)
        iScoreTempCheoNguoc *= 2;
    if (iSoQuanTa == 0)
        iScoreTempCheoNguoc += Defend_Score[iSoQuanDich] * 2;
    else
        iScoreTempCheoNguoc += Defend_Score[iSoQuanDich];
    if (iSoQuanTa2 == 0)
        iScoreTempCheoNguoc += Defend_Score[iSoQuanDich2] * 2;
    else
        iScoreTempCheoNguoc += Defend_Score[iSoQuanDich2];
    return iScoreTempCheoNguoc;
}
long SoDiemTanCong_DuyetCheo2(long Dong, long Cot, const long Defend_Score[], const long Attack_Score[])
{
    long iScoreTempCheoXuoi = 0;
    long iScoreAttack = 0;
    int iSoQuanTa = 0;
    int iSoQuanDich = 0;
    int iSoQuanTa2 = 0;
    int iSoQuanDich2 = 0;
    for (int iDem = 1; iDem < 6 && Cot - iDem >= 0 && Dong + iDem < SIZE; iDem++)
    {
        if (getCheck(Dong + iDem, Cot - iDem) == 1)
            iSoQuanTa++;
        if (getCheck(Dong + iDem, Cot - iDem) == -1)
        {
            iSoQuanDich++;
            break;
        }
        if (getCheck(Dong + iDem, Cot - iDem) == 0)
        {
            for (int iDem2 = 2; iDem2 < 7 && Cot - iDem2 >= 0 && Dong + iDem2 < SIZE; iDem2++)
            {
                if (getCheck(Dong + iDem2, Cot - iDem2) == 1)
                    iSoQuanTa2++;
                if (getCheck(Dong + iDem2, Cot - iDem2) == -1)
                {
                    iSoQuanDich2++;
                    break;
                }
                if (getCheck(Dong + iDem2, Cot - iDem2) == 0)
                    break;
            }
            break;
        }
    }
    for (int iDem = 1; iDem < 6 && Cot + iDem < SIZE && Dong - iDem >= 0; iDem++)
    {
        if (getCheck(Dong - iDem, Cot + iDem) == 1)
            iSoQuanTa++;
        if (getCheck(Dong - iDem, Cot + iDem) == -1)
        {
            iSoQuanDich++;
            break;
        }
        if (getCheck(Dong - iDem, Cot + iDem) == 0)
        {
            for (int iDem2 = 2; iDem2 < 7 && Cot + iDem2 < SIZE && Dong - iDem2 >= 0; iDem2++)
            {
                if (getCheck(Dong - iDem2, Cot + iDem2) == 1)
                    iSoQuanTa2++;
                if (getCheck(Dong - iDem2, Cot + iDem2) == -1)
                {
                    iSoQuanDich2++;
                    break;
                }
                if (getCheck(Dong - iDem2, Cot + iDem2) == 0)
                    break;
            }
            break;
        }
    }
    if (iSoQuanDich == 2)
        return 0;
    if (iSoQuanDich == 0)
        iScoreTempCheoXuoi += Attack_Score[iSoQuanTa] * 2;
    else
        iScoreTempCheoXuoi += Attack_Score[iSoQuanTa];
    if (iSoQuanDich2 == 0)
        iScoreTempCheoXuoi += Attack_Score[iSoQuanTa2] * 2;
    else
        iScoreTempCheoXuoi += Attack_Score[iSoQuanTa2];

    if (iSoQuanTa >= iSoQuanTa2)
        iScoreTempCheoXuoi -= 1;
    else
        iScoreTempCheoXuoi -= 2;
    if (iSoQuanTa == 4)
        iScoreTempCheoXuoi *= 2;
    if (iSoQuanTa == 0)
        iScoreTempCheoXuoi += Defend_Score[iSoQuanDich] * 2;
    else
        iScoreTempCheoXuoi += Defend_Score[iSoQuanDich];
    if (iSoQuanTa2 == 0)
        iScoreTempCheoXuoi += Defend_Score[iSoQuanDich2] * 2;
    else
        iScoreTempCheoXuoi += Defend_Score[iSoQuanDich2];
    return iScoreTempCheoXuoi;
}
long SoDiemPhongThu_DuyetDoc(long Dong, long Cot, const long Defend_Score[], const long Attack_Score[])
{
    long iScoreTempDoc = 0;
    long iScoreDefend = 0;
    int iSoQuanDich = 0;
    int iSoQuanTa = 0;
    int iSoQuanDich2 = 0;
    int iSoQuanTa2 = 0;
    for (int iDem = 1; iDem < 6 && Dong + iDem < SIZE; iDem++)
    {
        if (getCheck(Dong + iDem, Cot) == 1)
        {
            iSoQuanTa++;
            break;
        }
        if (getCheck(Dong + iDem, Cot) == -1)
            iSoQuanDich++;
        if (getCheck(Dong + iDem, Cot) == 0)
        {
            for (int iDem2 = 2; iDem2 < 7 && Dong + iDem2 < SIZE; iDem2++)
            {
                if (getCheck(Dong + iDem2, Cot) == 1)
                {
                    iSoQuanTa2++;
                    break;
                }
                if (getCheck(Dong + iDem2, Cot) == -1)
                    iSoQuanDich2++;
                if (getCheck(Dong + iDem2, Cot) == 0)
                    break;
            }
            break;
        }
    }
    for (int iDem = 1; iDem < 6 && Dong - iDem >= 0; iDem++)
    {
        if (getCheck(Dong - iDem, Cot) == 1)
        {
            iSoQuanTa++;
            break;
        }
        if (getCheck(Dong - iDem, Cot) == -1)
            iSoQuanDich++;
        if (getCheck(Dong - iDem, Cot) == 0)
        {
            for (int iDem2 = 2; iDem2 < 7 && Dong - iDem2 >= 0; iDem2++)
            {
                if (getCheck(Dong - iDem2, Cot) == 1)
                {
                    iSoQuanTa2++;
                    break;
                }
                if (getCheck(Dong - iDem2, Cot) == -1)
                    iSoQuanDich2++;
                if (getCheck(Dong - iDem2, Cot) == 0)
                    break;
            }
            break;
        }
    }

    if (iSoQuanTa == 2)
        return 0;
    if (iSoQuanTa == 0)
        iScoreTempDoc += Defend_Score[iSoQuanDich] * 2;
    else
        iScoreTempDoc += Defend_Score[iSoQuanDich];
    if (iSoQuanDich >= iSoQuanDich2)
        iScoreTempDoc -= 1;
    else
        iScoreTempDoc -= 2;
    if (iSoQuanDich == 4)
        iScoreTempDoc *= 2;
    return iScoreTempDoc;
}
long SoDiemPhongThu_DuyetNgang(long Dong, long Cot, const long Defend_Score[], const long Attack_Score[])
{
    long iScoreTempNgang = 0;
    long iScoreDefend = 0;
    int iSoQuanDich = 0;
    int iSoQuanTa = 0;
    int iSoQuanDich2 = 0;
    int iSoQuanTa2 = 0;
    //Phía trên ô đang xét. (Ta gọi là trường hợp 1).
    for (int iDem = 1; iDem < 6 && Cot + iDem < SIZE; iDem++)
    {
        //Nếu phía trên ô đang xét là quân ta, iSoQuanTa++; (số quân ta) và thoát khỏi vòng lặp (Trường hợp 1).
        if (getCheck(Dong, Cot + iDem) == 1)
        {
            iSoQuanTa++;
            break;
        }
        //Nếu phía trên ô đang xét là quân địch, iSoQuanDich++; (số quân địch).
        if (getCheck(Dong, Cot + iDem) == -1)
            iSoQuanDich++;
        //Nếu phía trên ô đang xét là ô trống, ta sẽ xét phía trên ô trống này.
        if (getCheck(Dong, Cot + iDem) == 0)
        {
            for (int iDem2 = 2; iDem2 < 7 && Cot + iDem2 < SIZE; iDem2++)
            {
                //Nếu phía trên ô trống là quân ta, iSoQuanTa2++; (Số quân ta 2) và thoát khỏi vòng lặp.
                if (getCheck(Dong, Cot + iDem2) == 1)
                {
                    iSoQuanTa2++;
                    break;
                }
                //Nếu phía trên ô trống là quân địch, iSoQuanDich2++; (Số quân địch 2).
                if (getCheck(Dong, Cot + iDem2) == -1)
                    iSoQuanDich2++;
                if (getCheck(Dong, Cot + iDem2) == 0)
                    //Nếu phía trên ô trống là ô trống, thoát khỏi vòng lặp.
                    break;
            }
            //Thoát khỏi vòng lặp.
            break;
        }
    }
    //Phía dưới ô đang xét. (Ta gọi là trường hợp 2).
    for (int iDem = 1; iDem < 6 && Cot - iDem >= 0; iDem++)
    {
        //Nếu phía dưới ô đang xét là quân ta, iSoQuanTa++; (số quân ta) và thoát khỏi vòng lặp (Trường hợp 2).
        if (getCheck(Dong, Cot - iDem) == 1)
        {
            iSoQuanTa++;
            break;
        }
        //Nếu phía dưới ô đang xét là quân địch, iSoQuanDich++; (số quân địch).
        if (getCheck(Dong, Cot - iDem) == -1)
            iSoQuanDich++;
        //Nếu phía dưới ô đang xét là ô trống, ta sẽ xét phía trên ô trống này.
        if (getCheck(Dong, Cot - iDem) == 0)
        {
            for (int iDem2 = 2; iDem2 < 7 && Cot - iDem2 >= 0; iDem2++)
            {
                //Nếu dưới trên ô trống là quân ta, iSoQuanTa2++; (Số quân ta 2) và thoát khỏi vòng lặp.
                if (getCheck(Dong, Cot - iDem2) == 1)
                {
                    iSoQuanTa2++;
                    break;
                }
                //Nếu phía dưới ô trống là quân địch, iSoQuanDich2++; (Số quân địch 2).
                if (getCheck(Dong, Cot - iDem2) == 0)
                    break;
                //Nếu phía dưới ô trống là ô trống, thoát khỏi vòng lặp.
                if (getCheck(Dong, Cot - iDem2) == -1)
                    iSoQuanDich2++;
            }
            //Thoát khỏi vòng lặp.
            break;
        }

    }
    //const long Defend_Score1[7] = { 0, 24, 3072, 196608, 12582912, 805306368 };
    //const long Attack_Score1[7] = { 0, 192, 24576, 1572864, 100663296, 6442450944 };
    //Giả sử X là quân ta, O là quân địch, E là ô trống, H là ô đang xét.

    //Cột: Đây là trường hợp 2 ô trên dưới của ô đang xét đầu là quân ta -> Thiên về tấn công -> Điểm phòng thủ của ô sẽ là 0.
    //Mô tả: ... X ... H ... X ...
    if (iSoQuanTa == 2)
        return 0;
    //Cột: 5 ô phía trên và 5 ô phía dưới ô đang xét không có bất kì ta nào (Trường hợp ưu tiên nhiều về phòng thủ) -> Điểm phòng thủ của ô phụ thuộc vào số quân địch trong khoảng đó.
    //Số điểm phòng thủ của ô cộng thêm Defend_Score[số quân địch]*2;
    if (iSoQuanTa == 0)
        iScoreTempNgang += Defend_Score[iSoQuanDich] * 2;
    //Cột: Tồn tại duy nhất 1 quân ta tại đầu trên hoặc đầu dưới tại ô đang xét.
    //Mô tả: ... X ... H ...... hoặc ...... H ... X ...
    //Số điểm phòng thủ phụ thuộc vào số quân địch trong khoảng đang xét. Số điểm phòng thủ của ô cộng thêm Defend_Score[số quân địch];
    else
        iScoreTempNgang += Defend_Score[iSoQuanDich];
    //Xét trên khoảng 10 ô xung quanh ô đang xét. Nếu số quân địch liền nhau nhiều hơn số quân địch trong khoảng đang xét nhưng không liền nhau thì:
    //Số điểm phòng của ô -1 (Ưu tiên trường hợp quân địch liền nhau).
    if (iSoQuanDich >= iSoQuanDich2)
        iScoreTempNgang -= 1;
    //Nếu những ô liền nhau ít hơn thì:
    //Số điểm phòng thủ của ô -2 (Không ưu tiên hơn trường hợp những ô quân địch liền nhau).
    else
        iScoreTempNgang -= 2;
    //Đât là trường hợp 4 quân địch liền nhau -> Ưu tiên phòng thủ lên mức cao độ nhất.
    //->Số điêm phòng thủ tăng nhanh. Số điểm phòng thủ của ô cộng nhân đôi.
    if (iSoQuanDich == 4)
        iScoreTempNgang *= 2;
    return iScoreTempNgang;
}
long SoDiemPhongThu_DuyetCheo1(long Dong, long Cot, const long Defend_Score[], const long Attack_Score[])
{
    long iScoreTempCheoNguoc = 0;
    long iScoreDefend = 0;
    int iSoQuanDich = 0;
    int iSoQuanTa = 0;
    int iSoQuanDich2 = 0;
    int iSoQuanTa2 = 0;
    for (int iDem = 1; iDem < 6 && Cot + iDem < SIZE && Dong + iDem < SIZE; iDem++)
    {
        if (getCheck(Dong + iDem, Cot + iDem) == 1)
        {
            iSoQuanTa++;
            break;
        }
        if (getCheck(Dong + iDem, Cot + iDem) == 0)
        {
            for (int iDem2 = 2; iDem2 < 7 && Cot + iDem2 < SIZE && Dong + iDem2 < SIZE; iDem2++)
            {
                if (getCheck(Dong + iDem2, Cot + iDem2) == 1)
                {
                    iSoQuanTa2++;
                    break;
                }
                if (getCheck(Dong + iDem2, Cot + iDem2) == 0)
                    break;
                if (getCheck(Dong + iDem2, Cot + iDem2) == -1)
                    iSoQuanDich2++;
            }
            break;
        }
        if (getCheck(Dong + iDem, Cot + iDem) == -1)
            iSoQuanDich++;
    }
    for (int iDem = 1; iDem < 6 && Cot - iDem >= 0 && Dong - iDem >= 0; iDem++)
    {
        if (getCheck(Dong - iDem, Cot - iDem) == 1)
        {
            iSoQuanTa++;
            break;
        }

        if (getCheck(Dong - iDem, Cot - iDem) == 0)
        {
            for (int iDem2 = 2; iDem2 < 7 && Cot - iDem2 >= 0 && Dong - iDem2 >= 0; iDem2++)
            {
                if (getCheck(Dong - iDem2, Cot - iDem2) == 1)
                {
                    iSoQuanTa2++;
                    break;
                }

                if (getCheck(Dong - iDem2, Cot - iDem2) == 0)
                    break;
                if (getCheck(Dong - iDem2, Cot - iDem2) == -1)
                    iSoQuanDich2++;
            }
            break;
        }
        if (getCheck(Dong - iDem, Cot - iDem) == -1)
            iSoQuanDich++;
    }
    if (iSoQuanTa == 2)
        return 0;
    if (iSoQuanTa == 0)
        iScoreTempCheoNguoc += Defend_Score[iSoQuanDich] * 2;
    else
        iScoreTempCheoNguoc += Defend_Score[iSoQuanDich];
    if (iSoQuanDich >= iSoQuanDich2)
        iScoreTempCheoNguoc -= 1;
    else
        iScoreTempCheoNguoc -= 2;
    if (iSoQuanDich == 4)
        iScoreTempCheoNguoc *= 2;
    return iScoreTempCheoNguoc;
}
long SoDiemPhongThu_DuyetCheo2(long Dong, long Cot, const long Defend_Score[], const long Attack_Score[])
{
    long iScoreTempCheoXuoi = 0;
    long iScoreDefend = 0;
    int iSoQuanDich = 0;
    int iSoQuanTa = 0;
    int iSoQuanDich2 = 0;
    int iSoQuanTa2 = 0;
    for (int iDem = 1; iDem < 6 && Cot - iDem >= 0 && Dong + iDem < SIZE; iDem++)
    {
        if (getCheck(Dong + iDem, Cot - iDem) == 1)
        {
            iSoQuanTa++;
            break;
        }
        if (getCheck(Dong + iDem, Cot - iDem) == 0)
        {
            for (int iDem2 = 2; iDem2 < 7 && Cot - iDem2 >= 0 && Dong + iDem2 < SIZE; iDem2++)
            {
                if (getCheck(Dong + iDem2, Cot - iDem2) == 1)
                {
                    iSoQuanTa2++;
                    break;
                }
                if (getCheck(Dong + iDem2, Cot - iDem2) == 0)
                    break;
                if (getCheck(Dong + iDem2, Cot - iDem2) == -1)
                    iSoQuanDich2++;
            }
            break;
        }
        if (getCheck(Dong + iDem, Cot - iDem) == -1)
            iSoQuanDich++;
    }
    for (int iDem = 1; iDem < 6 && Cot + iDem < SIZE && Dong - iDem >= 0; iDem++)
    {
        if (getCheck(Dong - iDem, Cot + iDem) == 1)
        {
            iSoQuanTa++;
            break;
        }
        if (getCheck(Dong - iDem, Cot + iDem) == 0)
        {
            for (int iDem2 = 2; iDem < 7 && Cot + iDem2 < SIZE && Dong - iDem2 >= 0; iDem2++)
            {
                if (getCheck(Dong - iDem2, Cot + iDem2) == 1)
                {
                    iSoQuanTa2++;
                    break;
                }
                if (getCheck(Dong - iDem2, Cot + iDem2) == 0)
                    break;
                if (getCheck(Dong - iDem2, Cot + iDem2) == -1)
                    iSoQuanDich2++;
            }
            break;
        }
        if (getCheck(Dong - iDem, Cot + iDem) == -1)
            iSoQuanDich++;
    }

    if (iSoQuanTa == 2)
        return 0;
    if (iSoQuanTa == 0)
        iScoreTempCheoXuoi += Defend_Score[iSoQuanDich] * 2;
    else
        iScoreTempCheoXuoi += Defend_Score[iSoQuanDich];
    if (iSoQuanDich >= iSoQuanDich2)
        iScoreTempCheoXuoi -= 1;
    else
        iScoreTempCheoXuoi -= 2;
    if (iSoQuanDich == 4)
        iScoreTempCheoXuoi *= 2;
    return iScoreTempCheoXuoi;
}


void Tim_Kiem_NuocDi_1()
{
    //Đây là điểm tại ô mà ta đang xét trên bàn cờ.

    int dong = 0, cot = 0;
    //Ta sẽ dùng biến 'Diem' để tìm ra ô có điểm số cao nhất, ô nào có điểm số cao nhất sẽ được đánh X vào.
    long Diem = 0;
    //Dùng vòng lặp chay qua tất cả các ô trên bàn cờ.
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            //Đặt điểm tấn công, điểm phòng thủ cho tất cả các ô này ban đầu bằng 0.
            long DiemTanCong = 0;
            long DiemPhongThu = 0;
            //Vì ta chỉ có thể tấn công hay phòng thủ ở những ô đang trống, lọc lấy những ô trống bằng dòng code _pArr[i][j].getCheck() == 0;
            if (getCheck(i, j) == 0)
            {
                
                //Tính số điểm tấn công của ô trống bằng tổng tất cả số điểm tấn công của ô theo hàng, theo cột, theo đường chéo 1 và theo đường chéo 2.
                //Số điểm tấn công của ô theo cột.
                DiemTanCong += SoDiemTanCong_DuyetDoc(i, j, Defend_Score1, Attack_Score1);
                //Số điểm tấn công của ô theo hàng.
                DiemTanCong += SoDiemTanCong_DuyetNgang(i, j, Defend_Score1, Attack_Score1);
                //Số điểm tấn công của ô theo đường chéo 1.
                DiemTanCong += SoDiemTanCong_DuyetCheo1(i, j, Defend_Score1, Attack_Score1);
                //Số điểm tấn công của ô theo đường chéo 2.
                DiemTanCong += SoDiemTanCong_DuyetCheo2(i, j, Defend_Score1, Attack_Score1);
                //Tính số điểm phòng thủ của ô trống bằng tổng tất cả số điểm phòng thủ của ô theo hàng, theo cột, theo đường chéo 1 và theo đường chéo 2.
                //Số điểm phòng thủ của ô theo cột.
                DiemPhongThu += SoDiemPhongThu_DuyetDoc(i, j, Defend_Score1, Attack_Score1);
                //Số điểm phòng thủ của ô theo hàng.
                DiemPhongThu += SoDiemPhongThu_DuyetNgang(i, j, Defend_Score1, Attack_Score1);
                //Số điểm phòng thủ của ô theo đường chéo 1.
                DiemPhongThu += SoDiemPhongThu_DuyetCheo1(i, j, Defend_Score1, Attack_Score1);
                //Số điểm phòng thủ của ô theo đường chéo 2.
                DiemPhongThu += SoDiemPhongThu_DuyetCheo2(i, j, Defend_Score1, Attack_Score1);
                //Tại ô đang xét, nếu điểm tấn công lớn hơn điểm phòng thủ của ô
                if (DiemTanCong > DiemPhongThu)
                {
                    //Nếu điểm nhỏ hơn điểm tấn công thì gán điểm có giá trị mới bằng giá trị của điểm tấn công của ô đang xét.
                    if (Diem < DiemTanCong)
                    {
                        //Gán giá trị mới cho điểm.
                        Diem = DiemTanCong;
                        //Lấy ra dòng cần đánh vào quân X.
                        dong = i;
                        //Lấy ra cột cần đánh vào quân X.
                        cot = j;
                    }
                }
                //Ngược lại, nếu tại ô đang xét, điểm phòng thủ lớn hơn điểm tấn công của ô.
                else
                {
                    //Nếu điểm nhỏ hơn điểm phòng thủ thì gán điểm có giá trị mới bằng giá trị của điểm phòng thủ của ô đang xét.
                    if (Diem < DiemPhongThu)
                    {
                        //Gán giá trị mới cho điểm.
                        Diem = DiemPhongThu;
                        //Lấy ra dòng cần đánh vào quân X.
                        dong = i;
                        //Lấy ra cột cần đánh vào quân X.
                        cot = j;
                    }
                }
            }
        }
    }
    //Đánh X vào ô có điểm cao nhất (Ô mà tại đó biến 'Diem' có giá trị cao nhất).

    //Đánh Y vào ô có điểm cao nhất (Ô mà tại đó biến 'Diem' có giá trị cao nhất).
    board[dong][cot].c = 'X';
    bestMoveX = dong;
    bestMoveY = cot;
}

int main() {
    
    initializeBoard();
    system("color F0");
    DrawBoard();
    printBoard();
    

    while (true) {
        Tim_Kiem_NuocDi_1();
        printBoard();
        if (checkWin(bestMoveX, bestMoveY, 'X')) {
            gotoxy(0, SIZE + 4);
            cout << "Computer wins!" << endl;
            break;
        }
        char move;
        while (true) {
            
            gotoxy(cursorY, cursorX);
            CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
            GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
            WORD saved_attributes = consoleInfo.wAttributes;
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | (saved_attributes & 0x00F0));
            cout << 'O';
           
            

            move = _getch();
            gotoxy(cursorY, cursorX);
            cout << board[cursorX][cursorY].c;
            SetConsoleTextAttribute(hConsole, saved_attributes);
 
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
            break;
        }
        
        
        
        
        if (isDraw()) {
            gotoxy(0, SIZE + 4);
            cout << "It's a draw!" << endl;
            break;
        }
    }
    return 0;
}