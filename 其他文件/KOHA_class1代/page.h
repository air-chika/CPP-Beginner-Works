#pragma once
#include"str.h"
#include"color.h"
#include"pattern.h"
//list存储内容，与屏幕参数无关

class Para
{
public:
	Para(int i);
	Para();
	~Para();
	char* str;
	int rank = 0;
	Para* next = 0;
	Para* pre = 0;
};

class Page
{
public:
	Page();
	~Page();
	Para* add();
	void Delete();
	Page* next = 0;
	Page* pre = 0;

	Para* parahead ;
	int rank = 0;
private:
	Para * paraend,* p = 0;
};

//需要进行board设置，背景设置
class Pagelist
{
public:
	Pagelist()
	{
		pagehead = new Page();
		end = pagehead;
	}

	~Pagelist()
	{
		while (pagehead)
		{
			p = pagehead;
			pagehead = pagehead->next;
			delete p;
		}
	}

	Page* add();
	Page* pagehead;

	
	char name[100]{};

	int mainwordcolor=0,mainwordbackcolor=0,mainbackcolor=0;
	int boardmode=0;
	int boardcolor=0;

	int number=0;

private:
	Page* end, * p = 0;
};
