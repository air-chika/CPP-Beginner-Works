#include "board.h"

Board::Board(const Screen& scr,Cursor& cur):cursor(cur)
{
	nl = 0;
	high = scr.high;
	wide = scr.wide;
	for (int i = 0; i < 35; i++)
		for (int j = 0; j < 140; j++)
			if(i<high&&j<wide)
			str[i][j] = ' ';
			else
				str[i][j] = 0;
	pattern(scr.boarddata.patternmode);
}
