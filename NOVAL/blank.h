#pragma once
#include"str.h"

class Blank
{
public:
	Blank();
	Blank& operator + (int full);
	Blank& operator - (int half);
	Blank& operator += (int fullstar);
	Blank& operator -= (int halfstar);
	Blank& operator * (int blank);
	Blank& operator / (int endl);
	Blank& operator % (int blank1);
	//配合指针计数使用？检测末尾块
	Blank& repeat(const char* a)
	{
		int x = s.len(str);
		int y = s.len(a);
		int c = x / y;
		int v = x % y;
		for (int i = 0;i<c;i++)
			s.copy(&str[i*y], a,y);
		s.copy(&str[c*y], a, v);
		return *this;
	}
	Blank& repeat(const char* a,int x)
	{
		int y = s.len(a);
		int c = x / y;
		int v = x % y;
		for (int i = 0; i < c; i++)
			s.copy(&str[i * y], a,y);
		s.copy(&str[c * y], a, v);
		return *this;
	}
	Blank& gp(char* a);
	Blank& out();

private:
	char* str ; 
	Str s;
	void in(int num, const char* form);
};

//class Blank_out{};