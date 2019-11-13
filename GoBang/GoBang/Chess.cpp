#include "Chess.h"



Chess::Chess(char color, int row, int column)
{
	if(color == 0 || color == 1)
		this->color = color;
	if(row >= 0 && row <= 14)
		this->row = row;
	if (column >= 0 && column <= 14)
		this->column = column;
}


Chess::~Chess()
{
}
