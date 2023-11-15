#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;
#define SIZE 14
#define LEFT 0
#define TOP 0
void gotoxy(int x, int y);
void initializeBoard();
void Gotoxy(int x, int y); 
void DrawBoardBOT();
void printBoard();
bool checkWin(int x, int y, char player);
int evaluateCell(int x, int y);

void computerMove();
void PlayerVsBOTEasy();
void COMPUTERWIN();
void YOUWIN();
void DRAW();
int AskContinueBOTEasy();

