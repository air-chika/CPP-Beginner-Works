#pragma once
#include "str.h"
#include<conio.h>
class Get
{
public:
	Get(char& rega,char& regb,int &controlb):reg1(rega),reg2(regb),control(controlb){}

	//写入reg reg2，如果没有输入则跳过
	void nowait()
	{
		reg1 = 0;
		reg2 = 0;
		if (_kbhit())
		{
			reg1 = _getch();
			if (reg1 > 127 || reg1 < 0)
					reg2 = _getch();
		}
	}

	//写入reg reg2，等待输入
	void wait()
	{
		reg2 = 0;
		reg1 = _getch();
		if (reg1 > 127 || reg1 < 0)
			reg2 = _getch();
	}

	//同样没有输入则跳过，且会改变reg1,reg2的值
	//在键盘写入 w(1) a(2) s(3) d(4) 上下左右 esc(27) enter(13) backspace(8) space(32)时
	//修改control的值，否则将其设为0
	void getcontrol()
	{
		clear();
		if (_kbhit())
		{
			reg1 = _getch();
			if (reg1 > 127 || reg1 < 0)
				reg2 = _getch();
		}
		if (reg1 == -32)
		{
			switch (reg2)
			{
			case 72:reg1 = 'w'; break;
			case 75:reg1 = 'a'; break;
			case 77:reg1 = 'd'; break;
			case 80:reg1 = 's'; break;
			default:
				break;
			}
		}
		//因后期可能更改不做变动
		switch (reg1)
		{
		case 'w':control = 'w'; break;
		case 'a':control = 'a'; break;
		case 's':control = 's'; break;
		case 'd':control = 'd'; break;
		case 27:control = reg1; break;
		case 32:control = reg1; break;
		case 13:control = reg1; break;
		case 8:control = reg1; break;
		default:
			break;
		}
		return;
	}

	//简单的清除
	void clear()
	{
		reg1 = 0; reg2 = 0; control = 0;
	}

	//等待型，用于查看字符的asc值
	void testkb()
	{
		while (reg1 != 27)
		{
			wait();
			cout << int(reg1) << ' ' << int(reg2) << '\n';
		}
	}

private:
	char& reg1, & reg2;
	int& control;
};
