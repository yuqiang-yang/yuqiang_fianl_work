#include "PeoplePlayer.h"


/*带参构造，初始化玩家的姓名*/
PeoplePlayer::PeoplePlayer(std::string name)
{
	this->name = name;
}
PeoplePlayer::~PeoplePlayer()
{
}
/*从键盘中获取下一步棋子的行和列，并返回状态值。0为获取成功，1为悔棋，2为存档*/
int PeoplePlayer::nextStep(short& row, short& colunm, ChessBoard& board)
{
	int key;		//获取键盘的输入
	int w;			//获取键盘的输入

	coord.X = row;
	coord.Y = colunm;
	while (key = _getch())
	{
		switch (key)
		{
		case 13:				//假如键盘输入回车，则存储此时的行列值，并返回0表示成功
			row = coord.X;
			colunm = coord.Y;
			return 0;
		case '9':				//输入9表示悔棋
			return 1;
		case '8':
			return 2;			//输入8表示存档
		case 224:
			w = _getch();
			switch (w)
			{
			
			case 72:			//上
				for (int i = 1; coord.Y - 2 * i >= 0; i++)
				{
					if (board.getChess(coord.X / 4,coord.Y / 2 - i) == nullptr)
					{
						coord.Y -= 2 * i;
						break;
					}
				}
				break;
			case 80:		//下
				for (int i = 1; coord.Y + 2 * i <= 28; i++)
				{
					if (board.getChess(coord.X / 4, coord.Y / 2 + i) == nullptr)
					{
						coord.Y += 2 * i;
						break;

					}
				}
				break;
			case 75:		//左
				for (int i = 1; coord.X - 4 * i >= 0; i++)
				{
					if (board.getChess(coord.X / 4 - i, coord.Y / 2) == nullptr)
					{
						coord.X -= 4 * i;
						break;
					}
				}
				break;
			case 77:		//右
				for (int i = 1; coord.X + 4 * i <= 56; i++)
				{
					if (board.getChess(coord.X / 4 + i, coord.Y / 2) == nullptr)
					{
						coord.X += 4 * i;
						break;
					}
				}
				break;
			}
			DrawUtil::moveCursor(coord.X, coord.Y);

		}
	}
	
}