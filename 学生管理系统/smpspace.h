#pragma once
#include <iostream>
#include <fstream>
#include<Windows.h>
#include<conio.h>
#include<easyx.h>
using namespace std;

//simple_space

namespace smpStr {

	char* strcpy(char* sDestination, const char* sSourse);
	char* strcat(char* sDestination, const char* sSourse);
	int strlen(const char* sSourse);
	int aHasb(const char* a, const char* b);
	void quicksort(char* a[], int astart, int aend);
	int getDigit(int num);

	template<typename t>
	t** newpp(int long1, int long2);
	template<typename t>
	void dltpp(t** str, int long1);
	//delete pp，其中第二个p指向单个类 
	template<typename t>
	void dltppclass(t** prrClass, int long1);

	namespace pvt {
		int partition(char* a[], int astart, int aend);
	}

}

namespace smpFile {

	//获取文件行数，单行eof不算在内
	int CntFileLine(const char* sFileName);

	//获取文件词数
	int CntFileWord(const char* sFileName);

	//获取文件位数
	long long unsigned int CntFileBit(const char* sFileName);

	//随机打乱文件中的每行
	void RdmFileLine(const char* sFileName, const char* sAimFileName = 0);

	//随机打乱文件中的每句
	void RdmFileWord(const char* sFileName, const char* sAimFileName = 0);

	//对每行进行字符串排序
	void SortFileLine(const char* sFileName, const char* sAimFileName = 0);

	//复制文件
	void CpyFile(const char* sAimFileName, const char* sSourseFileName);

	//令两文件的每行合并，成功返回1，失败返回0
	int MergeFileLine(const char* sFileName1, const char* sFileName2, const char* sAimFileName = 0);

	//令两文件在结尾处合并
	void MergeFileEnd(const char* sFileName1, const char* sFileName2, const char* sAimFileName = 0);

	//文件中每n句转换为一行
	void blanktoline(const char* sFileName, int iMaxWord, const char* sAimFileName = 0);

	//打印文件内容到控制台
	void PrintFile(const char* sFileName, bool isEnter = 1);

	//备份文件
	void BackupFile(const char* sFileName, const char* sFolderName = "backup");

}

namespace smpFio
{

	ifstream& ignorein(ifstream&, char, char* str = 0);
	ifstream& ignorein(ifstream&, char, int& ir);
	ifstream& ignoreln(ifstream&);

	ofstream& autoblankout(ofstream&, const char* cstr);
	ofstream& autoblankout(ofstream&, int i);

}

namespace smpUI {

	void setWinMode(int modeNumber, int  wid, int hei, int hln, int hbl);
	void setWinMode(int modeNumber, int sourseNumber);
	void setWinHBinMid(int modeNumber, const char str[]);
	void useWinMode(int modeNumber);

	void clear();
	void prt(char type, int num);
	void prtLine(int num);
	void prtBlank(int num);
	void prtMidNeedBlank(int length);
	void prtMidNeedBlank(const char str[]);

	void prtlnWithoutHB(const char str[]);
	void prtln(const char str[]);
	void prtln(const char str[], int i);
	void prtln(const char str1[], const char str2[]);

	void midClear(int midLineNum);
	void midprtln(const char str[]);
	void midprtln(const char str[], int i);

	int getMidNeedBlNum(const char str[]);
	int getMidNeedBlNum(int length);

	void prtHeadBlank();

	//遇bc返回0,esc返回-1,自动识别位数
	int getChoice(int maxallowed);

	int scanInt();
	char* scanStr();
	int scanIntAtMid(int len);
	char* scanStrAtMid(int len);



	struct Window
	{
		int iHeight = 0;
		int iWidth = 0;
		int iHeadLine = 0;
		int iHeadBlank = 0;
	};

	extern Window winMode[10];

}

namespace color
{
	enum colorname
	{
		纯黑 = 1, 深黑 = 1, 黑 = 1,
		纯蓝, 深蓝 = 2, 蓝 = 2,
		纯绿, 深绿 = 3, 绿 = 3,
		天蓝 = 4,
		纯红, 深红 = 5, 红 = 5,
		纯紫, 深紫 = 6, 紫 = 6,
		棕黄 = 7,
		淡灰, 默认 = 8,
		深灰 = 9,
		湖蓝 = 10,
		草绿, 鲜绿 = 11,
		冰蓝, 蓝绿 = 12,
		粉红 = 13,
		紫红, 品红 = 14,
		月黄, 亮黄 = 15, 明黄 = 15,
		纯白 = 16
	};

	void set(const int word, const int back);
	void setword(const int word);
	void setback(const int back);
	void setblank(const int word);
	void setall(const int word, const int back);

}

namespace font
{
	void font();
	void setHeight(int num);
	void setMaxScreenHeight(int maxLine);
	void setFontName(const wchar_t*);
}

namespace cursor
{
	void hideCursor();
	void unhideCursor();
}

namespace smpRdm {

	void refresh();

	int intRdm(int min, int max);

}

namespace smpWchar
{
	void wchar();
}

namespace smpTime
{
	char* newWorldTimeStr();
}

//string_create
class smpSCrt
{
public:
	const char* rpt(char c, int num) {
		for (int i = 0; i < num; i++)
			buffer[i] = c;
		buffer[num] = 0;
		return buffer;
	}
	const char* rpt(const char c[], int endSubP1) {
		int len = smpStr::strlen(c);
		for (int i = 0; i < endSubP1; i++)
			buffer[i] = c[i % len];
		buffer[endSubP1] = 0;
		return buffer;
	}
	const char* rptTimes(const char c[], int times) {
		int len = smpStr::strlen(c);
		for (int i = 0; i < len * times; i++)
			buffer[i] = c[i % len];
		buffer[len * times] = 0;
		return buffer;
	}
	const char* blank(int num) {
		return rpt(32, num);
	}
	const char* line(int num) {
		return rpt(10, num);
	}

	//const char* sPrt(const char*, ...);
	const char* strAtEnd(const char str[], int len) {
		int lenm = len - smpStr::strlen(str);
		for (int i = 0; i < lenm; i++)
			buffer[i] = 32;
		for (int i = lenm; i < len; i++)
			buffer[i] = *str++;
		buffer[len] = 0;
		return buffer;
	}

	const char* getBuffer() {
		return buffer;
	}

private:
	char buffer[300]{};
	int sub = 0;  //bufferSub
	void add(char c) {
		buffer[sub++] = c;
	}
	/*void addD(int i) {
		if (i < 0) {
			i *= -1;
		}
		if (i / 10 != 0)
			addD(i / 10);
		add(i % 10 + '0');
	}
	void addF(double db) {
		int I_db = (int)db;
		db -= I_db;
		int Flo = 1000000 * db;
		addD(I_db);
		add('.');
		addD(Flo);
	}
	void addStr(const char* str) {
		while (*str)
			add(*str++);
	}
	void addX(unsigned long long ull, int radix) {
		addX(ull / radix, radix);
		add("0123456789abcdef"[ull % radix]);
	}
	void addP(unsigned long long  num) {
		addX(num, 16);
	}*/

};


//simple_add_string
//下一步是运算符重载
class smpAstr
{
public:
	smpAstr() {
		setZero();
	}

	//源
	smpAstr& setZero() {
		sub = buffer = sourse + 1000;
		*buffer = 0;
		return *this;
	}

	int getLen() {
		return int(sub - buffer);
	}
	void giveCopy(char* str) {
		strcpy_s(str, getLen() + 1, buffer);
	}
	const char* getBuffer() {
		return buffer;
	}
	

	smpAstr& add(char c, int num = 1) {
		for (int i = 0; i < num; i++)
			*sub++ = c;
		*sub = 0;
		return *this;
	}
	smpAstr& add(const char c[], int times = 1) {
		int len = smpStr::strlen(c);
		for (int i = 0, sum = len * times; i < sum; i++)
			*sub++ = c[i % len];
		*sub = 0;
		return *this;
	}
	smpAstr& addSub(const char c[], int len_endSubP1 = 1) {
		int len = smpStr::strlen(c);
		for (int i = 0; i < len_endSubP1; i++)
			*sub++ = c[i % len];
		*sub = 0;
		return *this;
	}
	smpAstr& add(int number, int radix = 10, int num = 1) {
		int neg = (number < 0) ? number *= -1 : 0;
		for (int i = 0; i < num; i++) {
			if (neg) *sub++ = '-';
			assistAdd(number, radix);
		}
		return *this;
	}
	smpAstr& add(long long number, int radix = 10, int num = 1) {
		long long neg = (number < 0) ? number *= -1 : 0;
		for (int i = 0; i < num; i++) {
			if (neg) *sub++ = '-';
			assistAdd(number, radix);
		}
		return *this;
	}
	smpAstr& add(double number, int smallDigit = 1, int num = 1) {
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

	smpAstr& disadd(char c, int num = 1) {
		for (int i = 0; i < num; i++)
			*--buffer = c;
		return *this;
	}
	smpAstr& disadd(const char c[], int times = 1) {
		int len = smpStr::strlen(c);
		for (int i = len * times - 1; i >= 0; i--)
			*--buffer = c[i % len];
		return *this;
	}
	smpAstr& disaddSub(const char c[], int len_endSubP1 = 1) {
		int len = smpStr::strlen(c);
		for (int i = len_endSubP1 - 1; i >= 0; i--)
			*--buffer = c[i % len];
		return *this;
	}
	smpAstr& disadd(int number, int radix = 10, int num = 1) {
		int neg = (number < 0) ? number *= -1 : 0;
		for (int i = 0; i < num; i++) {
			int numc = number;
			while (numc) {
				*--buffer = "0123456789abcdef"[numc % radix];
				numc /= radix;
			}
			if (neg) *--buffer = '-';
		}
		return *this;
	}
	smpAstr& disadd(long long number, int radix = 10, int num = 1) {
		long long neg = (number < 0) ? number *= -1 : 0;
		for (int i = 0; i < num; i++) {
			long long numc = number;
			while (numc) {
				*--buffer = "0123456789abcdef"[numc % radix];
				numc /= radix;
			}
			if (neg) *--buffer = '-';
		}
		return *this;
	}
	smpAstr& disadd(double number, int smallDigit = 1, int num = 1) {
		int neg = (number < 0) ? number *= -1, 1 : 0;
		for (int i = 0; i < num; i++) {
			double sml = number - (long long)number;
			for (int i = 0; i < smallDigit; i++)
				sml *= 10;
			if (sml) {
				disadd(long long(sml), 10);
				*--buffer = '.';
			}
			disadd(int(number), 10);
			if (neg) *--buffer = '-';
		}
		return *this;
	}

	smpAstr& coverBuffer(const char c[]) {
		char* beg = buffer;
		while (*c)
			*beg++ = *c++;
		return *this;
	}


	//一层依赖
	template<class t>
	smpAstr(t str) {
		setZero().add(str);
	}
	smpAstr& setBuffer(const char* str) {
		setZero();
		strcpy_s(buffer, strlen(str) + 1, str);
		return *this;
	}
	char* giveNewCopy() {
		char* str = new char[sub - buffer + 1]{};
		giveCopy(str);
		return str;
	}
	void giveNewCopy(const char*& str) {
		str = giveNewCopy();
	}
	void giveNewCopy(char*& str) {
		str = giveNewCopy();
	}
	//这里的const char在实参为char时失效

	smpAstr& addbl(int num) {
		return add(' ', num);
	}
	smpAstr& addln(int num) {
		return add('\n', num);
	}
	template<class t>
	smpAstr& addLeftInBlank(t str, int totalLen) {
		smpAstr smp(str);
		add(str);
		addbl(totalLen - smp.getLen());
		return *this;
	}
	template<class t>
	smpAstr& addRightInBlank(t str, int totalLen) {
		smpAstr smp(str);
		addbl(totalLen - smp.getLen());
		add(str);
		return *this;
	}
	template<class t>
	smpAstr& addMidinBlank(t str, int totalLen) {
		smpAstr smp(str);
		int lens = (totalLen - smp.getLen()) / 2;
		addbl(lens);
		add(str);
		addbl(totalLen - smp.getLen() - lens);
		return *this;
	}
	template<class t>
	smpAstr& addMidinBlank_setLeft(t str, int totalLen, int left) {
		addbl(left);
		add(str);
		smpAstr smp(str);
		addbl(totalLen - smp.getLen() - left);
		return *this;
	}
	template<class t>
	smpAstr& addMidinBlank_setRight(t str, int totalLen, int right) {
		smpAstr smp(str);
		addbl(totalLen - smp.getLen() - right);
		add(str);
		addbl(right);
		return *this;
	}

	template<class t>
	smpAstr& addRightIn0(t str, int totalLen) {
		smpAstr smp(str);
		add('0',totalLen - smp.getLen());
		add(str);
		return *this;
	}

	smpAstr& disbl(int num) {
		return disadd(32, num);
	}
	smpAstr& disln(int num) {
		return disadd(10, num);
	}
	template<class t>
	smpAstr& disLeftInBlank(t str, int totalLen) {
		smpAstr smp(str);
		disbl(totalLen - smp.getLen());
		disadd(str);
		return *this;
	}
	template<class t>
	smpAstr& disRightInBlank(t str, int totalLen) {
		smpAstr smp(str);
		disadd(str);
		disbl(totalLen - smp.getLen());
		return *this;
	}

	//二层依赖
	smpAstr& setBuffer(smpAstr& smp) {
		setZero();
		setBuffer(smp.buffer);
		return *this;
	}
	

private:
	char sourse[2001]{};
	char* buffer;
	char* sub;
	//int sub=0;

	//源
	template<class type>
	void assistAdd(type number, int radix) {
		if (number / radix != 0)
			assistAdd(number / radix, radix);
		*sub++ = "0123456789abcdef"[number % radix];
	}
	template<class type>
	void assistDis(type number, int radix) {
		*--buffer = "0123456789abcdef"[number % radix];
		if (number / radix != 0)
			assistDis(number / radix, radix);
	}
};