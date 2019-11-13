#pragma once
#include "Player.h"
#include <string>

class PeoplePlayer :	public Player
{
public:
	PeoplePlayer(std::string name);
	~PeoplePlayer();
	inline std::string getName() { return name; }

	/*从键盘中获取下一步棋子的行和列，并返回状态值。0为获取成功，1为悔棋，2为存档*/
	int nextStep(short& row, short& colunm, ChessBoard& board);	

private:
	std::string name;
};

