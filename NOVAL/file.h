#pragma once
#include<fstream>
#include"page.h"
#include"screen.h"

class File
{
public:
	//ҳ����#��������$
	File& novelread(Pagelist& list,const char a[]);
	File& novelwrite(Pagelist& list, const char a[]);

	void datawrite(Screen& scr,Save& save)
	{
		fout.open("data.txt");
		fout << "//Screen��";
		fout << "\n//������ֵ";
		fout << "\n��Ļ�� " << scr.wide;
		fout << "\n��Ļ�ߣ� " << scr.high;
		fout << "\n//����";
		fout << "\n����λ�ã� " << scr.worddata.hline;
		fout << "\nÿ�����ָ������ޣ� " << scr.worddata.row;
		fout << "\nÿ���׿ո� " << scr.worddata.phblank;
		fout << "\n�μ������� " << scr.worddata.eline;
		fout << "\n//ģ��";
		fout << "\n����ģʽ�� " << scr.boarddata.animatemode;
		fout << "\nģ�����ͣ� " << scr.boarddata.patternmode;
		fout << "\n//���";
		fout << "\n�����ӳٺ������� " << scr.outdata.worddy;
		fout << "\n�����ӳٺ������� " << scr.outdata.patterndy;

		fout << "\n\n//Save��";
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

