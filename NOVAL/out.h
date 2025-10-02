#pragma once
#include"page.h"
#include"get.h"
#include"pattern.h"
#include"color.h"

class OutPattern
{
public:
	OutPattern(const Screen& scr) :cursor(scr)
	{
		patterndy = scr.outdata.patterndy;
		patterndysave = scr.outdata.patterndy;

		wide = scr.wide;
		high = scr.high;

		patternmode = scr.boarddata.patternmode;
		animatemode = scr.boarddata.animatemode;
	}

	void out(Pattern& pattern, int x, int y)
	{
		int HIGH;
		int WIDE;
		cursor.setxy(x, y);
		for (HIGH = 1; HIGH <= pattern.high; HIGH++)
		{
			for (WIDE = 1; WIDE <= pattern.wide;)
			{
				outpatternword(pattern, HIGH, WIDE);
			}
			cursor.setx(x);
			cursor.addy(1);
		}
	}

	int backcolor=0;

private:
	Cursor cursor;
	Color color;
	

	char reg[3] = {};
	char reg1 = 0, reg2 = 0;

	Str s;

	//board
	int patternmode = 2;
	int animatemode = 0;

	//out
	int patterndy;
	int patterndysave;

	//计算坐标
	int wide;
	int high;

	void outpatternword(Pattern& pattern, int& HIGH, int& WIDE)
	{
		if (!pattern.prr(HIGH, WIDE))
		{
			color.setback(backcolor);
			cout << "  ";
			WIDE+=2;
			cursor.addx(2);
		}
		else
			if (pattern.prr(HIGH, WIDE) == 'b')
			{
				color.setblank(pattern.crr(HIGH, WIDE));
				cout << "  ";
				WIDE += 2;
				cursor.addx(2);
				return;
			}
			else
				if (pattern.prr(HIGH, WIDE) >= 32 && pattern.prr(HIGH, WIDE) <= 127)
				{
					//改动
					color.set(pattern.crr(HIGH, WIDE),backcolor);
					cout << pattern.prr(HIGH, WIDE);
					WIDE++;
					cursor.addx(1);
					return;
				}
				else
				{
					//改动
					color.set(pattern.crr(HIGH, WIDE),backcolor);
					reg[0] = pattern.prr(HIGH, WIDE++);
					reg[1] = pattern.prr(HIGH, WIDE++);
					cout << reg;
					cursor.addx(2);
					return;
				}
	}
};

class OutWord
{
public:
	OutWord(const Screen& scr) :
		//in(&reg1, &reg2), 
		cursor(scr), outpattern(scr),in(reg1,reg2,control)
		//,wordcolor(list.mainwordcolor, list.mainbackcolor)
	{
		worddy = scr.outdata.worddy;
		patterndy = scr.outdata.patterndy;
		row = scr.worddata.row;
		wide = scr.wide;
		high = scr.high;
		leftposition = (wide - row) / 2 + 1;
		rightposition = (wide + row) / 2 + 1;


		listend = 0;
		pageend = 0;
		paraend = 0;
		wordend = 0;

		pagesave = 1;
		parasave = 1;
		wordsave = 0;

		hline = scr.worddata.hline;
		phblank = scr.worddata.phblank;
		eline = scr.worddata.eline;

		//移入pagelist
		//boardmode = scr.boarddata.patternmode;
		//animatemode = scr.boarddata.animatemode;
	}

	//void save(Save& save,int i)
	//{
	//	save.listdata[i].pagesave= pagesave;
	//	save.listdata[i].parasave= parasave;
	//}
	//void load(Save& save,Pagelist& list ,int i)
	//{
	//	cursor.hide();
	//	pagesave = save.listdata[i].pagesave;
	//	parasave = save.listdata[i].parasave;
	//	nowpage = list.pagehead->next;
	//	while (nowpage->rank != pagesave)
	//		nowpage = nowpage->next;
	//	nowpara = nowpage->parahead->next;
	////	outpattern();
	//	cursor.sety(hline);
	//	worddy = 0;
	//	cursor.setx(leftposition + phblank);
	//	parajump = 1;
	//	while (nowpara->rank != parasave)
	//	{
	//		outpara();
	//		cursor.addy(eline + 1);
	//		nowpara = nowpara->next;
	//	}
	//	parajump = 0;
	//	worddy = worddysave;
	//	//outlist(list);
	//}


	void outlist( const Pagelist& list)
	{
		//board动画
		//共七个颜色，初始化
		wordmaincolor=wordcolor = list.mainwordcolor;
		wordbackmaincolor=wordbackcolor = list.mainwordbackcolor;
		backcolor = list.mainbackcolor;
		outpattern.backcolor = backcolor;//背景颜色与图案无关(图案只有有意义块拥有颜色)

		//背景板初始化，生成背景板
		pattern = new Pattern;
		pattern->boardline(wide, high, list.boardcolor, list.boardmode);
		outpattern.out(*pattern, 1, 1);

		//链单初始化
		nowpage = list.pagehead;
		listend = 0;

		while (!listend)
		{
			nowpage = nowpage->next;
			nowpara = nowpage->parahead;
			outpage();
		}
		delete pattern;
		clear();
	}
	void outpage()
	{
		//保存每页开始的颜色数据，用于save
		wordcolorsave = wordcolor;
		wordbackcolorsave = wordbackcolor;
		backcolorsave = backcolor;

		//每页开始的清除文字
		clear();

		//擦除使得back=backcolor,此时需要换回wordback
		color.set(wordcolor, wordbackcolor);

		pageend = 0;
		cursor.sety(hline);
		while (!pageend)
		{
			nowpara = nowpara->next;
			outpara();
			if(!pageend)
			cursor.addy(eline + 1);
		}
	}
	void outpara()
	{
		paraend = 0;
		str = nowpara->str;
		cursor.setx(leftposition + phblank);

		while (!paraend)
		{
			decodeword();
		}
		nowword = 0;

	}

	void decodeword()
	{
		switch (str[nowword])
		{
		case '$':in.wait();
			paraend = 1; pageend = 1; listend = 1; break;
		case '#':
			in.wait();
			if (reg1 == 'q')
			{
				quick++;
				quick %= 3;
			}
			if (reg1 == 27)
			{
				paraend = 1; pageend = 1; listend = 1;
			}
				
			paraend = 1; pageend = 1; break;
		case 0:
			if (!parajump)
			{
				in.wait();
				if (reg1 == 'q')
				{
					quick++;
					quick %= 3;
				}
				if (reg1 == 27)
				{
					paraend = 1; pageend = 1; listend = 1;
				}
			}
			paraend = 1;  break;
		case '%':changecolor(); break;
		default:
			outword();
			break;
		}
	}
	void outword()
	{
		if (cursor.xx >= rightposition-1)
		{
			cursor.setx(leftposition);
			cursor.addy(1);
		}
		if (cursor.yy >= high - hline)
		{
			reg1 = _getch();
			clear();
			cursor.setxy(leftposition, hline);
		}
		color.set(wordcolor, wordbackcolor);
		if(!s.asc(str[nowword]))
		{
		regc[0] = str[nowword++];
		regc[1] = str[nowword++];
		cout << regc;
		cursor.addx(2);
		}
		else
		{
			cout << str[nowword++];
			cursor.addx(1);
		}
		in.nowait();
		if (reg1 == 'q')
		{
			quick++;
			quick %= 3;
		}
		if (reg1 == 27)
		{
			paraend = 1; pageend = 1; listend = 1;
		}

		if (quick == 0)
			Sleep(worddy);
		else
			if (quick == 1)
				Sleep(5);
	}

	void changecolor()
	{
		char ram1[5]{}, ram2[5]{};
		nowword++;
		ram1[0] = str[nowword++];
		ram1[1] = str[nowword++];
		ram1[2] = str[nowword++];
		ram1[3] = str[nowword++];
		ram2[0] = str[nowword++];
		ram2[1] = str[nowword++];
		ram2[2] = str[nowword++];
		ram2[3] = str[nowword++];
		if (strcmp(ram1, "主色") == 0)
			wordcolor = wordmaincolor;
		else
		wordcolor = colortransform(ram1);
		if (strcmp(ram2, "主色") == 0)
			wordbackcolor = wordbackmaincolor;
		else
		wordbackcolor = colortransform(ram2);

	}

	void clear()
	{
		char* rrr = new char[row+1] {};
		for (int j = 0; j < row; j++)
			rrr[j] = 32;

		for (int i = 0; i < high - hline; i++)
		{
			cursor.setxy(leftposition, hline+i);
			color.setback(backcolor);
			cout << rrr ;
		}
	}

	void waitget()
	{
		char reg=_getch();
	}
private:	
	//Page bm,bp;//backmodern,backp
	//Page* page = 0;

	Pattern* pattern=0;

	Cursor cursor;
	Color color;
	//Color patterncolor;
	char* str=0;
	char regc[3] = {};
	char reg1 = 0, reg2 = 0;
	int control = 0;
	Get in;
	Str s;
	OutPattern outpattern;
	
	//now
	//Pagelist* list = 0;
	Page* nowpage = 0;
	Para* nowpara = 0;
	int nowword = 0;

	//end
	int listend = 0;
	int pageend = 0;
	int paraend = 0;
	int wordend = 0;
	int wordcolorsave = 0;
	int wordbackcolorsave = 0;
	int backcolorsave = 0;

	//save
	int pagesave=0;
	int parasave=0;
	int wordsave=0;
	int parajump =0;

	//word
	int hline ;
	int phblank ;
	int eline ;
	int row;
	int leftposition;
	int rightposition;

	//board 应该在list中
	//int boardmode = 2;
	//int animatemode = 0;

	//out
	int worddy;
	int patterndy;
	int quick = 0;

	//color
	int wordcolor=0;
	int wordbackcolor=0;
	int backcolor=0;
	int wordmaincolor = 0;
	int wordbackmaincolor = 0;

	int wide;
	int high;

};
