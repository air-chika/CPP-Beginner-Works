#pragma once
#include"Windows.h"
#include"WinBase.h"
#include <cstring>
using namespace std;

struct wordd
{
	int hline = 3;//headline
	int phblank = 2;//paragraph headblank
	int eline = 2;//everyline
	int row = 50;//maxrow
};
struct boardd
{
	int patternmode=2;
	int animatemode = 0;
};
struct outd
{
	int worddy = 5;//word_dy
	int patterndy = 20;//pattern_dy
};

class Screen
{
public:

	int wide=106;
	int high=30;
	wordd worddata;
	boardd boarddata;
	outd outdata;

};

struct Listdata
{
	int pagesave=1;
	int parasave=1;
};
class Save
{
public:
	Listdata listdata[21];
};

int colortransform(const char a[]);

char* colortransform(int num, char* a);

int boardtransform(const char a[]);

char* boardtransform(int num, char* a);