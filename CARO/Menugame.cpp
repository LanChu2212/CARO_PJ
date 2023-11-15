#include "_Play.h"
#include <vector>
#include <Windows.h>
#include <mmsystem.h>
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include "PlayervsPlayer.h"
#include "Loadingbar.h"
#include "Textfile.h"
#include "PLAYERVSBOTEasy.h"
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
    Textcolor(Green);

  
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
    system("color F0");
    SetConsoleCP(437);
    SetConsoleOutputCP(437);
    Textdecorate("animationAbout.txt", 1.0,3);
    Textdecorate("animation.txt", 2.0,5);
    system("cls");
    
    DrawBoardAbout(18,40,0);
   // PrintCaro3();
    Textcolor(GreyBlue);
    GotoXY(65, 18);
    //cout << "ABOUT";
    Logo(2);
    GotoXY(60, 21);
    cout << "DO AN GAME CARO - LOP23TNT1  - HCMUS" << endl;
    GotoXY(60, 22);
    cout << "-> MSSV   : 23122009/23122038/23122041/23122048" << endl;
    GotoXY(60, 23);
    cout << "-> Ho ten :My Linh/Trung Kien/Duy Minh/Phu Quy ." << endl;
    GotoXY(60, 24);
    cout << "-> Lop    : 23TNT1." << endl;
    GotoXY(60, 25);
    cout << "-> GV huong dan : Truong Toan Thinh " << endl;

    GotoXY(60, 26);
    cout << "!!" << endl;
    GotoXY(60, 30);
    cout << "BACK";
    char command = ' ';
    command = _getch();
    system("cls");
}
void Help() {
    SetConsoleCP(437);
    SetConsoleOutputCP(437);
    Textdecorate("HelpTil.txt", 2.0,5);
    system("cls");
    In_Tep("Help.txt");
    DrawBoardAbout(18,40,0);
}
struct Name {
    char data[30];
};
vector <Name> ch;

void Textcolor(int color)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}


void PrintCaro()
{
    int x = 25, y = 0;
    Textcolor(rand() % 15 + 1);
    GotoXY(x, y);				   cout << "ooooooooooooo";
    GotoXY(x - 3, y + 1);			cout << "oooooooooooooooo";
    GotoXY(x - 5, y + 2);    cout << "oooooooooooooooooo";
    GotoXY(x - 6, y + 3);   cout << "ooooooooooooooooooo";
    Textcolor(rand() % 15 + 1);
    GotoXY(x - 7, y + 4);  cout << "ooooooo";
    GotoXY(x - 8, y + 5); cout << "ooooooo";
    GotoXY(x - 8, y + 6); cout << "ooooooo";
    GotoXY(x - 8, y + 7); cout << "ooooooo";
    GotoXY(x - 8, y + 8); cout << "ooooooo";
    GotoXY(x - 8, y + 9); cout << "ooooooo";
    Textcolor(rand() % 15 + 1);
    GotoXY(x - 8, y + 10); cout << "ooooooo";
    GotoXY(x - 7, y + 11); cout << "ooooooo";
    GotoXY(x - 6, y + 12);  cout << "ooooooooooooooooooo";
    GotoXY(x - 5, y + 13);   cout << "oooooooooooooooooo";
    Textcolor(rand() % 15 + 1);
    GotoXY(x - 3, y + 14);		cout << "oooooooooooooooo";
    GotoXY(x, y + 15);			   cout << "ooooooooooooo";
    Textcolor(rand() % 15 + 1);
    GotoXY(x - 4 + 22, y + 4);				    cout << "ooooooooooo";
    GotoXY(x - 4 + 22 - 2, y + 5);		      cout << "ooooooooooooooo";
    GotoXY(x - 4 + 22 - 3, y + 6);		     cout << "ooooooooooooooooo";
    Textcolor(rand() % 15 + 1);
    GotoXY(x - 4 + 22 - 3, y + 7);			 cout << "ooooooooooooooooo";
    GotoXY(x - 4 + 22 - 3, y + 8);			 cout << "oooooo     oooooo";
    GotoXY(x - 4 + 22 - 3, y + 9);			 cout << "oooooo     oooooo";
    Textcolor(rand() % 15 + 1);
    GotoXY(x - 4 + 22 - 3, y + 10);		 cout << "oooooo     oooooo";
    GotoXY(x - 4 + 22 - 3, y + 11);		 cout << "ooooooooooooooooo";
    GotoXY(x - 4 + 22 - 3, y + 12);		 cout << "oooooo     oooooo";
    Textcolor(rand() % 15 + 1);
    GotoXY(x - 4 + 22 - 3, y + 13);		 cout << "oooooo     oooooo";
    GotoXY(x - 4 + 22 - 3, y + 14);		 cout << "oooooo     oooooo";
    GotoXY(x - 4 + 22 - 3, y + 15);		 cout << "oooooo     oooooo";

    Textcolor(rand() % 15 + 1);

    GotoXY(x + 33, y + 4);			cout << "ooooo   ooooooooo";
    GotoXY(x + 33, y + 5);			cout << "oooooooooooooooooo";
    GotoXY(x + 33, y + 6);			cout << "ooooooooooooooooooo";
    Textcolor(rand() % 15 + 1);
    GotoXY(x + 33, y + 7);			cout << "oooooooooooooooooooo";
    GotoXY(x + 1 + 33, y + 8);			 cout << "ooooooo     ooooooo";
    GotoXY(x + 1 + 33, y + 9);			 cout << "ooooooo     ooooooo";
    Textcolor(rand() % 15 + 1);
    GotoXY(x + 1 + 33, y + 10);		 cout << "ooooooo";
    GotoXY(x + 1 + 33, y + 11);		 cout << "ooooooo";
    GotoXY(x + 1 + 33, y + 12);		 cout << "ooooooo";
    Textcolor(rand() % 15 + 1);
    GotoXY(x + 1 + 33, y + 13);		 cout << "ooooooo";
    GotoXY(x + 1 + 33, y + 14);		 cout << "ooooooo";
    GotoXY(x + 1 + 33, y + 15);		 cout << "ooooooo";
    // Textcolor(Yellow);
    GotoXY(x + 57, y + 4);					cout << "ooooooooooo";
    GotoXY(x + 57 - 2, y + 5);			  cout << "ooooooooooooooo";
    Textcolor(rand() % 15 + 1);
    GotoXY(x + 57 - 3, y + 6);			 cout << "ooooooooooooooooo";
    GotoXY(x + 57 - 3, y + 7);			 cout << "ooooooooooooooooo";
    Textcolor(rand() % 15 + 1);
    GotoXY(x + 57 - 3, y + 8);			 cout << "oooooo     oooooo";
    GotoXY(x + 57 - 3, y + 9);			 cout << "oooooo     oooooo";
    GotoXY(x + 57 - 3, y + 10);		 cout << "oooooo     oooooo";
    GotoXY(x + 57 - 3, y + 11);		 cout << "oooooo     oooooo";
    Textcolor(rand() % 15 + 1);
    GotoXY(x + 57 - 3, y + 12);		 cout << "ooooooooooooooooo";
    GotoXY(x + 57 - 3, y + 13);		 cout << "ooooooooooooooooo";
    Textcolor(rand() % 15 + 1);
    GotoXY(x + 57 - 2, y + 14);		  cout << "ooooooooooooooo";
    GotoXY(x + 57, y + 15);				cout << "ooooooooooo";



}
void PrintCaro2()
{
    int x = 25, y = 0;
    Sleep(200);
    Textcolor(Red);
    GotoXY(x, y);				   cout << "ooooooooooooo";
    GotoXY(x - 3, y + 1);			cout << "oooooooooooooooo";
    GotoXY(x - 5, y + 2);    cout << "oooooooooooooooooo";
    GotoXY(x - 6, y + 3);   cout << "ooooooooooooooooooo";
    GotoXY(x - 7, y + 4);  cout << "ooooooo";
    GotoXY(x - 8, y + 5); cout << "ooooooo";
    GotoXY(x - 8, y + 6); cout << "ooooooo";
    GotoXY(x - 8, y + 7); cout << "ooooooo";
    GotoXY(x - 8, y + 8); cout << "ooooooo";
    GotoXY(x - 8, y + 9); cout << "ooooooo";
    GotoXY(x - 8, y + 10); cout << "ooooooo";
    GotoXY(x - 7, y + 11); cout << "ooooooo";
    GotoXY(x - 6, y + 12);  cout << "ooooooooooooooooooo";
    GotoXY(x - 5, y + 13);   cout << "oooooooooooooooooo";
    GotoXY(x - 3, y + 14);		cout << "oooooooooooooooo";
    GotoXY(x, y + 15);			   cout << "ooooooooooooo";
    Sleep(200);
    Textcolor(Green);
    GotoXY(x - 4 + 22, y + 4);				    cout << "ooooooooooo";
    GotoXY(x - 4 + 22 - 2, y + 5);		      cout << "ooooooooooooooo";
    GotoXY(x - 4 + 22 - 3, y + 6);		     cout << "ooooooooooooooooo";
    GotoXY(x - 4 + 22 - 3, y + 7);			 cout << "ooooooooooooooooo";
    GotoXY(x - 4 + 22 - 3, y + 8);			 cout << "oooooo     oooooo";
    GotoXY(x - 4 + 22 - 3, y + 9);			 cout << "oooooo     oooooo";
    GotoXY(x - 4 + 22 - 3, y + 10);		 cout << "oooooo     oooooo";
    GotoXY(x - 4 + 22 - 3, y + 11);		 cout << "ooooooooooooooooo";
    GotoXY(x - 4 + 22 - 3, y + 12);		 cout << "oooooo     oooooo";
    GotoXY(x - 4 + 22 - 3, y + 13);		 cout << "oooooo     oooooo";
    GotoXY(x - 4 + 22 - 3, y + 14);		 cout << "oooooo     oooooo";
    GotoXY(x - 4 + 22 - 3, y + 15);		 cout << "oooooo     oooooo";
    Sleep(200);
    Textcolor(Blue);

    GotoXY(x + 33, y + 4);			cout << "ooooo   ooooooooo";
    GotoXY(x + 33, y + 5);			cout << "oooooooooooooooooo";
    GotoXY(x + 33, y + 6);			cout << "ooooooooooooooooooo";
    GotoXY(x + 33, y + 7);			cout << "oooooooooooooooooooo";
    GotoXY(x + 1 + 33, y + 8);			 cout << "ooooooo     ooooooo";
    GotoXY(x + 1 + 33, y + 9);			 cout << "ooooooo     ooooooo";
    GotoXY(x + 1 + 33, y + 10);		 cout << "ooooooo";
    GotoXY(x + 1 + 33, y + 11);		 cout << "ooooooo";
    GotoXY(x + 1 + 33, y + 12);		 cout << "ooooooo";
    GotoXY(x + 1 + 33, y + 13);		 cout << "ooooooo";
    GotoXY(x + 1 + 33, y + 14);		 cout << "ooooooo";
    GotoXY(x + 1 + 33, y + 15);		 cout << "ooooooo";
    Sleep(200);
    Textcolor(Violet);
    GotoXY(x + 57, y + 4);					cout << "ooooooooooo";
    GotoXY(x + 57 - 2, y + 5);			  cout << "ooooooooooooooo";
    GotoXY(x + 57 - 3, y + 6);			 cout << "ooooooooooooooooo";
    GotoXY(x + 57 - 3, y + 7);			 cout << "ooooooooooooooooo";
    GotoXY(x + 57 - 3, y + 8);			 cout << "oooooo     oooooo";
    GotoXY(x + 57 - 3, y + 9);			 cout << "oooooo     oooooo";
    GotoXY(x + 57 - 3, y + 10);		 cout << "oooooo     oooooo";
    GotoXY(x + 57 - 3, y + 11);		 cout << "oooooo     oooooo";
    GotoXY(x + 57 - 3, y + 12);		 cout << "ooooooooooooooooo";
    GotoXY(x + 57 - 3, y + 13);		 cout << "ooooooooooooooooo";
    GotoXY(x + 57 - 2, y + 14);		  cout << "ooooooooooooooo";
    GotoXY(x + 57, y + 15);				cout << "ooooooooooo";
    Textcolor(defaultColor);
}
void PrintCaro3()
{
    int x = 25, y = 0;
    Textcolor(FullRed);
    GotoXY(x, y);				   cout << "ooooooooooooo";
    GotoXY(x - 3, y + 1);			cout << "oooooooooooooooo";
    GotoXY(x - 5, y + 2);    cout << "oooooooooooooooooo";
    GotoXY(x - 6, y + 3);   cout << "ooooooooooooooooooo";
    GotoXY(x - 7, y + 4);  cout << "ooooooo";
    GotoXY(x - 8, y + 5); cout << "ooooooo";
    GotoXY(x - 8, y + 6); cout << "ooooooo";
    GotoXY(x - 8, y + 7); cout << "ooooooo";
    GotoXY(x - 8, y + 8); cout << "ooooooo";
    GotoXY(x - 8, y + 9); cout << "ooooooo";
    GotoXY(x - 8, y + 10); cout << "ooooooo";
    GotoXY(x - 7, y + 11); cout << "ooooooo";
    GotoXY(x - 6, y + 12);  cout << "ooooooooooooooooooo";
    GotoXY(x - 5, y + 13);   cout << "oooooooooooooooooo";
    GotoXY(x - 3, y + 14);		cout << "oooooooooooooooo";
    GotoXY(x, y + 15);			   cout << "ooooooooooooo";
    Textcolor(FullGreen);
    GotoXY(x - 4 + 22, y + 4);				    cout << "ooooooooooo";
    GotoXY(x - 4 + 22 - 2, y + 5);		      cout << "ooooooooooooooo";
    GotoXY(x - 4 + 22 - 3, y + 6);		     cout << "ooooooooooooooooo";
    GotoXY(x - 4 + 22 - 3, y + 7);			 cout << "ooooooooooooooooo";
    GotoXY(x - 4 + 22 - 3, y + 8);			 cout << "oooooo     oooooo";
    GotoXY(x - 4 + 22 - 3, y + 9);			 cout << "oooooo     oooooo";
    GotoXY(x - 4 + 22 - 3, y + 10);		 cout << "oooooo     oooooo";
    GotoXY(x - 4 + 22 - 3, y + 11);		 cout << "ooooooooooooooooo";
    GotoXY(x - 4 + 22 - 3, y + 12);		 cout << "oooooo     oooooo";
    GotoXY(x - 4 + 22 - 3, y + 13);		 cout << "oooooo     oooooo";
    GotoXY(x - 4 + 22 - 3, y + 14);		 cout << "oooooo     oooooo";
    GotoXY(x - 4 + 22 - 3, y + 15);		 cout << "oooooo     oooooo";
    Textcolor(FullBlue);

    GotoXY(x + 33, y + 4);			cout << "ooooo   ooooooooo";
    GotoXY(x + 33, y + 5);			cout << "oooooooooooooooooo";
    GotoXY(x + 33, y + 6);			cout << "ooooooooooooooooooo";
    GotoXY(x + 33, y + 7);			cout << "oooooooooooooooooooo";
    GotoXY(x + 1 + 33, y + 8);			 cout << "ooooooo     ooooooo";
    GotoXY(x + 1 + 33, y + 9);			 cout << "ooooooo     ooooooo";
    GotoXY(x + 1 + 33, y + 10);		 cout << "ooooooo";
    GotoXY(x + 1 + 33, y + 11);		 cout << "ooooooo";
    GotoXY(x + 1 + 33, y + 12);		 cout << "ooooooo";
    GotoXY(x + 1 + 33, y + 13);		 cout << "ooooooo";
    GotoXY(x + 1 + 33, y + 14);		 cout << "ooooooo";
    GotoXY(x + 1 + 33, y + 15);		 cout << "ooooooo";
    Textcolor(FullAzure);
    GotoXY(x + 57, y + 4);					cout << "ooooooooooo";
    GotoXY(x + 57 - 2, y + 5);			  cout << "ooooooooooooooo";
    GotoXY(x + 57 - 3, y + 6);			 cout << "ooooooooooooooooo";
    GotoXY(x + 57 - 3, y + 7);			 cout << "ooooooooooooooooo";
    GotoXY(x + 57 - 3, y + 8);			 cout << "oooooo     oooooo";
    GotoXY(x + 57 - 3, y + 9);			 cout << "oooooo     oooooo";
    GotoXY(x + 57 - 3, y + 10);		 cout << "oooooo     oooooo";
    GotoXY(x + 57 - 3, y + 11);		 cout << "oooooo     oooooo";
    GotoXY(x + 57 - 3, y + 12);		 cout << "ooooooooooooooooo";
    GotoXY(x + 57 - 3, y + 13);		 cout << "ooooooooooooooooo";
    GotoXY(x + 57 - 2, y + 14);		  cout << "ooooooooooooooo";
    GotoXY(x + 57, y + 15);				cout << "ooooooooooo";
    Textcolor(defaultColor);

}


void ScreenStartGame(int n) {

    system("Color FA");
    AnTroChuot();
    int x = 50, y = 20;
    //int i;
    char s[30] = " ";
    int check = 1;
    Textcolor(Red);
    GotoXY(50, 20); cout << "Player Vs Player";
    Textcolor(Black);
    GotoXY(50, 21); cout << "Player Vs Computer (Easy)";
    GotoXY(50, 22); cout << "Player Vs Computer (Hard)";
    GotoXY(50, 23); cout << "Load Game";
    GotoXY(50, 24); cout << "Help";
    GotoXY(50, 25); cout << "About";
    GotoXY(50, 26); cout << "Exit";
    GotoXY(50, 32); cout << "....... W - S : Move  ";
    GotoXY(50, 33); cout << "....... Enter : Select ";
    GotoXY(50, 34); cout << ".......   M   : Mute ";
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
                    GotoXY(x, y);
                }
                if (y == 20)
                {
                    Textcolor(Red);
                    GotoXY(50, 20); cout << "Player Vs Player";
                    Textcolor(Black);
                    GotoXY(50, 21); cout << "Player Vs Computer (Easy)";
                    GotoXY(50, 22); cout << "Player Vs Computer (Hard)";
                    GotoXY(50, 23); cout << "Load Game";
                    GotoXY(50, 24); cout << "Help";
                    GotoXY(50, 25); cout << "About";
                    GotoXY(50, 26); cout << "Exit";
                }
                if (y == 21)
                {
                    Textcolor(Black);
                    GotoXY(50, 20); cout << "Player Vs Player";
                    Textcolor(Red);
                    GotoXY(50, 21); cout << "Player Vs Computer (Easy)";
                    Textcolor(Black);
                    GotoXY(50, 22); cout << "Player Vs Computer (Hard)";
                    GotoXY(50, 23); cout << "Load Game";
                    GotoXY(50, 24); cout << "Help";
                    GotoXY(50, 25); cout << "About";
                    GotoXY(50, 26); cout << "Exit";
                }
                if (y == 22)
                {
                    Textcolor(Black);
                    GotoXY(50, 20); cout << "Player Vs Player";
                    GotoXY(50, 21); cout << "Player Vs Computer (Easy)";
                    Textcolor(Red);
                    GotoXY(50, 22); cout << "Player Vs Computer (Hard)";
                    Textcolor(Black);
                    GotoXY(50, 23); cout << "Load Game";
                    GotoXY(50, 24); cout << "Help";
                    GotoXY(50, 25); cout << "About";
                    GotoXY(50, 26); cout << "Exit";
                }
                if (y == 23)
                {
                    Textcolor(Black);
                    GotoXY(50, 20); cout << "Player Vs Player";
                    GotoXY(50, 21); cout << "Player Vs Computer (Easy)";
                    GotoXY(50, 22); cout << "Player Vs Computer (Hard)";
                    Textcolor(Red);
                    GotoXY(50, 23); cout << "Load Game";
                    Textcolor(Black);
                    GotoXY(50, 24); cout << "Help";
                    GotoXY(50, 25); cout << "About";
                    GotoXY(50, 26); cout << "Exit";
                }
                if (y == 24)
                {
                    Textcolor(Black);
                    GotoXY(50, 20); cout << "Player Vs Player";
                    GotoXY(50, 21); cout << "Player Vs Computer (Easy)";
                    GotoXY(50, 22); cout << "Player Vs Computer (Hard)";
                    GotoXY(50, 23); cout << "Load Game";
                    Textcolor(Red);
                    GotoXY(50, 24); cout << "Help";
                    Textcolor(Black);
                    GotoXY(50, 25); cout << "About";
                    GotoXY(50, 26); cout << "Exit";
                }
                if (y == 25)
                {
                    Textcolor(Black);
                    GotoXY(50, 20); cout << "Player Vs Player";
                    GotoXY(50, 21); cout << "Player Vs Computer (Easy)";
                    GotoXY(50, 22); cout << "Player Vs Computer (Hard)";
                    GotoXY(50, 23); cout << "Load Game";
                    GotoXY(50, 24); cout << "Help";
                    Textcolor(Red);
                    GotoXY(50, 25); cout << "About";
                    Textcolor(Black);
                    GotoXY(50, 26); cout << "Exit";
                }
                if (y == 26)
                {
                    Textcolor(Black);
                    GotoXY(50, 20); cout << "Player Vs Player";
                    GotoXY(50, 21); cout << "Player Vs Computer (Easy)";
                    GotoXY(50, 22); cout << "Player Vs Computer (Hard)";
                    GotoXY(50, 23); cout << "Load Game";
                    GotoXY(50, 24); cout << "Help";
                    Textcolor(Red);
                    GotoXY(50, 25); cout << "About";
                    Textcolor(Black);
                    GotoXY(50, 26); cout << "Exit";
                }
                break;
            case 's':
                // PlaySound(TEXT("move.wav"), NULL, SND_FILENAME | SND_ASYNC);
                playSound(1);
                if (y < 26)
                {
                    y++;
                    GotoXY(x, y);
                }
                if (y == 20)
                {
                    Textcolor(Red);
                    GotoXY(50, 20); cout << "Player Vs Player";
                    Textcolor(Black);
                    GotoXY(50, 21); cout << "Player Vs Computer (Easy)";
                    GotoXY(50, 22); cout << "Player Vs Computer (Hard)";
                    GotoXY(50, 23); cout << "Load Game";
                    GotoXY(50, 24); cout << "Help";
                    GotoXY(50, 25); cout << "About";
                    GotoXY(50, 26); cout << "Exit";
                }
                if (y == 21)
                {
                    Textcolor(Black);
                    GotoXY(50, 20); cout << "Player Vs Player";
                    Textcolor(Red);
                    GotoXY(50, 21); cout << "Player Vs Computer (Easy)";
                    Textcolor(Black);
                    GotoXY(50, 22); cout << "Player Vs Computer (Hard)";
                    GotoXY(50, 23); cout << "Load Game";
                    GotoXY(50, 24); cout << "Help";
                    GotoXY(50, 25); cout << "About";
                    GotoXY(50, 26); cout << "Exit";
                }
                if (y == 22)
                {
                    Textcolor(Black);
                    GotoXY(50, 20); cout << "Player Vs Player";
                    GotoXY(50, 21); cout << "Player Vs Computer (Easy)";
                    Textcolor(Red);
                    GotoXY(50, 22); cout << "Player Vs Computer (Hard)";
                    Textcolor(Black);
                    GotoXY(50, 23); cout << "Load Game";
                    GotoXY(50, 24); cout << "Help";
                    GotoXY(50, 25); cout << "About";
                    GotoXY(50, 26); cout << "Exit";
                }
                if (y == 23)
                {
                    Textcolor(Black);
                    GotoXY(50, 20); cout << "Player Vs Player";
                    GotoXY(50, 21); cout << "Player Vs Computer (Easy)";
                    GotoXY(50, 22); cout << "Player Vs Computer (Hard)";
                    Textcolor(Red);
                    GotoXY(50, 23); cout << "Load Game";
                    Textcolor(Black);
                    GotoXY(50, 24); cout << "Help";
                    GotoXY(50, 25); cout << "About";
                    GotoXY(50, 26); cout << "Exit";
                }
                if (y == 24)
                {
                    Textcolor(Black);
                    GotoXY(50, 20); cout << "Player Vs Player";
                    GotoXY(50, 21); cout << "Player Vs Computer (Easy)";
                    GotoXY(50, 22); cout << "Player Vs Computer (Hard)";
                    GotoXY(50, 23); cout << "Load Game";
                    Textcolor(Red);
                    GotoXY(50, 24); cout << "Help";
                    Textcolor(Black);
                    GotoXY(50, 25); cout << "About";
                    GotoXY(50, 26); cout << "Exit";
                }
                if (y == 25)
                {
                    Textcolor(Black);
                    GotoXY(50, 20); cout << "Player Vs Player";
                    GotoXY(50, 21); cout << "Player Vs Computer (Easy)";
                    GotoXY(50, 22); cout << "Player Vs Computer (Hard)";
                    GotoXY(50, 23); cout << "Load Game";
                    GotoXY(50, 24); cout << "Help";
                    Textcolor(Red);
                    GotoXY(50, 25); cout << "About";
                    Textcolor(Black);
                    GotoXY(50, 26); cout << "Exit";
                }
                if (y == 26)
                {
                    Textcolor(Black);//0 là đen het
                    GotoXY(50, 20); cout << "Player Vs Player";
                    GotoXY(50, 21); cout << "Player Vs Computer (Easy)";
                    GotoXY(50, 22); cout << "Player Vs Computer (Hard)";
                    GotoXY(50, 23); cout << "Load Game";
                    GotoXY(50, 24); cout << "Help";
                    GotoXY(50, 25); cout << "About";
                    Textcolor(Red);
                    GotoXY(50, 26); cout << "Exit";
                }
                break;
            case 13:
                //aySound(TEXT("tick.wav"), NULL, SND_FILENAME | SND_ASYNC);
                playSound(2);
                if (y == 20)
                {
                    // Diem a;
                    //a.score1 = 0;
                    // a.score2 = 0;*/
                     //int t = PlayerVsPlayer(a, 0, s);
                    //Sub_Loadingbar();
                    PlayervsPlayer();
                    system("cls");
                    ScreenStartGame(99);
                    /*if (t == 27)
                    {
                        system("cls");
                        ScreenStartGame(99);
                    }*/
                }
                if (y == 21)
                {
                    //Diem a;
                    //a.score1 = 0;
                    //a.score2 = 0;
                   // int t = PlayerVsCom2(a, 0, s);
                    /*if (t == 27)
                    {
                        system("cls");
                        ScreenStartGame(99);
                    }*/
                    Sub_Loadingbar();
                    PlayerVsBOTEasy();
                    system("cls");
                    ScreenStartGame(99);

                }/*
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
                */
                if (y == 24)
                {
                    system("cls");
                    Help();
                    system("Pause");
                    system("cls");
                    ScreenStartGame(99);
                }
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
