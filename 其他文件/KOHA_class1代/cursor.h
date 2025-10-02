#pragma once

class Cursor
{
public:
	Cursor(Screen scr):high(scr.high),wide(scr.wide){}
	
	int xx = 1;
	int yy = 1;
	int high;
	int wide;

	void setxy(int x, int y)
	{
		xx = x;
		yy = y;
		position();
	}
	void setx(int x)
	{
		xx = x;
		position();
	}
	void sety( int y)
	{
		yy = y;
		position();
	}
	void addxy(int x, int y)
	{
		xx += x;
		yy += y;
		position();
	}
	void addx(int x)
	{
		xx += x;
		position();
	}
	void addy(int y)
	{
		yy += y;
		position();
	}

	void hide()
	{
		info.bVisible = 0;
		SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
	}
	void unhide()
	{
		info.bVisible = 1;
		SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
	}
	void position()
	{
		if (xx > wide)
			xx -= wide;
		if (yy > high)
			yy -= high;
		c.X = xx - 1;
		c.Y = yy - 1;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	}

	
private:
	CONSOLE_CURSOR_INFO info = { 1, 0 };
	COORD c = {1,1};
};

