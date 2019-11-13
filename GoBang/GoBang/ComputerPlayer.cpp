#include "ComputerPlayer.h"



ComputerPlayer::ComputerPlayer()
{
}


ComputerPlayer::~ComputerPlayer()
{

}
/*由算法确定下一步棋应该走的位置*/
int ComputerPlayer::nextStep(int& row, int& colunm, Chess* board[15][15])
{
	char valueGrid[15][15];				//电脑判断的有效格子
	long scores[15][15];				//电脑给每个格子的评分
	for (int i = 0; i < 15; i++)		//给数组赋值为所有值为0
	{
		for (int j = 0; j < 15; j++)
		{
			valueGrid[i][j] = 0;
		}
	}  
	for (int i = 0; i < 15; i++)		//得到电脑判断有效位置。只有在有棋子地方的相邻格子才是电脑判断的有效格子，有效格子在对应的valueGrid中置1
	{
		for (int j = 0; j < 15; j++)
		{
			if (board[i][j] != nullptr)
			{
				if (i == 0 && j == 0)
				{
					if (board[i + 1][j + 1] == nullptr)
					{
						valueGrid[i + 1][j + 1] = 1;
					}
					if (board[i ][j + 1] == nullptr)
					{
						valueGrid[i ][j + 1] = 1;
					}
					if (board[i + 1][j ] == nullptr)
					{
						valueGrid[i + 1][j ] = 1;
					}
					
				}
				else if (i == 0 && j == 14)
				{
					if (board[i + 1][j] == nullptr)
					{
						valueGrid[i + 1][j] = 1;
					}
					if (board[i][j - 1] == nullptr)
					{
						valueGrid[i][j - 1] = 1;
					}
					if (board[i + 1][j - 1] == nullptr)
					{
						valueGrid[i + 1][j - 1] = 1;
					}
				}
				else if (i == 14 && j == 0)
				{
					if (board[i - 1][j + 1] == nullptr)
					{
						valueGrid[i - 1][j + 1] = 1;
					}
					if (board[i][j + 1] == nullptr)
					{
						valueGrid[i][j + 1] = 1;
					}
					if (board[i - 1][j] == nullptr)
					{
						valueGrid[i - 1][j] = 1;
					}
				}
				else if (i == 14 && j == 14)
				{
					if (board[i - 1][j - 1] == nullptr)
					{
						valueGrid[i - 1][j - 1] = 1;
					}
					if (board[i][j - 1] == nullptr)
					{
						valueGrid[i][j - 1] = 1;
					}
					if (board[i - 1][j] == nullptr)
					{
						valueGrid[i - 1][j] = 1;
					}
				}
				else if (i == 0)
				{
					
					//
					if (board[i][j - 1] == nullptr)
					{
						valueGrid[i][j - 1] = 1;
					}
					if (board[i][j + 1] == nullptr)
					{
						valueGrid[i][j + 1] = 1;
					}
					//
					if (board[i + 1][j - 1] == nullptr)
					{
						valueGrid[i + 1][j - 1] = 1;
					}
					if (board[i + 1][j] == nullptr)
					{
						valueGrid[i + 1][j] = 1;
					}

					if (board[i + 1][j + 1] == nullptr)
					{
						valueGrid[i + 1][j + 1] = 1;
					}
				}
				else if (j == 0)
				{
				
					if (board[i - 1][j] == nullptr)
					{
						valueGrid[i - 1][j] = 1;
					}

					if (board[i - 1][j + 1] == nullptr)
					{
						valueGrid[i - 1][j + 1] = 1;
					}
					//
					
					if (board[i][j + 1] == nullptr)
					{
						valueGrid[i][j + 1] = 1;
					}
					//
					
					if (board[i + 1][j] == nullptr)
					{
						valueGrid[i + 1][j] = 1;
					}

					if (board[i + 1][j + 1] == nullptr)
					{
						valueGrid[i + 1][j + 1] = 1;
					}
				}
				else if (i == 14)
				{
				if (board[i - 1][j - 1] == nullptr)
				{
					valueGrid[i - 1][j - 1] = 1;
				}
				if (board[i - 1][j] == nullptr)
				{
					valueGrid[i - 1][j] = 1;
				}

				if (board[i - 1][j + 1] == nullptr)
				{
					valueGrid[i - 1][j + 1] = 1;
				}
				//
				if (board[i][j - 1] == nullptr)
				{
					valueGrid[i][j - 1] = 1;
				}
				if (board[i][j + 1] == nullptr)
				{
					valueGrid[i][j + 1] = 1;
				}
				//
			
				}
				else if (j == 14)
				{
				if (board[i - 1][j - 1] == nullptr)
				{
					valueGrid[i - 1][j - 1] = 1;
				}
				if (board[i - 1][j] == nullptr)
				{
					valueGrid[i - 1][j] = 1;
				}

				//
				if (board[i][j - 1] == nullptr)
				{
					valueGrid[i][j - 1] = 1;
				}

				//
				if (board[i + 1][j - 1] == nullptr)
				{
					valueGrid[i + 1][j - 1] = 1;
				}
				if (board[i + 1][j] == nullptr)
				{
					valueGrid[i + 1][j] = 1;
				}

				}
				else
				{
					if (board[i - 1][j - 1] == nullptr)
					{
						valueGrid[i - 1][j - 1] = 1;
					}
					if (board[i - 1][j] == nullptr)
					{
						valueGrid[i - 1][j] = 1;
					}
					
					if (board[i - 1][j + 1] == nullptr)
					{
						valueGrid[i - 1][j + 1] = 1;
					}
					//
					if (board[i][j - 1] == nullptr)
					{
						valueGrid[i][j - 1] = 1;
					}
					if (board[i][j + 1] == nullptr)
					{
						valueGrid[i][j + 1] = 1;
					}
					//
					if (board[i + 1][j - 1] == nullptr)
					{
						valueGrid[i + 1][j - 1] = 1;
					}
					if (board[i + 1][j] == nullptr)
					{
						valueGrid[i + 1][j] = 1;
					}

					if (board[i + 1][j + 1] == nullptr)
					{
						valueGrid[i + 1][j + 1] = 1;
					}
				}
			}
		}
	}

	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			scores[i][j] = 0;
			if (valueGrid[i][j] == 1)
			{
				scores[i][j] = getScore1(i, j, board, 0) + getScore1(i, j, board, 1);		//得到自己和对方的横向评分
				scores[i][j] += getScore2(i, j, board, 0) + getScore2(i, j, board, 1);		//得到自己和对方的纵向评分
				scores[i][j] += getScore3(i, j, board, 0) + getScore3(i, j, board, 1);		//得到自己和对方的下斜评分
				scores[i][j] += getScore4(i, j, board, 0) + getScore4(i, j, board, 1);		//得到自己和对方的上斜评分

			}
		}
	}
	findMax(scores, row, colunm);		//寻找评分最大值的i和j就是电脑得出下一步的位置
	return 0;
}
/*给一个15*15的数组，寻找其中最大值的i和j*/
void ComputerPlayer::findMax(long scores[15][15], int&row, int& colunm)
{
	int max_value = scores[0][0];
	row = 0;
	colunm = 0;
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			if (scores[i][j] > max_value)
			{
				max_value = scores[i][j];
				row = i;
				colunm = j;
			}
		}
	}
}


/*以下四个函数均是根据评分表来进行判断相应的情况，进而返回对应情况的分数*/
/*得到color颜色的横向评分*/
int ComputerPlayer::getScore1(int i, int j, Chess* board[15][15],char color)
{
	//横向
	int count = 0;
	int block = 0;

	//向左扫描
	int temp = 1;
	while (j - temp >= 0)
	{
		if (board[i][j - temp] == nullptr)
		{
			break;
		}
		else if (board[i][j - temp]->getColor() == color)
		{
			count++;
		}
		else if (board[i][j - temp]->getColor() != color)
		{
			block++;
			break;
		}
		temp++;
	}

	temp = 1;
	while (j + temp <= 14)
	{
		if (board[i][j + temp] == nullptr)
		{
			break;
		}
		else if (board[i][j + temp]->getColor() == color)
		{
			count++;
		}
		else if (board[i][j + temp]->getColor() != color)
		{
			block++;
			break;
		}
		temp++;
	}

	if (count >= 4)
	{
		return 20000;
	}
	else if (count == 3 && block == 0)
	{
		return 10000;
	}
	else if (count == 3 && block == 1)
	{
		return 5000;
	}
	else if (count == 3 && block == 2)
	{
		return 2000;
	}
	else if (count == 2 && block == 0)
	{
		return 4500;
	}
	else if (count == 2 && block == 1)
	{
		return 2000;
	}
	else if (count == 2 && block == 2)
	{
		return 1000;
	}
	else if (count == 1 && block == 0)
	{
		return 1000;
	}
	else if (count == 1 && block == 1)
	{
		return 500;
	}
	else if (count == 1 && block == 2)
	{
		return 100;
	}
	else if (count == 0) { return 20; }

}
/*得到color颜色的纵向评分*/
int ComputerPlayer::getScore2(int i, int j, Chess* board[15][15],char color)
{
	//横向
	int count = 0;
	int block = 0;

	//向左扫描
	int temp = 1;
	while (i - temp >= 0)
	{
		if (board[i-temp][j] == nullptr)
		{
			break;
		}
		else if (board[i-temp][j]->getColor() == color)
		{
			count++;
		}
		else if (board[i-temp][j]->getColor() != color)
		{
			block++;
			break;
		}
		temp++;
	}

	temp = 1;
	while (i + temp <= 14)
	{
		if (board[i + temp][j] == nullptr)
		{
			break;
		}
		else if (board[i + temp][j]->getColor() == color)
		{
			count++;
		}
		else if (board[i + temp][j]->getColor() != color)
		{
			block++;
			break;
		}
		temp++;
	}

	if (count >= 4)
	{
		return 20000;
	}
	else if (count == 3 && block == 0)
	{
		return 10000;
	}
	else if (count == 3 && block == 1)
	{
		return 5000;
	}
	else if (count == 3 && block == 2)
	{
		return 2000;
	}
	else if (count == 2 && block == 0)
	{
		return 4500;
	}
	else if (count == 2 && block == 1)
	{
		return 2000;
	}
	else if (count == 2 && block == 2)
	{
		return 1000;
	}
	else if (count == 1 && block == 0)
	{
		return 1000;
	}
	else if (count == 1 && block == 1)
	{
		return 500;
	}
	else if (count == 1 && block == 2)
	{
		return 100;
	}
	else if (count == 0) { return 20; }
}
/*得到color颜色的下斜评分*/
int ComputerPlayer::getScore3(int i, int j, Chess* board[15][15],char color)
{
	//横向
	int count = 0;
	int block = 0;

	//向左扫描
	int temp = 1;
	while (j - temp >= 0 && i - temp >= 0)
	{
		if (board[i - temp][j - temp] == nullptr)
		{
			break;
		}
		else if (board[i - temp][j - temp]->getColor() == color)
		{
			count++;
		}
		else if (board[i - temp][j - temp]->getColor() != color)
		{
			block++;
			break;
		}
		temp++;
	}

	temp = 1;
	while (j + temp <= 14 && i + temp <= 14)
	{
		if (board[i + temp][j + temp] == nullptr)
		{
			break;
		}
		else if (board[i + temp][j + temp]->getColor() == color)
		{
			count++;
		}
		else if (board[i + temp][j + temp]->getColor() != color)
		{
			block++;
			break;
		}
		temp++;
	}

	if (count >= 4)
	{
		return 20000;
	}
	else if (count == 3 && block == 0)
	{
		return 10000;
	}
	else if (count == 3 && block == 1)
	{
		return 5000;
	}
	else if (count == 3 && block == 2)
	{
		return 2000;
	}
	else if (count == 2 && block == 0)
	{
		return 4500;
	}
	else if (count == 2 && block == 1)
	{
		return 2000;
	}
	else if (count == 2 && block == 2)
	{
		return 1000;
	}
	else if (count == 1 && block == 0)
	{
		return 1000;
	}
	else if (count == 1 && block == 1)
	{
		return 500;
	}
	else if (count == 1 && block == 2)
	{
		return 100;
	}
	else if (count == 0) { return 20; }
}
/*得到color颜色的上斜评分*/
int ComputerPlayer::getScore4(int i, int j, Chess* board[15][15],char color)
{
	//横向
	int count = 0;
	int block = 0;

	//向左扫描
	int temp = 1;
	while (j - temp >= 0 && i + temp <= 14)
	{
		if (board[i + temp][j - temp] == nullptr)
		{
			break;
		}
		else if (board[i + temp][j - temp]->getColor() == color)
		{
			count++;
		}
		else if (board[i + temp][j - temp]->getColor() != color)
		{
			block++;
			break;
		}
		temp++;
	}

	temp = 1;
	while (j + temp <= 14 && i -temp >= 0)
	{
		if (board[i - temp][j + temp] == nullptr)
		{
			break;
		}
		else if (board[i - temp][j + temp]->getColor() == color)
		{
			count++;
		}
		else if (board[i - temp][j + temp]->getColor() != color)
		{
			block++;
			break;
		}
		temp++;
	}

	if (count >= 4)
	{
		return 20000;
	}
	else if (count == 3 && block == 0)
	{
		return 10000;
	}
	else if (count == 3 && block == 1)
	{
		return 5000;
	}
	else if (count == 3 && block == 2)
	{
		return 2000;
	}
	else if (count == 2 && block == 0)
	{
		return 4500;
	}
	else if (count == 2 && block == 1)
	{
		return 2000;
	}
	else if (count == 2 && block == 2)
	{
		return 1000;
	}
	else if (count == 1 && block == 0)
	{
		return 1000;
	}
	else if (count == 1 && block == 1)
	{
		return 500;
	}
	else if (count == 1 && block == 2)
	{
		return 100;
	}
	else if (count == 0) { return 20; }
}