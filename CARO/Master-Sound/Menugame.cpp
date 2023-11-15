#include "_Play.h"
#include <vector>
#include <Windows.h>
#include <mmsystem.h>
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include "PlayervsPlayer.h"
#include "Loadingbar.h"
using namespace std;
#pragma comment(lib, "winmm.lib")//Kien them
void playSound(int i); bool isSoundOn = true;

void AnTroChuot()
{
    CONSOLE_CURSOR_INFO Info;
    Info.bVisible = FALSE;
    Info.dwSize = 20;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}
void HienTroChuot()
{
    CONSOLE_CURSOR_INFO Info;
    Info.bVisible = TRUE;
    Info.dwSize = 20;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}
void Screen()
{
    int check = 1;
    while (check < 20)
    {
        PrintCaro();
        Sleep(100);
        check++;
    }
}
void About()
{
    system("cls");
    PrintCaro3();
    Textcolor(Cyan);
    _Common::gotoXY(60, 18);
    cout << "ABOUT";
    _Common::gotoXY(50, 21);
    cout << "DO AN GAME CARO - LOPTNT1  - HCMUS" << endl;
    _Common::gotoXY(50, 22);
    cout << "-> MSSV   : 23122041." << endl;
    _Common::gotoXY(50, 23);
    cout << "-> Ho ten :DuyMinh/Mylinh/PhuQuy/TrungKien ." << endl;
    _Common::gotoXY(50, 24);
    cout << "-> Lop    : TNT1." << endl;
    _Common::gotoXY(50, 25);
    cout << "-> GV huong dan : Truong Toan Thinh " << endl;

    _Common::gotoXY(50, 26);
    cout << "!!" << endl;
    _Common::gotoXY(60, 30);
    cout << "BACK";
    char command = ' ';
    command = _getch();
    system("cls");
}
struct Name {
    char data[30];
};
vector <Name> ch;

void Textcolor(int color)
{
    HANDLE hConsoleColor;
    hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsoleColor, color);
}


void PrintCaro()
{
    int x = 25, y = 0;
    Textcolor(rand() % 15 + 1);
    _Common::gotoXY(x, y);				   cout << "ooooooooooooo";
    _Common::gotoXY(x - 3, y + 1);			cout << "oooooooooooooooo";
    _Common::gotoXY(x - 5, y + 2);    cout << "oooooooooooooooooo";
    _Common::gotoXY(x - 6, y + 3);   cout << "ooooooooooooooooooo";
    Textcolor(rand() % 15 + 1);
    _Common::gotoXY(x - 7, y + 4);  cout << "ooooooo";
    _Common::gotoXY(x - 8, y + 5); cout << "ooooooo";
    _Common::gotoXY(x - 8, y + 6); cout << "ooooooo";
    _Common::gotoXY(x - 8, y + 7); cout << "ooooooo";
    _Common::gotoXY(x - 8, y + 8); cout << "ooooooo";
    _Common::gotoXY(x - 8, y + 9); cout << "ooooooo";
    Textcolor(rand() % 15 + 1);
    _Common::gotoXY(x - 8, y + 10); cout << "ooooooo";
    _Common::gotoXY(x - 7, y + 11); cout << "ooooooo";
    _Common::gotoXY(x - 6, y + 12);  cout << "ooooooooooooooooooo";
    _Common::gotoXY(x - 5, y + 13);   cout << "oooooooooooooooooo";
    Textcolor(rand() % 15 + 1);
    _Common::gotoXY(x - 3, y + 14);		cout << "oooooooooooooooo";
    _Common::gotoXY(x, y + 15);			   cout << "ooooooooooooo";
    Textcolor(rand() % 15 + 1);
    _Common::gotoXY(x - 4 + 22, y + 4);				    cout << "ooooooooooo";
    _Common::gotoXY(x - 4 + 22 - 2, y + 5);		      cout << "ooooooooooooooo";
    _Common::gotoXY(x - 4 + 22 - 3, y + 6);		     cout << "ooooooooooooooooo";
    Textcolor(rand() % 15 + 1);
    _Common::gotoXY(x - 4 + 22 - 3, y + 7);			 cout << "ooooooooooooooooo";
    _Common::gotoXY(x - 4 + 22 - 3, y + 8);			 cout << "oooooo     oooooo";
    _Common::gotoXY(x - 4 + 22 - 3, y + 9);			 cout << "oooooo     oooooo";
    Textcolor(rand() % 15 + 1);
    _Common::gotoXY(x - 4 + 22 - 3, y + 10);		 cout << "oooooo     oooooo";
    _Common::gotoXY(x - 4 + 22 - 3, y + 11);		 cout << "ooooooooooooooooo";
    _Common::gotoXY(x - 4 + 22 - 3, y + 12);		 cout << "oooooo     oooooo";
    Textcolor(rand() % 15 + 1);
    _Common::gotoXY(x - 4 + 22 - 3, y + 13);		 cout << "oooooo     oooooo";
    _Common::gotoXY(x - 4 + 22 - 3, y + 14);		 cout << "oooooo     oooooo";
    _Common::gotoXY(x - 4 + 22 - 3, y + 15);		 cout << "oooooo     oooooo";

    Textcolor(rand() % 15 + 1);

    _Common::gotoXY(x + 33, y + 4);			cout << "ooooo   ooooooooo";
    _Common::gotoXY(x + 33, y + 5);			cout << "oooooooooooooooooo";
    _Common::gotoXY(x + 33, y + 6);			cout << "ooooooooooooooooooo";
    Textcolor(rand() % 15 + 1);
    _Common::gotoXY(x + 33, y + 7);			cout << "oooooooooooooooooooo";
    _Common::gotoXY(x + 1 + 33, y + 8);			 cout << "ooooooo     ooooooo";
    _Common::gotoXY(x + 1 + 33, y + 9);			 cout << "ooooooo     ooooooo";
    Textcolor(rand() % 15 + 1);
    _Common::gotoXY(x + 1 + 33, y + 10);		 cout << "ooooooo";
    _Common::gotoXY(x + 1 + 33, y + 11);		 cout << "ooooooo";
    _Common::gotoXY(x + 1 + 33, y + 12);		 cout << "ooooooo";
    Textcolor(rand() % 15 + 1);
    _Common::gotoXY(x + 1 + 33, y + 13);		 cout << "ooooooo";
    _Common::gotoXY(x + 1 + 33, y + 14);		 cout << "ooooooo";
    _Common::gotoXY(x + 1 + 33, y + 15);		 cout << "ooooooo";
    // Textcolor(Yellow);
    _Common::gotoXY(x + 57, y + 4);					cout << "ooooooooooo";
    _Common::gotoXY(x + 57 - 2, y + 5);			  cout << "ooooooooooooooo";
    Textcolor(rand() % 15 + 1);
    _Common::gotoXY(x + 57 - 3, y + 6);			 cout << "ooooooooooooooooo";
    _Common::gotoXY(x + 57 - 3, y + 7);			 cout << "ooooooooooooooooo";
    Textcolor(rand() % 15 + 1);
    _Common::gotoXY(x + 57 - 3, y + 8);			 cout << "oooooo     oooooo";
    _Common::gotoXY(x + 57 - 3, y + 9);			 cout << "oooooo     oooooo";
    _Common::gotoXY(x + 57 - 3, y + 10);		 cout << "oooooo     oooooo";
    _Common::gotoXY(x + 57 - 3, y + 11);		 cout << "oooooo     oooooo";
    Textcolor(rand() % 15 + 1);
    _Common::gotoXY(x + 57 - 3, y + 12);		 cout << "ooooooooooooooooo";
    _Common::gotoXY(x + 57 - 3, y + 13);		 cout << "ooooooooooooooooo";
    Textcolor(rand() % 15 + 1);
    _Common::gotoXY(x + 57 - 2, y + 14);		  cout << "ooooooooooooooo";
    _Common::gotoXY(x + 57, y + 15);				cout << "ooooooooooo";



}
void PrintCaro2()
{
    int x = 25, y = 0;
    Sleep(200);
    Textcolor(Red);
    _Common::gotoXY(x, y);				   cout << "ooooooooooooo";
    _Common::gotoXY(x - 3, y + 1);			cout << "oooooooooooooooo";
    _Common::gotoXY(x - 5, y + 2);    cout << "oooooooooooooooooo";
    _Common::gotoXY(x - 6, y + 3);   cout << "ooooooooooooooooooo";
    _Common::gotoXY(x - 7, y + 4);  cout << "ooooooo";
    _Common::gotoXY(x - 8, y + 5); cout << "ooooooo";
    _Common::gotoXY(x - 8, y + 6); cout << "ooooooo";
    _Common::gotoXY(x - 8, y + 7); cout << "ooooooo";
    _Common::gotoXY(x - 8, y + 8); cout << "ooooooo";
    _Common::gotoXY(x - 8, y + 9); cout << "ooooooo";
    _Common::gotoXY(x - 8, y + 10); cout << "ooooooo";
    _Common::gotoXY(x - 7, y + 11); cout << "ooooooo";
    _Common::gotoXY(x - 6, y + 12);  cout << "ooooooooooooooooooo";
    _Common::gotoXY(x - 5, y + 13);   cout << "oooooooooooooooooo";
    _Common::gotoXY(x - 3, y + 14);		cout << "oooooooooooooooo";
    _Common::gotoXY(x, y + 15);			   cout << "ooooooooooooo";
    Sleep(200);
    Textcolor(Green);
    _Common::gotoXY(x - 4 + 22, y + 4);				    cout << "ooooooooooo";
    _Common::gotoXY(x - 4 + 22 - 2, y + 5);		      cout << "ooooooooooooooo";
    _Common::gotoXY(x - 4 + 22 - 3, y + 6);		     cout << "ooooooooooooooooo";
    _Common::gotoXY(x - 4 + 22 - 3, y + 7);			 cout << "ooooooooooooooooo";
    _Common::gotoXY(x - 4 + 22 - 3, y + 8);			 cout << "oooooo     oooooo";
    _Common::gotoXY(x - 4 + 22 - 3, y + 9);			 cout << "oooooo     oooooo";
    _Common::gotoXY(x - 4 + 22 - 3, y + 10);		 cout << "oooooo     oooooo";
    _Common::gotoXY(x - 4 + 22 - 3, y + 11);		 cout << "ooooooooooooooooo";
    _Common::gotoXY(x - 4 + 22 - 3, y + 12);		 cout << "oooooo     oooooo";
    _Common::gotoXY(x - 4 + 22 - 3, y + 13);		 cout << "oooooo     oooooo";
    _Common::gotoXY(x - 4 + 22 - 3, y + 14);		 cout << "oooooo     oooooo";
    _Common::gotoXY(x - 4 + 22 - 3, y + 15);		 cout << "oooooo     oooooo";
    Sleep(200);
    Textcolor(Blue);

    _Common::gotoXY(x + 33, y + 4);			cout << "ooooo   ooooooooo";
    _Common::gotoXY(x + 33, y + 5);			cout << "oooooooooooooooooo";
    _Common::gotoXY(x + 33, y + 6);			cout << "ooooooooooooooooooo";
    _Common::gotoXY(x + 33, y + 7);			cout << "oooooooooooooooooooo";
    _Common::gotoXY(x + 1 + 33, y + 8);			 cout << "ooooooo     ooooooo";
    _Common::gotoXY(x + 1 + 33, y + 9);			 cout << "ooooooo     ooooooo";
    _Common::gotoXY(x + 1 + 33, y + 10);		 cout << "ooooooo";
    _Common::gotoXY(x + 1 + 33, y + 11);		 cout << "ooooooo";
    _Common::gotoXY(x + 1 + 33, y + 12);		 cout << "ooooooo";
    _Common::gotoXY(x + 1 + 33, y + 13);		 cout << "ooooooo";
    _Common::gotoXY(x + 1 + 33, y + 14);		 cout << "ooooooo";
    _Common::gotoXY(x + 1 + 33, y + 15);		 cout << "ooooooo";
    Sleep(200);
    Textcolor(Yellow);
    _Common::gotoXY(x + 57, y + 4);					cout << "ooooooooooo";
    _Common::gotoXY(x + 57 - 2, y + 5);			  cout << "ooooooooooooooo";
    _Common::gotoXY(x + 57 - 3, y + 6);			 cout << "ooooooooooooooooo";
    _Common::gotoXY(x + 57 - 3, y + 7);			 cout << "ooooooooooooooooo";
    _Common::gotoXY(x + 57 - 3, y + 8);			 cout << "oooooo     oooooo";
    _Common::gotoXY(x + 57 - 3, y + 9);			 cout << "oooooo     oooooo";
    _Common::gotoXY(x + 57 - 3, y + 10);		 cout << "oooooo     oooooo";
    _Common::gotoXY(x + 57 - 3, y + 11);		 cout << "oooooo     oooooo";
    _Common::gotoXY(x + 57 - 3, y + 12);		 cout << "ooooooooooooooooo";
    _Common::gotoXY(x + 57 - 3, y + 13);		 cout << "ooooooooooooooooo";
    _Common::gotoXY(x + 57 - 2, y + 14);		  cout << "ooooooooooooooo";
    _Common::gotoXY(x + 57, y + 15);				cout << "ooooooooooo";
    Textcolor(defaultColor);
}
void PrintCaro3()
{
    int x = 25, y = 0;
    Textcolor(Red);
    _Common::gotoXY(x, y);				   cout << "ooooooooooooo";
    _Common::gotoXY(x - 3, y + 1);			cout << "oooooooooooooooo";
    _Common::gotoXY(x - 5, y + 2);    cout << "oooooooooooooooooo";
    _Common::gotoXY(x - 6, y + 3);   cout << "ooooooooooooooooooo";
    _Common::gotoXY(x - 7, y + 4);  cout << "ooooooo";
    _Common::gotoXY(x - 8, y + 5); cout << "ooooooo";
    _Common::gotoXY(x - 8, y + 6); cout << "ooooooo";
    _Common::gotoXY(x - 8, y + 7); cout << "ooooooo";
    _Common::gotoXY(x - 8, y + 8); cout << "ooooooo";
    _Common::gotoXY(x - 8, y + 9); cout << "ooooooo";
    _Common::gotoXY(x - 8, y + 10); cout << "ooooooo";
    _Common::gotoXY(x - 7, y + 11); cout << "ooooooo";
    _Common::gotoXY(x - 6, y + 12);  cout << "ooooooooooooooooooo";
    _Common::gotoXY(x - 5, y + 13);   cout << "oooooooooooooooooo";
    _Common::gotoXY(x - 3, y + 14);		cout << "oooooooooooooooo";
    _Common::gotoXY(x, y + 15);			   cout << "ooooooooooooo";
    Textcolor(Green);
    _Common::gotoXY(x - 4 + 22, y + 4);				    cout << "ooooooooooo";
    _Common::gotoXY(x - 4 + 22 - 2, y + 5);		      cout << "ooooooooooooooo";
    _Common::gotoXY(x - 4 + 22 - 3, y + 6);		     cout << "ooooooooooooooooo";
    _Common::gotoXY(x - 4 + 22 - 3, y + 7);			 cout << "ooooooooooooooooo";
    _Common::gotoXY(x - 4 + 22 - 3, y + 8);			 cout << "oooooo     oooooo";
    _Common::gotoXY(x - 4 + 22 - 3, y + 9);			 cout << "oooooo     oooooo";
    _Common::gotoXY(x - 4 + 22 - 3, y + 10);		 cout << "oooooo     oooooo";
    _Common::gotoXY(x - 4 + 22 - 3, y + 11);		 cout << "ooooooooooooooooo";
    _Common::gotoXY(x - 4 + 22 - 3, y + 12);		 cout << "oooooo     oooooo";
    _Common::gotoXY(x - 4 + 22 - 3, y + 13);		 cout << "oooooo     oooooo";
    _Common::gotoXY(x - 4 + 22 - 3, y + 14);		 cout << "oooooo     oooooo";
    _Common::gotoXY(x - 4 + 22 - 3, y + 15);		 cout << "oooooo     oooooo";
    Textcolor(Blue);

    _Common::gotoXY(x + 33, y + 4);			cout << "ooooo   ooooooooo";
    _Common::gotoXY(x + 33, y + 5);			cout << "oooooooooooooooooo";
    _Common::gotoXY(x + 33, y + 6);			cout << "ooooooooooooooooooo";
    _Common::gotoXY(x + 33, y + 7);			cout << "oooooooooooooooooooo";
    _Common::gotoXY(x + 1 + 33, y + 8);			 cout << "ooooooo     ooooooo";
    _Common::gotoXY(x + 1 + 33, y + 9);			 cout << "ooooooo     ooooooo";
    _Common::gotoXY(x + 1 + 33, y + 10);		 cout << "ooooooo";
    _Common::gotoXY(x + 1 + 33, y + 11);		 cout << "ooooooo";
    _Common::gotoXY(x + 1 + 33, y + 12);		 cout << "ooooooo";
    _Common::gotoXY(x + 1 + 33, y + 13);		 cout << "ooooooo";
    _Common::gotoXY(x + 1 + 33, y + 14);		 cout << "ooooooo";
    _Common::gotoXY(x + 1 + 33, y + 15);		 cout << "ooooooo";
    Textcolor(Yellow);
    _Common::gotoXY(x + 57, y + 4);					cout << "ooooooooooo";
    _Common::gotoXY(x + 57 - 2, y + 5);			  cout << "ooooooooooooooo";
    _Common::gotoXY(x + 57 - 3, y + 6);			 cout << "ooooooooooooooooo";
    _Common::gotoXY(x + 57 - 3, y + 7);			 cout << "ooooooooooooooooo";
    _Common::gotoXY(x + 57 - 3, y + 8);			 cout << "oooooo     oooooo";
    _Common::gotoXY(x + 57 - 3, y + 9);			 cout << "oooooo     oooooo";
    _Common::gotoXY(x + 57 - 3, y + 10);		 cout << "oooooo     oooooo";
    _Common::gotoXY(x + 57 - 3, y + 11);		 cout << "oooooo     oooooo";
    _Common::gotoXY(x + 57 - 3, y + 12);		 cout << "ooooooooooooooooo";
    _Common::gotoXY(x + 57 - 3, y + 13);		 cout << "ooooooooooooooooo";
    _Common::gotoXY(x + 57 - 2, y + 14);		  cout << "ooooooooooooooo";
    _Common::gotoXY(x + 57, y + 15);				cout << "ooooooooooo";
    Textcolor(defaultColor);

}


void ScreenStartGame(int n) {

    AnTroChuot();
    int x = 50, y = 20;
    //int i;
    char s[30] = " ";
    int check = 1;
    Textcolor(Red);
    _Common::gotoXY(50, 20); cout << "Player Vs Player";
    Textcolor(15);
    _Common::gotoXY(50, 21); cout << "Player Vs Computer (Easy)";
    _Common::gotoXY(50, 22); cout << "Player Vs Computer (Hard)";
    _Common::gotoXY(50, 23); cout << "Load Game";
    _Common::gotoXY(50, 24); cout << "Help";
    _Common::gotoXY(50, 25); cout << "About";
    _Common::gotoXY(50, 26); cout << "Exit";
    _Common::gotoXY(50, 32); cout << "....... W - S : Move  ";
    _Common::gotoXY(50, 33); cout << "....... Enter : Select ";
    _Common::gotoXY(50, 34); cout << ".......   M   : Mute ";
    if (n == 100)
    {
        // PlaySound(TEXT("nhacnen.wav"), NULL, SND_FILENAME | SND_ASYNC);
        Screen();
        PrintCaro2();
    }
    else
        PrintCaro3();

    while (check)
    {
        if (_kbhit())
        {
            switch (_getch())
            {
            case 'm':SOUND_ON++;
                if (SOUND_ON > 1) SOUND_ON = 0;

                if (SOUND_ON != 1)
                {
                    isSoundOn = false;
                    PlaySound(0, 0, 0);
                }
                else if (SOUND_ON == 1) {
                    isSoundOn = true;
                    playSound(2);
                }break;
            case 'w':
                //  PlaySound(TEXT("move.wav"), NULL, SND_FILENAME | SND_ASYNC);
                playSound(1);
                if (y > 20)
                {
                    y--;
                    _Common::gotoXY(x, y);
                }
                if (y == 20)
                {
                    Textcolor(Red);
                    _Common::gotoXY(50, 20); cout << "Player Vs Player";
                    Textcolor(7);
                    _Common::gotoXY(50, 21); cout << "Player Vs Computer (Easy)";
                    _Common::gotoXY(50, 22); cout << "Player Vs Computer (Hard)";
                    _Common::gotoXY(50, 23); cout << "Load Game";
                    _Common::gotoXY(50, 24); cout << "Help";
                    _Common::gotoXY(50, 25); cout << "About";
                    _Common::gotoXY(50, 26); cout << "Exit";
                }
                if (y == 21)
                {
                    Textcolor(7);
                    _Common::gotoXY(50, 20); cout << "Player Vs Player";
                    Textcolor(Red);
                    _Common::gotoXY(50, 21); cout << "Player Vs Computer (Easy)";
                    Textcolor(7);
                    _Common::gotoXY(50, 22); cout << "Player Vs Computer (Hard)";
                    _Common::gotoXY(50, 23); cout << "Load Game";
                    _Common::gotoXY(50, 24); cout << "Help";
                    _Common::gotoXY(50, 25); cout << "About";
                    _Common::gotoXY(50, 26); cout << "Exit";
                }
                if (y == 22)
                {
                    Textcolor(7);
                    _Common::gotoXY(50, 20); cout << "Player Vs Player";
                    _Common::gotoXY(50, 21); cout << "Player Vs Computer (Easy)";
                    Textcolor(Red);
                    _Common::gotoXY(50, 22); cout << "Player Vs Computer (Hard)";
                    Textcolor(7);
                    _Common::gotoXY(50, 23); cout << "Load Game";
                    _Common::gotoXY(50, 24); cout << "Help";
                    _Common::gotoXY(50, 25); cout << "About";
                    _Common::gotoXY(50, 26); cout << "Exit";
                }
                if (y == 23)
                {
                    Textcolor(7);
                    _Common::gotoXY(50, 20); cout << "Player Vs Player";
                    _Common::gotoXY(50, 21); cout << "Player Vs Computer (Easy)";
                    _Common::gotoXY(50, 22); cout << "Player Vs Computer (Hard)";
                    Textcolor(Red);
                    _Common::gotoXY(50, 23); cout << "Load Game";
                    Textcolor(7);
                    _Common::gotoXY(50, 24); cout << "Help";
                    _Common::gotoXY(50, 25); cout << "About";
                    _Common::gotoXY(50, 26); cout << "Exit";
                }
                if (y == 24)
                {
                    Textcolor(7);
                    _Common::gotoXY(50, 20); cout << "Player Vs Player";
                    _Common::gotoXY(50, 21); cout << "Player Vs Computer (Easy)";
                    _Common::gotoXY(50, 22); cout << "Player Vs Computer (Hard)";
                    _Common::gotoXY(50, 23); cout << "Load Game";
                    Textcolor(Red);
                    _Common::gotoXY(50, 24); cout << "Help";
                    Textcolor(7);
                    _Common::gotoXY(50, 25); cout << "About";
                    _Common::gotoXY(50, 26); cout << "Exit";
                }
                if (y == 25)
                {
                    Textcolor(7);
                    _Common::gotoXY(50, 20); cout << "Player Vs Player";
                    _Common::gotoXY(50, 21); cout << "Player Vs Computer (Easy)";
                    _Common::gotoXY(50, 22); cout << "Player Vs Computer (Hard)";
                    _Common::gotoXY(50, 23); cout << "Load Game";
                    _Common::gotoXY(50, 24); cout << "Help";
                    Textcolor(Red);
                    _Common::gotoXY(50, 25); cout << "About";
                    Textcolor(7);
                    _Common::gotoXY(50, 26); cout << "Exit";
                }
                if (y == 26)
                {
                    Textcolor(7);
                    _Common::gotoXY(50, 20); cout << "Player Vs Player";
                    _Common::gotoXY(50, 21); cout << "Player Vs Computer (Easy)";
                    _Common::gotoXY(50, 22); cout << "Player Vs Computer (Hard)";
                    _Common::gotoXY(50, 23); cout << "Load Game";
                    _Common::gotoXY(50, 24); cout << "Help";
                    Textcolor(Red);
                    _Common::gotoXY(50, 25); cout << "About";
                    Textcolor(7);
                    _Common::gotoXY(50, 26); cout << "Exit";
                }
                break;
            case 's':
                // PlaySound(TEXT("move.wav"), NULL, SND_FILENAME | SND_ASYNC);
                playSound(1);
                if (y < 26)
                {
                    y++;
                    _Common::gotoXY(x, y);
                }
                if (y == 20)
                {
                    Textcolor(Red);
                    _Common::gotoXY(50, 20); cout << "Player Vs Player";
                    Textcolor(7);
                    _Common::gotoXY(50, 21); cout << "Player Vs Computer (Easy)";
                    _Common::gotoXY(50, 22); cout << "Player Vs Computer (Hard)";
                    _Common::gotoXY(50, 23); cout << "Load Game";
                    _Common::gotoXY(50, 24); cout << "Help";
                    _Common::gotoXY(50, 25); cout << "About";
                    _Common::gotoXY(50, 26); cout << "Exit";
                }
                if (y == 21)
                {
                    Textcolor(7);
                    _Common::gotoXY(50, 20); cout << "Player Vs Player";
                    Textcolor(Red);
                    _Common::gotoXY(50, 21); cout << "Player Vs Computer (Easy)";
                    Textcolor(7);
                    _Common::gotoXY(50, 22); cout << "Player Vs Computer (Hard)";
                    _Common::gotoXY(50, 23); cout << "Load Game";
                    _Common::gotoXY(50, 24); cout << "Help";
                    _Common::gotoXY(50, 25); cout << "About";
                    _Common::gotoXY(50, 26); cout << "Exit";
                }
                if (y == 22)
                {
                    Textcolor(7);
                    _Common::gotoXY(50, 20); cout << "Player Vs Player";
                    _Common::gotoXY(50, 21); cout << "Player Vs Computer (Easy)";
                    Textcolor(Red);
                    _Common::gotoXY(50, 22); cout << "Player Vs Computer (Hard)";
                    Textcolor(7);
                    _Common::gotoXY(50, 23); cout << "Load Game";
                    _Common::gotoXY(50, 24); cout << "Help";
                    _Common::gotoXY(50, 25); cout << "About";
                    _Common::gotoXY(50, 26); cout << "Exit";
                }
                if (y == 23)
                {
                    Textcolor(7);
                    _Common::gotoXY(50, 20); cout << "Player Vs Player";
                    _Common::gotoXY(50, 21); cout << "Player Vs Computer (Easy)";
                    _Common::gotoXY(50, 22); cout << "Player Vs Computer (Hard)";
                    Textcolor(Red);
                    _Common::gotoXY(50, 23); cout << "Load Game";
                    Textcolor(7);
                    _Common::gotoXY(50, 24); cout << "Help";
                    _Common::gotoXY(50, 25); cout << "About";
                    _Common::gotoXY(50, 26); cout << "Exit";
                }
                if (y == 24)
                {
                    Textcolor(7);
                    _Common::gotoXY(50, 20); cout << "Player Vs Player";
                    _Common::gotoXY(50, 21); cout << "Player Vs Computer (Easy)";
                    _Common::gotoXY(50, 22); cout << "Player Vs Computer (Hard)";
                    _Common::gotoXY(50, 23); cout << "Load Game";
                    Textcolor(Red);
                    _Common::gotoXY(50, 24); cout << "Help";
                    Textcolor(7);
                    _Common::gotoXY(50, 25); cout << "About";
                    _Common::gotoXY(50, 26); cout << "Exit";
                }
                if (y == 25)
                {
                    Textcolor(7);
                    _Common::gotoXY(50, 20); cout << "Player Vs Player";
                    _Common::gotoXY(50, 21); cout << "Player Vs Computer (Easy)";
                    _Common::gotoXY(50, 22); cout << "Player Vs Computer (Hard)";
                    _Common::gotoXY(50, 23); cout << "Load Game";
                    _Common::gotoXY(50, 24); cout << "Help";
                    Textcolor(Red);
                    _Common::gotoXY(50, 25); cout << "About";
                    Textcolor(7);
                    _Common::gotoXY(50, 26); cout << "Exit";
                }
                if (y == 26)
                {
                    Textcolor(0);
                    _Common::gotoXY(50, 20); cout << "Player Vs Player";
                    _Common::gotoXY(50, 21); cout << "Player Vs Computer (Easy)";
                    _Common::gotoXY(50, 22); cout << "Player Vs Computer (Hard)";
                    _Common::gotoXY(50, 23); cout << "Load Game";
                    _Common::gotoXY(50, 24); cout << "Help";
                    _Common::gotoXY(50, 25); cout << "About";
                    Textcolor(Red);
                    _Common::gotoXY(50, 26); cout << "Exit";
                }
                break;
            case 13:
                //aySound(TEXT("tick.wav"), NULL, SND_FILENAME | SND_ASYNC);
                playSound(2);
                if (y == 20)
                {
                    /* Diem a;
                     a.score1 = 0;
                     a.score2 = 0;*/
                     //int t = PlayerVsPlayer(a, 0, s);
                    Sub_Loadingbar();
                    PlayervsPlayer();
                    /*if (t == 27)
                    {
                        system("cls");
                        ScreenStartGame(99);
                    }*/
                }
                /*
                if (y == 21)
                {
                    Diem a;
                    a.score1 = 0;
                    a.score2 = 0;
                    int t = PlayerVsCom2(a, 0, s);
                    if (t == 27)
                    {
                        system("cls");
                        ScreenStartGame(99);
                    }
                }
                if (y == 22)
                {
                    Diem a;
                    a.score1 = 0;
                    a.score2 = 0;
                    int t = PlayerVsCom(a, 0, s);
                    if (t == 27)
                    {
                        system("cls");
                        ScreenStartGame(99);
                    }
                }
                if (y == 23)
                {
                   // LoadLoad();

                }

                if (y == 24)
                {
                    //Help();
                    ScreenStartGame(99);
                }*/
                if (y == 25)
                {
                    About();
                    ScreenStartGame(99);
                }
                if (y == 26)
                {
                    exit(0);
                }
                break;
            }
        }
    }
}
void playSound(int i) {
    static vector<const wchar_t*> soundFile{ L"beep.wav", L"move.wav",
       L"tick.wav", L"error.wav", L"win.wav", L"draw.wav", L"nhaccho1.wav",L"Cat-Doi-Noi-Sau-Tang-Duy-Tan-Drum7.wav" };
    if (isSoundOn == true && SOUND_ON == 1) {
        PlaySound(soundFile[i], NULL, SND_FILENAME | SND_ASYNC);
    }
}
void settingPlaySound(int input) {
    if (input == 8) {
        SOUND_ON++;
        if (SOUND_ON > 1) SOUND_ON = 0;
    }
    if (SOUND_ON != 1)
    {
        isSoundOn = false;
        PlaySound(0, 0, 0);
    }
    else if (SOUND_ON == 1) {
        isSoundOn = true;
        playSound(2);
    }
}
