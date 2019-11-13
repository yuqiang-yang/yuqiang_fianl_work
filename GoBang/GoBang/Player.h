#pragma once
#include <windows.h>
#include <conio.h>
#include "ChessBoard.h"
#include "DrawUtil.h"
class Player
{
public:
	Player();
	~Player();

	virtual void nextStep(int& row, int& colunm,ChessBoard& board);	//得出下一步应该所下棋的位置
	COORD coord;
};

