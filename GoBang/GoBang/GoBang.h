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

	void control();				//������Ϸ�����غ���
	void selectDisplay();		//ѡ�������ʾ
	void playerMode();			//��Ҷ�սģʽ	
	void computerMode();		//���Զ�սģʽ
	void saveMode();			//����ģʽ	
	void turn(char& player);	//�л��غ�
private:
	COORD coord;				//�洢����ֵ�ı���
	ChessBoard board;			//�洢��Ϸ������
	FileUtil fileUtil;			//�����浵�Ĺ�����

};

