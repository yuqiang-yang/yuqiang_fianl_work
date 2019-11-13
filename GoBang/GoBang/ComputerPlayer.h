#pragma once
#include "Player.h"
#include "ChessBoard.h"
class ComputerPlayer :	public Player
{
public:
	ComputerPlayer();
	~ComputerPlayer();
	int nextStep(int& row, int& colunm, Chess* board[15][15]);			/*由算法确定下一步棋应该走的位置*/
	void findMax(long scores[15][15],int&row,int& colunm);				/*给一个15*15的数组，寻找其中最大值的i和j*/
	int getScore1(int i, int j, Chess* board[15][15],char color);		/*得到color颜色的横向评分*/
	int getScore2(int i, int j, Chess* board[15][15],char color);		/*得到color颜色的纵向评分*/
	int getScore3(int i, int j, Chess* board[15][15],char color);		/*得到color颜色的下斜评分*/
	int getScore4(int i, int j, Chess* board[15][15],char color);		/*得到color颜色的上斜评分*/


};

