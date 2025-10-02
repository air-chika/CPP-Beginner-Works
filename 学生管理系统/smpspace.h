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
	//delete pp�����еڶ���pָ�򵥸��� 
	template<typename t>
	void dltppclass(t** prrClass, int long1);

	namespace pvt {
		int partition(char* a[], int astart, int aend);
	}

}

namespace smpFile {

	//��ȡ�ļ�����������eof��������
	int CntFileLine(const char* sFileName);

	//��ȡ�ļ�����
	int CntFileWord(const char* sFileName);

	//��ȡ�ļ�λ��
	long long unsigned int CntFileBit(const char* sFileName);

	//��������ļ��е�ÿ��
	void RdmFileLine(const char* sFileName, const char* sAimFileName = 0);

	//��������ļ��е�ÿ��
	void RdmFileWord(const char* sFileName, const char* sAimFileName = 0);

	//��ÿ�н����ַ�������
	void SortFileLine(const char* sFileName, const char* sAimFileName = 0);

	//�����ļ�
	void CpyFile(const char* sAimFileName, const char* sSourseFileName);

	//�����ļ���ÿ�кϲ����ɹ�����1��ʧ�ܷ���0
	int MergeFileLine(const char* sFileName1, const char* sFileName2, const char* sAimFileName = 0);

	//�����ļ��ڽ�β���ϲ�
	void MergeFileEnd(const char* sFileName1, const char* sFileName2, const char* sAimFileName = 0);

	//�ļ���ÿn��ת��Ϊһ��
	void blanktoline(const char* sFileName, int iMaxWord, const char* sAimFileName = 0);

	//��ӡ�ļ����ݵ�����̨
	void PrintFile(const char* sFileName, bool isEnter = 1);

	//�����ļ�
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

	//��bc����0,esc����-1,�Զ�ʶ��λ��
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
		���� = 1, ��� = 1, �� = 1,
		����, ���� = 2, �� = 2,
		����, ���� = 3, �� = 3,
		���� = 4,
		����, ��� = 5, �� = 5,
		����, ���� = 6, �� = 6,
		�ػ� = 7,
		����, Ĭ�� = 8,
		��� = 9,
		���� = 10,
		����, ���� = 11,
		����, ���� = 12,
		�ۺ� = 13,
		�Ϻ�, Ʒ�� = 14,
		�»�, ���� = 15, ���� = 15,
		���� = 16
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
//��һ�������������
class smpAstr
{
public:
	smpAstr() {
		setZero();
	}

	//Դ
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


	//һ������
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
	//�����const char��ʵ��ΪcharʱʧЧ

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

	//��������
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

	//Դ
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