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
	bool putChess(Chess* chess);			//�������ӵ�������
	bool delChess(Chess* chess);			//ɾ������
	Chess* getChess(int row, int column);	//�õ���ĳ��λ�����ӵ�ֵ
	void printBoard();						//��ӡ����
	bool win();								//�ж����޾���ʤ��
	void clearBoard();						//��board�������е�λ�ö���Ϊ��ָ�룬���board
	bool regret();							//���庯��
public:
	Chess* board[15][15];					//һ��15*15������
	COORD coord;
	Chess* chessHistory[10];				//��¼��ʮ�������������

};

