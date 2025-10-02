#include"smpspace.h"

namespace smpStr {

	using namespace pvt;

	char* strcpy(char* sDestination, const char* sSourse)
	{
		strcpy_s(sDestination, strlen(sSourse) + 1, sSourse);
		return sDestination;
	}

	char* strcat(char* sDestination, const char* sSourse)
	{
		strcat_s(sDestination, strlen(sDestination) + strlen(sSourse) + 1, sSourse);
		return sDestination;
	}

	int strlen(const char* sSourse)
	{
		return int(std::strlen(sSourse));
	}

	int aHasb(const char* a, const char* b)
	{
		int lenb = (int)strlen(b);
		int minus = (int)strlen(a) - lenb;
		for (int i = 0; i <= minus; i++) {
			int same = 1;
			for (int j = 0; j < lenb; j++)
				if (a[i + j] != b[j]) {
					same = 0;
					break;
				}
			if (same)	return 1;
			if (int(a[i]) < 0) i++;
		}
		return 0;
	}

	void quicksort(char* a[], int astart, int aend) {
		if (astart < aend) {
			int j = partition(a, astart, aend);
			quicksort(a, astart, j - 1);
			quicksort(a, j + 1, aend);
		}
	}

	int getDigit(int num) {
		if (num == 0) return 0;
		int dig = 1;
		while (num /= 10)
			dig++;
		return dig;
	}

	template<typename t>
	t** newpp(int long1, int long2)
	{
		t** str = new t * [long1];
		for (int i = 0; i < long1; i++)
			str[i] = new t[long2]{};
		return str;
	}

	template<typename t>
	void dltpp(t** str, int long1)
	{
		for (int i = 0; i < long1; i++)
			delete[] str[i];
		delete[] str;
	}

	template<typename t>
	void dltppclass(t** prrClass, int long1)
	{
		for (int i = 0; i < long1; i++)
			delete prrClass[i];
		delete[] prrClass;
	}

	namespace pvt {

		int partition(char* a[], int astart, int aend) {
			int i = astart;
			int j = aend + 1;
			char* k = a[astart];
			while (i < j) {
				i++;
				while (strcmp(a[i], k) < 1 && i < aend)
					i++;
				j--;
				while (strcmp(a[j], k) > 0)
					j--;
				if (i < j)
					swap(a[i], a[j]);
			}
			swap(a[astart], a[j]);
			return j;
		}

	}

}

namespace smpFile {

	//获取文件行数，单行eof不算在内
	int CntFileLine(const char* sFileName)
	{
		ifstream fin(sFileName);
		if (!fin.is_open()) return 0;
		char cstr[100];
		int iMaxLine;
		for (iMaxLine = 0; fin.getline(cstr, 100); iMaxLine++);
		fin.close();
		return iMaxLine;
	}

	//获取文件词数
	int CntFileWord(const char* sFileName)
	{
		ifstream fin(sFileName);
		if (!fin.is_open()) return 0;
		char cstr[100];
		int iMaxWord;
		for (iMaxWord = 0; fin >> cstr; iMaxWord++);
		fin.close();
		return iMaxWord;
	}

	//获取文件位数
	long long unsigned int CntFileBit(const char* sFileName)
	{
		ifstream fin(sFileName, ios::ate);
		if (!fin.is_open()) return 0;
		long long unsigned int iMax = fin.tellg();
		fin.close();
		return iMax;
	}

	//随机打乱文件中的每行
	void RdmFileLine(const char* sFileName, const char* sAimFileName)
	{
		if (!sAimFileName) sAimFileName = sFileName;
		int iMaxLine = smpFile::CntFileLine(sFileName);
		string* str = new string[iMaxLine]{};
		char cstr[100];

		fstream fio(sFileName, 1);
		for (int i = 0; fio.getline(cstr, 100); i++)
			str[i] = cstr;
		fio.close();

		srand(unsigned int(time(0)));
		for (int j = 0; j < 3; j++)
			for (int i = 0; i < iMaxLine; i++)
				swap(str[i], str[rand() % iMaxLine]);

		fio.open(sAimFileName, 2);
		for (int i = 0; i < iMaxLine; i++)
			fio << str[i] << endl;
		fio.close();
	}

	//随机打乱文件中的每句
	void RdmFileWord(const char* sFileName, const char* sAimFileName)
	{
		if (!sAimFileName) sAimFileName = sFileName;
		int iMaxWord = CntFileWord(sFileName);
		string* str = new string[iMaxWord]{};

		fstream fio(sFileName, 1);
		for (int i = 0; fio >> str[i]; i++);
		fio.close();

		srand(unsigned int(time(0)));
		for (int j = 0; j < 3; j++)
			for (int i = 0; i < iMaxWord; i++)
				swap(str[i], str[rand() % iMaxWord]);

		fio.open(sAimFileName, 2);
		for (int i = 0; i < iMaxWord; i++)
			fio << str[i] << ' ';
		fio.close();
	}

	//对每行进行字符串排序
	void SortFileLine(const char* sFileName, const char* sAimFileName)
	{
		if (!sAimFileName) sAimFileName = sFileName;
		int iMaxLine = smpFile::CntFileLine(sFileName);
		char** str = smpStr::newpp<char>(iMaxLine, 100);
		char cstr[100]{};

		fstream fio(sFileName, 1);
		for (int i = 0; fio.getline(cstr, 100); i++)
			smpStr::strcpy(str[i], cstr);
		fio.close();

		smpStr::quicksort(str, 0, iMaxLine - 1);

		fio.open(sAimFileName, 2);
		for (int i = 0; i < iMaxLine; i++)
			fio << str[i] << endl;

		smpStr::dltpp(str, iMaxLine);
		fio.close();
	}

	//复制文件
	void CpyFile(const char* sAimFileName, const char* sSourseFileName)
	{
		if (sSourseFileName == sAimFileName) return;
		char cstr[200];
		ofstream fout(sAimFileName);
		ifstream fin(sSourseFileName);
		while (fin.getline(cstr, 200)) {
			fout << cstr;
			if (fin.peek() != -1)fout << endl;
		}
		fin.close();
		fout.close();
	}

	//令两文件的每行合并，成功返回1，失败返回0
	int MergeFileLine(const char* sFileName1, const char* sFileName2, const char* sAimFileName)
	{
		char sFiletmp[20] = "reg.txt";
		char sreg[200]{};
		int iMaxLine1 = smpFile::CntFileLine(sFileName1);
		int iMaxLine2 = smpFile::CntFileLine(sFileName2);
		int max = iMaxLine1 > iMaxLine2 ? iMaxLine1 : iMaxLine2;
		ifstream fio1(sFileName1);
		ifstream fio2(sFileName2);
		ofstream fio3(sFiletmp);
		for (int i = 0; i < max; i++) {
			if (fio1.getline(sreg, 200))
				fio3 << sreg << ' ';
			if (fio2.getline(sreg, 200))
				fio3 << sreg << ' ';
			fio3 << endl;
		}
		fio1.close();
		fio2.close();
		fio3.close();
		if (sAimFileName) {
			if (!rename(sFiletmp, sAimFileName))
				return 1;
			return 0;
		}
		remove(sFileName1);
		//remove(sFileName2);
		if (!rename(sFiletmp, sFileName1))
			return 1;
		return 0;
	}

	//令两文件在结尾处合并
	void MergeFileEnd(const char* sFileName1, const char* sFileName2, const char* sAimFileName)
	{
		if (!sAimFileName) {
			CpyFile(sAimFileName, sFileName1);
			sFileName1 = sAimFileName;
		}
		char sreg[200]{};
		fstream fio1(sFileName1, 3);
		fio1.seekp(-1, 2);
		bool isEnter = fio1.peek() == 10;
		fio1.seekp(0, 2);
		if (!isEnter) fio1 << '\n';
		ifstream fio2(sFileName2);
		while (fio2.getline(sreg, 200))
			fio1 << sreg << '\n';
		fio1.close();
		fio2.close();
	}

	//文件中每n句转换为一行
	void blanktoline(const char* sFileName, int iMaxWord, const char* sAimFileName)
	{
		if (!sAimFileName) {

			char csreg[20] = "不存在.txt";
			ifstream fin(sFileName);
			ofstream fout(csreg);

			char cstr[100]{};
			while (1) {
				for (int i = 0; i < iMaxWord; i++) {
					if (!(fin >> cstr)) {
						fin.close();
						fout.close();
						remove(sFileName);
						rename(csreg, sFileName);
						return;
					}
					fout << cstr << ' ';
				}
				fout << endl;
			}
		}
		else {
			ifstream fin(sFileName);
			ofstream fout(sAimFileName);
			char cstr[100]{};
			while (1) {
				for (int i = 0; i < iMaxWord; i++) {
					if (!(fin >> cstr)) {
						fin.close();
						fout.close();
						return;
					}
					fout << cstr << ' ';
				}
				fout << endl;
			}
		}
	}

	//打印文件内容到控制台
	void PrintFile(const char* sFileName, bool isEnter)
	{
		ifstream fin(sFileName);
		if (!fin.is_open()) {
			cout << "文件不存在";
		}

		char cstr[200];
		while (fin.getline(cstr, 200))
			if (isEnter)
				cout << cstr << endl;
			else
				cout << cstr << ' ';
		fin.close();
	}

	//备份文件
	void BackupFile(const char* sFileName, const char* sFolderName)
	{
		char sBackup[100];
		smpStr::strcpy(sBackup, sFolderName);
		smpStr::strcat(sBackup, "\\");

		char* sTime = smpTime::newWorldTimeStr();
		smpStr::strcat(sBackup, sTime);

		int len = smpStr::strlen(sFileName);
		int pos = 0;
		for (int i = 0; i < len; i++)
			if (sFileName[i] == '\\')
				pos = i;

		smpStr::strcat(sBackup, sFileName + pos + 1);
		smpFile::CpyFile(sBackup, sFileName);
		delete[] sTime;
	}

}

namespace smpFio {

	//源
	ifstream& ignorein(ifstream& fin, char c, char* str)
	{
		char cs[100];
		fin.getline(cs, 100, c);
		if (str) fin >> str;
		return fin;
	}
	ifstream& ignorein(ifstream& fin, char c, int& ir)
	{
		char cs[100];
		fin.getline(cs, 100, c);
		fin >> ir;
		return fin;
	}
	//忽略最开始的\n，并消除结尾的\n
	ifstream& ignoreln(ifstream& fin)
	{
		char cs[100];
		fin >> cs;
		fin.getline(cs, 100);
		return fin;
	}

	ofstream& autoblankout(ofstream& fout, const char* cstr)
	{
		fout << cstr << ' ';
		return fout;
	}
	ofstream& autoblankout(ofstream& fout, int i)
	{
		fout << i << ' ';
		return fout;
	}


}

namespace smpUI {

	Window winMode[10];
	int iWinSub = 9;
	void setWinMode(int modeNumber, int  wid, int hei, int hln, int hbl)
	{
		if (wid != -1)	winMode[modeNumber].iWidth = wid;
		if (hei != -1)	winMode[modeNumber].iHeight = hei;
		if (hln != -1)	winMode[modeNumber].iHeadLine = hln;
		if (hbl != -1)	winMode[modeNumber].iHeadBlank = hbl;
	}
	void setWinMode(int modeNumber, int sourseNumber)
	{
		winMode[modeNumber] = winMode[sourseNumber];
	}
	void setWinHBinMid(int modeNumber,const char str[]) {
		winMode[modeNumber].iHeadBlank = getMidNeedBlNum(str);
	}
	void useWinMode(int modeNumber)
	{
		if ((winMode[iWinSub].iWidth != winMode[modeNumber].iWidth) || (winMode[iWinSub].iHeight != winMode[modeNumber].iHeight)) {
			char chCmd[32];
			sprintf_s(chCmd, "mode con cols=%d lines=%d", winMode[modeNumber].iWidth, winMode[modeNumber].iHeight);
			system(chCmd);
		}
		iWinSub = modeNumber;
	}

	smpAstr smp;

	//输出源
	void clear()
	{
		system("cls");
		prtLine(winMode[iWinSub].iHeadLine);
	}
	void prt(char type, int num)
	{
		cout << smp.setZero().add(type, num).getBuffer();
	}
	int getMidNeedBlNum(const char str[])
	{
		return (winMode[iWinSub].iWidth - (int)strlen(str)) / 2;
	}
	int getMidNeedBlNum(int length)
	{
		return (winMode[iWinSub].iWidth - length) / 2;
	}
	void midClear(int midLineNum)
	{
		system("cls");
		prtLine((winMode[iWinSub].iHeight - midLineNum) / 2);
	}

	//一层依赖
	void prtLine(int num) { prt('\n', num); }
	void prtBlank(int num) { prt(' ', num); }
	void prtlnWithoutHB(const char str[]) {
		cout << str << endl;
	}

	//二层依赖
	void prtHeadBlank()
	{
		prtBlank(winMode[iWinSub].iHeadBlank);
	}
	void prtln(const char str[])
	{
		prtBlank(winMode[iWinSub].iHeadBlank);
		cout << str << endl;
	}
	void prtln(const char str[], int i)
	{
		prtBlank(winMode[iWinSub].iHeadBlank);
		cout << str << i << endl;
	}
	void prtln(const char str1[], const char str2[])
	{
		prtBlank(winMode[iWinSub].iHeadBlank);
		cout << str1 << str2 << endl;
	}
	void midprtln(const char str[])
	{
		prtBlank(getMidNeedBlNum(str));
		cout << str << endl;
	}
	void midprtln(const char str[], int i)
	{
		prtBlank(getMidNeedBlNum(str));
		cout << str << i << endl;
	}
	

	//输入源
	//遇bc返回0,esc(退出程序?返回主界面),否则读取指定区域,自动识别位数
	int getChoice(int maxallowed)
	{
		if (maxallowed == 0) {
			while (1) {
				int c = _getch();
				if (c == 8) return 0;
				if (c == 27) {
					exit(0);//return -1;
					smpUI::getChoice(0);
				}
				if (c == 13) return 0;
			}
		}
		int digit = 1;
		for (int i = maxallowed; i /= 10;)
			digit++;

		int* c = new int[digit] {};
		while (1) {
			int sum = 0;
			for (int i = 0; 1; i++) {
				c[i] = _getch();
				if (c[i] == 8) {
					delete[]c;
					return 0;
				}
				if (c[i] == 27) {
					delete[]c;
					//return -1;
					exit(0);
				}
				if (c[i] == 13) {
					if (sum > 0 && sum <= maxallowed) {
						delete[]c;
						return sum;
					}
					else break;
				}
				sum *= 10;
				c[i] -= '0';
				if (!(c[i] >= 0 && c[i] < 10))
					break;
				sum += c[i];
				if (i == digit - 1) {
					if (sum > 0 && sum <= maxallowed) {
						delete[]c;
						return sum;
					}
					else break;
				}
			}
		}
	}
	int scanInt()
	{
		cursor::unhideCursor();
		int i = 0;
		while (!(cin >> i)) {
			cin.clear();
			cin.ignore(5000, '\n');
			prtBlank(winMode[iWinSub].iHeadBlank);
		}
		cin.ignore(5000, '\n');
		cursor::hideCursor();
		return i;
	}
	char* scanStr()
	{
		cursor::unhideCursor();
		char* str = new char[300]{};
		cin >> str;
		cin.ignore(5000, '\n');
		cursor::hideCursor();
		return str;
	}

	//输入源 输出为二层依赖
	void prtMidNeedBlank(int length)
	{
		prtBlank(getMidNeedBlNum(length));
	}
	void prtMidNeedBlank(const char str[])
	{
		prtBlank(getMidNeedBlNum(str));
	}

	//一层依赖
	int scanIntAtMid(int len)
	{
		prtMidNeedBlank(len);
		return scanInt();
	}
	char* scanStrAtMid(int len)
	{
		prtMidNeedBlank(len);
		cursor::unhideCursor();
		char* str = new char[300]{};
		cin >> str;
		cin.ignore(5000, '\n');
		cursor::hideCursor();
		return str;
	}

}

namespace color
{
	//private
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	int nowword = 月黄, nowbg = 黑, nowmainbg = 黑;
	//int blankturn;
	void paintword()
	{
		SetConsoleTextAttribute(hCon, (nowword - 1) + (nowbg - 1) * 16);
	}
	void paintblank()
	{
		SetConsoleTextAttribute(hCon, (nowword - 1) * 16);
	}

	//public
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
		if (word)
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
		nowword = word;
		nowmainbg = back;
		char a[10] = "color 00";
		sprintf_s(a, 10, "color %x%x", nowmainbg - 1, nowword - 1);//先背景，再文字
		system(a);
	}

}

namespace font
{
	//private
	CONSOLE_FONT_INFOEX cfi;
	//public
	void font()
	{
		cfi.cbSize = sizeof cfi;
		cfi.nFont = 0;
		cfi.dwFontSize.X = 0; //字宽
		cfi.dwFontSize.Y = 23;//字高
		cfi.FontFamily = FF_DONTCARE;
		cfi.FontWeight = FW_BOLD;//粗细
		wcscpy_s(cfi.FaceName, L"楷体");
		SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
	}

	void setMaxScreenHeight(int maxLine) {
		int winHeight = GetSystemMetrics(SM_CYFULLSCREEN);
		setHeight(winHeight/maxLine);
	}

	void setHeight(int iHeight)
	{
		cfi.dwFontSize.Y = iHeight;
		SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
	}

	void setFontName(const wchar_t* cstr)
	{
		wcscpy_s(cfi.FaceName, cstr);
		SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
	}

}

namespace cursor
{
	//private
	CONSOLE_CURSOR_INFO info = { 1, 0 };

	//public
	void hideCursor()
	{
		info.bVisible = 0;
		SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
	}

	void unhideCursor()
	{
		info.bVisible = 1;
		SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
	}

}

namespace smpRdm {

	void refresh()
	{
		srand(unsigned int(time(0)));
	}

	int intRdm(int min, int max)
	{
		return (rand() % (max - min)) + min;
	}

}

namespace smpWchar
{
	void wchar()
	{
		locale currentlocale("chs");
		setlocale(LC_ALL, "zh-CN");
	}
}

namespace smpTime
{
	char* newWorldTimeStr()
	{
		char* str = new char[50]{};
		time_t t;
		tm* lt = new tm;
		time(&t);//获取Unix时间戳。
		localtime_s(lt, &t);//转为时间结构。
		sprintf_s(str, 50, "%d.%d.%d %d时%d昏%d秒 ", lt->tm_year + 1900, lt->tm_mon, lt->tm_mday, lt->tm_hour, lt->tm_min, lt->tm_sec);
		delete lt;
		return str;
	}
}


//namespace reprintf
//{
//	void PrintD(int Data) {
//		if (Data < 0) {
//			Data *= -1;
//		}
//		if (Data / 10 != 0)
//			PrintD(Data / 10);
//		putchar(Data % 10 + '0');
//	}
//	void PrintF(double Data) {
//		int I_Data = (int)Data;
//		Data -= I_Data;
//		int Flo = 1000000 * Data;
//		PrintD(I_Data);
//		putchar('.');
//		PrintD(Flo);
//	}
//	void PrintC(char C) {
//		putchar(C);
//	}
//	void PrintStr(const char* Str) {
//		while (*Str != '\0')
//			putchar(*Str++);
//	}
//	void PrintX(unsigned long Num, int Base) {
//		if (Num <= 0) {
//			return;
//		}
//		PrintX(Num / Base, Base);
//		putchar("0123456789abcdef"[Num % Base]);
//	}
//	void PrintP(unsigned long long  num) {
//		PrintX(num, 16);
//	}
//	int Printf(const char* csFormat, ...) {
//		int num = 0;
//		va_list va_l;
//		va_start(va_l, csFormat);
//
//		char Line = *csFormat;
//		while (Line != '\0') {
//			if (Line == '%') {
//				Line = *++csFormat;
//				switch (Line) {
//				case 'c':
//					PrintC(va_arg(va_l, char));
//					break;
//				case 's':
//					PrintStr(va_arg(va_l, char*));
//					break;
//				case 'd':
//					PrintD(va_arg(va_l, char));
//					break;
//				case 'f':
//					PrintF(va_arg(va_l, double));
//					break;
//				case 'l':
//					PrintF(va_arg(va_l, double));
//					break;
//				case 'p':
//					PrintP(va_arg(va_l, unsigned long long));
//					break;
//				case 'o':
//					PrintX(va_arg(va_l, int), 8);
//					break;
//				case 'x':
//					PrintX(va_arg(va_l, int), 16);
//					break;
//				default:
//					putchar('%');
//					putchar(Line);
//					break;
//				}
//			}
//			else {
//				putchar(Line);
//			}
//			Line = *++csFormat;
//			++num;
//		}
//		return num;
//	}
//}
//const char* smpSCrt::sPrt(const char* csFormat, ...) {
//	sub = 0;
//	va_list va_l;
//	va_start(va_l, csFormat);
//	while (*csFormat) {
//		if (*csFormat == '%') {
//			switch (*++csFormat) {
//			case 'c':
//				add(va_arg(va_l, char));
//				break;
//			case 's':
//				addStr(va_arg(va_l, char*));
//				break;
//			case 'd':
//				addD(va_arg(va_l, char));
//				break;
//			case 'f':
//				addF(va_arg(va_l, double));
//				break;
//			case 'l':
//				addF(va_arg(va_l, double));
//				break;
//			case 'p':
//				addP(va_arg(va_l, unsigned long long));
//				break;
//			case 'o':
//				addX(va_arg(va_l, int), 8);
//				break;
//			case 'x':
//				addX(va_arg(va_l, int), 16);
//				break;
//			default:
//				add('%');
//				add(*csFormat);
//				break;
//			}
//		}
//		else 
//			add(*csFormat);
//		++csFormat;
//	}
//	buffer[sub] = 0;
//	return buffer;
//}
