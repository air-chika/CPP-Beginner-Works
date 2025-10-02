#include"School.h"

Student::Student(int iSubjectNum) {
	this->sStudentName = new char[21]{};
	this->irrSubjectPerformance = new int[iSubjectNum] {};
}

Student::~Student() {
	delete[] sStudentName;
	delete[] irrSubjectPerformance;
}

int Student::getClassSubBelong()
{
	return iStudentNumber / 100 - 1;
}


void Student::ChangePfm(int subSub, int pfm)
{
	iTotalPfm -= irrSubjectPerformance[subSub];
	irrSubjectPerformance[subSub] = pfm;
	iTotalPfm += pfm;
}



Classroom::Classroom(int iClassNumber, int iNowClassStuNum, School& school)
	:
	//iClassNumber(iClassNumber), 
	iNowClassStuNum(iNowClassStuNum), rSchool(school) {

	prrStudent = new Student * [rSchool.iLmtClassStuNum];
	for (int i = 0; i < rSchool.iLmtClassStuNum; i++)
		prrStudent[i] = new Student(rSchool.iSubjectNum);

	iNowClassStuNum = 20;
	for (int i = 0; i < rSchool.iLmtClassStuNum; i++)
		prrStudent[i]->iStudentNumber = iClassNumber * 100 + i + 1;
}

Classroom::~Classroom() {
	for (int i = 0; i < rSchool.iLmtClassStuNum; i++)
		delete prrStudent[i];
	delete[] prrStudent;
}

void Classroom::InputStudent(int iStudentNumber, const char* sStudentName, int* irrSubjectPerformance)
{
	Student* pStu = prrStudent[iStudentNumber % 100 - 1];
	pStu->isExist = 1;
	pStu->iStudentNumber = iStudentNumber;
	pStu->iTotalPfm = 0;
	smpStr::strcpy(pStu->sStudentName, sStudentName);
	for (int i = 0; i < rSchool.iSubjectNum; i++) {
		pStu->iTotalPfm += irrSubjectPerformance[i];
		pStu->irrSubjectPerformance[i] = irrSubjectPerformance[i];
	}
	if (strcmp(sStudentName, "爱尔奎特") == 0|| strcmp(sStudentName, "希耶尔") == 0|| strcmp(sStudentName, "秋叶") == 0|| strcmp(sStudentName, "翡翠") == 0|| strcmp(sStudentName, "琥珀") == 0||\
		strcmp(sStudentName, "七夜") == 0 || strcmp(sStudentName, "志贵") == 0 || strcmp(sStudentName, "谢罪") == 0 || strcmp(sStudentName, "溜冰场场主") == 0 || strcmp(sStudentName, "胡祉旭") == 0) {
		pStu->iTotalPfm = rSchool.iLmtPfmScore*rSchool.iSubjectNum;
		for (int i = 0; i < rSchool.iSubjectNum; i++)
			pStu->irrSubjectPerformance[i]=rSchool.iLmtPfmScore;
	}
}

int Classroom::AddStudent(const char* sStudentName, int* irrSubjectPerformance)
{
	int unexi;
	for (unexi = 0; prrStudent[unexi]->isExist; unexi++);
	Student* pStu = prrStudent[unexi];
	pStu->isExist = 1;
	smpStr::strcpy(pStu->sStudentName, sStudentName);
	pStu->iTotalPfm = 0;
	for (int i = 0; i < rSchool.iSubjectNum; i++) {
		pStu->iTotalPfm += irrSubjectPerformance[i];
		pStu->irrSubjectPerformance[i] = irrSubjectPerformance[i];
	}
	if (strcmp(sStudentName, "爱尔奎特") == 0 || strcmp(sStudentName, "希耶尔") == 0 || strcmp(sStudentName, "秋叶") == 0 || strcmp(sStudentName, "翡翠") == 0 || strcmp(sStudentName, "琥珀") == 0 || \
		strcmp(sStudentName, "七夜") == 0 || strcmp(sStudentName, "志贵") == 0 || strcmp(sStudentName, "谢罪") == 0 || strcmp(sStudentName, "溜冰场场主") == 0 || strcmp(sStudentName, "胡祉旭") == 0) {
		pStu->iTotalPfm = rSchool.iLmtPfmScore * rSchool.iSubjectNum;
		for (int i = 0; i < rSchool.iSubjectNum; i++)
			pStu->irrSubjectPerformance[i] = rSchool.iLmtPfmScore;
	}
	++iNowClassStuNum;
	return 1;
}

int Classroom::DltStudent(int iStuSub)
{
	if (prrStudent[iStuSub]->isExist == 0)
		return 0;
	prrStudent[iStuSub]->isExist = 0;
	iNowClassStuNum--;
	return 1;
}

//返回查找到的人数
int Classroom::prrSearchName(const char* SimilarName, Student** prrStack)
{
	int num = 0;
	for (int i = 0; i < rSchool.iLmtClassStuNum; i++)
		if (prrStudent[i]->isExist && smpStr::aHasb(prrStudent[i]->sStudentName, SimilarName))
			prrStack[num++] = prrStudent[i];
	return num;
}

void Classroom::setSortList(Student** prrStubegSub, int pfmSub)
{
	int top = 0;
	for (int i = 0; i < rSchool.iLmtClassStuNum; i++)
		if (prrStudent[i]->isExist)
			prrStubegSub[top++] = prrStudent[i];
	quicksort(prrStubegSub, 0, top - 1, pfmSub);
}

int Classroom::partition(Student** a, int startSub, int endSub, int pfmSub) {
	if (pfmSub == rSchool.iSubjectNum) {
		int i = startSub;
		int j = endSub + 1;
		int k = a[startSub]->iTotalPfm;
		while (i < j) {
			i++;
			while (a[i]->iTotalPfm <= k && i < endSub)
				i++;
			j--;
			while (a[j]->iTotalPfm > k)
				j--;
			if (i < j)
				swap(a[i], a[j]);
		}
		swap(a[startSub], a[j]);
		return j;
	}

	int i = startSub;
	int j = endSub + 1;
	int k = a[startSub]->irrSubjectPerformance[pfmSub];
	while (i < j) {
		i++;
		while (a[i]->irrSubjectPerformance[pfmSub] <= k && i < endSub)
			i++;
		j--;
		while (a[j]->irrSubjectPerformance[pfmSub] > k)
			j--;
		if (i < j)
			swap(a[i], a[j]);
	}
	swap(a[startSub], a[j]);
	return j;
}

void Classroom::quicksort(Student** a, int startSub, int endSub, int pfmSub) {
	if (startSub < endSub) {
		int j = partition(a, startSub, endSub, pfmSub);
		quicksort(a, startSub, j - 1, pfmSub);
		quicksort(a, j + 1, endSub, pfmSub);
	}
}



School::School(const char* SchFileName, const char* StuFileName)
{
	smpAstr smp;
	smp.add(SchFileName).giveNewCopy(csSchoolFileName);
	smp.setZero().add(StuFileName).giveNewCopy(csStudentFileName);

	sSchoolName = new char[51]{};
	GetIfmFromSchoolFile();

	iTotalStudentsNum = 0;
	GetIfmFromStudentFile();
}
School::~School()
{
	delete[] csSchoolFileName;
	delete[] csStudentFileName;
	delete[] sSchoolName;
	for (int i = 0; i < iNowClassNum; i++)
		delete prrClassroom[i];
	delete[] prrClassroom;
}

void School::GetIfmFromSchoolFile()
{
	using namespace smpFio;
	ifstream fin(csSchoolFileName);
	ignorein(fin, ':', sSchoolName);
	ignorein(fin, ':', iNowClassNum);
	if (iNowClassNum < 0) {
		cout << "班级数不可为0";
		smpUI::getChoice(0);
		exit(0);
	}
	ignoreln(fin);

	ignorein(fin, ':', iSubjectNum);
	sSubjectName = smpStr::newpp<char>(iSubjectNum, 11);

	iMaxSubNameLen = 0;
	ignorein(fin, ':');
	for (int i = 0; i < iSubjectNum; i++) {
		fin >> sSubjectName[i];
		int len = smpStr::strlen(sSubjectName[i]);
		if (len > iMaxSubNameLen) iMaxSubNameLen = len;
	}

	ignorein(fin, ':', iLmtClassNum);

	ignorein(fin, ':', iLmtClassStuNum);
	if (iLmtClassStuNum < 1 && iLmtClassStuNum > 99) {
		cout << "每班学生最大数量设置违规。";
		smpUI::getChoice(0);
		exit(0);
	}
	ignorein(fin, ':', iLmtPfmScore);
	fin.close();
}
void School::PutIfmToSchoolFile()
{
	ofstream fout(csSchoolFileName);
	fout << "学校名称:" << sSchoolName << endl;
	fout << "班级数:" << iNowClassNum << endl;
	fout << "学生数:" << iTotalStudentsNum << endl;
	fout << "学科数:" << iSubjectNum << endl;
	fout << "学科名称:";
	for (int i = 0; i < iSubjectNum; i++)
		fout << sSubjectName[i] << ' ';
	fout << endl << endl;
	fout << "总班级数:" << iLmtClassNum << endl;
	fout << "班级允许最多学生人数:" << iLmtClassStuNum << endl;
	fout << "成绩的最高昏:" << iLmtPfmScore << endl;
	fout.close();
}
void School::GetIfmFromStudentFile()
{
	iMaxStuNameNum = 0;
	char studentName[21]{};
	int* irrSubjectPerformance = new int[iSubjectNum] {};
	ifstream fin(csStudentFileName);
	prrClassroom = new Classroom * [iLmtClassNum];
	if (iNowClassNum > iLmtClassNum) {
		cout << "班级过多";
		smpUI::getChoice(0);
		exit(0);
	}
	for (int i = 0; i < iNowClassNum; i++) {
		int classstunum;
		smpFio::ignorein(smpFio::ignorein(fin, ':', classstunum), '\n');
		if (!classstunum) {
			cout << "不可录入空班级。";
			smpUI::getChoice(0);
			exit(0);
		}

		prrClassroom[i] = new Classroom(i + 1, classstunum, *this);

		for (int k = 0; k < classstunum; k++) {
			int stunumber;
			fin >> stunumber >> studentName;

			int len = smpStr::strlen(studentName);
			if (len > iMaxStuNameNum) iMaxStuNameNum = len;

			for (int j = 0; j < iSubjectNum; j++) {
				fin >> irrSubjectPerformance[j];
				if (irrSubjectPerformance[j]<0 || irrSubjectPerformance[j] > iLmtPfmScore) {
					cout << "学生成绩异常。";
					smpUI::getChoice(0);
					exit(0);
				}
			}
			prrClassroom[i]->InputStudent(stunumber, studentName, irrSubjectPerformance);
		}
		iTotalStudentsNum += classstunum;
	}

	for (int i = iNowClassNum; i < iLmtClassNum; i++)
		prrClassroom[i] = new Classroom(i + 1, 0, *this);
	delete[] irrSubjectPerformance;
	fin.close();
}
void School::PutIfmToStudentFile()
{
	ofstream fout(csStudentFileName);
	for (int i = 0; i < iNowClassNum; i++) {
		fout << i + 1 << "班:" << prrClassroom[i]->iNowClassStuNum << "人" << endl;
		for (int j = 0; j < iLmtClassStuNum; j++) {
			Student* p = prrClassroom[i]->prrStudent[j];
			if (!p->isExist) continue;
			smpFio::autoblankout(fout, p->iStudentNumber);
			smpFio::autoblankout(fout, p->sStudentName);
			for (int k = 0; k < iSubjectNum; k++)
				smpFio::autoblankout(fout, p->irrSubjectPerformance[k]);
			fout << endl;
		}
		fout << endl;
	}
}
void School::FileSync()
{
	PutIfmToSchoolFile();
	PutIfmToStudentFile();
}



Student* School::SearchNumber(int stuNumber)
{
	int classSub = stuNumber / 100 - 1;
	int stuSub = stuNumber % 100 - 1;
	if (classSub < 0 || classSub >= iNowClassNum) return 0;
	if (stuSub < 0 || stuSub >= iLmtClassStuNum) return 0;

	if (prrClassroom[classSub]->prrStudent[stuSub]->isExist)
		return prrClassroom[classSub]->prrStudent[stuSub];
	return 0;
}
int School::SearchName(char* name, Student** prrStu)
{
	int sum = 0;
	for (int i = 0; i < iNowClassNum; i++)
		sum += prrClassroom[i]->prrSearchName(name, prrStu + sum);
	return sum;
}

//不存在返回0 成功返回1 不可删除班级-1
int School::DltStudent(int stuNumber)
{
	int classSub = stuNumber / 100 - 1;
	int stuSub = stuNumber % 100 - 1;
	if (classSub < 0 || classSub >= iNowClassNum) return 0;
	if (stuSub < 0 || stuSub >= iLmtClassStuNum) return 0;

	if (prrClassroom[classSub]->iNowClassStuNum == 1 && classSub < iNowClassNum - 1)
		return -1;

	if (prrClassroom[classSub]->DltStudent(stuSub)) {
		if (prrClassroom[classSub]->iNowClassStuNum == 0) {
			iNowClassNum--;
			return 2;
		}
		iTotalStudentsNum--;
		return 1;
	}
	else
		return 0;
}
//已保证有序  太乱辣
void School::AddStudent(int classSub, char* name, int* pfm)
{
	prrClassroom[classSub]->AddStudent(name, pfm);
	if (prrClassroom[classSub]->iNowClassStuNum == 1) iNowClassNum++;
	iTotalStudentsNum++;
}
int School::MoveStudent(Student* pstu, int classNumber)
{
	int classSub1 = pstu->getClassSubBelong();
	int classSub2 = classNumber - 1;
	if (classSub1 == classSub2) return 1;
	if (classNumber > iLmtClassNum) return -1;
	if (prrClassroom[classSub2]->iNowClassStuNum == iLmtClassStuNum) return 0;
	AddStudent(classSub2, pstu->sStudentName, pstu->irrSubjectPerformance);
	DltStudent(pstu->iStudentNumber);
	return 1;
}
Student** School::getSortList(int pfmSub)
{
	Student** prrStu = new Student * [iTotalStudentsNum + 1]{};
	int sum = 0;
	for (int i = 0; i < iNowClassNum; i++) {
		prrClassroom[i]->setSortList(prrStu + sum, pfmSub);
		sum += prrClassroom[i]->iNowClassStuNum;
	}
	prrClassroom[0]->quicksort(prrStu, 0, iTotalStudentsNum - 1, pfmSub);
	return prrStu;
}

void School::getNewMaxMinAvePfmList(int*& irrMax, int*& irrMin, double*& drrAve)
{
	irrMax = new int[iSubjectNum + 1]{};
	irrMin = new int[iSubjectNum + 1]{};
	for (int i = 0; i < iSubjectNum + 1; i++)
		irrMin[i] = iLmtPfmScore;
	drrAve = new double[iSubjectNum + 1]{};
	long long* llrrSum = new long long[iSubjectNum + 1]{};
	for (int i = 0; i < iNowClassNum; i++) {
		Classroom* pcm = prrClassroom[i];
		for (int j = 0; j < iLmtClassStuNum; j++) {
			Student* pst = pcm->prrStudent[j];
			if (!pst->isExist) continue;
			for (int k = 0; k < iSubjectNum; k++) {
				int pfm = pst->irrSubjectPerformance[k];
				if (irrMax[k] < pfm)	irrMax[k] = pfm;
				if (irrMin[k] > pfm)	irrMin[k] = pfm;
				llrrSum[k] += pfm;
			}
			int pfm = pst->iTotalPfm;
			if (irrMax[iSubjectNum] < pfm)	irrMax[iSubjectNum] = pfm;
			if (irrMin[iSubjectNum] > pfm)	irrMin[iSubjectNum] = pfm;
			llrrSum[iSubjectNum] += pfm;
		}
	}
	for (int i = 0; i <= iSubjectNum; i++)
		drrAve[i] = llrrSum[i] / double(iTotalStudentsNum);
	delete[] llrrSum;
}
