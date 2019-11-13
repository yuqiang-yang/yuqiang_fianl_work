#pragma once
#include <windows.h>
#include <conio.h>
#include <iostream>
class DrawUtil
{
public:
	DrawUtil();
	~DrawUtil();
	static void moveCursor(int x,int y);			//移动光标
	static void setText(_In_ WORD wAttributes);		//设置文字颜色
	static void clear();							//清屏
};

