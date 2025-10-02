#pragma once
#include<Windows.h>

class Color
{
public:
	//不同页面只能用相等了
	Color(const int a, const int b) { nowword = a; nowbg = b; }
	Color() { nowword = 2; nowbg = 1; }


	void set(const int word, const int back)
	{		
			if (word)
			nowword = word;
			if (back)
			nowbg = back;
			paintword();
	}
	void setword(const int word)
	{
			if(word)
			nowword = word;
			paintword();
	}
	void setback(const int back)
	{
			if (back)
				nowbg = back;
			paintword();
	}
	void setblank(const int word)
	{
			if (word)
				nowword = word;
			paintblank();
	}
	void setall(const int word, const int back)
	{
		//先背景，再文字
		nowword = word;
		nowbg = back;
		char a[] = "color 00";

		if (back < 11)
			a[6] = '0' + nowbg - 1;
		else
			switch (back)
			{
			case 11:a[6] = 'a'; break;
			case 12:a[6] = 'b'; break;
			case 13:a[6] = 'c'; break;
			case 14:a[6] = 'd'; break;
			case 15:a[6] = 'e'; break;
			case 16:a[6] = 'f'; break;
			default:
				break;
			}
		if (word < 11)
			a[7] = '0' + nowword - 1;
		else
			switch (word)
			{
			case 11:a[7] = 'a'; break;
			case 12:a[7] = 'b'; break;
			case 13:a[7] = 'c'; break;
			case 14:a[7] = 'd'; break;
			case 15:a[7] = 'e'; break;
			case 16:a[7] = 'f'; break;
			default:
				break;
			}
		system(a);
	}


	static int nowword, nowbg;
private:
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	static int blankturn;
	

	void paintword()
	{
		SetConsoleTextAttribute(hCon, (nowword - 1) + (nowbg - 1) * 16);
	}
	void paintblank()
	{
		SetConsoleTextAttribute(hCon, (nowword - 1) * 16);
	}
};
