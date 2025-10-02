#pragma once
#include"blank.h"
#include"screen.h"
#include"cursor.h"
class Pattern
{
public:
	Pattern()
	{
		wide = 0;
		high = 0;
		pattern = new char[high*wide];
		color = new int[high*wide];
	}
	~Pattern() { delete[]pattern, delete[]color; }
	char& pat(int High,int Wide)
	{
		return pattern[(High-1)*wide+Wide-1];
	}
	int& col(int High, int Wide)
	{
		return color[(High-1) * wide + Wide-1];
	}

	void cake(int frame)
	{

	}

private:
	int wide;
	int high;
	char* pattern;
	int* color;
};

namespace pat
{

}
class Anime
{

};


class Board
{
public:
	Board(const Screen& scr,Cursor& cur);
	void pattern(int a)
	{
		switch (a)
		{
		case 0:return;
		case 1:frame("█"); break;
		case 2:frame("▓"); break;
		case 3:frame("█","|"); break;
		default:
			break;
		}
	}
	void frame(const char* a)
	{
		b.gp(str[nl]);
		b.repeat(a,wide);
		side(a);
		b.gp(str[nl]);
		b.repeat(a,wide);
	}
	void frame(const char* a, const char* c)
	{
		b.gp(str[nl]);
		b.repeat(a, wide);
		side(c);
		b.gp(str[nl]);
		b.repeat(a, wide);
	}
	void side(const char* a)
	{
		int x = s.len(a);
		for (nl=1; nl < high-1; nl++)
		{
			s.copy(str[nl], a, x);
			s.copy(&str[nl][wide- x], a, x);
		}
	}

	Board& copy(Board& a)
	{
		for (int i = 0; i < 33; i++)
			for (int j = 0; j < 120; j++)
					str[i][j] = a.str[i][j];
	}
	void copyto(char ex[][250])
	{
		for (int i = 0; i < 35; i++)
			for (int j = 0; j < 250; j++)
				if (i < high && j < wide)
					ex[i][j]=str[i][j] ;
				else
					ex[i][j] = 0;
	}


	void add(const char a[],int x,int y,int n)
	{
		s.copy(&str[x][y], a,n);
	}

	void testout()
	{
		for (int i = 0; i < high; i++)
		{
			cout << str[i] << endl;
		}
	}

	//wide,high是实际值,数组的最大值为其-1
	int wide;
	int high;
	Blank b;
	Str s;
	Cursor& cursor;
	int nl=0;
	char str[35][140];//cpp
};
