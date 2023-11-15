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
#include"Loadingbar.h"
using namespace std;




int main() {
    SetConsoleCP(437);
    SetConsoleOutputCP(437);
    FixConsoleWindow();
    system("Color FA");
    int n = 100;
    _Common::fixConsoleWindow();
    _Common::setConsoleWindow(1000, 600);
    system("Color FA");
    _LoadingBar();
    ScreenStartGame(n);

    system("Color FA");



    return 0;
    system("pause");
}




void test() {
    for (int i = 1; i <= 50; i++)
    {
        system("cls");
        //cout<<"\n\n\t\t "<<2*i<<"%";
        cout << "\n\t<<<<<<<< <(^_^) > >> >>>";
        cout << "\n\t<< >>";
        cout << "\n\t<<< >>>";
        cout << "\n\t<<<< Welcome To IT Learning >>>>";
        cout << "\n\t<<< >>>";
        cout << "\n\t<< >>";
        cout << "\n\t<<<<<<<<< <<<<(^:^) >>> >>>";
        cout << "\n\t! [";
        cout << "\n\t| |";
        cout << "\n\t<<<<<<< <<<<<<<<<(^:^) > >>>>>";
        cout << "\n\n\t Teach by Venerable NOUN GNOUN" << endl;
        cout << "\n\n\t Loading " << 2 * i << "%\n\t";
        for (int j = 1; j <= i; j++)
            cout << '2';// cout<<"\xB2"
        // cout<<"\n\n\t\t "<<2*i<< "%"; // display percentage
        if (i > 1 && i < 20)
            cout << "\n\n\t\tCreating Temporary files";
        else if (i > 20 && i < 40)
            cout << "\n\n\t\tAccessing Main Memory";
        else if (i > 40 && 1 < 48)
            cout << "\n\n\t\tAccessing Cache";
        else cout << "\n\n\t\tComplete. Press Enter to Continue ";
        Sleep(150 - i * 3);
    }
}