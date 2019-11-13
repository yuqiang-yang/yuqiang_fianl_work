#include "ComputerPlayer.h"



ComputerPlayer::ComputerPlayer()
{
}


ComputerPlayer::~ComputerPlayer()
{

}
/*���㷨ȷ����һ����Ӧ���ߵ�λ��*/
int ComputerPlayer::nextStep(int& row, int& colunm, Chess* board[15][15])
{
	char valueGrid[15][15];				//�����жϵ���Ч����
	long scores[15][15];				//���Ը�ÿ�����ӵ�����
	for (int i = 0; i < 15; i++)		//�����鸳ֵΪ����ֵΪ0
	{
		for (int j = 0; j < 15; j++)
		{
			valueGrid[i][j] = 0;
		}
	}  
	for (int i = 0; i < 15; i++)		//�õ������ж���Чλ�á�ֻ���������ӵط������ڸ��Ӳ��ǵ����жϵ���Ч���ӣ���Ч�����ڶ�Ӧ��valueGrid����1
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
				scores[i][j] = getScore1(i, j, board, 0) + getScore1(i, j, board, 1);		//�õ��Լ��ͶԷ��ĺ�������
				scores[i][j] += getScore2(i, j, board, 0) + getScore2(i, j, board, 1);		//�õ��Լ��ͶԷ�����������
				scores[i][j] += getScore3(i, j, board, 0) + getScore3(i, j, board, 1);		//�õ��Լ��ͶԷ�����б����
				scores[i][j] += getScore4(i, j, board, 0) + getScore4(i, j, board, 1);		//�õ��Լ��ͶԷ�����б����

			}
		}
	}
	findMax(scores, row, colunm);		//Ѱ���������ֵ��i��j���ǵ��Եó���һ����λ��
	return 0;
}
/*��һ��15*15�����飬Ѱ���������ֵ��i��j*/
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


/*�����ĸ��������Ǹ������ֱ��������ж���Ӧ��������������ض�Ӧ����ķ���*/
/*�õ�color��ɫ�ĺ�������*/
int ComputerPlayer::getScore1(int i, int j, Chess* board[15][15],char color)
{
	//����
	int count = 0;
	int block = 0;

	//����ɨ��
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
/*�õ�color��ɫ����������*/
int ComputerPlayer::getScore2(int i, int j, Chess* board[15][15],char color)
{
	//����
	int count = 0;
	int block = 0;

	//����ɨ��
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
/*�õ�color��ɫ����б����*/
int ComputerPlayer::getScore3(int i, int j, Chess* board[15][15],char color)
{
	//����
	int count = 0;
	int block = 0;

	//����ɨ��
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
/*�õ�color��ɫ����б����*/
int ComputerPlayer::getScore4(int i, int j, Chess* board[15][15],char color)
{
	//����
	int count = 0;
	int block = 0;

	//����ɨ��
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