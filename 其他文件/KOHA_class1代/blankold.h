#pragma once
#include <cstring>
#include<string>
#include"stdio.h"
#include"stdlib.h"
#include"Windows.h"
#include"WinBase.h"
#include <iostream>  //字符串的存储与释放类  
using namespace std;

void putC(const char a[])
{
	char b[3];
	b[0] = *a;
	b[1] = *(a + 1);
	b[2] = 0;
	cout << b;
}

void getS()
{
	char b = 'a';
	while (!(b == '\n' || b == '@'))
		b = getchar();
}
void clear()
{
	system("cls");
}
class Blank
{
public:

	Blank(int eve = 10, int end = 0) :dy_blank_end(end), dy_blank_every(eve), dy_blank1_end(end), dy_blank1_every(eve), dy_full_end(end), dy_full_every(eve),
		dy_line_end(end), dy_line_every(eve), dy_half_end(end), dy_half_every(eve), dy_halfstar_end(end), dy_halfstar_every(eve), dy_fullstar_end(end), dy_fullstar_every(eve) {}
	void All(int every, int end)
	{
		dy_blank_every = every;
		dy_blank_end = end;
		dy_blank1_every = every;
		dy_blank1_end = end;
		dy_full_every = every;
		dy_full_end = end;
		dy_half_every = every;
		dy_half_end = end;
		dy_line_every = every;
		dy_line_end = end;
	}
	void Full(int every, int end)
	{
		dy_full_every = every;
		dy_full_end = end;
	}
	void Half(int every, int end)
	{
		dy_half_every = every;
		dy_half_end = end;
	}
	void Fullstar(int every, int end)
	{
		dy_fullstar_every = every;
		dy_fullstar_end = end;
	}
	void Halfstar(int every, int end)
	{
		dy_halfstar_every = every;
		dy_halfstar_end = end;
	}
	void Line(int every, int end)
	{
		dy_line_every = every;
		dy_line_end = end;
	}
	void Blank2(int every, int end)
	{
		dy_blank_every = every;
		dy_blank_end = end;
	}
	void Blank1(int every, int end)
	{
		dy_blank1_every = every;
		dy_blank1_end = end;
	}

	/*
	+   满格
	-   虚满格
	+=  实星
	-=  虚星
	*   双space
	/   换行
	%   单space
	*/

	Blank& operator + (int full)
	{
		if (dy_full_every == 0)
		{
			switch (full)
			{
			case 0:break;
			case 1:cout << "█"; break;
			case 2:cout << "██"; break;
			case 3:cout << "███"; break;
			case 4:cout << "████"; break;
			case 5:cout << "█████"; break;
			case 6:cout << "██████"; break;
			case 7:cout << "███████"; break;
			case 8:cout << "████████"; break;
			case 9:cout << "█████████"; break;
			case 10:cout << "██████████"; break;
			case 11:cout << "███████████"; break;
			case 12:cout << "████████████"; break;
			case 13:cout << "█████████████"; break;
			case 14:cout << "██████████████"; break;
			case 15:cout << "███████████████"; break;
			case 16:cout << "████████████████"; break;
			case 17:cout << "█████████████████"; break;
			case 18:cout << "██████████████████"; break;
			case 19:cout << "███████████████████"; break;
			case 20:cout << "████████████████████"; break;
			case 21:cout << "█████████████████████"; break;
			case 22:cout << "██████████████████████"; break;
			case 23:cout << "███████████████████████"; break;
			case 24:cout << "████████████████████████"; break;
			case 25:cout << "█████████████████████████"; break;
			case 26:cout << "██████████████████████████"; break;
			case 27:cout << "███████████████████████████"; break;
			case 28:cout << "████████████████████████████"; break;
			case 29:cout << "█████████████████████████████"; break;
			case 30:cout << "██████████████████████████████"; break;
			case 31:cout << "███████████████████████████████"; break;
			case 32:cout << "████████████████████████████████"; break;
			case 33:cout << "█████████████████████████████████"; break;
			case 34:cout << "██████████████████████████████████"; break;
			case 35:cout << "███████████████████████████████████"; break;
			default:
				for (; full > 0; full--)cout << "█"; break;
			}
		}
		else
		{
			for (; full > 0; full--)
			{
				Sleep(dy_full_every);
				cout << "█";
			}
		}
		Sleep(dy_full_end);
		return *this;
	}
	Blank& operator - (int half)
	{
		if (dy_half_every == 0)
		{
			switch (half)
			{
			case 0:break;
			case 1:cout << "▓"; break;
			case 2:cout << "▓▓"; break;
			case 3:cout << "▓▓▓"; break;
			case 4:cout << "▓▓▓▓"; break;
			case 5:cout << "▓▓▓▓▓"; break;
			case 6:cout << "▓▓▓▓▓▓"; break;
			case 7:cout << "▓▓▓▓▓▓▓"; break;
			case 8:cout << "▓▓▓▓▓▓▓▓"; break;
			case 9:cout << "▓▓▓▓▓▓▓▓▓"; break;
			case 10:cout << "▓▓▓▓▓▓▓▓▓▓"; break;
			case 11:cout << "▓▓▓▓▓▓▓▓▓▓▓"; break;
			case 12:cout << "▓▓▓▓▓▓▓▓▓▓▓▓"; break;
			case 13:cout << "▓▓▓▓▓▓▓▓▓▓▓▓▓"; break;
			case 14:cout << "▓▓▓▓▓▓▓▓▓▓▓▓▓▓"; break;
			case 15:cout << "▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓"; break;
			case 16:cout << "▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓"; break;
			case 17:cout << "▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓"; break;
			case 18:cout << "▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓"; break;
			case 19:cout << "▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓"; break;
			case 20:cout << "▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓"; break;
			case 21:cout << "▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓"; break;
			case 22:cout << "▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓"; break;
			case 23:cout << "▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓"; break;
			case 24:cout << "▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓"; break;
			case 25:cout << "▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓"; break;
			case 26:cout << "▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓"; break;
			case 27:cout << "▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓"; break;
			case 28:cout << "▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓"; break;
			case 29:cout << "▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓"; break;
			case 30:cout << "▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓"; break;
			case 31:cout << "▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓"; break;
			case 32:cout << "▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓"; break;
			case 33:cout << "▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓"; break;
			case 34:cout << "▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓"; break;
			case 35:cout << "▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓"; break;
			default:for (; half > 0; half--)cout << "▓"; break;
			}
		}
		else
		{
			for (; half > 0; half--)
			{
				Sleep(dy_half_every);
				cout << "▓";
			}
		}
		Sleep(dy_half_end);
		return *this;
	}
	Blank& operator += (int fullstar)
	{
		if (dy_fullstar_every == 0)
		{
			switch (fullstar)
			{
			case 0:break;
			case 1:cout << "★"; break;
			case 2:cout << "★★"; break;
			case 3:cout << "★★★"; break;
			case 4:cout << "★★★★"; break;
			case 5:cout << "★★★★★"; break;
			case 6:cout << "★★★★★★"; break;
			case 7:cout << "★★★★★★★"; break;
			case 8:cout << "★★★★★★★★"; break;
			case 9:cout << "★★★★★★★★★"; break;
			case 10:cout << "★★★★★★★★★★"; break;
			case 11:cout << "★★★★★★★★★★★"; break;
			case 12:cout << "★★★★★★★★★★★★"; break;
			case 13:cout << "★★★★★★★★★★★★★"; break;
			case 14:cout << "★★★★★★★★★★★★★★"; break;
			case 15:cout << "★★★★★★★★★★★★★★★"; break;
			case 16:cout << "★★★★★★★★★★★★★★★★"; break;
			case 17:cout << "★★★★★★★★★★★★★★★★★"; break;
			case 18:cout << "★★★★★★★★★★★★★★★★★★"; break;
			case 19:cout << "★★★★★★★★★★★★★★★★★★★"; break;
			case 20:cout << "★★★★★★★★★★★★★★★★★★★★"; break;
			case 21:cout << "★★★★★★★★★★★★★★★★★★★★★"; break;
			case 22:cout << "★★★★★★★★★★★★★★★★★★★★★★"; break;
			case 23:cout << "★★★★★★★★★★★★★★★★★★★★★★★"; break;
			case 24:cout << "★★★★★★★★★★★★★★★★★★★★★★★★"; break;
			case 25:cout << "★★★★★★★★★★★★★★★★★★★★★★★★★"; break;
			case 26:cout << "★★★★★★★★★★★★★★★★★★★★★★★★★★"; break;
			case 27:cout << "★★★★★★★★★★★★★★★★★★★★★★★★★★★"; break;
			case 28:cout << "★★★★★★★★★★★★★★★★★★★★★★★★★★★★"; break;
			case 29:cout << "★★★★★★★★★★★★★★★★★★★★★★★★★★★★★"; break;
			case 30:cout << "★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★"; break;
			case 31:cout << "★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★"; break;
			case 32:cout << "★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★"; break;
			case 33:cout << "★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★"; break;
			case 34:cout << "★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★"; break;
			case 35:cout << "★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★"; break;
			default:
				for (; fullstar > 0; fullstar--)cout << "★"; break;
			}
		}
		else
		{
			for (; fullstar > 0; fullstar--)
			{
				Sleep(dy_fullstar_every);
				cout << "★";
			}
		}
		Sleep(dy_fullstar_end);
		return *this;
	}
	Blank& operator -= (int halfstar)
	{
		if (dy_halfstar_every == 0)
		{
			switch (halfstar)
			{
			case 0:break;
			case 1:cout << "☆"; break;
			case 2:cout << "☆☆"; break;
			case 3:cout << "☆☆☆"; break;
			case 4:cout << "☆☆☆☆"; break;
			case 5:cout << "☆☆☆☆☆"; break;
			case 6:cout << "☆☆☆☆☆☆"; break;
			case 7:cout << "☆☆☆☆☆☆☆"; break;
			case 8:cout << "☆☆☆☆☆☆☆☆"; break;
			case 9:cout << "☆☆☆☆☆☆☆☆☆"; break;
			case 10:cout << "☆☆☆☆☆☆☆☆☆☆"; break;
			case 11:cout << "☆☆☆☆☆☆☆☆☆☆☆"; break;
			case 12:cout << "☆☆☆☆☆☆☆☆☆☆☆☆"; break;
			case 13:cout << "☆☆☆☆☆☆☆☆☆☆☆☆☆"; break;
			case 14:cout << "☆☆☆☆☆☆☆☆☆☆☆☆☆☆"; break;
			case 15:cout << "☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆"; break;
			case 16:cout << "☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆"; break;
			case 17:cout << "☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆"; break;
			case 18:cout << "☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆"; break;
			case 19:cout << "☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆"; break;
			case 20:cout << "☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆"; break;
			case 21:cout << "☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆"; break;
			case 22:cout << "☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆"; break;
			case 23:cout << "☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆"; break;
			case 24:cout << "☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆"; break;
			case 25:cout << "☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆"; break;
			case 26:cout << "☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆"; break;
			case 27:cout << "☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆"; break;
			case 28:cout << "☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆"; break;
			case 29:cout << "☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆"; break;
			case 30:cout << "☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆"; break;
			case 31:cout << "☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆"; break;
			case 32:cout << "☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆"; break;
			case 33:cout << "☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆"; break;
			case 34:cout << "☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆"; break;
			case 35:cout << "☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆"; break;
			default:for (; halfstar > 0; halfstar--)cout << "☆"; break;
			}
		}
		else
		{
			for (; halfstar > 0; halfstar--)
			{
				Sleep(dy_halfstar_every);
				cout << "☆";
			}
		}
		Sleep(dy_halfstar_end);
		return *this;
	}
	Blank& operator * (int blank)
	{
		if (dy_blank_every == 0)
		{
			switch (blank)
			{
			case 0:break;
			case 1:cout << "  "; break;
			case 2:cout << "    "; break;
			case 3:cout << "      "; break;
			case 4:cout << "        "; break;
			case 5:cout << "          "; break;
			case 6:cout << "            "; break;
			case 7:cout << "              "; break;
			case 8:cout << "                "; break;
			case 9:cout << "                  "; break;
			case 10:cout << "                    "; break;
			case 11:cout << "                      "; break;
			case 12:cout << "                        "; break;
			case 13:cout << "                          "; break;
			case 14:cout << "                            "; break;
			case 15:cout << "                              "; break;
			case 16:cout << "                                "; break;
			case 17:cout << "                                  "; break;
			case 18:cout << "                                    "; break;
			case 19:cout << "                                      "; break;
			case 20:cout << "                                        "; break;
			case 21:cout << "                                          "; break;
			case 22:cout << "                                            "; break;
			case 23:cout << "                                              "; break;
			default:for (; blank > 0; blank--)printf("  ");
				break;
			}
		}
		else
		{
			for (; blank > 0; blank--)
			{
				Sleep(dy_blank_every / 2);
				cout << " ";
				Sleep(dy_blank_every / 2);
				cout << " ";
			}
		}
		Sleep(dy_blank_end);
		return *this;
	}
	Blank& operator / (int line)
	{
		if (dy_line_every == 0)
		{
			switch (line)
			{
			case 0:break;
			case 1:cout << "\n"; break;
			case 2:cout << "\n\n"; break;
			case 3:cout << "\n\n\n"; break;
			case 4:cout << "\n\n\n\n"; break;
			case 5:cout << "\n\n\n\n\n"; break;
			case 6:cout << "\n\n\n\n\n\n"; break;
			case 7:cout << "\n\n\n\n\n\n\n"; break;
			case 8:cout << "\n\n\n\n\n\n\n\n"; break;
			case 9:cout << "\n\n\n\n\n\n\n\n\n"; break;
			case 10:cout << "\n\n\n\n\n\n\n\n\n\n"; break;
			case 11:cout << "\n\n\n\n\n\n\n\n\n\n\n"; break;
			case 12:cout << "\n\n\n\n\n\n\n\n\n\n\n\n"; break;
			case 13:cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n"; break;
			case 14:cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n"; break;
			case 15:cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"; break;
			case 16:cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"; break;
			case 17:cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"; break;
			case 18:cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"; break;
			case 19:cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"; break;
			case 20:cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"; break;
			case 21:cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"; break;
			case 22:cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"; break;
			case 23:cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"; break;
			case 24:cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"; break;
			case 25:cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"; break;
			case 26:cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"; break;
			case 27:cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"; break;
			case 28:cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"; break;
			case 29:cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"; break;
			case 30:cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"; break;
			case 31:cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"; break;
			case 32:cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"; break;
			case 33:cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"; break;
			case 34:cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"; break;
			case 35:cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"; break;
			default:for (; line > 0; line--)cout << "\n";	   break;
			}
		}
		else
		{
			for (; line > 0; line--)
			{
				Sleep(dy_line_every);
				cout << "\n";
			}
		}
		Sleep(dy_line_end);
		return *this;
	}
	Blank& operator % (int blank1)
	{
		if (dy_blank1_every == 0)
		{
			switch (blank1)
			{
			case 0:break;
			case 1:cout << " "; break;
			case 2:cout << "  "; break;
			case 3:cout << "   "; break;
			case 4:cout << "    "; break;
			case 5:cout << "     "; break;
			case 6:cout << "      "; break;
			case 7:cout << "       "; break;
			case 8:cout << "        "; break;
			case 9:cout << "         "; break;
			case 10:cout << "          "; break;
			case 11:cout << "           "; break;
			case 12:cout << "            "; break;
			case 13:cout << "             "; break;
			case 14:cout << "              "; break;
			case 15:cout << "               "; break;
			case 16:cout << "                "; break;
			case 17:cout << "                 "; break;
			case 18:cout << "                  "; break;
			case 19:cout << "                   "; break;
			case 20:cout << "                    "; break;
			case 21:cout << "                     "; break;
			case 22:cout << "                      "; break;
			case 23:cout << "                       "; break;
			case 25:cout << "                         "; break;
			case 27:cout << "                           "; break;
			case 29:cout << "                             "; break;
			case 31:cout << "                               "; break;
			case 33:cout << "                                 "; break;
			case 35:cout << "                                   "; break;
			case 37:cout << "                                     "; break;
			case 39:cout << "                                       "; break;
			default:for (; blank1 > 0; blank1--)printf(" ");	break;

			}
		}
		else
		{
			for (; blank1 > 0; blank1--)
			{
				Sleep(dy_blank1_every);
				cout << " ";
			}
		}
		Sleep(dy_blank1_end);
		return *this;
	}

	//void operator ++(int)
	//{
	//	for (int i = 22; i > 15; i--)
	//	{
	//		Sleep(188 - i * 8);
	//		printf("\n");
	//	}
	//	for (int i = 15; i > 7; i--)
	//	{
	//		Sleep(128 - i * 4);
	//		printf("\n");
	//	}
	//	for (int i = 7; i > 0; i--)
	//	{
	//		Sleep(100 - i * 4);
	//		printf("\n");
	//	}
	//}
	//void clearThisLine()
	//{
	//	printf("\r"); 
	//	Blank b;
	//	b * 71;
	//	printf("\r");
	//}

private:
	int dy_full_every;
	int dy_full_end;
	int dy_half_every;
	int dy_half_end;
	int dy_line_every;
	int dy_line_end;
	int dy_blank_every;
	int dy_blank_end;
	int dy_blank1_every;
	int dy_blank1_end;
	int dy_fullstar_every;
	int dy_fullstar_end;
	int dy_halfstar_every;
	int dy_halfstar_end;
};

class Str
{
public:


private:
	int max;
	int num;
	string str[5];
};

class Page
{
public:

private:

};


class Out
{
public:
	/*初始说明：
	每一个Blank单元，每一段Blank结束 停留0ms
	每字停顿10ms，每段停顿100ms，选项停留0ms
	不居中，不确定
	数字4格，每句之间空一行
	页模式，71格，22行，每页开始空1行，前5格，后6格不打印，每页的起始现行数为1*/
	Out(int every_dy = 10, int end_dy = 100, int get = 0) :dy_every(every_dy), dy_end(end_dy), set_get(get) { b1.All(0, 0); }

	//预设
	//每页的开始
	void chushi()
	{
		Out a;
		*this = a;
	}
	void galgame()
	{
		Out a;
		*this = a;
		Get(1);
		Mid(0);
	}
	void tishi()
	{
		Out a;
		*this = a;
		Mid(1);
		Get(1);
	}


	//blank的延迟
	void BlankDy(int every, int end) { b1.All(every, end); }
	//文字的延迟
	void OutDy(int every, int end, int chosen) { dy_every = every; dy_end = end; dy_chosen = chosen; }
	//与上一行相差几行
	void LineEvery(int line) { set_line_every = line; }
	//是否取确定
	void Get(int yes) { set_get = yes; }

	//0代表不居中.1代表居中
	void Mid(int yes) { set_mid = yes; }
	//数字的占格
	void Int(int blank) { set_int = blank; }
	//总数
	//是否在打印一段
	void Only(int yes)
	{
		page_only = yes;
		if (yes == 1)
		{
			Mid(0);
			Get(0);
			BlankDy(dy_every, 0);
			OutDy(dy_every, 0, 0);
			LineEvery(0);
			Int(2);
			lineblank(0, 0);
			Pageheadline(0);
		}
	}
	//每页的格数，行数
	void Total(int blank, int line) { page_blank = blank; page_line = line; }
	//每行前面后面空多少格
	void lineblank(int head, int end) { page_head_blank = head; page_end_blank = end; }
	//每页开始空多少行
	void Pageheadline(int line) { page_head_line = line; }
	//
	void start()
	{
		page_now_line = page_head_line;
	}

	//冗余
	//上次是否取了确定（少一个换行）
	//void Bget(int a) { set_beforeget = a; }

	Out& operator << (const char a[])
	{
		int m;
		if (page_only == 0)
		{
			//截取字符串
			int len = page_blank - page_head_blank - page_end_blank; //每行最大数量
			m = (strlen(a) - 1) / len;
			char c[700];
			strcpy_s(c, a);
			char b[7][100];
			for (int j = m; j >= 0; j--)
			{
				strcpy_s(b[j], &c[len * j]);
				c[len * j] = 0;
			}
			int len1 = strlen(b[m]) - 1;
			//打印
			if (m + page_now_line + set_line_every + 1 >= page_line)
			{
				page_now_line = page_head_line;
				cout << "█"; getS();
				clear();
			}
			if (page_now_line == page_head_line)
			{
				b1 / page_head_line;
			}
			else
			{
				if (set_beforeget == 0)	b1 / (set_line_every + 1);
				else b1 / set_line_every;
			}
			for (int k = 0; k <= m; k++)
			{
				if (k != 0 && m != 0)
				{
					b1 / 1;
					if (k == m && set_mid != 0)	b1 % ((len - len1) / 2);
				}
				else
				{
					if (m == 0 && set_mid != 0) b1 % ((len - len1) / 2);
				}
				b1 % (page_head_blank);
				if (dy_every == 0) cout << b[k];
				else {
					for (int i = 0; b[k][i] != '\0'; i += 2)
					{
						if (b[k][i] != ' ')
							Sleep(dy_every);
						putC(&b[k][i]);
					}
				}
			}
		}
		else
		{
			for (int i = 0; a[i] != '\0'; i += 2)
			{
				if (a[i] != ' ')
					Sleep(dy_every);
				putC(&a[i]);
			}
		}
		if (page_only == 0)
		{
			if (set_get == 0)
			{
				Sleep(dy_end);
				set_beforeget = 0;
			}
			else
			{
				set_beforeget = 1;
				getS();
			}
			Sleep(dy_chosen);

			page_now_line += m + 1;
			if (page_now_line != page_head_line + m + 1)
				page_now_line += set_line_every;
		}
		return *this;
	}
	Out& operator << (int a)
	{
		int j = 10;
		for (int i = 1; i < set_int; i++) j *= 10;
		if (a >= j) a = j - 1;
		if (dy_every == 0)cout << a;
		else
		{
			for (j /= 10; j > 0; j /= 10)
			{
				Sleep(dy_every);
				cout << a / j;
				a %= j;
			}
			cout << a;
		}
		if (set_get == 0)
			Sleep(dy_end);
		Sleep(dy_chosen);
		return *this;
	}

private:
	Blank b1;

	//延迟
	int dy_every;
	int dy_end;
	int dy_chosen = 0;

	//格式选项
	int set_get;
	int set_mid = 0;
	int set_int = 4;
	int set_line_every = 1;	//每句之间打印多少换行
	static int set_beforeget;

	//页属性
	int page_only = 0;//0在打印一段话，1在打印一句短语
	int page_blank = 71;
	int page_line = 22;
	int page_head_line = 1; //每一页开始空行数	
	int page_head_blank = 5;
	int page_end_blank = 6;
	static int page_now_line;
};
int Out::page_now_line = 1;//等于page_head_line
int Out::set_beforeget = 0;//上次是否换行

class In
{

};

class _Color
{
public:
	_Color(int back_ = 8, int word_ = 6) :back(back_), word(word_) { o.Only(1); }
	void Back(int back_) { back_ %= 16; if (back_ == word)back_++; if (back_ == 16)back_ == 0; back = back_; }
	void Word(int word_) { word_ %= 16; if (word_ == back)word_++; if (word_ == 16)word_ == 0; word = word_; }
	void Trandy(int eve) { o.OutDy(eve, 0, 0); }
	void color(int back_, int word_)
	{
		Back(back_);
		Word(word_);
		int a = back;
		int b = word;
		if (a == b)
			return;
		switch (a)
		{
		case 0:
			switch (b)
			{
			case 1:system("color 01"); break;
			case 2:system("color 02"); break;
			case 3:system("color 03"); break;
			case 4:system("color 04"); break;
			case 5:system("color 05"); break;
			case 6:system("color 06"); break;
			case 7:system("color 07"); break;
			case 8:system("color 08"); break;
			case 9:system("color 09"); break;
			case 10:system("color 0A"); break;
			case 11:system("color 0B"); break;
			case 12:system("color 0C"); break;
			case 13:system("color 0D"); break;
			case 14:system("color 0E"); break;
			case 15:system("color 0F"); break;
			default:
				break;
			}
			break;
		case 1:
			switch (b)
			{
			case 0:system("color 10"); break;
			case 2:system("color 12"); break;
			case 3:system("color 13"); break;
			case 4:system("color 14"); break;
			case 5:system("color 15"); break;
			case 6:system("color 16"); break;
			case 7:system("color 17"); break;
			case 8:system("color 18"); break;
			case 9:system("color 19"); break;
			case 10:system("color 1A"); break;
			case 11:system("color 1B"); break;
			case 12:system("color 1C"); break;
			case 13:system("color 1D"); break;
			case 14:system("color 1E"); break;
			case 15:system("color 1F"); break;
			default:
				break;
			}
			break;
		case 2:
			switch (b)
			{
			case 0:system("color 20"); break;
			case 1:system("color 21"); break;
			case 3:system("color 23"); break;
			case 4:system("color 24"); break;
			case 5:system("color 25"); break;
			case 6:system("color 26"); break;
			case 7:system("color 27"); break;
			case 8:system("color 28"); break;
			case 9:system("color 29"); break;
			case 10:system("color 2A"); break;
			case 11:system("color 2B"); break;
			case 12:system("color 2C"); break;
			case 13:system("color 2D"); break;
			case 14:system("color 2E"); break;
			case 15:system("color 2F"); break;
			default:
				break;
			}
			break;
		case 3:
			switch (b)
			{
			case 0:system("color 30"); break;
			case 1:system("color 31"); break;
			case 2:system("color 32"); break;
			case 4:system("color 34"); break;
			case 5:system("color 35"); break;
			case 6:system("color 36"); break;
			case 7:system("color 37"); break;
			case 8:system("color 38"); break;
			case 9:system("color 39"); break;
			case 10:system("color 3A"); break;
			case 11:system("color 3B"); break;
			case 12:system("color 3C"); break;
			case 13:system("color 3D"); break;
			case 14:system("color 3E"); break;
			case 15:system("color 3F"); break;
			default:
				break;
			}
			break;
		case 4:
			switch (b)
			{
			case 0:system("color 40"); break;
			case 1:system("color 41"); break;
			case 2:system("color 42"); break;
			case 3:system("color 43"); break;
			case 5:system("color 45"); break;
			case 6:system("color 46"); break;
			case 7:system("color 47"); break;
			case 8:system("color 48"); break;
			case 9:system("color 49"); break;
			case 10:system("color 4A"); break;
			case 11:system("color 4B"); break;
			case 12:system("color 4C"); break;
			case 13:system("color 4D"); break;
			case 14:system("color 4E"); break;
			case 15:system("color 4F"); break;
			default:
				break;
			}
			break;
		case 5:
			switch (b)
			{
			case 0:system("color 50"); break;
			case 1:system("color 51"); break;
			case 2:system("color 52"); break;
			case 3:system("color 53"); break;
			case 4:system("color 54"); break;
			case 6:system("color 56"); break;
			case 7:system("color 57"); break;
			case 8:system("color 58"); break;
			case 9:system("color 59"); break;
			case 10:system("color 5A"); break;
			case 11:system("color 5B"); break;
			case 12:system("color 5C"); break;
			case 13:system("color 5D"); break;
			case 14:system("color 5E"); break;
			case 15:system("color 5F"); break;
			default:
				break;
			}
			break;
		case 6:
			switch (b)
			{
			case 0:system("color 60"); break;
			case 1:system("color 61"); break;
			case 2:system("color 62"); break;
			case 3:system("color 63"); break;
			case 4:system("color 64"); break;
			case 5:system("color 65"); break;
			case 7:system("color 67"); break;
			case 8:system("color 68"); break;
			case 9:system("color 69"); break;
			case 10:system("color  6A"); break;
			case 11:system("color 6B"); break;
			case 12:system("color 6C"); break;
			case 13:system("color 6D"); break;
			case 14:system("color 6E"); break;
			case 15:system("color 6F"); break;
			default:
				break;
			}
			break;
		case 7:
			switch (b)
			{
			case 0:system("color 70"); break;
			case 1:system("color 71"); break;
			case 2:system("color 72"); break;
			case 3:system("color 73"); break;
			case 4:system("color 74"); break;
			case 5:system("color 75"); break;
			case 6:system("color 76"); break;
			case 8:system("color 78"); break;
			case 9:system("color 79"); break;
			case 10:system("color 7A"); break;
			case 11:system("color 7B"); break;
			case 12:system("color 7C"); break;
			case 13:system("color 7D"); break;
			case 14:system("color 7E"); break;
			case 15:system("color 7F"); break;
			default:
				break;
			}
			break;
		case 8:
			switch (b)
			{
			case 0:system("color 80"); break;
			case 1:system("color 81"); break;
			case 2:system("color 82"); break;
			case 3:system("color 83"); break;
			case 4:system("color 84"); break;
			case 5:system("color 85"); break;
			case 6:system("color 86"); break;
			case 7:system("color 87"); break;
			case 9:system("color 89"); break;
			case 10:system("color  8A"); break;
			case 11:system("color 8B"); break;
			case 12:system("color 8C"); break;
			case 13:system("color 8D"); break;
			case 14:system("color 8E"); break;
			case 15:system("color 8F"); break;
			default:
				break;
			}
			break;
		case 9:
			switch (b)
			{
			case 0:system("color 90"); break;
			case 1:system("color 91"); break;
			case 2:system("color 92"); break;
			case 3:system("color 93"); break;
			case 4:system("color 94"); break;
			case 5:system("color 95"); break;
			case 6:system("color 96"); break;
			case 7:system("color 97"); break;
			case 8:system("color 98"); break;
			case 10:system("color 9A"); break;
			case 11:system("color 9B"); break;
			case 12:system("color 9C"); break;
			case 13:system("color 9D"); break;
			case 14:system("color 9E"); break;
			case 15:system("color 9F"); break;
			default:
				break;
			}
			break;
		case 10:
			switch (b)
			{
			case 0:system("color A0"); break;
			case 1:system("color A1"); break;
			case 2:system("color A2"); break;
			case 3:system("color A3"); break;
			case 4:system("color A4"); break;
			case 5:system("color A5"); break;
			case 6:system("color A6"); break;
			case 7:system("color A7"); break;
			case 8:system("color A8"); break;
			case 9:system("color A9"); break;
			case 11:system("color AB"); break;
			case 12:system("color AC"); break;
			case 13:system("color AD"); break;
			case 14:system("color AE"); break;
			case 15:system("color AF"); break;
			default:
				break;
			}
			break;
		case 11:
			switch (b)
			{
			case 0:system("color B0"); break;
			case 1:system("color B1"); break;
			case 2:system("color B2"); break;
			case 3:system("color B3"); break;
			case 4:system("color B4"); break;
			case 5:system("color B5"); break;
			case 6:system("color B6"); break;
			case 7:system("color B7"); break;
			case 8:system("color B8"); break;
			case 9:system("color B9"); break;
			case 10:system("color BA"); break;
			case 12:system("color BC"); break;
			case 13:system("color BD"); break;
			case 14:system("color BE"); break;
			case 15:system("color BF"); break;
			default:
				break;
			}
			break;
		case 12:
			switch (b)
			{
			case 0:system("color C0"); break;
			case 1:system("color C1"); break;
			case 2:system("color C2"); break;
			case 3:system("color C3"); break;
			case 4:system("color C4"); break;
			case 5:system("color C5"); break;
			case 6:system("color C6"); break;
			case 7:system("color C7"); break;
			case 8:system("color C8"); break;
			case 9:system("color C9"); break;
			case 10:system("color CA"); break;
			case 11:system("color CB"); break;
			case 13:system("color CD"); break;
			case 14:system("color CE"); break;
			case 15:system("color CF"); break;
			default:
				break;
			}
			break;
		case 13:
			switch (b)
			{
			case 0:system("color D0"); break;
			case 1:system("color D1"); break;
			case 2:system("color D2"); break;
			case 3:system("color D3"); break;
			case 4:system("color D4"); break;
			case 5:system("color D5"); break;
			case 6:system("color D6"); break;
			case 7:system("color D7"); break;
			case 8:system("color D8"); break;
			case 9:system("color D9"); break;
			case 10:system("color DA"); break;
			case 11:system("color DB"); break;
			case 12:system("color DC"); break;
			case 14:system("color DE"); break;
			case 15:system("color DF"); break;
			default:
				break;
			}
			break;
		case 14:
			switch (b)
			{
			case 0:system("color E0"); break;
			case 1:system("color E1"); break;
			case 2:system("color E2"); break;
			case 3:system("color E3"); break;
			case 4:system("color E4"); break;
			case 5:system("color E5"); break;
			case 6:system("color E6"); break;
			case 7:system("color E7"); break;
			case 8:system("color E8"); break;
			case 9:system("color E9"); break;
			case 10:system("color EA"); break;
			case 11:system("color EB"); break;
			case 12:system("color EC"); break;
			case 13:system("color ED"); break;
			case 15:system("color EF"); break;
			default:
				break;
			}
			break;
		case 15:
			switch (b)
			{
			case 0:system("color F0"); break;
			case 1:system("color F1"); break;
			case 2:system("color F2"); break;
			case 3:system("color F3"); break;
			case 4:system("color F4"); break;
			case 5:system("color F5"); break;
			case 6:system("color F6"); break;
			case 7:system("color F7"); break;
			case 8:system("color F8"); break;
			case 9:system("color F9"); break;
			case 10:system("color FA"); break;
			case 11:system("color FB"); break;
			case 12:system("color FC"); break;
			case 13:system("color FD"); break;
			case 14:system("color FE"); break;
			default:
				break;
			}
			break;
		default:
			break;
		}
	}
	const char* Translate(int color)
	{
		color %= 16;
		char a[5];
		switch (color)
		{
		case 0:o << "纯黑"; break;
		case 1:o << "纯蓝"; break;
		case 2:o << "深绿"; break;
		case 3:o << "天蓝"; break;
		case 4:o << "纯红"; break;
		case 5:o << "深紫"; break;
		case 6:o << "棕黄"; break;
		case 7:o << "淡灰"; break;
		case 8:o << "深灰"; break;
		case 9:o << "湖蓝"; break;
		case 10:o << "草绿"; break;
		case 11:o << "冰蓝"; break;
		case 12:o << "粉红"; break;
		case 13:o << "紫红"; break;
		case 14:o << "月黄"; break;
		case 15:o << "纯白"; break;
		default:
			break;
		}
		return a;
	}

protected:
	Out o;
	int back;
	int word;
};



#pragma once
