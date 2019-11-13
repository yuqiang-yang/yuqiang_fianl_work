#pragma once
#include "Player.h"
#include "ChessBoard.h"
class ComputerPlayer :	public Player
{
public:
	ComputerPlayer();
	~ComputerPlayer();
	int nextStep(int& row, int& colunm, Chess* board[15][15]);			/*���㷨ȷ����һ����Ӧ���ߵ�λ��*/
	void findMax(long scores[15][15],int&row,int& colunm);				/*��һ��15*15�����飬Ѱ���������ֵ��i��j*/
	int getScore1(int i, int j, Chess* board[15][15],char color);		/*�õ�color��ɫ�ĺ�������*/
	int getScore2(int i, int j, Chess* board[15][15],char color);		/*�õ�color��ɫ����������*/
	int getScore3(int i, int j, Chess* board[15][15],char color);		/*�õ�color��ɫ����б����*/
	int getScore4(int i, int j, Chess* board[15][15],char color);		/*�õ�color��ɫ����б����*/


};

