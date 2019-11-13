#include "PeoplePlayer.h"


/*���ι��죬��ʼ����ҵ�����*/
PeoplePlayer::PeoplePlayer(std::string name)
{
	this->name = name;
}
PeoplePlayer::~PeoplePlayer()
{
}
/*�Ӽ����л�ȡ��һ�����ӵ��к��У�������״ֵ̬��0Ϊ��ȡ�ɹ���1Ϊ���壬2Ϊ�浵*/
int PeoplePlayer::nextStep(short& row, short& colunm, ChessBoard& board)
{
	int key;		//��ȡ���̵�����
	int w;			//��ȡ���̵�����

	coord.X = row;
	coord.Y = colunm;
	while (key = _getch())
	{
		switch (key)
		{
		case 13:				//�����������س�����洢��ʱ������ֵ��������0��ʾ�ɹ�
			row = coord.X;
			colunm = coord.Y;
			return 0;
		case '9':				//����9��ʾ����
			return 1;
		case '8':
			return 2;			//����8��ʾ�浵
		case 224:
			w = _getch();
			switch (w)
			{
			
			case 72:			//��
				for (int i = 1; coord.Y - 2 * i >= 0; i++)
				{
					if (board.getChess(coord.X / 4,coord.Y / 2 - i) == nullptr)
					{
						coord.Y -= 2 * i;
						break;
					}
				}
				break;
			case 80:		//��
				for (int i = 1; coord.Y + 2 * i <= 28; i++)
				{
					if (board.getChess(coord.X / 4, coord.Y / 2 + i) == nullptr)
					{
						coord.Y += 2 * i;
						break;

					}
				}
				break;
			case 75:		//��
				for (int i = 1; coord.X - 4 * i >= 0; i++)
				{
					if (board.getChess(coord.X / 4 - i, coord.Y / 2) == nullptr)
					{
						coord.X -= 4 * i;
						break;
					}
				}
				break;
			case 77:		//��
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