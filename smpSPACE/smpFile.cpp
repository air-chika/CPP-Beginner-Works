#include"smpFile.h"
#include"smpStr.h"
#include"smptime.h"
using namespace std;

bool getUntil(std::istream& fin, char* destination, dchar deli)
{
	while (1) {
		char c1 = fin.get(), c2 = 0;
		if (fin.eof()) {
			*destination++ = 0;
			return 0;
		}
		if (c1 < 0) {
			c2 = fin.get();
			dchar cc(c1, c2);
			if (deli == cc) {
				*destination++ = 0;
				return 1;
			}
			else {
				*destination++ = c1;
				*destination++ = c2;
			}
		}
		else {
			*destination++ = c1;
		}
	}
}

smpFin::smpFin(const char* fileName) :fileName(smpStr::cpyNew(fileName))
{
	fin.open(fileName);
}
smpFin::~smpFin() { fin.close(); }

void smpFin::igrBlLn() {
	char a = fin.peek();
	while (a == 32 || a == 10) {
		fin.get();
		a = fin.peek();
	}
}

bool smpFin::ignore(char deli) {
	igrBlLn();
	char cs[100];
	if (fin.getline(cs, 100, deli)) return 1;
	else return 0;
}

bool smpFin::ignoreln() {
	return ignore('\n');
}



int smpFin::getWordsNum(char deli) {
	std::streamoff pos = fin.tellg();
	char reg[200]{};
	int num = -1;
	while (reg[0] != deli) {
		fin >> reg;
		num++;
	}
	fin.seekg(pos, 0);
	return num;
}

int smpFin::getNewWordsR(char**& prr, char deli) {
	int len = getWordsNum(deli);
	prr = smpStr::getNewpp<char>(len, 20);
	for (int i = 0; i < len; i++)
		fin >> prr[i];
	ignore(deli);
	return len;
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
		char** str = smpStr::getNewpp<char>(iMaxLine, 100);
		char cstr[100]{};

		fstream fio(sFileName, 1);
		for (int i = 0; fio.getline(cstr, 100); i++)
			smpStr::cpy(str[i], cstr);
		fio.close();

	//	smpStr::quicksort(str, 0, iMaxLine - 1);

		fio.open(sAimFileName, 2);
		for (int i = 0; i < iMaxLine; i++)
			fio << str[i] << endl;

		smpStr::dltpp(str, iMaxLine);
		fio.close();
	}

	//复制文件
	void CpyFile(const char* sAimFileName, const char* sourseFileName)
	{
		if (sourseFileName == sAimFileName) return;
		char cstr[200];
		ofstream fout(sAimFileName);
		ifstream fin(sourseFileName);
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
				fio3 << sreg;
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
		smpStr::cpy(sBackup, sFolderName);
		smpStr::cat(sBackup, "\\");

		char* sTime = smpTime::newWorldTimeStr();
		smpStr::cat(sBackup, sTime);

		int len = smpStr::len(sFileName);
		int pos = 0;
		for (int i = 0; i < len; i++)
			if (sFileName[i] == '\\')
				pos = i;

		smpStr::cat(sBackup, sFileName + pos + 1);
		smpFile::CpyFile(sBackup, sFileName);
		delete[] sTime;
	}


	int SearchLine(cstr aim, cstr filename) {
		char str[500];
		ifstream fin(filename);
		while (fin.getline(str, 500))
			if (!smpStr::cmp(str, aim))
				return 1;
		return 0;
	}

}



