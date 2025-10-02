#pragma once
#include <iostream>
#include <sstream>
#include"smpMath.h"
//#include"smpSPACE.h"

typedef int (*qsortType)(const void*, const void*);
typedef const char* cstr;

namespace smpStr {

	constexpr int pNullSign = -2;
	constexpr int rightSign = 1;
	int len(const char* sourse);
	int cpy(char* destination, const char* sourse);
	int cat(char* destination, const char* sourse);
	int cmp(const char* fir, const char* sec);
	int cpyNewR(const char*& destination, const char* sourse);
	int cpyNewR(char*& destination, const char* sourse);
	char* cpyNew(const char* sourse);
	int getNewR(const char*& destination, const char* sourse);
	int getNewR(char*& destination, const char* sourse);
	char* getNew(const char* sourse);
	int search(const char* sourse, const char* aim); //返回成功sub+1（避免与失败冲突）

	void repairTxt(char*);

	template<typename t>
	t** getNewpp(int long1, int long2) {
		t** pp = new t * [long1];
		for (int i = 0; i < long1; i++)
			pp[i] = new t[long2]{};
		return pp;
	}
	template<typename t>
	void dltpp(t** pp, int long1) {
		for (int i = 0; i < long1; i++)
			delete[] pp[i];
		delete[] pp;
	}

}

//simple_add_string
class smpAstr
{
public:
	smpAstr();
	template<class t>
	smpAstr(const t& str);
	~smpAstr();

	//源
	smpAstr& set0();

	int getLen()const;
	void getCpy(char* str)const;
	const char* getBuffer()const;

	smpAstr& add(char c, int num = 1);
	smpAstr& add(const char c[], int times = 1);
	smpAstr& addNum(const char c[], int singleTimes = 1);
	smpAstr& add(int number, int radix = 10, int num = 1);
	smpAstr& add(long long number, int radix = 10, int num = 1);
	smpAstr& add(double number, int smallDigit = 1, int num = 1);
	smpAstr& reduce(int posnum);

	smpAstr& disadd(char c, int num = 1);
	smpAstr& disadd(const char c[], int times = 1);
	smpAstr& disaddSingleNum(const char c[], int singleTimes = 1);
	smpAstr& disadd(int number, int radix = 10, int num = 1);
	smpAstr& disadd(long long number, int radix = 10, int num = 1);
	smpAstr& disadd(double number, int smallDigit = 1, int num = 1);
	smpAstr& disreduce(int posnum);


	//一层依赖
	template<class t>
	smpAstr& resetBuffer(const t& str);
	char* getNewCpy()const;
	void getNewCpyR(const char*& str)const;
	void getNewCpyR(char*& str)const;
	//这里的const char在实参为char时失效

	smpAstr& addbl(int num);
	smpAstr& addln(int num);
	template<class t>
	smpAstr& addLeftInBlank(const t& str, int totalLen);
	template<class t>
	smpAstr& addRightInBlank(const t& str, int totalLen);
	template<class t>
	smpAstr& addMidinBlank(const t& str, int totalLen, bool isBlankLeftMore = 0);
	template<class t>
	smpAstr& addMidinBlank_addBlock(const t& str, int totalLen, bool isBlankLeftMore = 0);
	template<class t>
	smpAstr& addinBlank_setLeft(const t& str, int totalLen, int left);
	template<class t>
	smpAstr& addinBlank_setRight(const t& str, int totalLen, int right);

	template<class t>
	smpAstr& addRightin0(const t& str, int totalLen);

	smpAstr& disbl(int num);
	smpAstr& disln(int num);
	template<class t>
	smpAstr& disLeftInBlank(const t& str, int totalLen);
	template<class t>
	smpAstr& disRightInBlank(const t& str, int totalLen);

	//二层依赖
	smpAstr& addBLtoLen(int len);

	template<typename t>
	smpAstr& operator= (const t& str) {
		resetbuffer(str);
		return *this;
	}

	smpAstr& operator-(int num) {
		sub -= num;
		*sub = 0;
		return *this;
	}

	bool operator==(const smpAstr& str)const {
		return !smpStr::cmp(beg, str.beg);
	}

	char operator[](int sub)const {
		return beg[sub];
	}

	operator cstr () const {
		return beg;
	}


private:
	char* sourse;
	char* beg;
	char* sub;
	int nowSize;

	//源
	template<class type>
	void assistAdd(type number, int radix);
	template<class type>
	void assistDis(type number, int radix);
	void edge(int len);
	void disedge(int len);
};

template<class t>
smpAstr::smpAstr(const t& str) :smpAstr() {
	add(str);
}
template<class t>
smpAstr& smpAstr::resetBuffer(const t& str) {
	set0().add(str);
	return *this;
}

template<class t>
smpAstr& smpAstr::addLeftInBlank(const t& str, int totalLen) {
	smpAstr smp(str);
	add(str);
	addbl(totalLen - smp.getLen());
	return *this;
}
template<class t>
smpAstr& smpAstr::addRightInBlank(const t& str, int totalLen) {
	smpAstr smp(str);
	//jdgIF(totalLen < smp.getLen(), "字符串过长");
	addbl(totalLen - smp.getLen());
	add(str);
	return *this;
}
template<class t>
smpAstr& smpAstr::addMidinBlank(const t& str, int totalLen, bool isBlankLeftMore) {
	smpAstr smp(str);
	int lens = (totalLen - smp.getLen() + isBlankLeftMore) / 2;
	addbl(lens);
	add(str);
	addbl(totalLen - smp.getLen() - lens);
	return *this;
}
template<class t>
smpAstr& smpAstr::addMidinBlank_addBlock(const t& str, int totalLen, bool isBlankLeftMore) {
	smpAstr smp(str);
	int lens = (totalLen - smp.getLen() + isBlankLeftMore) / 2;
	addbl(lens - 3);
	add("■ ");
	add(str);
	addbl(totalLen - smp.getLen() - lens);
	return *this;
}
template<class t>
smpAstr& smpAstr::addinBlank_setLeft(const t& str, int totalLen, int left) {
	addbl(left);
	add(str);
	smpAstr smp(str);
	addbl(totalLen - smp.getLen() - left);
	return *this;
}
template<class t>
smpAstr& smpAstr::addinBlank_setRight(const t& str, int totalLen, int right) {
	smpAstr smp(str);
	addbl(totalLen - smp.getLen() - right);
	add(str);
	addbl(right);
	return *this;
}

template<class t>
smpAstr& smpAstr::addRightin0(const t& str, int totalLen) {
	smpAstr smp(str);
	add('0', totalLen - smp.getLen());
	add(str);
	return *this;
}

template<class t>
smpAstr& smpAstr::disLeftInBlank(const t& str, int totalLen) {
	smpAstr smp(str);
	disbl(totalLen - smp.getLen());
	disadd(str);
	return *this;
}
template<class t>
smpAstr& smpAstr::disRightInBlank(const t& str, int totalLen) {
	smpAstr smp(str);
	disadd(str);
	disbl(totalLen - smp.getLen());
	return *this;
}

template<class type>
void smpAstr::assistAdd(type number, int radix) {
	edge();
	if (number / radix != 0)
		assistAdd(number / radix, radix);
	*sub++ = "0123456789abcdef"[number % radix];
}
template<class type>
void smpAstr::assistDis(type number, int radix) {
	disedge();
	*--beg = "0123456789abcdef"[number % radix];
	if (number / radix != 0)
		assistDis(number / radix, radix);
}

template<typename t>
smpAstr& operator+ (smpAstr& smp, const t& str) {
	smp.add(str);
	return smp;
}
template<typename t>
smpAstr& operator+ (const t& str, smpAstr& smp) {
	smp.disadd(str);
	return smp;
}


class dchar {
public:
	template <class cc>
	dchar(cc dc) {
		*this = dc;
	}
	dchar(char c1, char c2) {
		c[0] = c1;
		c[1] = c2;
	}
	dchar() {
		*this = '\0';
	}

	char& operator[] (int sub) {
		return c[sub];
	}

	dchar& operator=(dchar& dc) {
		c[0] = dc[0];
		c[1] = dc[1];
		return *this;
	}
	dchar& operator=(const char* cc) {
		c[0] = cc[0];
		c[1] = cc[1];
		return *this;
	}
	dchar& operator=(const char sc) {
		c[0] = sc;
		c[1] = 0;
		return *this;
	}

	bool operator==(dchar& dc)const {
		if (c[0] == dc[0] && c[1] == dc[1]) return 1;
		return 0;
	}
	bool operator==(const char* cc)const {
		if (c[0] == cc[0] && c[1] == cc[1]) return 1;
		return 0;
	}
	bool operator==(char c)const {
		if (this->c[0] == c && !this->c[1]) return 1;
		return 0;
	}

private:
	char c[2];
};
std::istream& operator>>(std::istream& in, dchar& c);





