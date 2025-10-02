#include"smpSPACE.h"

constexpr int ASTR_SIZE = 100;

namespace smpStr {

	int cpy(char* destination, const char* sourse) {
		if (!destination || !sourse) return pNullSign;
		while (*destination++ = *sourse++);
		return rightSign;
	}
	int cmp(const char* positive, const char* negative) {
		if (!positive || !negative) return pNullSign;
		while (*positive++ == *negative++)
			if (!*positive && !*negative) return 0; //二者都等于0,结束为止都相等,返回0
		if (*positive > *negative) return 1; //左大,返回1
		return -1;
	}
	int cat(char* destination, const char* sourse) {
		if (!destination || !sourse) return pNullSign;
		while (*destination) destination++;
		while (*destination++ = *sourse++);
		return rightSign;
	}
	int len(const char* sourse) {
		if (!sourse) return pNullSign;
		int i = 0;
		while (*sourse++)	i++;
		return i;
	}
	int cpyNewR(const char*& destination, const char* sourse)
	{
		return getNewR(destination, sourse);
	}
	int cpyNewR(char*& destination, const char* sourse) {
		return getNewR(destination, sourse);
	}
	char* cpyNew(const char* sourse) {
		return getNew(sourse);
	}
	int getNewR(const char*& destination, const char* sourse) {
		if (!sourse) return pNullSign;
		char* str = new char[len(sourse) + 1];
		cpy(str, sourse);
		destination = str;
		return rightSign;
	}
	int getNewR(char*& destination, const char* sourse) {
		if (!sourse) return pNullSign;
		char* str = new char[len(sourse) + 1];
		cpy(str, sourse);
		destination = str;
		return rightSign;
	}
	char* getNew(const char* sourse) {
		if (!sourse) return 0;
		char* str = new char[len(sourse) + 1];
		cpy(str, sourse);
		return str;
	}
	//返回第i字节开始相同,sourse是长串,i字节是从1开始的，与0区分
	int search(const char* sourse, const char* smaller)
	{
		int lenb = (int)strlen(smaller);
		int minus = (int)strlen(sourse) - lenb;
		for (int i = 0; i <= minus; i++) {
			int same = 1;
			for (int j = 0; j < lenb; j++)
				if (sourse[i + j] != smaller[j]) {
					same = 0;
					break;
				}
			if (same)	return i + 1;
			if (int(sourse[i]) < 0) i++;
		}
		return 0;
	}


	void repairTxt(char* str) {
		int len1 = len(str);
		if (cmp(str + len1 - 4, ".txt"))
			smpAstr(str).add(".txt").getCpy(str);
	}




}

using namespace smpStr;


smpAstr::smpAstr() {
	nowSize = ASTR_SIZE;
	sourse = new char[nowSize] {};
	set0();
}
smpAstr::~smpAstr() {
	delete[] sourse;
}
//源
smpAstr& smpAstr::set0() {
	sub = beg = sourse + nowSize / 10;
	*beg = 0;
	return *this;
}


int smpAstr::getLen()const {
	return int(sub - beg);
}
void smpAstr::getCpy(char* str)const {
	cpy(str, beg);
}
const char* smpAstr::getBuffer()const {
	return beg;
}
void smpAstr::edge(int len = 1) {
	if (sub + len >= sourse + nowSize) {
		long long st = beg - sourse;
		long long ed = sub - sourse;
		char* reg = new char[nowSize * 2] {};
		cpy(reg, sourse);
		delete sourse;
		sourse = reg;
		beg = sourse + st;
		sub = sourse + ed;
	}
}
void smpAstr::disedge(int len = 1) {
	if (beg - len < sourse) {
		long long st = beg - sourse + nowSize;
		long long ed = sub - sourse + nowSize;
		char* reg = new char[nowSize * 2] {};
		cpy(reg + nowSize, sourse);
		delete sourse;
		sourse = reg;
		beg = sourse + st;
		sub = sourse + ed;
	}
}

smpAstr& smpAstr::add(char c, int num) {
	edge(num);
	for (int i = 0; i < num; i++)
		*sub++ = c;
	*sub = 0;
	return *this;
}
smpAstr& smpAstr::add(const char c[], int times) {
	int len = smpStr::len(c);
	edge(times * len);
	for (int i = 0, sum = len * times; i < sum; i++)
		*sub++ = c[i % len];
	*sub = 0;
	return *this;
}


smpAstr& smpAstr::addNum(const char c[], int singleTimes) {
	edge(singleTimes);
	int len = smpStr::len(c);
	for (int i = 0; i < singleTimes; i++)
		*sub++ = c[i % len];
	*sub = 0;
	return *this;
}
smpAstr& smpAstr::add(int number, int radix, int num) {
	int neg = (number < 0) ? number *= -1 : 0;
	for (int i = 0; i < num; i++) {
		if (neg) *sub++ = '-';
		assistAdd(number, radix);
	}
	*sub = 0;
	return *this;
}
smpAstr& smpAstr::add(long long number, int radix, int num) {
	long long neg = (number < 0) ? number *= -1 : 0;
	for (int i = 0; i < num; i++) {
		if (neg) *sub++ = '-';
		assistAdd(number, radix);
	}
	*sub = 0;
	return *this;
}
smpAstr& smpAstr::add(double number, int smallDigit, int num) {
	int neg = (number < 0) ? number *= -1, 1 : 0;
	for (int i = 0; i < num; i++) {
		if (neg) *sub++ = '-';
		add(long long(number), 10);
		double sml = number - (long long)number;
		for (int i = 0; i < smallDigit; i++)
			sml *= 10;
		if (sml) {
			*sub++ = '.';
			add(int(sml), 10);
		}
	}
	return *this;
}

smpAstr& smpAstr::reduce(int posnum) {
	if (posnum > 0)	*(sub -= posnum) = 0;
	return *this;
}

smpAstr& smpAstr::disadd(char c, int num) {
	disedge(num);
	for (int i = 0; i < num; i++)
		*--beg = c;
	return *this;
}
smpAstr& smpAstr::disadd(const char c[], int times) {
	int len = smpStr::len(c);
	disedge(len * times);
	for (int i = len * times - 1; i >= 0; i--)
		*--beg = c[i % len];
	return *this;
}


smpAstr& smpAstr::disaddSingleNum(const char c[], int singleTimes) {
	disedge(singleTimes);
	int len = smpStr::len(c);
	for (int i = singleTimes - 1; i >= 0; i--)
		*--beg = c[i % len];
	return *this;
}
smpAstr& smpAstr::disadd(int number, int radix, int num) {
	int neg = (number < 0) ? number *= -1 : 0;
	for (int i = 0; i < num; i++) {
		int numc = number;
		while (numc) {
			*--beg = "0123456789abcdef"[numc % radix];
			numc /= radix;
		}
		if (neg) *--beg = '-';
	}
	return *this;
}
smpAstr& smpAstr::disadd(long long number, int radix, int num) {
	long long neg = (number < 0) ? number *= -1 : 0;
	for (int i = 0; i < num; i++) {
		long long numc = number;
		while (numc) {
			*--beg = "0123456789abcdef"[numc % radix];
			numc /= radix;
		}
		if (neg) *--beg = '-';
	}
	return *this;
}
smpAstr& smpAstr::disadd(double number, int smallDigit, int num) {
	int neg = (number < 0) ? number *= -1, 1 : 0;
	for (int i = 0; i < num; i++) {
		double sml = number - (long long)number;
		for (int i = 0; i < smallDigit; i++)
			sml *= 10;
		if (sml) {
			disadd(long long(sml), 10);
			*--beg = '.';
		}
		disadd(int(number), 10);
		if (neg) *--beg = '-';
	}
	return *this;
}
smpAstr& smpAstr::disreduce(int posnum) {
	if (posnum > 0)	 beg += posnum;
	return *this;
}


//一层依赖

char* smpAstr::getNewCpy()const {
	char* str = new char[sub - beg + 1] {};
	getCpy(str);
	return str;
}
void smpAstr::getNewCpyR(const char*& str)const {
	str = getNewCpy();
}
void smpAstr::getNewCpyR(char*& str)const {
	str = getNewCpy();
}
//这里的const char在实参为char时失效

smpAstr& smpAstr::addbl(int num) {
	return add(' ', num);
}
smpAstr& smpAstr::addln(int num) {
	return add('\n', num);
}
smpAstr& smpAstr::disbl(int num) {
	return disadd(32, num);
}
smpAstr& smpAstr::disln(int num) {
	return disadd(10, num);
}


//二层依赖

smpAstr& smpAstr::addBLtoLen(int len) {
	addbl(len - getLen());
	return *this;
}

smpAstr& operator+ (smpAstr& smp, const smpAstr& str) {
	smp.add(str);
	return smp;
}

std::istream& operator>>(std::istream& in, dchar& c) {
	c[0] = in.get();
	if (c[0] < 0) {
		c[1] = in.get();

		//smpError::jdgIF(c[1] > 0, "dchar读取失败!");
	}

	return in;
}

