#pragma once
#include"blank.h"
#include"screen.h"
#include"cursor.h"

struct Rect
{
	//char* ul, * ur, * dl, * dr, * up, * down, * left, * right;
	//左上，右上，左下，右下，左，上，右，下
	char(* rect)[3] =new char[8][3]{};
	Str s;
	void copy(const char a[8][3])
	{
		for (int i = 0; i < 8; i++)
			s.copy(rect[i], a[i]);
	}
	~Rect() { delete[]rect; }
};
namespace boardlinemodel
{
	
	char full[][3];
	char singleline[][3];
	char doubleline[][3];
	char highdoubleline[][3];
	char widedoubleline[][3];
	char fullcorners[][3];
}

class Pattern
{
public:
	Pattern()
	{
		wide = 0;
		high = 0;
		pattern = 0;
		color = 0;
	}
	void build(int WIDE, int HIGH)
	{
		wide = WIDE;
		high = HIGH;
		pattern = new char[high * wide + 1]{};
		color = new char[high * wide + 1]{};
	}
	//测试用
	void buildtest(int WIDE, int HIGH)
	{
		wide = WIDE;
		high = HIGH;
		pattern = new char[high * wide + 1]{};
		color = new char[high * wide + 1]{};
		for (int i = 0; i < high * wide; i++)
			pattern[i] = 32;
	}

	~Pattern() { delete[]pattern, delete[]color; }

	//返回引用
	char& prr(int High, int Wide)
	{
		return pattern[(High - 1) * wide + Wide - 1];
	}
	//返回地址
	char* arrayp(int High, int Wide)
	{
		return &pattern[(High - 1) * wide + Wide - 1];
	}
	//返回第一个地址
	char& prr2(int High, int Wide, const char* a)
	{
		prr(High, Wide) = a[0];
		prr(High, Wide + 1) = a[1];
		return pattern[(High - 1) * wide + Wide - 1];
	}

	//将b的两个字节复制到a
	void copy2(char&a,const char b[])
	{
		a = b[0];
		*(&a + 1) = b[1];
	}

	//从HW开始 按行 复制x个字节,num<=0时则为差n个使列满
	///有必要分成两组函数，因为负值有不同的意义
	//取消str的使用，不再支持2位以上的字符串
	void rangewidesetp(int High, int Wide,const char a,int num)
	{
		for (int i = 0; i < wide - Wide + 1- num; i++)
		{
			prr(High, Wide+i) = a;
		}
	}
	
	//从HW开始 按行 复制到本行剩下x个“2格”,到本行截止为wide-Wide+1
	void rangewidesetp(int High, int Wide, const char* a, int num)
	{
		for (int i = 0; i < (wide-Wide+1)/2 - num ;i++)
		{
			prr2(High, Wide + i*2, a);
		}
	}

	//从HW开始 按列 复制到本列剩下x个格,到本行截止为wide-Wide+1
	void rangehighsetp(int High, int Wide, const char a, int num)
	{
		for (int i = 0; i < high-High+1-num; i++)
		{
			prr(High + i, Wide) = a;
		}
	}
	
	//从HW开始 按列 复制x个字节,到本行截止为wide-Wide+1
	void rangehighsetp(int High, int Wide, const char* a, int num)
	{
		for (int i = 0; i < high - High + 1 - num; i++)
		{
			prr2(High+i, Wide, a);
		}
	}

	//返回引用
	char& crr(int High, int Wide)
	{
		return color[(High - 1) * wide + Wide - 1];
	}
    //返回地址
	char* arrayc(int High, int Wide)
	{
		return &color[(High - 1) * wide + Wide - 1];
	}


	//从0位直接赋值
	void copyprr(const char a[])
	{
		strcpy_s(pattern, strlen(a) + 1, a);
	}
	void widecopy(int High, int Wide, const char a[])
	{
		strcpy_s(arrayp(High,Wide), strlen(a) + 1, a);
	}
	void highcopy(int High, int Wide, const char a[])
	{
		for (int i = 0; i < (int)strlen(a)/2; i++)
		{
			copy2(prr(High + i, Wide), a);
		}
	}

	void colorall(int a)
	{
		for (int i = 0; i < high * wide; i++)
			color[i] = a;
	}

	void widecolor(int High, int Wide, char a, int num)
	{
		for (int i = 0; i < num; i++)
			crr(High, Wide + i) = a;
	}
	void highcolor(int High, int Wide, char a, int num)
	{
		for (int i = 0; i < num; i++)
			crr(High + i, Wide) = a;
	}


	void countmode()
	{
		build(1, 5);
	}
	//动画
	Pattern& count(int num)
	{
		switch (num % 12)
		{
		case 0:
			copyprr("     "); break;
		case 1:
			prr(1, 1) = ':'; colorall(14); break;
		case 2:
			prr(2, 1) = ':'; colorall(10); break;
		case 3:
			prr(3, 1) = ':'; colorall(13); break;
		case 4:
			prr(4, 1) = ':'; colorall(11); break;
		case 5:
			prr(5, 1) = ':'; colorall(15); break;
		case 6:
			copyprr("     "); break;
		case 7:
			prr(1, 1) = ':'; crr(1,1)=14; break;
		case 8:
			prr(2, 1) = ':'; crr(2, 1)=10; break;
		case 9:
			prr(3, 1) = ':';  crr(3, 1) = 13; break;
		case 10:
			prr(4, 1) = ':'; crr(4, 1) = 11; break;
		case 11:
			prr(5, 1) = ':';  crr(5, 1) = 15; break;
		
		default:
			break;
		}
		return *this;
	}


	void boardline(int WIDE,int HIGH, int color,int num)
	{
		//有修改
		build(WIDE, HIGH);
		colorall(color);

		if (!num) return;

		Rect bor;
		
		switch (num)
		{
		case 1: bor.copy(boardlinemodel::full ); break;
		case 2: bor.copy(boardlinemodel::fullcorners); break;
		case 3: bor.copy(boardlinemodel ::fullcorners); break;
		//case 4: bor.copy(boardlinemodel ::highdoubleline ); break;
		//case 5: bor.copy(boardlinemodel ::widedoubleline ); break;
		//case 6: bor.copy(boardlinemodel ::singleline ); break;
		//case 7: bor.copy(boardlinemodel ::doubleline); break;
		//case 8: bor.copy(boardlinemodel ::doubleline); break;
		default:
			break;
		}
		rangewidesetp(1, 3, bor.rect[5], 1);
		rangewidesetp(high, 3, bor.rect[7], 1);
		rangehighsetp(2, 1, bor.rect[4], 1);
		rangehighsetp(2, wide-1, bor.rect[6], 1);

		if (num > 0 && num<3)
		{
			prr2(1, 1, bor.rect[0]);
			prr2(1, wide-1, bor.rect[1]);
			prr2(high, 1, bor.rect[2]);
			prr2(high, wide-1, bor.rect[3]);
		}
		else
		{
			if (num == 3)
				//适用全部三格四角且不同类型
			{
				prr2(1, 1, bor.rect[0]);
				prr2(1, wide - 1, bor.rect[1]);
				prr2(high, 1, bor.rect[2]);
				prr2(high, wide - 1, bor.rect[3]);

				prr2(2, 1, bor.rect[0]);
				prr2(2, wide-1, bor.rect[1]);
				prr2(high-1, 1, bor.rect[2]);
				prr2(high-1, wide-1, bor.rect[3]);

				prr2(1, 3, bor.rect[0]);
				prr2(1, wide - 3, bor.rect[1]);
				prr2(high, 3, bor.rect[2]);
				prr2(high, wide - 3, bor.rect[3]);
				
			}
			
		}
		
	}

	

	int wide;
	int high;
private:
	char* pattern;
	char* color;
};

