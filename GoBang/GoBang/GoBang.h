#pragma once
#include "ChessBoard.h"
#include <iostream>
#include <string>
#include "PeoplePlayer.h"
#include "ComputerPlayer.h"
#include "Chess.h"
#include "FileUtil.h"
#include "DrawUtil.h"
using namespace std;

class GoBang
{
public:
	GoBang(ChessBoard board);
	~GoBang();

	void control();				//整个游戏的主控函数
	void selectDisplay();		//选择界面显示
	void playerMode();			//玩家对战模式	
	void computerMode();		//电脑对战模式
	void saveMode();			//读档模式	
	void turn(char& player);	//切换回合
private:
	COORD coord;				//存储坐标值的变量
	ChessBoard board;			//存储游戏的棋盘
	FileUtil fileUtil;			//读档存档的工具类

};

