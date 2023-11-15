#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
#include <thread>
#include <chrono>
#include <vector>
#include <cmath>
#include<iostream>
#include<windows.h>
#include<conio.h>
#include"Textfile.h"
#include "PlayervsPlayer.h"
using namespace std;



void KhungGiaoDien() {
    system("color F0");
    Textcolor(245);
    for (int i = 0; i <= 28; i++)
    {
        GotoXY(60, i);
        cout << char(186);
    }
    for (int i = 0; i <= 58; i++)
    {
        GotoXY(61 + i, 1);
        cout << char(205);
    }
    for (int i = 0; i <= 28; i++)
    {
        GotoXY(120, i);
        cout << char(186);
    }
    GotoXY(87, 1);
    Textcolor(246);
    cout << " TI SO ";
    GotoXY(70, 3);
    Textcolor(240);
    cout << "PLAYER X                         PLAYER O";
    Textcolor(245);
    for (int i = 0; i <= 8; i++)
    {
        GotoXY(90, 2 + i);
        cout << char(186);
    }
    for (int i = 0; i <= 58; i++)
    {
        GotoXY(61 + i, 10);
        cout << char(205);
    }
    Textcolor(246);
    GotoXY(86, 10);
    cout << " LUOT DI ";
    Textcolor(245);
    for (int i = 0; i <= 58; i++)
    {
        GotoXY(61 + i, 20);
        cout << char(205);
    }
    for (int i = 0; i <= 120; i++)
    {
        GotoXY(0 + i, 29);
        cout << char(205);
    }
    GotoXY(85, 20);
    Textcolor(246);
    cout << " HUONG DAN ";
    Textcolor(241);
    GotoXY(74, 23); cout << "W : " << char(30) << "    S : " << char(31) << "    D : " << char(16) << "    A : " << char(17);

    Textcolor(240);
    GotoXY(74, 25); cout << "Enter : Chon vi tri danh X hoac O";
    GotoXY(74, 27); cout << "ESC : Nhan de thoat";
}
void DrawBoardAbout(int pSize,float Left ,float Top) {
    system("color F0");

    GotoXY(Left, Top);
    printf_s("%c", 218);
    printf_s("%c%c%c", 196, 196, 196);
    GotoXY(Left + 4 * pSize, Top);
    printf_s("%c", 191);
    for (int i = 1; i < pSize; i++) {

        GotoXY(Left + 4 * i, Top);
        printf_s("%c%c%c%c", 196, 196, 196, 196);
    }
    GotoXY(Left + 4 * pSize, Top);
    printf_s("%c", 191);
    printf_s("\n");
    for (int j = 1; j < 2 * pSize; j++) {
        GotoXY(Left, Top + j);
        printf_s("%c", 179);


    }
    GotoXY(Left, Top + 2 * pSize);
    printf_s("%c", 192);
    printf_s("%c%c%c", 196, 196, 196);
    GotoXY(Left + 4 * pSize, Top + 2 * pSize);
    printf_s("%c", 217);

    for (int i = 1; i < pSize; i++) {

        GotoXY(Left + 4 * i, Top + 2 * pSize);
        printf_s("%c%c%c%c", 196, 196, 196, 196);
    }
    for (int j = 1; j < 2 * pSize; j++) {
        GotoXY(Left + 4 * pSize, Top + j);
        printf_s("%c", 179);

    }
    GotoXY(Left, Top + 2 * pSize);
    cout << (char)192;
    for (int i = 1; i < pSize; i++) {

        GotoXY(Left + 4 * i, Top + 2 * pSize);
        printf_s("%c%c%c%c", 196, 196, 196, 196);
    }
    GotoXY(Left + 4 * pSize, Top + 2 * pSize);
    cout << (char)217;
    system("color F0");
}

// Hàm để thay đổi màu sắc theo chu kỳ
std::string getDynamicColor(int frameIndex) {
    return COLORS[frameIndex % COLORS.size()];
}

// Hàm để tạo hiệu ứng đi lên và xuống
std::string applyVerticalMotion(const std::string& frame, int frameIndex, float n) {
    int motion = static_cast<int>((std::sin(frameIndex / n) + 1) * int(n)); // Tạo hiệu ứng di chuyển mượt mà
    return std::string(motion, '\n') + frame;
}

void Textdecorate(std::string filename, float n,int i) {
    std::string line;
    std::ifstream file(filename);
    std::vector<std::string> frames;
    int frameIndex = 0;
    
    if (file.is_open()) {
        while (getline(file, line)) {
            if (line == "###") {
                frames.push_back("");
                continue;
            }
            if (!frames.empty()) {
                frames.back() += line + "\n";

            }
        }
        file.close();
    }
    else {
        std::cout << "Không thể mở tệp!" << std::endl;

    }
    
    while (i) {
        system("color F0");
        i--;
        system("cls");
        std::string frame = frames[frameIndex % frames.size()];
        frame = applyVerticalMotion(frame, frameIndex, n); // Áp dụng hiệu ứng di chuyển
        std::string color = getDynamicColor(frameIndex); // Lấy màu sắc hiện tại

        std::cout << color;
        std::cout << frame;
        std::cout << RESET_COLOR;

        std::this_thread::sleep_for(std::chrono::milliseconds(150));
        frameIndex++;
    }
    file.close();
}
void In_Tep(const char* FileName) {
    FILE* file;

    if (fopen_s(&file, FileName, "r") != 0) {
        cout << "Khong the mo tep" << endl;
        return;
    }
    char buffer[1000];
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        cout << buffer;
    }
    fclose(file);
}
void DRAW() {
    Textdecorate("DRAW.txt", 3.0, 10);
}
void COMPUTERWIN() {
    Textdecorate("BOTWIN.txt", 3.0, 10);
}
void YOUWIN() {
    Textdecorate("YOUWIN.txt", 3.0, 10);
}
