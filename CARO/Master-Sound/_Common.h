#pragma once
#include <Windows.h>

class _Common
{
public:
	static void fixConsoleWindow();
	// C? �?nh m�n h?nh Console
	static void gotoXY(int, int);
	// Di chuy?n �?n t?a �? (x,y) trong m�n h?nh Console
	static void setConsoleWindow(int w, int h);
	// Ch?nh size c?a m�n h?nh Console 
public:
	_Common();
	~_Common();
};
