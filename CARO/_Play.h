
#pragma once
//#include "_Point.h"
#include "PlayervsPlayer.h"
//#include "_Board.h"
//#include "_Game.h"
//Định nghĩa thông số màu hiển thị
//Định nghĩa thông số màu hiển thị
#define Black			240
#define Blue		    241
#define Green		    242
#define Red      		244
#define Violet          245
#define FullBlue		17
#define BlueYellow		30
#define FullGreen		34
#define FullAzure       51
#define FullRed         68
#define YellowRed       100
#define FullYellow		102
#define Grey		    135
#define GreyBlue	    121
#define MintPink		189
#define defaultColor    7 

#define ColorCode_Back			0
#define ColorCode_DarkBlue		1
#define ColorCode_DarkGreen		2
#define ColorCode_DarkCyan		3
#define ColorCode_DarkRed		4
#define ColorCode_DarkPink		5
#define ColorCode_DarkYellow	6
#define ColorCode_DarkWhite		7
#define ColorCode_Grey			8
#define ColorCode_Blue			9
#define ColorCode_Green			10
#define ColorCode_Cyan			11
#define ColorCode_Red			12
#define ColorCode_Pink			13
#define ColorCode_Yellow		14
#define ColorCode_White			15

#define default_ColorCode		7


struct Diem
{
	int score1;
	int score2;
};
// Tỉ số thắng thua 

//int ReadChedo(char a[30]); // Đọc chế độ chơi
//void ReadNameFile();  // Đọc tên các file đã lưu
void PrintCaro();
void PrintCaro2();
void PrintCaro3();
void Screen();
// In chữ CARO 
void Textcolor(int n); // Đổi màu kí tự 
void AnTroChuot();    // Ẩn trỏ chuột
void HienTroChuot();  // Hiện trỏ chuột
void ScreenStartGame(int); // Menu Chính
//void PrintScoreBoard(); // In bảng điểm
//int PlayerVsCom(Diem& a, int, char data[30]); // BOT HARD
//int PlayerVsCom2(Diem& a, int, char data[30]); // BOT EASY
//int PlayerVsPlayer(Diem& a, int, char data[30]); // P VS P
void Help(); // Help
void About(); // About 
//void LoadLoad(); // Load Game
//Kien test sound
extern bool isSoundOn;
static int SOUND_ON = 1;
void playSound(int i);
void settingPlaySound(int input);