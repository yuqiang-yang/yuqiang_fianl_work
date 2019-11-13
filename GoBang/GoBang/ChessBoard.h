#pragma once
#include "Chess.h"
#include <iostream>
#include "DrawUtil.h"
using namespace std;
class ChessBoard
{
public:
	ChessBoard();
	~ChessBoard();
	bool putChess(Chess* chess);			//放置棋子到棋盘上
	bool delChess(Chess* chess);			//删除棋子
	Chess* getChess(int row, int column);	//得到的某个位置棋子的值
	void printBoard();						//打印棋盘
	bool win();								//判断有无决出胜负
	void clearBoard();						//将board里面所有的位置都置为空指针，清空board
	bool regret();							//悔棋函数
public:
	Chess* board[15][15];					//一个15*15的棋盘
	COORD coord;
	Chess* chessHistory[10];				//记录上十次所下棋的棋子

};

