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

	virtual void nextStep(int& row, int& colunm,ChessBoard& board);	//�ó���һ��Ӧ���������λ��
	COORD coord;
};

