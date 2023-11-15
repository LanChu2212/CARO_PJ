#pragma once
#include <Windows.h>
#include <mmsystem.h>
#include <iostream>
#include <string.h>
#include "_Common.h"
#include "_Play.h"
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <stdbool.h>
#include <vector>
#include "PlayervsPlayer.h"

// Hàm nhóm view
void FixConsoleWindow();
void setConsoleWindow(int w, int h);
void GotoXY(int x, int y);
// Hằng số
void ResetData();
// Hàm khởi tạo dữ liệu mặc định ban đầu cho ma trận bàn cờ
void ResetData();
// Hàm nhóm view
void DrawBoard();
void Xturn();
void Oturn();
// Hàm nhóm Control
void StartGame(int* dX, int* dY);
void GabageCollect();
void ExitGame();
//Hàm nhóm Model
int TestBoard();
int CheckBoard(int pX, int pY);
//Hàm di chuyển :
void MoveRight();
void MoveLeft();
void MoveDown();
void MoveUp();
void PlayervsPlayer();
void WINX1();
void WINX2();
void WINX();
void WINO();
void DRAW();
int AskContinue();
