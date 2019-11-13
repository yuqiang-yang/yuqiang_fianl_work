#include "DrawUtil.h"



DrawUtil::DrawUtil()
{
}


DrawUtil::~DrawUtil()
{
}
void DrawUtil::moveCursor(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void DrawUtil::setText(_In_ WORD wAttributes)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wAttributes);

}
void DrawUtil::clear()
{
	moveCursor(0, 0);
	for (int i = 0; i < 50; i++)
	{
		for (int j = 0; j < 110; j++)
		{
			std::cout << " ";
		}
		std::cout << std::endl;
	}
}