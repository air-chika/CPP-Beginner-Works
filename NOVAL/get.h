#pragma once
#include "str.h"
#include<conio.h>
class Get
{
public:
	Get(char& rega,char& regb,int &controlb):reg1(rega),reg2(regb),control(controlb){}

	//д��reg reg2�����û������������
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

	//д��reg reg2���ȴ�����
	void wait()
	{
		reg2 = 0;
		reg1 = _getch();
		if (reg1 > 127 || reg1 < 0)
			reg2 = _getch();
	}

	//ͬ��û���������������һ�ı�reg1,reg2��ֵ
	//�ڼ���д�� w(1) a(2) s(3) d(4) �������� esc(27) enter(13) backspace(8) space(32)ʱ
	//�޸�control��ֵ����������Ϊ0
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
		//����ڿ��ܸ��Ĳ����䶯
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

	//�򵥵����
	void clear()
	{
		reg1 = 0; reg2 = 0; control = 0;
	}

	//�ȴ��ͣ����ڲ鿴�ַ���ascֵ
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
