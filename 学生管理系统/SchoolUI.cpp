#include"SchoolUI.h"

using namespace smpUI;


SchoolUI::SchoolUI(School& school, const char* fileName) :school(school)
{
	using namespace smpFio;
	ifstream fin(fileName);
	smpAstr smp;
	ignorein(fin, ':', iTabLenStuNumber);
	if (smp.add(school.iLmtClassNum).getLen() > iTabLenStuNumber - 2) {
		cout << "ѧ�Ź����������ø�����ռλ����";
		getChoice(0);
		exit(0);
	}
	ignorein(fin, ':', iTabLenStuName);
	if (school.iMaxStuNameNum > iTabLenStuName) {
		cout << "ѧ�����ֹ����������ø�����ռλ����";
		getChoice(0);
		exit(0);
	}

	iStuPfmTotalNum = school.iSubjectNum + 2; //+�ܷ�+ƽ����
	int bit = iStuPfmTotalNum;

	ignorein(fin, ':', iTabLenSubName);
	if (school.iLmtSubNameLen < iTabLenSubName) {
		cout << "ѧ�����ֹ����������ø�����ռλ����";
		getChoice(0);
		exit(0);
	}

	ignorein(fin, ':', iStuPfmSMALLDigit);
	if (iStuPfmSMALLDigit < 0) {
		cout << "���Ȳ���Ϊ����";
		getChoice(0);
		exit(0);
	}
	if (iStuPfmSMALLDigit > 3) {
		cout << "���Ȳ��ɳ���3λ";
		getChoice(0);
		exit(0);
	}

	ignorein(fin, ':', iChoiceLn);
	if (iChoiceLn < 1) {
		cout << "�Ի���߶�ֻ��Ϊ����";
		getChoice(0);
		exit(0);
	}

	ignorein(fin, ':', iSortBrowsePageLen);
	if (iSortBrowsePageLen > school.iLmtClassStuNum) {
		cout << "�Ի���߶�ֻ��Ϊ����";
		getChoice(0);
		exit(0);
	}


	int word = 15, back = 1;
	ignorein(fin, ':', word);
	ignorein(fin, ':', back);
	if (word < 1 || word>16 || back < 1 || back>16 || word == back) {
		cout << "������ɫΥ��";
		getChoice(0);
		exit(0);
	}
	else color::setall(word, back);
	fin.close();

	iWidth = iTabLenStuNumber + iTabLenStuName + iTabLenSubName * iStuPfmTotalNum;
	iHeight = iChoiceLn + school.iLmtClassStuNum;

	iHeadBlank = iWidth / 20;
	if (iHeadBlank % 2) iHeadBlank++;
	iWidth += iHeadBlank * 2;
	iHeadLine = iHeadBlank / 2;
	iHeight += iHeadLine * 2;

	setWinMode(0, iWidth, iHeight, iHeadLine, iHeadBlank);
	useWinMode(0);
	font::font();
	font::setMaxScreenHeight(iHeight);

	MakeFormat();
}
SchoolUI::~SchoolUI()
{
	delete[] sPfmFormat;
}
void SchoolUI::MakeFormat()
{
	smpAstr smp;
	smp.addbl(iHeadBlank).addRightInBlank("ѧ��", iTabLenStuNumber).addRightInBlank("����", iTabLenStuName);
	for (int i = 0; i < school.iSubjectNum; i++)
		smp.addRightInBlank(school.sSubjectName[i], iTabLenSubName);
	smp.addRightInBlank("�ܷ�", iTabLenSubName);
	smp.addRightInBlank("ƽ����", iTabLenSubName);
	sStuTop = smp.giveNewCopy();
	sPfmFormat = smp.setZero().add('%').add(iTabLenSubName).add('d').giveNewCopy();
	sPfmAveFormat = smp.setZero().add('%').add(iTabLenSubName).add('.').add(iStuPfmSMALLDigit).add('f').giveNewCopy();
}


void SchoolUI::MainBranch()
{
	while (1) {
		//1.����ѧ�� 2.����ѧУ
		prtMain();
		//switch (2) {
		switch (smpUI::getChoice(2)) {
		case 0:return;
		case 1:prtSchool(); getChoice(0);  break;
		case 2:
			browseSub = 0;
			StudentChoice123_Browse();
			break;
		}
	}
}
void SchoolUI::prtMain()
{
	useWinMode(0);
	midClear(4);
	midprtln("ѧ������ϵͳ");
	prtLine(1);
	midprtln("1 �鿴ѧУ");
	midprtln("2 ����ѧ��");
}
void SchoolUI::prtSchool()
{
	setWinMode(1, 0);
	int wid = getMidNeedBlNum(9);
	setWinMode(1, -1, -1, -1, wid);
	useWinMode(1);

	midClear(4 + school.iSubjectNum);
	prtln(school.sSchoolName);
	prtLine(1);
	prtln("�༶��:", school.iNowClassNum);
	prtln("ѧ����:", school.iTotalStudentsNum);
	prtln("ѧ����:", school.iSubjectNum);
	char subName[10] = "ѧ��  :";
	for (int i = 0; i < school.iSubjectNum; i++) {
		if (i < 9)
			subName[4] = i + '1';
		else {
			subName[4] = (i + 1) / 10 + '0';
			subName[5] = (i + 1) % 10 + '0';
		}
		prtln(subName, school.sSubjectName[i]);
	}
}


void SchoolUI::NullStudentInsert()
{
	useWinMode(0);
	clear();
	midprtln("ѧУ��ѧ������Ϊ0���벹����Դ");
	prtLine(1);
	char* name = 0;
	int* arrPfm = 0;
	ScanNewStudentIfm(name, arrPfm);
	school.AddStudent(0, name, arrPfm);
	school.FileSync();
	delete[] name;
	delete[] arrPfm;
}
void SchoolUI::prtlnStudent(Student* pStu)
{
	smpAstr str;
	str.addbl(iHeadBlank).addRightIn0(pStu->iStudentNumber, iTabLenStuNumber).addRightInBlank(pStu->sStudentName, iTabLenStuName);
	printf(str.getBuffer());
	for (int i = 0; i < school.iSubjectNum; i++)
		printf(sPfmFormat, pStu->irrSubjectPerformance[i]);
	printf(sPfmFormat, pStu->iTotalPfm);
	printf(sPfmAveFormat, (double)pStu->iTotalPfm / school.iSubjectNum);
	prtLine(1);
}
void SchoolUI::prtStudent_Head()
{
	if (school.iTotalStudentsNum == 0)
		NullStudentInsert();
	useWinMode(0);
	clear();
	prtlnWithoutHB(sStuTop);
	Classroom* pClass = school.prrClassroom[browseSub];
	for (int i = 0; i < school.iLmtClassStuNum; i++) {
		int k = i;
		if (!isAscend) k = school.iLmtClassStuNum - 1 - i;
		Student* pStu = pClass->prrStudent[k];
		if (pStu->isExist)
			prtlnStudent(pStu);
	}
	prtLine(1);
}
void SchoolUI::prtPartStudent(Student** prrstudent, int num)
{
	useWinMode(0);
	clear();
	prtlnWithoutHB(sStuTop);
	for (int i = 0; i < num; i++)
		prtlnStudent(prrstudent[i]);
	prtLine(1);
}
char* SchoolUI::ScanNewStuName()
{
	while (1) {
		char* name = scanStrAtMid(4);
		if (strlen(name) <= school.iLmtStuNameLen) return name;
		midprtln("��������");
		delete[] name;
	}
}
int SchoolUI::ScanNewStuPfm(int movePos)
{
	while (1) {
		int Pfm = scanIntAtMid(movePos);
		if (Pfm <= school.iLmtPfmScore && Pfm > -2) return Pfm;
		midprtln("�ɼ�����");
	}
}
void SchoolUI::ScanNewStudentIfm(char*& name, int*& arrPfm)
{
	midprtln("��������ѧ�����������ɼ�:");
	midprtln("ÿ�����붼��Ҫʹ�ûس�ȷ��");
	midprtln("�������ɹ�����ô��������һ��ˮƽ�ƶ�");
	smpAstr smp;
	smp.add("�������ó���").add(school.iLmtStuNameLen).add("���ֽڣ�������Ϊ˫�ֽ�");
	midprtln(smp.getBuffer());
	smp.setZero().add("�ɼ����ó���").add(school.iLmtPfmScore).add("�裬�ɼ�����Ϊ-1,��Ĭ�Ͻ������ĳɼ���Ϊ0��");
	midprtln(smp.getBuffer());

	name = ScanNewStuName();
	arrPfm = new int[school.iSubjectNum]{};
	for (int i = 0; i < school.iSubjectNum; i++) {
		arrPfm[i] = ScanNewStuPfm(-1 * i * 2 + 15);
		if (arrPfm[i] == -1)
			for (; i < school.iSubjectNum; i++)
				arrPfm[i] = 0;
	}
}
void SchoolUI::prtStudentUntilUnexist()
{
	useWinMode(0);
	clear();
	prtlnWithoutHB(sStuTop);
	Classroom* pClass = school.prrClassroom[browseSub];
	for (int i = 0; i < school.iLmtClassStuNum; i++) {
		Student* pStu = pClass->prrStudent[i];
		if (pStu->isExist)
			prtlnStudent(pStu);
		else break;
	}
	prtLine(1);
}


void SchoolUI::StudentChoice123_Browse()
{
	while (1) {
		//1.�ϸ��༶ 2.�¸��༶ 3.ת������˳�� 4.����Ϣ������ļ� 5.����  6.�޸� 7.���� 8.ͳ��
		prtStudentChoice123_Browse();

		switch (getChoice(8)) {
			//switch (8) {
		case 0:return;
		case 1:
			PreviousPage();
			break;

		case 2:
			NextPage();
			break;

		case 3:
			isAscend = !isAscend;
			break;

		case 4:
			StudentChoice4_Fileprt();
			break;

		case 5:
			StudentChoice5_Search();
			break;

		case 6:
			StudentChoice6_Change();
			break;

		case 7:
			StudentChoice7_Sort();
			break;

		case 8:
			StudentChoice8_Statistics();
			break;
		}
	}
}
void SchoolUI::prtStudentChoice123_Browse()
{
	prtStudent_Head();
	//1.�ϸ��༶ 2.�¸��༶ 3.ת������˳�� 4.����Ϣ������ļ� 5.����  6.�޸� 7.���� 8.ͳ��
	setWinMode(2, 0);
	setWinHBinMid(2, "5.����     6.��ɾ��   7.����       8.ͳ��");
	useWinMode(2);

	if (isAscend)
		prtln("1.��һҳ   2.��һҳ   3.��������   4.������ļ�");
	else
		prtln("1.��һҳ   2.��һҳ   3.��������   4.������ļ�");
	prtln("5.����     6.��ɾ��   7.����       8.ͳ��");
}
int SchoolUI::PreviousPage()
{
	for (int i = browseSub - 1; i >= 0; i--)
		if (school.prrClassroom[i]->iNowClassStuNum != 0) {
			browseSub = i;
			return 1;
		}
	return 0;
}
int SchoolUI::NextPage()
{
	for (int i = browseSub + 1; i < school.iLmtClassNum; i++)
		if (school.prrClassroom[i]->iNowClassStuNum != 0) {
			browseSub = i;
			return 1;
		}
	return 0;
}
int SchoolUI::FindEffectBrowseSub()
{
	if (school.prrClassroom[browseSub]->iNowClassStuNum == 0)
		//if (!NextPage())
		if (!PreviousPage())
			return 0;
	return 1;
}


void SchoolUI::StudentChoice4_Fileprt()
{
	prtStudent_Head();
	midprtln("�������ļ�·��:");
	midprtln("�ļ������ܰ��������κ��ַ�:\\ / : * ? \" < > |");
	midprtln("ֱ�������ļ�������������exeͬ�ļ���");

	char* a = scanStrAtMid(iStdFileNameLen);
	FILE* fp;
	if (a[0] == '"') {
		int len = smpStr::strlen(a);
		for (int i = 0; i < len; i++)
			a[i] = a[i + 1];
		a[len - 2] = 0;
	}
	if (fopen_s(&fp, a, "w")) {
		midprtln("����·������");
		getChoice(0);
		delete[] a;
		return;
	}
	fprtStudentChoice4_Fileprt(fp);
	fclose(fp);
	midprtln("����ɹ�");
	delete[] a;
	getChoice(0);
}
void SchoolUI::fprtStudentChoice4_Fileprt(FILE* fp)
{
	smpAstr smp;

	for (int ii = 0; ii < school.iNowClassNum; ii++) {
		fprintf(fp, "%s\n", sStuTop);
		Classroom* pClass = school.prrClassroom[ii];
		if (!isAscend) pClass = school.prrClassroom[school.iNowClassNum - 1 - ii];
		for (int i = 0; i < school.iLmtClassStuNum; i++) {
			Student* pStu = pClass->prrStudent[i];
			if (!isAscend) pStu = pClass->prrStudent[school.iLmtClassStuNum - 1 - i];
			if (pStu->isExist) {

				smp.setZero().addbl(iHeadBlank).addRightIn0(pStu->iStudentNumber, iTabLenStuNumber).addRightInBlank(pStu->sStudentName, iTabLenStuName);
				fprintf(fp, "%s", smp.getBuffer());
				for (int i = 0; i < school.iSubjectNum; i++)
					fprintf(fp, sPfmFormat, pStu->irrSubjectPerformance[i]);
				fprintf(fp, sPfmFormat, pStu->iTotalPfm);
				fprintf(fp, sPfmAveFormat, (double)pStu->iTotalPfm / school.iSubjectNum);
				fprintf(fp, "\n");
			}
		}
	fprintf(fp, "\n\n");
	}
}


void SchoolUI::StudentChoice5_Search()
{
	while (1) {
		prtStudent_Head();
		midprtln("1.ѧ�Ų��� 2.��������");
		switch (smpUI::getChoice(2)) {
		case 0:return;
		case 1:StudentChoice5_1_NumberSearch();  break;
		case 2:StudentChoice5_2_NameSearch(); break;
		}
	}
}
void SchoolUI::StudentChoice5_1_NumberSearch()
{
	prtStudent_Head();
	midprtln("������ѧ��(��ʡ��λ���ֺ�����0):");
	int number = scanIntAtMid(iTabLenStuNumber);

	Student* pStu = school.SearchNumber(number);
	if (!pStu)
		midprtln("����ʧ��");
	else
		prtPartStudent(&pStu, 1);
	getChoice(0);
}
void SchoolUI::StudentChoice5_2_NameSearch()
{
	prtStudent_Head();
	midprtln("����������:");
	char* name = scanStrAtMid(iStdStuNameLen);
	Student** prrStu = new Student * [school.iTotalStudentsNum + 1]{};
	int stuNum = school.SearchName(name, prrStu);
	if (stuNum)
		prtPartStudent(prrStu, stuNum);
	else
		midprtln("����ʧ��");
	getChoice(0);
	delete[] name;
	delete[] prrStu;
}


void SchoolUI::StudentChoice6_Change()
{
	while (1) {
		prtStudent_Head();
		midprtln("1.����   2.ɾ��   3.�޸�");
		switch (getChoice(3)) {
		case 0:return;
		case 1:StudentChoice6_1_InsertChooseClass();  break;
		case 2:StudentChoice6_2_Dlt(); break;
		case 3:StudentChoice6_3_ChangeChooseStu(); break;
		}
	}
}
void SchoolUI::StudentChoice6_1_InsertChooseClass()
{
	while (1) {
		prtStudent_Head();
		midprtln("ѡ��Ҫ��ӵİ༶:");
		char str[100]{};
		char str2[100]{};
		smpAstr smp;
		smp.add("ѡ����:1-").add(school.iNowClassNum).addbl(3).add(school.iNowClassNum + 1).add(".�½��༶");
		midprtln(smp.getBuffer());

		int choice = JudgeStudentChoice6_1_InsertChooseClass();
		if (choice == 0) return;
		StudentChoice6_1_1ChangeInsert(choice - 1);

		school.FileSync();
	}
}
int SchoolUI::JudgeStudentChoice6_1_InsertChooseClass()
{
	int choice = getChoice(school.iNowClassNum + 1);
	if (choice == 0) return 0;
	if (choice < school.iNowClassNum + 1) {
		if (school.prrClassroom[choice - 1]->iNowClassStuNum >= school.iLmtClassStuNum) {
			midprtln("�ð���������");
			getChoice(0);
			StudentChoice6_1_InsertChooseClass();
			return 0;
		}
		return choice;
	}
	else {
		if (choice > school.iLmtClassNum) {
			midprtln("�༶���Ѵ�����");
			getChoice(0);
			StudentChoice6_1_InsertChooseClass();
			return 0;
		}
		return choice;
	}
}
void SchoolUI::StudentChoice6_1_1ChangeInsert(int classSub)
{
	browseSub = classSub;
	prtStudentUntilUnexist();
	midprtln("��ѧ������������ʾ�����һ�˺���");
	midprtln("��ѧ����ʾ����Ϊ1��");

	char* name = 0;
	int* arrPfm = 0;
	ScanNewStudentIfm(name, arrPfm);
	school.AddStudent(classSub, name, arrPfm);

	delete[] name;
	delete[] arrPfm;
}

void SchoolUI::StudentChoice6_2_Dlt()
{
	while (1) {
		prtStudent_Head();
		midprtln("������Ҫɾ��ѧ����ѧ��(��ʡ��λ���ֺ�����0):");
		int number = scanIntAtMid(iStdStuNameLen);
		int result = school.DltStudent(number);
		if (result > 0) {
			FindEffectBrowseSub();
			prtStudent_Head();
			if (result == 2) {
				if (school.iTotalStudentsNum == 0)
					NullStudentInsert();
				else midprtln("�༶ɾ���ɹ�");
			}
			midprtln("ѧ��ɾ���ɹ�");
			school.FileSync();
			midprtln("1.����ɾ��");
			switch (getChoice(1)) {
			case 0:return;
			}
		}
		else {
			if (result == 0)
				midprtln("����������ѧ��");
			if (result == -1)
				midprtln("���һ���༶ǰ�İ༶��������Ϊ0");
			midprtln("1.����ɾ��");
			switch (getChoice(1)) {
			case 0:return;
			}
		}
	}
}

void SchoolUI::StudentChoice6_3_ChangeChooseStu()
{
	while (1) {
		prtStudent_Head();
		midprtln("������Ҫ�޸�ѧ����ѧ��(��ʡ��λ���ֺ�����0):");
		int a = scanIntAtMid(iStdStuNameLen);
		Student* pstu = school.SearchNumber(a);
		if (pstu) {
			StudentChoice6_3_1_Change(pstu);
			break;
		}
		else {
			midprtln("����������ѧ��");
			prtLine(1);
			midprtln("1.��������ѧ��");
			switch (getChoice(1)) {
			case 0:return;
			}
		}
	}
}
void SchoolUI::StudentChoice6_3_1_Change(Student* pstu)
{
	while (1) {
		smpAstr smp;
		prtPartStudent(&pstu, 1);
		int choiceDig = smpStr::getDigit(school.iSubjectNum + 2);

		smp.setZero().addRightIn0(1, choiceDig).add(".ת��");
		midprtln(smp.getBuffer());
		smp.setZero().addRightIn0(2, choiceDig).add(".����");
		midprtln(smp.getBuffer());

		for (int i = 0; i < school.iSubjectNum; i++) {
			smp.setZero().addRightIn0(i + 3, choiceDig).add(".�޸�").add(school.sSubjectName[i]).add("�ɼ�");
			midprtln(smp.getBuffer());
		}
		int choice = getChoice(2 + school.iSubjectNum);
		if (choice == 0) return;
		if (choice == 1) {
			if ((pstu->iStudentNumber / 100) != school.iNowClassNum && school.prrClassroom[pstu->iStudentNumber / 100 - 1]->iNowClassStuNum == 1) {
				midprtln("���һ���༶ǰ�İ༶��������Ϊ0");
				getChoice(0);
			}
			else StudentChoice6_3_1_1ChangeClass(pstu);
			school.FileSync();
			return;
		}
		if (choice == 2) {
			smp.setZero().add("(�������ó���").add(school.iLmtStuNameLen).add("���ֽڣ�������Ϊ˫�ֽ�)");
			midprtln(smp.getBuffer());
			midprtln("������������:");
			char* name = ScanNewStuName();
			smpStr::strcpy(pstu->sStudentName, name);
			school.FileSync();
			delete[] name;
		}
		if (choice > 2) {
			smp.setZero().add("(�ɼ����ó���").add(school.iLmtPfmScore).add("��)");
			midprtln(smp.getBuffer());
			midprtln("�������³ɼ�:");
			int pfm = ScanNewStuPfm();
			pstu->ChangePfm(choice - 3, pfm);
			school.FileSync();
		}
	}
}
void SchoolUI::StudentChoice6_3_1_1ChangeClass(Student* pstu)
{
	char str[100]{};
	char str2[100]{};
	sprintf_s(str, "ת����:1-%d", school.iNowClassNum);
	sprintf_s(str2, "   %d.�°༶", school.iNowClassNum + 1);
	smpStr::strcat(str, str2);
	midprtln(str);
	int choice = getChoice(school.iNowClassNum + 1);

	if ((pstu->iStudentNumber / 100) == school.iNowClassNum && choice == school.iNowClassNum + 1) {
		midprtln("���һ���༶ǰ�İ༶��������Ϊ0");
		getChoice(0);
		return;
	}

	int result = school.MoveStudent(pstu, choice);
	if (result == 0) {
		midprtln("�༶��������");
		getChoice(0);
	}
	if (result == -1) {
		midprtln("�༶���Ѵ�����");
		getChoice(0);
	}
}



int SchoolUI::gSortBrowseMaxSub()
{
	int sub = school.iTotalStudentsNum / iSortBrowsePageLen;
	if (school.iTotalStudentsNum % iSortBrowsePageLen == 0)sub--;
	return sub;
}
void SchoolUI::StudentChoice7_Sort()
{
	while (1) {
		setWinMode(3, 0);
		setWinHBinMid(3, "��ѡ��Ҫ����Ŀ�Ŀ:");
		useWinMode(3);

		midClear(school.iSubjectNum + 2);
		midprtln("��ѡ�������Ŀ:");

		int choiceDig = smpStr::getDigit(school.iSubjectNum + 1);
		smpAstr smp;

		for (int i = 0; i < school.iSubjectNum; i++) {
			smp.setZero().addRightIn0(i + 1, choiceDig).add('.').add(school.sSubjectName[i]);
			midprtln(smp.getBuffer());
		}

		smp.setZero().addRightIn0(school.iSubjectNum + 1, choiceDig).add('.').add("�ܷ�");
		midprtln(smp.getBuffer());

		int choice = getChoice(school.iSubjectNum + 1);
		if (choice == 0) return;
		else {
			Student** prrSort = school.getSortList(choice - 1);
			isSortAscend = 1;
			iSortBrowseSub = 0;
			Choice7_1_SortBrowse(prrSort);
			delete[] prrSort;
		}
	}
}
void SchoolUI::Choice7_1_SortBrowse(Student** prrSort)
{
	while (1) {
		//1.��һҳ  2.��һҳ 3.ת������˳�� 4.����Ϣ������ļ�
		prtChoice7_2_SortBrowse(prrSort);
		switch (getChoice(4)) {
		case 0:return;
		case 1:
			if (iSortBrowseSub != 0) iSortBrowseSub--;
			break;
		case 2:
			if (iSortBrowseSub != gSortBrowseMaxSub()) iSortBrowseSub++;
			break;
		case 3:
			isSortAscend = !isSortAscend;
			break;
		case 4:
			Choice7_1_4_Fileprt(prrSort);
			break;
		}
	}

}
void SchoolUI::prtChoice7_1_SortBrowse_Head(Student** prrSort)
{
	useWinMode(0);
	clear();
	prtlnWithoutHB(sStuTop);

	int thisPageLen = iSortBrowsePageLen;
	if (iSortBrowseSub == gSortBrowseMaxSub())
		thisPageLen = school.iTotalStudentsNum % iSortBrowsePageLen;

	if (isSortAscend) {
		Student** prrNowSort = prrSort + school.iTotalStudentsNum - 1 - iSortBrowseSub * iSortBrowsePageLen;
		for (int i = 0; i < thisPageLen; i++)
			prtlnStudent(prrNowSort[-1 * i]);
	}
	else {
		Student** prrNowSort = prrSort + iSortBrowseSub * iSortBrowsePageLen;
		for (int i = 0; i < thisPageLen; i++)
			prtlnStudent(prrNowSort[i]);
	}
	prtLine(1);
}
void SchoolUI::prtChoice7_2_SortBrowse(Student** prrSort)
{
	prtChoice7_1_SortBrowse_Head(prrSort);
	//1.�ϸ��༶ 2.�¸��༶ 3.ת������˳�� 4.����Ϣ������ļ� 
	if (isSortAscend)
		midprtln("1.��һҳ  2.��һҳ  3.��������  4.������ļ�");
	else
		midprtln("1.��һҳ  2.��һҳ  3.�ݼ�����  4.������ļ�");
}
void SchoolUI::Choice7_1_4_Fileprt(Student** prrSort)
{
	prtChoice7_1_SortBrowse_Head(prrSort);
	midprtln("�������ļ�·��");
	midprtln("�ļ������ܰ��������κ��ַ�:\\ / : * ? \" < > |");
	midprtln("ֱ�������ļ�������������exeͬ�ļ���:");

	char* a = scanStrAtMid(iStdFileNameLen);
	FILE* fp;
	if (a[0] == '"') {
		int len = smpStr::strlen(a);
		for (int i = 0; i < len; i++)
			a[i] = a[i + 1];
		a[len - 2] = 0;
	}
	if (fopen_s(&fp, a, "w")) {
		midprtln("����·������");
		getChoice(0);
		delete[] a;
		return;
	}
	fprtChoice7_1_4_Fileprt(prrSort, fp);
	fclose(fp);
	midprtln("����ɹ�");
	delete[] a;
	getChoice(0);
}
void SchoolUI::fprtChoice7_1_4_Fileprt(Student** prrSort, FILE* fp)
{
	smpAstr smp;
	fprintf(fp, sStuTop);
	fprintf(fp, "\n");

	for (int j = 0; j < school.iTotalStudentsNum; j++) {
		int k = j;
		if (isSortAscend) k = school.iTotalStudentsNum - 1 - j;
		smp.setZero().addbl(iHeadBlank).addRightIn0(prrSort[k]->iStudentNumber, iTabLenStuNumber).addRightInBlank(prrSort[k]->sStudentName, iTabLenStuName);
		fprintf(fp, smp.getBuffer());
		for (int i = 0; i < school.iSubjectNum; i++)
			fprintf(fp, sPfmFormat, prrSort[k]->irrSubjectPerformance[i]);
		fprintf(fp, sPfmFormat, prrSort[k]->iTotalPfm);
		fprintf(fp, sPfmAveFormat, (double)prrSort[k]->iTotalPfm / school.iSubjectNum);
		fprintf(fp, "\n");
	}
}


void SchoolUI::MakeNewStatisticsFormat(char*& top, char**& mid)
{
	int iStaHeadBlank = (iWidth - iTabLenSubName * (iStuPfmTotalNum - 1) - 8) / 2;
	if (iStaHeadBlank % 2) iStaHeadBlank--;
	int headLen = iStaHeadBlank + 8;

	smpAstr smp;
	smp.addMidinBlank_setRight("ͳ��", headLen, 2);
	for (int i = 0; i < school.iSubjectNum; i++)
		smp.addRightInBlank(school.sSubjectName[i], iTabLenSubName);
	smp.addRightInBlank("�ܷ�", iTabLenSubName);
	top = smp.giveNewCopy();

	mid[0] = smp.setZero().addRightInBlank("У��߻�", headLen).giveNewCopy();
	mid[1] = smp.setZero().addRightInBlank("Уƽ����", headLen).giveNewCopy();
	mid[2] = smp.setZero().addRightInBlank("У��ͻ�", headLen).giveNewCopy();
}
void SchoolUI::StudentChoice8_Statistics()
{
	int* irrMax = 0;
	int* irrMin = 0;
	double* drrAve = 0;
	school.getNewMaxMinAvePfmList(irrMax, irrMin, drrAve);

	char* top = 0;
	char** mid = new char* [3];
	MakeNewStatisticsFormat(top, mid);

	midClear(4);
	prtlnWithoutHB(top);

	printf(mid[0]);
	for (int i = 0; i <= school.iSubjectNum; i++)
		printf(sPfmFormat, irrMax[i]);
	prtLine(1);

	printf(mid[1]);
	for (int i = 0; i <= school.iSubjectNum; i++)
		printf(sPfmAveFormat, drrAve[i]);
	prtLine(1);

	printf(mid[2]);
	for (int i = 0; i <= school.iSubjectNum; i++)
		printf(sPfmFormat, irrMin[i]);
	prtLine(1);

	getChoice(0);
}