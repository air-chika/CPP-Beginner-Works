#pragma once
#include"smpspace.h"

struct Student
{
	Student(int iSubjectNum);
	~Student();

	int getClassSubBelong();
	void ChangePfm(int subSub, int pfm);

	int iStudentNumber = 0;				//学号 char?
	char* sStudentName;					//姓名
	int* irrSubjectPerformance;		    //成绩组
	int iTotalPfm = 0;					//总分
	bool isExist = 0;					//存在
};

class School;

class Classroom
{
public:
	Classroom(int iClassNumber, int iNowClassStuNum, School&);
	~Classroom();

	void InputStudent(int iStudentNumber, const char* sStudentName, int* irrSubjectPerformance);

	int prrSearchName(const char* SimilarName, Student** prrStack);
	int AddStudent(const char* sStudentName, int* irrSubjectPerformance);
	int DltStudent(int iStudentNumber);

	void setSortList(Student** prrStubegSub, int pfmSub);

	Student** prrStudent;
	School& rSchool;
	int iNowClassStuNum;
	//int iClassNumber;

	void quicksort(Student** a, int startSub, int endSub, int pfmSub);

private:
	int partition(Student** a, int startSub, int endSub, int pfmSub);
};

class School
{
public:
	School(const char*, const char*);
	~School();

	void GetIfmFromSchoolFile();
	void GetIfmFromStudentFile();
	void PutIfmToSchoolFile();
	void PutIfmToStudentFile();
	void FileSync();

	Student* SearchNumber(int);
	int SearchName(char*, Student**);

	int DltStudent(int);
	void AddStudent(int classSub, char*, int*);
	int MoveStudent(Student* pstu, int classNumber);
	//void DltClassroom(int);

	Student** getSortList(int prrStu);

	void getNewMaxMinAvePfmList(int*& irrMax, int*& irrMin, double*& irrAve);

	const char* csStudentFileName;
	const char* csSchoolFileName;

	char* sSchoolName;
	Classroom** prrClassroom;

	int iSubjectNum;
	char** sSubjectName;

	int iNowClassNum;
	int iTotalStudentsNum;
	int iMaxStuNameNum;
	int iMaxSubNameLen;

	int iLmtClassNum;
	int iLmtClassStuNum;
	int iLmtSubNameLen=10;
	int iLmtStuNameLen=20;
	int iLmtPfmScore;

};




