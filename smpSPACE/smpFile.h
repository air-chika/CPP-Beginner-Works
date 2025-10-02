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
	//void SortFileLine(const char* sFileName, const char* sAimFileName = 0);

	//�����ļ�
	void CpyFile(const char* sAimFileName, const char* sourseFileName);

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

	//�ļ�����һ������
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