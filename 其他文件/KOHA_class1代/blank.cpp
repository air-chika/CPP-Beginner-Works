#include"blank.h"

Blank::Blank()
{
	str = 0;
}
Blank& Blank::operator + (int full)
{
	in(full, "��");
	return *this;
}
Blank& Blank::operator - (int half)
{
	in(half, "��");
	return *this;
}
Blank& Blank::operator += (int fullstar)
{
	in(fullstar, "��");
	return *this;
}
Blank& Blank::operator -= (int halfstar)
{
	in(halfstar, "��");
	return *this;
}
Blank& Blank::operator * (int blank)
{
	in(blank, "  ");
	return *this;
}
Blank& Blank::operator / (int endl)
{
	in(endl, "\n");
	return *this;
}
Blank& Blank::operator % (int blank1)
{
	in(blank1, " ");
	return *this;
}
Blank& Blank::gp(char* a)
{
	str = a;
	return *this;
}

Blank& Blank::out()
{
	cout << str;
	return *this;
}
void Blank::in(int num,const char* form)
{
	for (int i = 0; i < num; i++)
	{
		s.cate(str, form);
	}
}