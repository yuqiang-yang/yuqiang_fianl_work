#include "ChessBoard.h"


ChessBoard::ChessBoard()
{
	/*��ʼ������*/
	for (int i = 0; i < 15; i++)
	{
		for(int j = 0; j < 15; j++)
		{
			board[i][j] = nullptr;
		}
	}
	/*��ʼ�������¼����*/
	for (int i = 0; i < 10; i++)
	{
		chessHistory[i] = nullptr;
	}
}
ChessBoard::~ChessBoard()
{

}
/*����������*/
void ChessBoard::clearBoard()
{
	for (int i = 0; i < 14; i++)
	{
		for (int j = 0; j < 14; j++)
		{
			if (board[i][j] != nullptr)
			{
				delete board[i][j];
				board[i][j] = nullptr;
			}
		}
	}
}
/*���庯��������һ��chess������ɹ�����true�����򷵻�false*/
bool ChessBoard::putChess(Chess* chess)
{
	int row, colunm;
	chess->getPosition(row, colunm);		//�����õ����к��е�ֵ�洢��row��colunm��
	DrawUtil::moveCursor(4 * row, 2 * colunm);
	if (getChess(row, colunm) == nullptr)	//�ж���������ø�������ſ�����
	{
		board[row][colunm] = chess;
		
		/*��¼������ʷ*/
		for (int i = 9; i >= 1; i--)	
		{
			chessHistory[i] = chessHistory[i-1];
		}
		chessHistory[0] = chess;
		
		
		/*���㺯��*/
		if (chess->getColor() == 0)
		{
			DrawUtil::setText(FOREGROUND_INTENSITY | FOREGROUND_RED);
			cout << "��\b";
		}
		else
		{
			DrawUtil::setText(FOREGROUND_INTENSITY|FOREGROUND_GREEN);
			cout << "��\b";
		}
		return true;
	}
	else
	{
		return false;
	}
}
/*�õ�ĳ��λ�õ�����*/
Chess* ChessBoard::getChess(int row, int column)
{
	return board[row][column];
}
/*��ӡһ��������*/
void ChessBoard::printBoard()
{
	DrawUtil::moveCursor(0, 0);
	DrawUtil::setText(FOREGROUND_INTENSITY | FOREGROUND_BLUE| FOREGROUND_GREEN);
	cout << "���������ө������ө������ө������ө������ө������ө������ө������ө������ө������ө������ө������ө������ө�������\n";
	for (int i = 0; i < 13; i++)
	{
		cout << "��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��\n";
		cout << "�ĩ������੤�����੤�����੤�����੤�����੤�����੤�����੤�����੤�����੤�����੤�����੤�����੤�����੤������\n";
	}
	cout << "��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��\n";
	cout << "���������۩������۩������۩������۩������۩������۩������۩������۩������۩������۩������۩������۩������۩�������\n";


}
/*�ж����޾���ʤ��*/
bool ChessBoard::win()
{
	int i, j, f;

	//��ɫ0
	for (i = 0; i < 15; i++)
	{/*����*/
		j = f = 0;
		while (f < 5 && j < 15)
		{
			if (getChess(i,j) != nullptr && getChess(i,j)->getColor() == 0) f++;
			else f = 0;
			j++;
		}
		if (f == 5) return true;
	}
	for (j = 0; j < 15; j++)
	{/*����*/
		i = f = 0;
		while (f < 5 && i < 15)
		{
			if (getChess(i,j) != nullptr && getChess(i,j)->getColor() == 0) f++;
			else f = 0;
			i++;
		}
		if (f == 5) return true;
	}
	for (i = 0; i < 11; i++)
	{/*��б*/
		j = f = 0;
		while (f < 5 && j < 11)
		{
			if (getChess(i+f,j+f) != nullptr && getChess(i+f, j+f)->getColor() == 0) f++;
			else { f = 0; j++; }
		}
		if (f == 5) return true;
	}
	for (i = 4; i < 15; i++)
	{/*��б*/
		j = f = 0;
		while (f < 5 && j < 11)
		{
			if (getChess(i - f, j + f) != nullptr && getChess(i - f, j + f)->getColor() == 0) f++;
			else { f = 0; j++; }
		}
		if (f == 5) return true;
	}

	//��ɫ1
	for (i = 0; i < 15; i++)
	{/*����*/
		j = f = 0;
		while (f < 5 && j < 15)
		{
			if (getChess(i, j) != nullptr && getChess(i, j)->getColor() == 1) f++;
			else f = 0;
			j++;
		}
		if (f == 5) return true;
	}
	for (j = 0; j < 15; j++)
	{/*����*/
		i = f = 0;
		while (f < 5 && i < 15)
		{
			if (getChess(i, j) != nullptr && getChess(i, j)->getColor() == 1) f++;
			else f = 0;
			i++;
		}
		if (f == 5) return true;
	}
	for (i = 0; i < 11; i++)
	{/*��б*/
		j = f = 0;
		while (f < 5 && j < 11)
		{
			if (getChess(i + f, j + f) != nullptr && getChess(i + f, j + f)->getColor() == 1) f++;
			else { f = 0; j++; }
		}
		if (f == 5) return true;
	}
	for (i = 4; i < 15; i++)
	{/*��б*/
		j = f = 0;
		while (f < 5 && j < 11)
		{
			if (getChess(i - f, j + f) != nullptr && getChess(i - f, j + f)->getColor() == 1) f++;
			else { f = 0; j++; }
		}
		if (f == 5) return true;
	}
	return false;
}
/*�Ƴ�����*/
bool ChessBoard::delChess(Chess* chess)
{
	int row, colunm;
	if (chess != nullptr && chess !=NULL)
	{
		chess->getPosition(row, colunm);
		delete board[row][colunm];
		board[row][colunm] = nullptr;
		DrawUtil::moveCursor(row * 4, colunm * 2 );
		DrawUtil::setText( FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
		if (row == 0 && colunm == 0)
		{
			cout << "����\b\b";
		}
		else if (row == 0 && colunm != 14)
		{
			cout << "�ĩ�\b\b";

		}
		else if (colunm == 0 && row != 14)
		{
			cout << "�ө�\b\b";


		}
		else if (row == 14 && colunm == 14)
		{
			cout << "��  \b\b";

		}
		else if (row == 0 && colunm == 14)
		{
			cout << "����\b\b";
		}
		else if (row == 14)
		{
			cout << "��  \b\b";

		}
		else if (colunm == 14)
		{
			cout << "�۩�\b\b";

		}
		else
		{
			cout << "�੤\b\b";

		}
		return true;
	}
	else
	{
		return false;
	}
}
/*���庯��*/
bool ChessBoard::regret()
{

	if (delChess(chessHistory[0]))
	{
		for (int i = 0; i <= 8; i++)
		{
			chessHistory[i] = chessHistory[i+1];
		}
		chessHistory[9] = nullptr;
		return true;
	}
	else
	{
		return false;
	}
}