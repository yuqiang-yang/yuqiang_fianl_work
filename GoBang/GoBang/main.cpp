#include "GoBang.h"
#include <windows.h>
#include "ChessBoard.h"


int main()
{

	ChessBoard board;
	GoBang goBang(board);		//��ʼ��������
	goBang.control();			//��ʼ�������߼�

	getchar();
	return 0;
}