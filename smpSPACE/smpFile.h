#pragma once
#include <fstream>
#include "smpStr.h"

using std::ifstream;


bool getUntil(std::istream& fin, char* destination, dchar deli);

class smpFin
{
public:
	smpFin(const char* fileName);
	~smpFin();

	void igrBlLn();
	bool ignore(char deli);
	bool ignoreln();
	template<class t>
	bool ignorein(t& destination, char deli) {
		if (!ignore(deli)) return 0;
		if (fin >> destination) return 1;
		else return 0;
	}
	int getWordsNum(char deli = '\n');
	int getNewWordsR(char**& prr, char deli);

	ifstream fin;
private:
	const char* fileName;
};



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
	//void SortFileLine(const char* sFileName, const char* sAimFileName = 0);

	//复制文件
	void CpyFile(const char* sAimFileName, const char* sourseFileName);

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

	//文件中有一行是它
	int SearchLine(cstr aim,cstr filename);

}






class smpFout
{
public:
	smpFout(const char* fileName, int format = std::ios::out) {
		fout.open(fileName, format);
	}
	~smpFout() { fout.close(); }

	void autoblankout() {

	}
private:
	std::ofstream fout;
};