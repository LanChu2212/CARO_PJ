#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <chrono>
#include <vector>
#include <cmath>
#include<iostream>
#include<windows.h>
#include<conio.h>
#include"_Play.h"
#include"PlayervsPlayer.h"
#include "Loadingbar.h"

const std::string RESET_COLOR = "\033[0m";
const std::vector<std::string> COLORS = {
    "\033[31m", // Red
    "\033[32m", // Green
    "\033[33m", // Yellow
    "\033[34m", // Blue
    "\033[35m", // Magenta
    "\033[36m", // Cyan
    "\033[37m"  // White
};
// Hàm để thay đổi màu sắc theo chu kỳ
std::string getDynamicColor(int frameIndex);
// Hàm để tạo hiệu ứng đi lên và xuống
std::string applyVerticalMotion(const std::string& frame, int frameIndex, float n);
//hàm để tạo hiệu ứng cho textfile
void Textdecorate(std::string filename, float n,int i);
void  DrawBoardAbout(int pSize,float Left,float Top);
void In_Tep(const char* FileName);
//Ve khung giao dien 
void KhungGiaoDien();