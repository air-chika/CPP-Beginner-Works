#include"d1.h"

using namespace std;
int eve=10;  //10
int tod=100; //100
int Dy_20 = 20;//20
int Dy_Jie =10 ;//10

int wenben = 15;//out的延迟
void sleepTod()
{
	if(tod!=0)
	Sleep(tod);
}

int inIntO(int num1, int num2, const char a[], const char b[],int c)
{
	int i = num1 - 1, j = 0;
	outO(a);
	outODy("[1or2]:",c);
	scanf_s(" %4d", &i);
	getS();


	while (i<num1 || i>num2)
	{
		i = num1;
		blank2(5);
		blankMid(strlen(b) + 6);
		if (j > 0)

		{
			outODy("叮咛:", c);
			outODy(b, c);
		}
		else
		{
			outODy(b, c);
			cout << "[" << num1 << "," << num2 << "]";
		}
		cout << ":";
	
		scanf_s("%4d", &i);
		getS();
		j++;
	}
	return i;
}
int inIntCan(int num1, int num2, const char a[], const char b[])
{
	int i = num1 - 1, j = 0;
	blankMid(strlen(a) + 6);
	outODy0(a);
	cout << "[" << num1 << "," << num2 << "]:";
	scanf_s(" %4d", &i);
	getS();


	while (i<num1 || i>num2)
	{
		i = num1;
		
		if (j > 0)
		{
			blank(7); blankMid(strlen(b) + 6);
			outODy0("叮咛：");
		}
		else 
		{
			blank2(5);
			blankMid(strlen(b) + 6);
		}
		outODy0(b);
		cout << ":";
		scanf_s("%4d", &i);
		getS();
		j++;
	}
	return i;
}
int inIntCan0(int num1, int num2, const char a[], const char b[])
{
	int i = num1 - 1, j = 0;
	blankMid(strlen(a) + 6);
	cout << a << "[" << num1 << "," << num2 << "]:";
	scanf_s(" %4d", &i);
	getS();
	while (i<num1 || i>num2)
	{
		i = num1 - 1;
		blank2(5);
		blankMid(strlen(b) + 6);
		if (j > 0)
			cout << "叮咛：";

		cout << b << ":";
		scanf_s(" %4d", &i);
		getS();
		j++;
	}
	return i;
}

int inIntCanM(int num1, int num2, const char a[], const char b[])
{
	return 0;
}


void out(const char a[])
{
	blank(9);  
	cout << a;
	line(1);
}
void outDy(const char a[])
{
	blank(9);
	int i = 0;
	while (a[i] != '\0')
	{
		Sleep(wenben);
		putchar(a[i]);
		i++;
	}
	line(1);
}
void outM(const char a[])
{
	int i = strlen(a) - 1;
	blank(9 + (50 - i) / 2);
	cout << a;
	line(1);
}
void outMDy(const char a[])
{
	int b = strlen(a) - 1;
	blank(9 + (50 - b) / 2);
	int i = 0;
	while (a[i] != '\0')
	{
		Sleep(wenben);
		putchar(a[i]);
		i++;
	}
	line(1);
}

void outG(const char a[])
{
	blank(9);  
	cout << a;
	getS();
	line(1);
}
void outGDy(const char a[])
{
	blank(9);
	int i = 0;
	while (a[i] != '\0')
	{
		Sleep(wenben);
		putchar(a[i]);
		i++;
	}
	getS();
	line(1);
}
void outGODy(const char a[])
{
	blank(9);
	int i = 0;
	while (a[i] != '\0')
	{
		Sleep(wenben);
		putchar(a[i]);
		i++;
	}
	getS();
}
void outGM(const char a[])
{
	
	int i = strlen(a)-1;
	blank(9 + (50 - i) / 2);
	cout << a;
	getS();
	line(1);
}
void outGMDy(const char a[])
{
	int b = strlen(a) - 1;
	blank(9 + (50 - b) / 2);
	int i = 0;
	while (a[i] != '\0')
	{
		Sleep(wenben);
		putchar(a[i]);
		i++;
	}
	getS();
	line(1);
}


void outTop(const char a[])
{
	line(1);
	out(a);
}
void outTopDy(const char a[])
{
	line(1);
	outDy(a);
}


void outODy(const char a[])
{
	
		int i = 0;
		while (a[i] != '\0')
		{
			if(a[i]!=' ')
			Sleep(eve);
			putchar(a[i]);
			i++;
		}
		Sleep(tod);
}
void outODy(const char a[],int b)
{

	int i = 0;
	while (a[i] != '\0')
	{
		if (a[i] != ' ')
			Sleep(b);
		putchar(a[i]);
		i++;
	}
}

//颜色表会用到

void outODy20(const char a[])
{

	int i = 0;
	while (a[i] != '\0')
	{
		if (a[i] != ' ')
			Sleep(Dy_20);
		putchar(a[i]);
		i++;
	}
	Sleep(tod);
}
void outODyJie(const char a[])
{

	int i = 0;
	while (a[i] != '\0')
	{
		if (a[i] != ' ')
			Sleep(Dy_Jie);
		putchar(a[i]);
		i++;
	}
}

void outODy0(const char a[])
{

	int i = 0;
	while (a[i] != '\0')
	{
		if (a[i] != ' ')
			Sleep(eve);
		putchar(a[i]);
		i++;
	}
}
void outOMDy(const char a[])
{
	blankMid(strlen(a));
	
		int i = 0;
		while (a[i] != '\0')
		{
			if (a[i] != ' ')
				Sleep(eve);
			putchar(a[i]);
			i++;
		}
		Sleep(tod);
}
void outOM(const char a[])
{
	blankMid(strlen(a));
	cout << a;
}
void outOMDy0(const char a[])
{
	blankMid(strlen(a));
	int i = 0;
	while (a[i] != '\0')
	{
		if (a[i] != ' ')
			Sleep(eve);
		putchar(a[i]);
		i++;
	}
}
void out2OMDy(const char a[],const char b[])
{
	blank2(5);
	int i = 0;
	outODy0(a);

	int c = strlen(a);
	blank(26 - c);
	outODy0(b);
}
void outOOMDy(const char a[])
{
	blank2(5);
	blankMid(strlen(a));

	int i = 0;
	while (a[i] != '\0')
	{
		if (a[i] != ' ')
			Sleep(eve);
		putchar(a[i]);
		i++;
	}
	Sleep(tod);
}
void outOOM(const char a[])
{
	blank2(5);
	blankMid(strlen(a));
	cout << a;
}


void outO(const char a[])
{
	cout << a;
}
//限定占四格
void outO(int a)
{
	if (a >= 10000)
	{
		cout << "9999";
		return;
	}
	int i = 0, b = a;

	while (a / 10 != 0)
	{
		a /= 10;
		i++;
	}
	blank(3 - i);
	cout << b;
}
//限定占4格,只在输入后Dy
void outODy(int a)
{
	if (a >= 10000)
	{
		cout<<"9999";
		return;
	}
	int i = 0,b=a;

		while(a/10!=0)
		{
				a /= 10;
				i++;
		}
		blank(3 - i);
		cout<<b;
		Sleep(tod);
}

//限定占2格
void outOT(int a)
{
	if(a<10)
	blank(1);
	cout << a;
}



//长延迟
void outODy2(const char a[])
{
	{
		int i = 0;
		while (a[i] != '\0')
		{
			if (a[i] != ' ')
			Sleep(2*tod);
			putchar(a[i]);
			i++;
		}
	}
}


void getS()
{
	char b = 'a';
	while (!(b == '\n' || b == '@'))
		b = getchar();
}
void clear(int a)
{
	system("cls");
	if(a!=0)
	line(a);
}
void clearLine()
{
	printf("\r"); blank(71); printf("\r");
}
void line(int a)
{
	for (; a > 0; a--)printf("\n");
}
void lineDy(int a)
{
	for (; a > 0; a--)
	{
		if (eve == 32)
			Sleep(64);
		else
			if (eve == 10)
				Sleep(38);
			else
				Sleep(10);
		printf("\n");
	}
}
//对eve检测
void endclear1()
{
		for (int i = 0; i <22; i++)
		{
			Sleep(25+i);
			line(1);
		}
}

//手动清行用
void lineDy2(int a)
{
	for (; a > 0; a--)
	{
		Sleep(33);//15
		printf("\n");
	}
}
//手动清行,全部用这个
void endclear2()
{
	for (int i=22; i > 15; i--)
	{
		Sleep(188-i*8);
		printf("\n");
	}
	for (int i = 15; i > 7; i--)
	{
		Sleep( 128 -i * 4);
		printf("\n");
	}
	for (int i = 7; i > 0; i--)
	{
		Sleep(100 - i * 4);
		printf("\n");
	}
}

void lineDy3(int a)
{
	for (; a > 0; a--)
	{
		Sleep(58);//15
		printf("\n");
	}
}

void blank(int a)
{
	switch (a)
	{
	case 0:return;
	case 1:cout << " "; return;
	case 2:cout << "  "; return;
	case 3:cout << "   "; return;
	case 4:cout << "    "; return;
	case 5:cout << "     "; return;
	case 6:cout << "      "; return;
	case 7:cout << "       "; return;
	case 8:cout << "        "; return;
	case 9:cout << "         "; return;
	case 10:cout << "          "; return;
	case 11:cout << "           "; return;
	case 12:cout << "            "; return;
	case 13:cout << "             "; return;
	case 14:cout << "              "; return;
	case 15:cout << "               "; return;
	case 16:cout << "                "; return;
	case 17:cout << "                 "; return;
	case 18:cout << "                  "; return;
	case 19:cout << "                   "; return;
	case 20:cout << "                    "; return;
	case 21:cout << "                     "; return;
	case 22:cout << "                      "; return;
	case 23:cout << "                       "; return;
	case 25:cout << "                         "; return;
	case 27:cout << "                           "; return;
	case 29:cout << "                             "; return;
	case 31:cout << "                               "; return;
	case 33:cout << "                                 "; return;
	case 35:cout << "                                   "; return;
	case 37:cout << "                                     "; return;
	case 39:cout << "                                       "; return;
	default: 
		break;
	}
	for (; a > 0; a--)printf(" ");
}
void blankDy(int a)  //绘画微调
{
	for (; a > 0; a--)
	{
		Sleep(50);
		cout << " ";
	}
}
//提示的初阶函数
void blankMid(int a)
{
	if(a<49)
	{
		int i = 24 - (a - 1) / 2;
		if (a % 2 == 0) i--;
		blank(i);
	}
}

void color(int a )
{
	switch (a)
	{
	case 0:system("color 00"); break;
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
}
void color(int a, int b)
{
	a %= 16; b %= 16;
	if (a == b)
		return;
	switch (a)
	{
	case 0:
		switch (b)
		{
		case 1:system("color 01");break;
		case 2:system("color 02"); break;
		case 3:system("color 03");break;
		case 4:system("color 04");break;
		case 5:system("color 05");break;
		case 6:system("color 06");break;
		case 7:system("color 07");break;
		case 8:system("color 08");break;
		case 9:system("color 09");break;
		case 10:system("color 0A");break;
		case 11:system("color 0B");break;
		case 12:system("color 0C");break;
		case 13:system("color 0D");break;
		case 14:system("color 0E");break;
		case 15:system("color 0F");break;
		default:
			break;
		}
		break;
	case 1:
		switch (b)
		{
		case 0:system("color 10");break;
		case 2:system("color 12");break;
		case 3:system("color 13");break;
		case 4:system("color 14");break;
		case 5:system("color 15");break;
		case 6:system("color 16");break;
		case 7:system("color 17");break;
		case 8:system("color 18");break;
		case 9:system("color 19");break;
		case 10:system("color 1A");break;
		case 11:system("color 1B");break;
		case 12:system("color 1C");break;
		case 13:system("color 1D");break;
		case 14:system("color 1E");break;
		case 15:system("color 1F");break;
		default:
			break;
		}
		break;
	case 2:
		switch (b)
		{
		case 0:system("color 20");break;
		case 1:system("color 21");break;
		case 3:system("color 23");break;
		case 4:system("color 24");break;
		case 5:system("color 25");break;
		case 6:system("color 26");break;
		case 7:system("color 27");break;
		case 8:system("color 28");break;
		case 9:system("color 29");break;
		case 10:system("color 2A");break;
		case 11:system("color 2B");break;
		case 12:system("color 2C");break;
		case 13:system("color 2D");break;
		case 14:system("color 2E");break;
		case 15:system("color 2F");break;
		default:
			break;
		}
		break;
	case 3:
		switch (b)
		{
		case 0:system("color 30");break;
		case 1:system("color 31");break;
		case 2:system("color 32");break;
		case 4:system("color 34");break;
		case 5:system("color 35");break;
		case 6:system("color 36");break;
		case 7:system("color 37");break;
		case 8:system("color 38");break;
		case 9:system("color 39");break;
		case 10:system("color 3A");break;
		case 11:system("color 3B");break;
		case 12:system("color 3C");break;
		case 13:system("color 3D");break;
		case 14:system("color 3E");break;
		case 15:system("color 3F");break;
		default:
			break;
		}
		break;
	case 4:
		switch (b)
		{
		case 0:system("color 40");break;
		case 1:system("color 41");break;
		case 2:system("color 42");break;
		case 3:system("color 43");break;
		case 5:system("color 45");break;
		case 6:system("color 46");break;
		case 7:system("color 47");break;
		case 8:system("color 48");break;
		case 9:system("color 49");break;
		case 10:system("color 4A");break;
		case 11:system("color 4B");break;
		case 12:system("color 4C");break;
		case 13:system("color 4D");break;
		case 14:system("color 4E");break;
		case 15:system("color 4F");break;
		default:
			break;
		}
		break;
	case 5:
		switch (b)
		{
		case 0:system("color 50");break;
		case 1:system("color 51");break;
		case 2:system("color 52");break;
		case 3:system("color 53");break;
		case 4:system("color 54");break;
		case 6:system("color 56");break;
		case 7:system("color 57");break;
		case 8:system("color 58");break;
		case 9:system("color 59");break;
		case 10:system("color 5A");break;
		case 11:system("color 5B");break;
		case 12:system("color 5C");break;
		case 13:system("color 5D");break;
		case 14:system("color 5E");break;
		case 15:system("color 5F");break;
		default:
			break;
		}
		break;
	case 6:
		switch (b)
		{
		case 0:system("color 60");break;
		case 1:system("color 61");break;
		case 2:system("color 62");break;
		case 3:system("color 63");break;
		case 4:system("color 64");break;
		case 5:system("color 65");break;
		case 7:system("color 67");break;
		case 8:system("color 68");break;
		case 9:system("color 69");break;
		case 10:system("color  6A");break;
		case 11:system("color 6B");break;
		case 12:system("color 6C");break;
		case 13:system("color 6D");break;
		case 14:system("color 6E");break;
		case 15:system("color 6F");break;
		default:
			break;
		}
		break;
	case 7:
		switch (b)
		{
		case 0:system("color 70");break;
		case 1:system("color 71");break;
		case 2:system("color 72");break;
		case 3:system("color 73");break;
		case 4:system("color 74");break;
		case 5:system("color 75");break;
		case 6:system("color 76");break;
		case 8:system("color 78");break;
		case 9:system("color 79");break;
		case 10:system("color 7A");break;
		case 11:system("color 7B");break;
		case 12:system("color 7C");break;
		case 13:system("color 7D");break;
		case 14:system("color 7E");break;
		case 15:system("color 7F");break;
		default:
			break;
		}
		break;
	case 8:
		switch (b)
		{
		case 0:system("color 80");break;
		case 1:system("color 81");break;
		case 2:system("color 82");break;
		case 3:system("color 83");break;
		case 4:system("color 84");break;
		case 5:system("color 85");break;
		case 6:system("color 86");break;
		case 7:system("color 87");break;
		case 9:system("color 89");break;
		case 10:system("color  8A");break;
		case 11:system("color 8B");break;
		case 12:system("color 8C");break;
		case 13:system("color 8D");break;
		case 14:system("color 8E");break;
		case 15:system("color 8F");break;
		default:
			break;
		}
		break;
	case 9:
		switch (b)
		{
		case 0:system("color 90");break;
		case 1:system("color 91");break;
		case 2:system("color 92");break;
		case 3:system("color 93");break;
		case 4:system("color 94");break;
		case 5:system("color 95");break;
		case 6:system("color 96");break;
		case 7:system("color 97");break;
		case 8:system("color 98");break;
		case 10:system("color 9A");break;
		case 11:system("color 9B");break;
		case 12:system("color 9C");break;
		case 13:system("color 9D");break;
		case 14:system("color 9E");break;
		case 15:system("color 9F");break;
		default:
			break;
		}
		break;
	case 10:
		switch (b)
		{
		case 0:system("color A0");break;
		case 1:system("color A1");break;
		case 2:system("color A2");break;
		case 3:system("color A3");break;
		case 4:system("color A4");break;
		case 5:system("color A5");break;
		case 6:system("color A6");break;
		case 7:system("color A7");break;
		case 8:system("color A8");break;
		case 9:system("color A9");break;
		case 11:system("color AB");break;
		case 12:system("color AC");break;
		case 13:system("color AD");break;
		case 14:system("color AE");break;
		case 15:system("color AF");break;
		default:
			break;
		}
		break;
	case 11:
		switch (b)
		{
		case 0:system("color B0");break;
		case 1:system("color B1");break;
		case 2:system("color B2");break;
		case 3:system("color B3");break;
		case 4:system("color B4");break;
		case 5:system("color B5");break;
		case 6:system("color B6");break;
		case 7:system("color B7");break;
		case 8:system("color B8");break;
		case 9:system("color B9");break;
		case 10:system("color BA");break;
		case 12:system("color BC");break;
		case 13:system("color BD");break;
		case 14:system("color BE");break;
		case 15:system("color BF");break;
		default:
			break;
		}
		break;
	case 12:
		switch (b)
		{
		case 0:system("color C0");break;
		case 1:system("color C1");break;
		case 2:system("color C2");break;
		case 3:system("color C3");break;
		case 4:system("color C4");break;
		case 5:system("color C5");break;
		case 6:system("color C6");break;
		case 7:system("color C7");break;
		case 8:system("color C8");break;
		case 9:system("color C9");break;
		case 10:system("color CA");break;
		case 11:system("color CB");break;
		case 13:system("color CD");break;
		case 14:system("color CE");break;
		case 15:system("color CF");break;
		default:
			break;
		}
		break;
	case 13:
		switch (b)
		{
		case 0:system("color D0");break;
		case 1:system("color D1");break;
		case 2:system("color D2");break;
		case 3:system("color D3");break;
		case 4:system("color D4");break;
		case 5:system("color D5");break;
		case 6:system("color D6");break;
		case 7:system("color D7");break;
		case 8:system("color D8");break;
		case 9:system("color D9");break;
		case 10:system("color DA");break;
		case 11:system("color DB");break;
		case 12:system("color DC");break;
		case 14:system("color DE");break;
		case 15:system("color DF");break;
		default:
			break;
		}
		break;
	case 14:
		switch (b)
		{
		case 0:system("color E0");break;
		case 1:system("color E1");break;
		case 2:system("color E2");break;
		case 3:system("color E3");break;
		case 4:system("color E4");break;
		case 5:system("color E5");break;
		case 6:system("color E6");break;
		case 7:system("color E7");break;
		case 8:system("color E8");break;
		case 9:system("color E9");break;
		case 10:system("color EA");break;
		case 11:system("color EB");break;
		case 12:system("color EC");break;
		case 13:system("color ED");break;
		case 15:system("color EF");break;
		default:
			break;
		}
		break;
	case 15:
		switch (b)
		{
		case 0:system("color F0");break;
		case 1:system("color F1");break;
		case 2:system("color F2");break;
		case 3:system("color F3");break;
		case 4:system("color F4");break;
		case 5:system("color F5");break;
		case 6:system("color F6");break;
		case 7:system("color F7");break;
		case 8:system("color F8");break;
		case 9:system("color F9");break;
		case 10:system("color FA");break;
		case 11:system("color FB");break;
		case 12:system("color FC");break;
		case 13:system("color FD");break;
		case 14:system("color FE");break;
		default:		
			break;
		}
		break;
	default:
		break;
	}
}
void gracolor(int a)
{
	switch (a)
	{
	case 6: color(10); Sleep(1000); color(2); Sleep(1000); color(6); Sleep(1000); clear(0); Sleep(1000); break;
	default:
		break;
	}
}
void tranCol(int a)
{
	a %= 16;
	switch (a)
	{
	case 0:cout << "纯黑"; break;
	case 1:cout << "纯蓝"; break;
	case 2:cout << "深绿"; break;
	case 3:cout << "天蓝"; break;
	case 4:cout << "纯红"; break;
	case 5:cout << "深紫"; break;
	case 6:cout << "棕黄"; break;
	case 7:cout << "淡灰"; break;
	case 8:cout << "深灰"; break;
	case 9:cout << "湖蓝"; break;
	case 10:cout << "草绿"; break;
	case 11:cout << "冰蓝"; break;
	case 12:cout << "粉红"; break;
	case 13:cout << "紫红"; break;
	case 14:cout << "月黄"; break;
	case 15:cout << "纯白"; break;
		
	default:
		break;
	}
}
void tranColDy(int a)
{
	a %= 16;
	switch (a)
	{
	case 0:outODy0( "纯黑"); break;
	case 1:outODy0( "纯蓝"); break;
	case 2:outODy0( "深绿"); break;
	case 3:outODy0( "天蓝"); break;
	case 4:outODy0( "纯红"); break;
	case 5:outODy0( "深紫"); break;
	case 6:outODy0( "棕黄"); break;
	case 7:outODy0( "淡灰"); break;
	case 8:outODy0( "深灰"); break;
	case 9:outODy0( "湖蓝"); break;
	case 10:outODy0( "草绿"); break;
	case 11:outODy0( "冰蓝"); break;
	case 12:outODy0( "粉红"); break;
	case 13:outODy0( "紫红"); break;
	case 14:outODy0( "月黄"); break;
	case 15:outODy0( "纯白"); break;

	default:
		break;
	}
}
void tranColDy0(int a)
{
	switch (a)
	{
	case 0:outODy0("纯黑"); break;
	case 1:outODy0("纯蓝"); break;
	case 2:outODy0("深绿"); break;
	case 3:outODy0("天蓝"); break;
	case 4:outODy0("纯红"); break;
	case 5:outODy0("深紫"); break;
	case 6:outODy0("棕黄"); break;
	case 7:outODy0("淡灰"); break;
	case 8:outODy0("深灰"); break;
	case 9:outODy0("湖蓝"); break;
	case 10:outODy0("草绿"); break;
	case 11:outODy0("冰蓝"); break;
	case 12:outODy0("粉红"); break;
	case 13:outODy0("紫红"); break;
	case 14:outODy0("月黄"); break;
	case 15:outODy0("纯白"); break;

	default:
		break;
	}
}
//共占8行
void colorTable()
{
	blank2(5); full(24); line(1);
	blank2(5); full(1); full(9); outO("颜"); half(2); outO("色");  full(9); full(1);  line(1);
	blank2(5); full(24); line(1);
	for (int i = 0; i < 16; i+=4)
	{
		blank2(5);  full(1); outOT(i+1);  blank2(1); tranCol(i); full(2); outOT(i+2);  blank2(1); tranCol(i+1);
		full(2); outOT(i+3);  blank2(1); tranCol(i+2); full(2); outOT(i+4);  blank2(1); tranCol(i+3);  full(1);
		line(1);
	}
	blank2(5); full(24);
}

//共占8行
void colorTableDy()
{
	blank2(5); fullDyJie(24); line(1);
	blank2(5); fullDyJie(1);  fullDyJie(9); outO("颜"); halfDyJie(2); outO("色");  fullDyJie(9); fullDyJie(1);  line(1);
	blank2(5); fullDyJie(24); line(1);
	for (int i = 0; i < 16; i += 4)
	{
		blank2(5);  fullDyJie(1); outOT(i+1);  blank2(1); tranColDy(i); fullDyJie(2); outOT(i + 2);  blank2(1); tranColDy(i + 1);
		fullDyJie(2); outOT(i + 3);  blank2(1); tranColDy(i + 2); fullDyJie(2); outOT(i + 4);  blank2(1); tranColDy(i + 3);  fullDyJie(1);
		line(1);
	}
	blank2(5); fullDyJie(24);
}

//淘汰的星打印

//void star(int a)     //绘画微调
//{
//	for (; a > 0; a--)
//	{
//		cout << "**";
//	}
//}
//void starDy(int a)
//{
//	for (; a > 0; a--)
//	{
//		Sleep(25);
//		cout << "*";
//		Sleep(25);
//		cout << "*";
//	}
//}
//void starDy2(int a)
//{
//	for (; a > 0; a--)
//	{
//		Sleep(100);
//		cout << "*";
//		Sleep(100);
//		cout << "*";
//	}
//}   

void blank2(int a)
{
	switch (a)
	{
	case 0:return;
	case 1:cout << "  "; return;
	case 2:cout << "    "; return;
	case 3:cout << "      "; return;
	case 4:cout << "        "; return;
	case 5:cout << "          "; return;
	case 6:cout << "            "; return;
	case 7:cout << "              "; return;
	case 8:cout << "                "; return;
	case 9:cout << "                  "; return;

	case 10:cout << "                    "; return;
	case 11:cout << "                      "; return;
	case 12:cout << "                        "; return;
	case 13:cout << "                          "; return;
	case 14:cout << "                            "; return;
	case 15:cout << "                              "; return;
	case 16:cout << "                                "; return;
	case 17:cout << "                                  "; return;
	case 18:cout << "                                    "; return;
	case 19:cout << "                                      "; return;
	case 20:cout << "                                        "; return;
	case 21:cout << "                                          "; return;
	case 22:cout << "                                            "; return;
	case 23:cout << "                                              "; return;
	default:
		break;
	}
	for (; a > 0; a--)printf("  ");
}

//绘画微调，drawline会用的小玩具
void blank2Dy(int a)
{
	for (; a > 0; a--)
	{
		Sleep(25);
		cout << " ";
		Sleep(25);
		cout << " ";
	}
}

//绘画微调
void full(int a)     
{
	switch (a)
	{
	case 0:return;
	case 1 :cout << "█"; return;
	case 2 :cout << "██"; return;
	case 3 :cout << "███"; return;
	case 4 :cout << "████"; return;
	case 5 :cout << "█████"; return;
	case 6 :cout << "██████"; return;
	case 7 :cout << "███████"; return;
	case 8:cout << "████████"; return;
	case 9:cout << "█████████"; return;
	case 10:cout << "██████████"; return;
	case 11:cout << "███████████"; return;
	case 12:cout << "████████████"; return;
	case 13:cout << "█████████████"; return;
	case 14:cout << "██████████████"; return;
	case 15:cout << "███████████████"; return;
	case 16:cout << "████████████████"; return;
	case 17:cout << "█████████████████"; return;
	case 18:cout << "██████████████████"; return;
	case 19:cout << "███████████████████"; return;
	case 20:cout << "████████████████████"; return;
	case 21:cout << "█████████████████████"; return;
	case 22:cout << "██████████████████████"; return;
	case 23:cout << "███████████████████████"; return;
	case 24:cout << "████████████████████████"; return;
	case 25:cout << "█████████████████████████"; return;
	case 26:cout << "██████████████████████████"; return;
	case 27:cout << "███████████████████████████"; return;
	case 28:cout << "████████████████████████████"; return;
	case 29:cout << "█████████████████████████████"; return;
	case 30:cout << "██████████████████████████████"; return;
	case 31:cout << "███████████████████████████████"; return;
	case 32:cout << "████████████████████████████████"; return;
	case 33:cout << "█████████████████████████████████"; return;
	case 34:cout << "██████████████████████████████████"; return;
	case 35:cout << "███████████████████████████████████"; return;
	default:
		break;
	}
	for (; a > 0; a--)
	{
		cout << "█"; //▓█→「」
	}
}
//50ms
void fullDy(int a)
{
	for (; a > 0; a--)
	{
		Sleep(tod);
		cout << "█";
	}
}
void fullDy(int a,int b)
{
	for (; a > 0; a--)
	{
		Sleep(b);
		cout << "█";
	}
}
void fullDy20(int a)
{
	for (; a > 0; a--)
	{
		Sleep(Dy_20);
		cout << "█";

	}
}
void fullDyJie(int a)
{
	for (; a > 0; a--)
	{
		Sleep(Dy_Jie);
		cout << "█";

	}
}
//200ms
void fullDy200(int a)
{
	for (; a > 0; a--)
	{
		Sleep(200);
		cout << "█";
	}
}

void half(int a)
{
	
	switch (a)
	{
	case 0:return;
	case 1:cout << "▓"; return;
	case 2:cout << "▓▓"; return;
	case 3:cout << "▓▓▓"; return;
	case 4:cout << "▓▓▓▓"; return;
	case 5:cout << "▓▓▓▓▓"; return;
	case 6:cout << "▓▓▓▓▓▓"; return;
	default:
		break;
	}
		for (; a > 0; a--)
		{
			cout << "▓"; 
		}
}
void halfDy(int a)
{
	for (; a > 0; a--)
	{
		Sleep(tod);
		cout << "▓";
	}
}
void halfDy(int a,int b)
{
	for (; a > 0; a--)
	{
		Sleep(b);
		cout << "▓";
	}
}
void halfDy20(int a)
{
	for (; a > 0; a--)
	{
		Sleep(Dy_20);
		cout << "▓";
	}
}
void halfDyJie(int a)
{
	for (; a > 0; a--)
	{
		Sleep(Dy_Jie);
		cout << "▓";
	}
}
void halfDy200(int a)
{
	for (; a > 0; a--)
	{
		Sleep(200);
		cout << "▓";
	}
}


//现实位置时用到
void Weizhi(int a)
{
	line(1);
	blank2(a);
	for (int i = 1; i <= 24; i++)
	{
		if (i < 10) printf(" ");
		cout<<(i);
	}
}

//先line
void draw(int a[])
{
	line(1);
	
	blank2(2);
	int i;
	for ( i = 0; a[i] != -1; i++);
	int b = i / 2;

	for (i = 0; i < b; i++)
	{
		switch (a[i])
		{
		case 0:blank2(a[i + b]); break;
		case 1:half(a[i + b]); break;
		case 2:full(a[i + b]); break;
		default:
			break;
		}
	}

}

//先line
void drawDy(int a[])
{
	line(1);
	blank2(2);
	int i;
	for (i = 0 ; a[i] != -1; i++);
	int b = i/2;

	for (i = 0; i < b; i++)
	{
		switch (a[i])
		{
		case 0:blank2(a[i + b]); break;
		case 1:halfDy20(a[i + b]); break;
		case 2:fullDy20(a[i + b]); break;
		default:
			break;
		}
	}
	
}



//老玩具
//
//void drawLine(int a, int b) //包括换行
//{
//	line(1); blank(a); star(b);
//}
//void drawLine(int a, int b, int c, int d)
//{
//	line(1); blank(a); star(b); blank2(c); star(d);
//}
//void drawLine(int a, int b, int c, int d, int a1, int a2)
//{
//	line(1); blank(a); star(b); blank2(c); star(d); blank2(a1); star(a2);
//}
//void drawLine(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
//{
//	line(1); blank(a1); star(a2); blank2(a3); star(a4); blank2(a5); star(a6); blank2(a7); star(a8);
//}
//
//void drawLineAllDy(int a, int b) //包括换行
//{
//	line(1);
//	blank(20); //可变
//	blank2Dy(a); starDy(b);
//}
//void drawLineAllDy(int a, int b, int c, int d)
//{
//	line(1); blank(20); blank2Dy(a); starDy(b); blank2Dy(c); starDy(d);
//}
//void drawLineAllDy(int a, int b, int c, int d, int a1, int a2)
//{
//	line(1); blank(20); blank2Dy(a); starDy(b); blank2Dy(c); starDy(d); blank2Dy(a1); starDy(a2);
//}
//void drawLineAllDy(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
//{
//	line(1); blank(20); blank2Dy(a1); starDy(a2); blank2Dy(a3); starDy(a4); blank2Dy(a5); starDy(a6); blank2Dy(a7); starDy(a8);
//}
//
//void drawLineStarDy(int a, int b) //包括换行
//{
//	line(1);
//	blank(20); //可变
//	blank2(a); fullDy(b);
//}
//void drawLineStarDy(int a, int b, int c, int d)
//{
//	line(1); blank(20); blank2(a); fullDy(b); blank2(c); fullDy(d);
//}
//void drawLineStarDy(int a, int b, int c, int d, int a1, int a2)
//{
//	line(1); blank(20); blank2(a); fullDy(b); blank2(c); fullDy(d); blank2(a1); fullDy(a2);
//}
//void drawLineStarDy(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
//{
//	line(1); blank(20); blank2(a1); fullDy(a2); blank2(a3); fullDy(a4); blank2(a5); fullDy(a6); blank2(a7); fullDy(a8);
//}
//
//void drawLineFroDy(int a, int b) //包括换行
//{
//	line(1);
//	blankDy(20); //可变
//	blank2Dy(a); starDy(b);
//}
//void drawLineFroDy(int a, int b, int c, int d)
//{
//	line(1); blankDy(20); blank2Dy(a); starDy(b); blank2Dy(c); starDy(d);
//}
//void drawLineFroDy(int a, int b, int c, int d, int a1, int a2)
//{
//	line(1); blankDy(20); blank2Dy(a); starDy(b); blank2Dy(c); starDy(d); blank2Dy(a1); starDy(a2);
//}
//void drawLineFroDy(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
//{
//	line(1); blankDy(20); blank2Dy(a1); starDy(a2); blank2Dy(a3); starDy(a4); blank2Dy(a5); starDy(a6); blank2Dy(a7); starDy(a8);
//}
//以下已经过时
//int inInt( int num, int color1)
//{
//	color(color1);
//	Sleep(500);
//	int a = 0;
//	line(2);
//	blank(9);
//	outODy("请输入序号[1,");
//	Sleep(50);
//	cout << num;
//	outODy("]：");
//	cin >> a;
//	getS();
//	while (!(a >= 1 && a <= num))
//	{
//		a = 0;
//		blank(9);
//		outODy("序号不在[1,");
//		Sleep(50);
//		cout << num;
//		outODy("]内= =");
//		line(1);
//		blank(9);
//		outODy("请重新输入序号：");
//		cin >> a;
//		getS();
//	}
//	color(15);
//	Sleep(500);
//	return a;
//}
//int inInt(int num, const char b[], const char c[], const char d[],int color1, int color2)
//{
//	color(color1);
//	Sleep(500);
//	int a = -1;
//	line(2);
//	blank(9);
//	outODy(b);
//	printf("[1,%d]：",num);
//	cin >> a;
//	getS();
//	while (!(a >= 1 && a <= num))
//	{
//		a = -1;
//		blank(9);
//		outODy(c);
//		printf("不在[1,%d]内= =",num);
//		line(1);
//		blank(9);
//		outODy(d);
//		cin >> a;
//		getS();
//	}
//	color(color2);
//	Sleep(500);
//	return a;
//}
//void outInt( const char b[], const char c[])
//{
//
//	printf("\n1.%s   2.%s\n",b,c);
//}
//void outInt( const char b[], const char c[], const char d[])
//{
//
//	
//}
//void outInt( const char b[], const char c[], const char d[], const char e[])
//{
//
//	printf("\n  1.%s   2.%s   3.%s   4.%s\n",  b, c,d,e);
//}
//void outInt( const char b[], const char c[], const char d[], const char e[], const char f[])
//{
//
//	printf("\n  1.%s   2.%s   3.%s   4.%s   5.%s\n",  b, c,d,e,f);
//}
//void outInt( const char b[], const char c[], const char d[], const char e[], const char f[], const char g[])
//{
//
//	printf("\n  1.%s   2.%s   3.%s   4.%s   5.%s   6.%s\n",  b, c,d,e,f,g);
//}
//以上已经过时
