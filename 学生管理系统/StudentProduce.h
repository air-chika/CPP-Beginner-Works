#pragma once
#include <iostream>
#include <fstream>
#include"smpspace.h"
using namespace std;

class StudentProduce {
public:

	//随机打乱文件中的每行
	//"数据\\学生.txt"
	//void RdmRepdcFileLine(string sFileName);
	
	//按顺序添加学号
	void PdcNum()
	{
		fstream fio("数据\\学生.txt", ios::ate | ios::out | ios::in);
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

	//生成成绩并打乱
	void RdmPmc(const char* sFileName)
	{
		smpFile::RdmFileWord(sFileName);
		smpFile::blanktoline(sFileName,10);
	}

	

	////生成成绩
	//void PdcPfm();
	////生成一项成绩
	//void PdcOnepfm(int* a, int degree);

	/* 使用过程
	StudentProduce produce;
	produce.RdmPmc("数据\\t2.txt");
	produce.RdmPmc("数据\\t3.txt");
	produce.RdmPmc("数据\\t4.txt");
	produce.RdmPmc("数据\\t5.txt");
	produce.RdmPmc("数据\\t6.txt");
	produce.RdmPmc("数据\\t7.txt");
	smpFile::MergeFileEnd("数据\\t1.txt", "数据\\t2.txt");
	smpFile::MergeFileEnd("数据\\t1.txt", "数据\\t3.txt");
	smpFile::MergeFileEnd("数据\\t1.txt", "数据\\t4.txt");
	smpFile::MergeFileEnd("数据\\t1.txt", "数据\\t5.txt");
	smpFile::MergeFileEnd("数据\\t1.txt", "数据\\t6.txt");
	smpFile::MergeFileEnd("数据\\t1.txt", "数据\\t7.txt");
	*/
};
