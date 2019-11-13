#pragma once
class Chess
{
public:
	Chess(char color, int row, int column);
	~Chess();


	inline char getColor() { return color; }
	inline void getPosition(int& row, int& column) { row = this->row; column = this->column; }
private:
	char color = -1;			//棋子的颜色，0为白，1为黑。	-1表示未经初始化
	int row = -1, column = -1;	//棋子所在的行和列，0-14		-1表示未经初始化
};

