#include "GoBang.h"
#include <windows.h>
#include "ChessBoard.h"


int main()
{

	ChessBoard board;
	GoBang goBang(board);		//初始化主控类
	goBang.control();			//开始主控制逻辑

	getchar();
	return 0;
}