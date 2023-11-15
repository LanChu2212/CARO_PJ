#include "Loadingbar.h"
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

void _LoadingBar()
{
    playSound(6);
    //set ASCII to print special character ...
    //code page 437 
    SetConsoleCP(437);
    SetConsoleOutputCP(437);
    int bar1 = 177, bar2 = 219;
    system("cls");



    cout << "\n\n\n\t\t\t\tLoading....";
    cout << "\n\n\n\t\t\t\t";
    for (int i = 0; i < 50; i++)
        cout << (char)bar1;
    cout << "\r";
    cout << "\t\t\t\t";

    for (int i = 0; i < 50; i++)
    {
        cout << (char)bar2;
        Sleep(150);
        cout << "\t Loading " << 2 * i << "%\t";

        Sleep(150 - i * 3);
    }

    system("cls");
    {
        system("cls");
        const char* hello[9] = { "WELCOME"," ","TO"," ","OUR"," ","GAME"," ","CARO" };
        int j = 60;

        for (int i = 0; i < 9; i++)
        {
            j = j + 3;
            GotoXY(j, 1); cout << hello[i];
            Sleep(150);

        }
        cout << "\n";
        TrangTri();

        GotoXY(60, 16);  system("Pause");

    }

    system("cls");
}
void Sub_Loadingbar() {
    system("cls");
    //set ASCII to print special character ...
    //code page 437 
    SetConsoleCP(437);
    SetConsoleOutputCP(437);
    int bar1 = 177, bar2 = 219;
    cout << "\n\n\n\t\t\t\tLoading....";
    cout << "\n\n\n\t\t\t\t";
    for (int i = 0; i < 25; i++)
        cout << (char)bar1;
    cout << "\r";
    cout << "\t\t\t\t";
    for (int i = 0; i < 25; i++)
    {
        cout << (char)bar2;
        Sleep(150);
    }
    /* {
        system("cls");
        const char* hello[9] = { "WELCOME"," ","TO"," ","OUR"," ","GAME"," ","CARO" };

        for (int i = 0; i < 9; i++)
        {
            cout << hello[i];
            Sleep(100);
        }
        cout << "\n";
        system("Pause");

    }*/
    system("Pause");
}
void TrangTri()
{ // in caro trang tri phan dau 
    Textcolor(252);

    GotoXY(5, 1);  cout << "xxx         xxx     " << endl;
    GotoXY(5, 2);  cout << "  xxx     xxx       " << endl;
    GotoXY(5, 3);  cout << "    xxx xxx         " << endl;
    GotoXY(5, 4);  cout << "      xxx           " << endl;
    GotoXY(5, 5);  cout << "    xxx xxx         " << endl;
    GotoXY(5, 6);  cout << "  xxx     xxx       " << endl;
    GotoXY(5, 7);  cout << "xxx         xxx     " << endl;
    GotoXY(5, 8);  cout << endl;
    GotoXY(5, 9);  cout << endl;
    Sleep(300);
    Textcolor(249);
    GotoXY(5, 10); cout << "   000000000    " << endl;
    GotoXY(5, 11); cout << " 000       000   " << endl;
    GotoXY(5, 12); cout << "000         000  " << endl;
    GotoXY(5, 13); cout << "000         000  " << endl;
    GotoXY(5, 14); cout << "000         000  " << endl;
    GotoXY(5, 15); cout << " 000       000  " << endl;
    GotoXY(5, 16); cout << "   000000000   " << endl;
    GotoXY(5, 17); cout << endl;
    GotoXY(5, 18); cout << endl;
    Sleep(300);
    Textcolor(252);
    GotoXY(5, 19);  cout << "xxx         xxx  " << endl;
    GotoXY(5, 20);  cout << "  xxx     xxx    " << endl;
    GotoXY(5, 21);  cout << "    xxx xxx      " << endl;
    GotoXY(5, 22);  cout << "      xxx        " << endl;
    GotoXY(5, 23);  cout << "    xxx xxx      " << endl;
    GotoXY(5, 24);  cout << "  xxx     xxx    " << endl;
    GotoXY(5, 25);  cout << "xxx         xxx  " << endl;
    GotoXY(5, 26); cout << endl;
    GotoXY(5, 27); cout << endl;
    /*
    Sleep(300);
    Textcolor(249);
    GotoXY(5, 28); cout << "   000000000    " << endl;
    GotoXY(5, 29); cout << " 000       000   " << endl;
    GotoXY(5, 30); cout << "000         000  " << endl;
    GotoXY(5, 31); cout << "000         000  " << endl;
    GotoXY(5, 32); cout << "000         000  " << endl;
    GotoXY(5, 33); cout << " 000       000  " << endl;
    GotoXY(5, 34); cout << "   000000000   " << endl;*/

    //in caro trang tri phan cuoi 
    Textcolor(252);
    GotoXY(135, 1);  cout << "xxx         xxx     " << endl;
    GotoXY(135, 2);  cout << "  xxx     xxx       " << endl;
    GotoXY(135, 3);  cout << "    xxx xxx         " << endl;
    GotoXY(135, 4);  cout << "      xxx           " << endl;
    GotoXY(135, 5);  cout << "    xxx xxx         " << endl;
    GotoXY(135, 6);  cout << "  xxx     xxx       " << endl;
    GotoXY(135, 7);  cout << "xxx         xxx     " << endl;
    GotoXY(135, 8);  cout << endl;
    GotoXY(135, 9);  cout << endl;
    Sleep(300);
    Textcolor(249);
    GotoXY(135, 10); cout << "   000000000    " << endl;
    GotoXY(135, 11); cout << " 000       000   " << endl;
    GotoXY(135, 12); cout << "000         000  " << endl;
    GotoXY(135, 13); cout << "000         000  " << endl;
    GotoXY(135, 14); cout << "000         000  " << endl;
    GotoXY(135, 15); cout << " 000       000  " << endl;
    GotoXY(135, 16); cout << "   000000000   " << endl;
    GotoXY(135, 17); cout << endl;
    GotoXY(135, 18); cout << endl;
    Sleep(300);
    Textcolor(252);
    GotoXY(135, 19);  cout << "xxx         xxx   " << endl;
    GotoXY(135, 20);  cout << "  xxx     xxx     " << endl;
    GotoXY(135, 21);  cout << "    xxx xxx       " << endl;
    GotoXY(135, 22);  cout << "      xxx         " << endl;
    GotoXY(135, 23);  cout << "    xxx xxx       " << endl;
    GotoXY(135, 24);  cout << "  xxx     xxx     " << endl;
    GotoXY(135, 25);  cout << "xxx         xxx   " << endl;
    GotoXY(135, 26); cout << endl;
    GotoXY(135, 27); cout << endl;
    /*
    Sleep(500);
    Textcolor(249);
    GotoXY(135, 28); cout << "   000000000    " << endl;
    GotoXY(135, 29); cout << " 000       000   " << endl;
    GotoXY(135, 30); cout << "000         000  " << endl;
    GotoXY(135, 31); cout << "000         000  " << endl;
    GotoXY(135, 32); cout << "000         000  " << endl;
    GotoXY(135, 33); cout << " 000       000  " << endl;
    GotoXY(135, 34); cout << "   000000000   " << endl;
    */
    //in caro trang tri phan giua
    Sleep(500);
    Textcolor(252);

    GotoXY(1, 28);  cout << "xxx         xxx   " << endl;
    GotoXY(1, 29);  cout << "  xxx     xxx     " << endl;
    GotoXY(1, 30);  cout << "    xxx xxx       " << endl;
    GotoXY(1, 31);  cout << "      xxx         " << endl;
    GotoXY(1, 32);  cout << "    xxx xxx       " << endl;
    GotoXY(1, 33);  cout << "  xxx     xxx     " << endl;
    GotoXY(1, 34);  cout << "xxx         xxx   " << endl;
    GotoXY(1, 35);  cout << endl;
    GotoXY(1, 36);  cout << endl;
    Sleep(300);
    Textcolor(249);
    GotoXY(20, 28); cout << "   000000000    " << endl;
    GotoXY(20, 29); cout << " 000       000   " << endl;
    GotoXY(20, 30); cout << "000         000  " << endl;
    GotoXY(20, 31); cout << "000         000  " << endl;
    GotoXY(20, 32); cout << "000         000  " << endl;
    GotoXY(20, 33); cout << " 000       000  " << endl;
    GotoXY(20, 34); cout << "   000000000   " << endl;
    GotoXY(20, 35); cout << endl;
    GotoXY(20, 36); cout << endl;
    Sleep(300);
    Textcolor(252);
    GotoXY(40, 28);  cout << "  xxx         xxx  " << endl;
    GotoXY(40, 29);  cout << "    xxx     xxx    " << endl;
    GotoXY(40, 30);  cout << "      xxx xxx      " << endl;
    GotoXY(40, 31);  cout << "        xxx        " << endl;
    GotoXY(40, 32);  cout << "      xxx xxx      " << endl;
    GotoXY(40, 33);  cout << "    xxx     xxx    " << endl;
    GotoXY(40, 34);  cout << "  xxx         xxx  " << endl;
    GotoXY(40, 35); cout << endl;
    GotoXY(40, 36); cout << endl;
    Sleep(300);
    Textcolor(249);
    GotoXY(60, 28); cout << "   000000000    " << endl;
    GotoXY(60, 29); cout << " 000       000   " << endl;
    GotoXY(60, 30); cout << "000         000  " << endl;
    GotoXY(60, 31); cout << "000         000  " << endl;
    GotoXY(60, 32); cout << "000         000  " << endl;
    GotoXY(60, 33); cout << " 000       000  " << endl;
    GotoXY(60, 34); cout << "   000000000   " << endl;
    Sleep(300);
    Textcolor(252);
    GotoXY(80, 28);  cout << "xxx         xxx " << endl;
    GotoXY(80, 29);  cout << "  xxx     xxx   " << endl;
    GotoXY(80, 30);  cout << "    xxx xxx     " << endl;
    GotoXY(80, 31);  cout << "      xxx       " << endl;
    GotoXY(80, 32);  cout << "    xxx xxx     " << endl;
    GotoXY(80, 33);  cout << "  xxx     xxx   " << endl;
    GotoXY(80, 34);  cout << "xxx         xxx " << endl;
    GotoXY(80, 35); cout << endl;
    GotoXY(80, 36); cout << endl;
    Sleep(300);
    Textcolor(249);
    GotoXY(100, 28); cout << "   000000000    " << endl;
    GotoXY(100, 29); cout << " 000       000   " << endl;
    GotoXY(100, 30); cout << "000         000  " << endl;
    GotoXY(100, 31); cout << "000         000  " << endl;
    GotoXY(100, 32); cout << "000         000  " << endl;
    GotoXY(100, 33); cout << " 000       000  " << endl;
    GotoXY(100, 34); cout << "   000000000   " << endl;
    Sleep(300);
    Textcolor(252);
    GotoXY(120, 28);  cout << "xxx         xxx " << endl;
    GotoXY(120, 29);  cout << "  xxx     xxx   " << endl;
    GotoXY(120, 30);  cout << "    xxx xxx     " << endl;
    GotoXY(120, 31);  cout << "      xxx       " << endl;
    GotoXY(120, 32);  cout << "    xxx xxx     " << endl;
    GotoXY(120, 33);  cout << "  xxx     xxx   " << endl;
    GotoXY(120, 34);  cout << "xxx         xxx " << endl;
    GotoXY(120, 35); cout << endl;
    GotoXY(120, 36); cout << endl;

    Sleep(300);
    Textcolor(249);
    GotoXY(140, 28); cout << "   000000000    " << endl;
    GotoXY(140, 29); cout << " 000       000   " << endl;
    GotoXY(140, 30); cout << "000         000  " << endl;
    GotoXY(140, 31); cout << "000         000  " << endl;
    GotoXY(140, 32); cout << "000         000  " << endl;
    GotoXY(140, 33); cout << " 000       000  " << endl;
    GotoXY(140, 34); cout << "   000000000   " << endl;


    /*
        GotoXY(1, 10); cout << " _____/\\\\\\\\\\\\_____/\\\\\\\\\_____/\\\\____________/\\\\__/\\\\\\\\\\\\\\\__________________/\\\\\\\\\_____/\\\\\\\\\_______/\\\\\\\\\___________/\\\\\______ _" << endl;
        GotoXY(1, 11); cout << "   ___/\\\//////////____/\\\\\\\\\\\\\__\/\\\\\\________/\\\\\\_\/\\\///////////________________/\\\////////____/\\\\\\\\\\\\\___/\\\///////\\\_______/\\\///\\\____       " << endl;
        GotoXY(1, 12); cout << "    __/\\\______________/\\\/////////\\\_\/\\\//\\\____/\\\//\\\_\/\\\_________________________/\\\/____________/\\\/////////\\\_\/\\\_____\/\\\_____/\\\/__\///\\\__      " << endl;
        GotoXY(1, 13); cout << "     _\/\\\____/\\\\\\\_\/\\\_______\/\\\_\/\\\\///\\\/\\\/_\/\\\_\/\\\\\\\\\\\________________/\\\_____________\/\\\_______\/\\\_\/\\\\\\\\\\\/_____/\\\______\//\\\_     " << endl;
        GotoXY(1, 14); cout << "      _\/\\\___\/////\\\_\/\\\\\\\\\\\\\\\_\/\\\__\///\\\/___\/\\\_\/\\\///////________________\/\\\_____________\/\\\\\\\\\\\\\\\_\/\\\//////\\\____\/\\\_______\/\\\_    " << endl;
        GotoXY(1, 15); cout << "      _\/\\\_______\/\\\_\/\\\/////////\\\_\/\\\____\///_____\/\\\_\/\\\_______________________\//\\\____________\/\\\/////////\\\_\/\\\____\//\\\___\//\\\______/\\\__   " << endl;
        GotoXY(1, 16); cout << "       _\/\\\_______\/\\\_\/\\\_______\/\\\_\/\\\_____________\/\\\_\/\\\________________________\///\\\__________\/\\\_______\/\\\_\/\\\_____\//\\\___\///\\\__/\\\____  " << endl;
        GotoXY(1, 17); cout << "        _\//\\\\\\\\\\\\/__\/\\\_______\/\\\_\/\\\_____________\/\\\_\/\\\\\\\\\\\\\\\______________\////\\\\\\\\\_\/\\\_______\/\\\_\/\\\______\//\\\____\///\\\\\/_____ " << endl;
        GotoXY(1, 18); cout << "         __\////////////____\///________\///__\///______________\///__\///////////////__________________\/////////__\///________\///__\///________\///_______\/////_______" << endl;
        */
    Textcolor(Red);
    GotoXY(60, 10); cout << "  _|_|_|    _|_|    _|_|_|      _|_|  " << endl;
    Sleep(200);
    Textcolor(Blue);
    GotoXY(60, 11); cout << " _|        _|    _|  _|    _|  _|    _|       " << endl;
    Sleep(200);
    Textcolor(Red);
    GotoXY(60, 12); cout << " _|        _|_|_|_|  _|_|_|    _|    _|  " << endl;
    Sleep(200);
    Textcolor(Blue);
    GotoXY(60, 13); cout << " _|        _|    _|  _|    _|  _|    _|  " << endl;
    Sleep(200);
    Textcolor(Red);
    GotoXY(60, 14); cout << "  _|_|_|  _|    _|  _|    _|    _|_|     " << endl;
    /*
    GotoXY(1, 15); cout << "  _\//\\\____________\/\\\/////////\\\_\/\\\____\//\\\___\//\\\______/\\\__   " << endl;
    GotoXY(1, 16); cout << "  __\///\\\__________\/\\\_______\/\\\_\/\\\_____\//\\\___\///\\\__/\\\____   " << endl;
    GotoXY(1, 17); cout << " ____\////\\\\\\\\\_\/\\\_______\/\\\_\/\\\______\//\\\____\///\\\\\/_____  " << endl;
    GotoXY(1, 18); cout << "  _______\/////////__\///________\///__\///________\///_______\/////____" << endl;*/

}
