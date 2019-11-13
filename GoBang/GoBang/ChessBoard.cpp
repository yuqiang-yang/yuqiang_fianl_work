#include "ChessBoard.h"


ChessBoard::ChessBoard()
{
	/*初始化棋盘*/
	for (int i = 0; i < 15; i++)
	{
		for(int j = 0; j < 15; j++)
		{
			board[i][j] = nullptr;
		}
	}
	/*初始化下棋记录数组*/
	for (int i = 0; i < 10; i++)
	{
		chessHistory[i] = nullptr;
	}
}
ChessBoard::~ChessBoard()
{

}
/*将棋盘清零*/
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
/*下棋函数。传入一个chess，下棋成功返回true，否则返回false*/
bool ChessBoard::putChess(Chess* chess)
{
	int row, colunm;
	chess->getPosition(row, colunm);		//将所得到的行和列的值存储在row和colunm中
	DrawUtil::moveCursor(4 * row, 2 * colunm);
	if (getChess(row, colunm) == nullptr)	//判断棋盘里面该格子无棋才可下棋
	{
		board[row][colunm] = chess;
		
		/*记录下棋历史*/
		for (int i = 9; i >= 1; i--)	
		{
			chessHistory[i] = chessHistory[i-1];
		}
		chessHistory[0] = chess;
		
		
		/*画点函数*/
		if (chess->getColor() == 0)
		{
			DrawUtil::setText(FOREGROUND_INTENSITY | FOREGROUND_RED);
			cout << "●\b";
		}
		else
		{
			DrawUtil::setText(FOREGROUND_INTENSITY|FOREGROUND_GREEN);
			cout << "◆\b";
		}
		return true;
	}
	else
	{
		return false;
	}
}
/*得到某个位置的棋子*/
Chess* ChessBoard::getChess(int row, int column)
{
	return board[row][column];
}
/*打印一个空棋盘*/
void ChessBoard::printBoard()
{
	DrawUtil::moveCursor(0, 0);
	DrawUtil::setText(FOREGROUND_INTENSITY | FOREGROUND_BLUE| FOREGROUND_GREEN);
	cout << "┏━━━┯━━━┯━━━┯━━━┯━━━┯━━━┯━━━┯━━━┯━━━┯━━━┯━━━┯━━━┯━━━┯━━━┓\n";
	for (int i = 0; i < 13; i++)
	{
		cout << "┃   │   │   │   │   │   │   │   │   │   │   │   │   │   ┃\n";
		cout << "┠───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┨\n";
	}
	cout << "┃   │   │   │   │   │   │   │   │   │   │   │   │   │   ┃\n";
	cout << "┗━━━┷━━━┷━━━┷━━━┷━━━┷━━━┷━━━┷━━━┷━━━┷━━━┷━━━┷━━━┷━━━┷━━━┛\n";


}
/*判断有无决出胜负*/
bool ChessBoard::win()
{
	int i, j, f;

	//颜色0
	for (i = 0; i < 15; i++)
	{/*横向*/
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
	{/*纵向*/
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
	{/*下斜*/
		j = f = 0;
		while (f < 5 && j < 11)
		{
			if (getChess(i+f,j+f) != nullptr && getChess(i+f, j+f)->getColor() == 0) f++;
			else { f = 0; j++; }
		}
		if (f == 5) return true;
	}
	for (i = 4; i < 15; i++)
	{/*上斜*/
		j = f = 0;
		while (f < 5 && j < 11)
		{
			if (getChess(i - f, j + f) != nullptr && getChess(i - f, j + f)->getColor() == 0) f++;
			else { f = 0; j++; }
		}
		if (f == 5) return true;
	}

	//颜色1
	for (i = 0; i < 15; i++)
	{/*横向*/
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
	{/*竖向*/
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
	{/*下斜*/
		j = f = 0;
		while (f < 5 && j < 11)
		{
			if (getChess(i + f, j + f) != nullptr && getChess(i + f, j + f)->getColor() == 1) f++;
			else { f = 0; j++; }
		}
		if (f == 5) return true;
	}
	for (i = 4; i < 15; i++)
	{/*上斜*/
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
/*移除棋子*/
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
			cout << "┏─\b\b";
		}
		else if (row == 0 && colunm != 14)
		{
			cout << "┠─\b\b";

		}
		else if (colunm == 0 && row != 14)
		{
			cout << "┯─\b\b";


		}
		else if (row == 14 && colunm == 14)
		{
			cout << "┛  \b\b";

		}
		else if (row == 0 && colunm == 14)
		{
			cout << "┗─\b\b";
		}
		else if (row == 14)
		{
			cout << "┨  \b\b";

		}
		else if (colunm == 14)
		{
			cout << "┷─\b\b";

		}
		else
		{
			cout << "┼─\b\b";

		}
		return true;
	}
	else
	{
		return false;
	}
}
/*悔棋函数*/
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