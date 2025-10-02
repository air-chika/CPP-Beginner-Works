#pragma once
#include<fstream>
#include"page.h"
#include"screen.h"

class File
{
public:
	//页结束#，链结束$
	File& novelread(Pagelist& list,const char a[]);
	File& novelwrite(Pagelist& list, const char a[]);

	void datawrite(Screen& scr,Save& save)
	{
		fout.open("data.txt");
		fout << "//Screen类";
		fout << "\n//基础数值";
		fout << "\n屏幕宽： " << scr.wide;
		fout << "\n屏幕高： " << scr.high;
		fout << "\n//文字";
		fout << "\n首行位置： " << scr.worddata.hline;
		fout << "\n每行文字个数上限： " << scr.worddata.row;
		fout << "\n每段首空格： " << scr.worddata.phblank;
		fout << "\n段间行数： " << scr.worddata.eline;
		fout << "\n//模板";
		fout << "\n动画模式： " << scr.boarddata.animatemode;
		fout << "\n模板类型： " << scr.boarddata.patternmode;
		fout << "\n//输出";
		fout << "\n文字延迟毫秒数： " << scr.outdata.worddy;
		fout << "\n动画延迟毫秒数： " << scr.outdata.patterndy;

		fout << "\n\n//Save类";
		for (int i = 1; i < 21; i++)
		{
			if (i < 10)
				fout << "\nsave   ";
			else 
				fout << "\nsave ";
			fout << i << ' ' << save.listdata[i].pagesave << ' ' << save.listdata[i].parasave;
		}
		fout.close();
	}
	void dataread(Screen& scr, Save& save)
	{
		fin.open("data.txt");
		char a[23];
		fin >> a >> a;
		fin >> a >> scr.wide;
		fin >> a >> scr.high;
		fin >> a;
		fin >> a >> scr.worddata.hline;
		fin >> a >> scr.worddata.row;
		fin >> a >> scr.worddata.phblank;
		fin >> a >> scr.worddata.eline;
		fin >> a;
		fin >> a >> scr.boarddata.animatemode;
		fin >> a >> scr.boarddata.patternmode;
		fin >> a;
		fin >> a >> scr.outdata.worddy;
		fin >> a >> scr.outdata.patterndy;
		fin >> a;
		for (int i = 1; i < 21; i++)
				fin >> a>>a>> save.listdata[i].pagesave>> save.listdata[i].parasave;
		fin.close();
	}

private:
	ifstream fin;
	ofstream fout;
	
};

