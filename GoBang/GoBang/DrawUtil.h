#pragma once
#include <windows.h>
#include <conio.h>
#include <iostream>
class DrawUtil
{
public:
	DrawUtil();
	~DrawUtil();
	static void moveCursor(int x,int y);			//�ƶ����
	static void setText(_In_ WORD wAttributes);		//����������ɫ
	static void clear();							//����
};

