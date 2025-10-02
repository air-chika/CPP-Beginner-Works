#pragma once
#include"School.h"

class SchoolUI
{
public:
	SchoolUI(School&,const char*);
	~SchoolUI();
	void MainBranch();

private:

	void MakeFormat();
	void MakeNewStatisticsFormat(char*&, char**&);
	void prtMain();
	void prtSchool();

	void NullStudentInsert();
	void prtlnStudent(Student* pStu);
	void prtStudent_Head();
	void prtPartStudent(Student** prrstudent, int num);
	char* ScanNewStuName();
	int ScanNewStuPfm(int movePos = 2);
	void ScanNewStudentIfm(char*& name, int*& arrPfm);
	void prtStudentUntilUnexist();


	void StudentChoice123_Browse();
	void prtStudentChoice123_Browse();
	int PreviousPage();
	int NextPage();
	int FindEffectBrowseSub();


	void StudentChoice4_Fileprt();
	void fprtStudentChoice4_Fileprt(FILE* fp);


	void StudentChoice5_Search();
	void StudentChoice5_1_NumberSearch();
	void StudentChoice5_2_NameSearch();


	void StudentChoice6_Change();


	void StudentChoice6_1_InsertChooseClass();
	int JudgeStudentChoice6_1_InsertChooseClass();
	void StudentChoice6_1_1ChangeInsert(int classSub);

	void StudentChoice6_2_Dlt();

	void StudentChoice6_3_ChangeChooseStu();

	void StudentChoice6_3_1_Change(Student*);
	void StudentChoice6_3_1_1ChangeClass(Student*);

	int gSortBrowseMaxSub();
	void StudentChoice7_Sort();
	void Choice7_1_SortBrowse(Student** prrSort);
	void prtChoice7_1_SortBrowse_Head(Student** prrSort);
	void prtChoice7_2_SortBrowse(Student** prrSort);
	void Choice7_1_4_Fileprt(Student**);
	void fprtChoice7_1_4_Fileprt(Student**, FILE* fp);

	void StudentChoice8_Statistics();


	School& school;

	bool isAscend = 1;
	int browseSub = 0;

	//1则从高到低，0则从低到高
	bool isSortAscend = 1;
	int iSortBrowseSub = 0;
	int iSortBrowsePageLen;


	const char* sStuTop;
	const char* sPfmFormat;
	const char* sPfmAveFormat;

	int iWidth;
	int iHeight;
	int iHeadLine;
	int iHeadBlank;

	int iChoiceLn; //对话框高度

	int iStuPfmTotalNum;
	int iStuPfmDigit;
	int iStuPfmSMALLDigit;

	int iTabLenStuNumber;
	int iTabLenStuName;
	int iTabLenSubName;

	int iStdFileNameLen=7;
	int iStdPfmLen=3;
	int iStdStuNameLen = 4;
};