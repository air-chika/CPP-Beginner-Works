#pragma once
#include <iostream>
#include <fstream>
#include"smpspace.h"
using namespace std;

class StudentProduce {
public:

	//��������ļ��е�ÿ��
	//"����\\ѧ��.txt"
	//void RdmRepdcFileLine(string sFileName);
	
	//��˳�����ѧ��
	void PdcNum()
	{
		fstream fio("����\\ѧ��.txt", ios::ate | ios::out | ios::in);
		char* cstr = new char[10];
		string *str=new string[214]{};

		fio.seekg(0, ios::beg);
		for (int i = 0; i < 214; i++) {
			fio.getline(cstr, 10);
			str[i] = cstr;
		}

		int iSum=0,iMaxnum=32;
		for (int i = 1; i < 8; i++) {
			if (i > 4) iMaxnum = 31;

			for (int j = 1; j < iMaxnum; j++) {
				_itoa_s(i * 100 + j, cstr,5, 10);
				str[iSum] = cstr+(' ' + str[iSum]);
				iSum++;
			}
		}
		fio.seekg(0, ios::beg);
		for (int i = 0; i < 214; i++)
		{
			fio << str[i] << endl;
			cout << str[i] << endl;
		}
		fio.close();
	}

	//���ɳɼ�������
	void RdmPmc(const char* sFileName)
	{
		smpFile::RdmFileWord(sFileName);
		smpFile::blanktoline(sFileName,10);
	}

	

	////���ɳɼ�
	//void PdcPfm();
	////����һ��ɼ�
	//void PdcOnepfm(int* a, int degree);

	/* ʹ�ù���
	StudentProduce produce;
	produce.RdmPmc("����\\t2.txt");
	produce.RdmPmc("����\\t3.txt");
	produce.RdmPmc("����\\t4.txt");
	produce.RdmPmc("����\\t5.txt");
	produce.RdmPmc("����\\t6.txt");
	produce.RdmPmc("����\\t7.txt");
	smpFile::MergeFileEnd("����\\t1.txt", "����\\t2.txt");
	smpFile::MergeFileEnd("����\\t1.txt", "����\\t3.txt");
	smpFile::MergeFileEnd("����\\t1.txt", "����\\t4.txt");
	smpFile::MergeFileEnd("����\\t1.txt", "����\\t5.txt");
	smpFile::MergeFileEnd("����\\t1.txt", "����\\t6.txt");
	smpFile::MergeFileEnd("����\\t1.txt", "����\\t7.txt");
	*/
};
