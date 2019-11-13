#pragma once
#include "Player.h"
#include <string>

class PeoplePlayer :	public Player
{
public:
	PeoplePlayer(std::string name);
	~PeoplePlayer();
	inline std::string getName() { return name; }

	/*�Ӽ����л�ȡ��һ�����ӵ��к��У�������״ֵ̬��0Ϊ��ȡ�ɹ���1Ϊ���壬2Ϊ�浵*/
	int nextStep(short& row, short& colunm, ChessBoard& board);	

private:
	std::string name;
};

