#pragma once
#include"SkillGraph.h"

using namespace smpConUI;
using namespace smpDebug;
//index 0��ɫ 1��ʼ 2��(n-3)�м� n-2���� n-1�ӳ� n����ӳ�
class Ice {
public:
	Ice() {}
	Ice(int midMax) { index = new int[midMax + 5]{}; }
	~Ice() { if (index && needDlt)delete[] index; }
	void cpy(Ice& ice) {
		num = ice.num;
		index = new int[num] {};
		for (int i = 0; i < num; i++)
			index[i] = ice.index[i];
	}

	void indexIn(int sub) {
		index[num++] = sub;
	}

	void coutIndex() {
		for (int i = 0; i < num; i++) {
			cout << index[i] << ' ';
		}
		cout << endl;
	}

	int num = 0;
	int* index = 0;
	int needDlt = 1;
};

class IceList {
public:
	IceList() {
		arrIce = new Ice[lmt]{};
		iceNum = 0;
	}
	~IceList() {
		delete[] arrIce;
	}
	void listIn(Ice& ice) {
		if (iceNum == lmt) {
			Ice* rr = new Ice[lmt * 2]{};
			for (int i = 0; i < lmt; i++) {
				rr[i].index = arrIce[i].index;
				rr[i].num = arrIce[i].num;
				arrIce[i].needDlt = 0;
			}
			delete[] arrIce;
			arrIce = rr;
			lmt <<= 1;
		}
		arrIce[iceNum++].cpy(ice);
	}

	Ice* arrIce;
	int lmt = 100;
	int iceNum;
};

class IceUI :public SkillGraph
{
public:
	IceUI() :SkillGraph(),
		charaBox(MultyChooseBox::getBoxFullWide(4, 1, color::����, color::�»�, smpConUI::isChoiceRightMore)),
		startBox(MultyChooseBox::getBoxFullWide(4, 1, color::����, color::����, smpConUI::isChoiceRightMore)),
		midBox(MultyChooseBox::getBoxFullWide(4, 1, color::����, color::�ۺ�, smpConUI::isChoiceRightMore)),
		endBox(MultyChooseBox::getBoxFullWide(4, 1, color::����, color::����, smpConUI::isChoiceRightMore)),
		delayBox(color::�»�)
	{
		wantChara = new int[iCharaNum + 4]{};
		wantStart = new int[iStartNum + 4]{};
		wantMid = new int[iMidNum + 4]{};
		wantEnd = new int[iEndNum + 4]{};

	/*	for (int i = 1; i <= iMidNum; i++)
			wantMid[i] = 1;
		for (int i = 1; i <= iEndNum; i++)
			wantEnd[i] = 1;*/

		iDelayMin = 0;
		iDelayMax = 0;
		for (int i = 1; i <= iCharaNum; i++)
			charaBox.setChooseContent(arrCharater[i].characterName);
		charaBox.setChooseContent("ȫѡ");
		charaBox.setChooseContent("��ɫѡ�����");
		charaBox.setChooseContent("�˳�");
		for (int i = 1; i <= iStartNum; i++)
			startBox.setChooseContent(arrStartSkill[i].nameStartSkill);
		startBox.setChooseContent("ȫѡ");
		startBox.setChooseContent("����ѡ�����");
		startBox.setChooseContent("���ؽ�ɫѡ��");
		for (int i = 1; i <= iMidNum; i++)
			midBox.setChooseContent(arrMidSkill[i].nameMidSkill);
		midBox.setChooseContent("ȫѡ");
		midBox.setChooseContent("�м̼������");
		midBox.setChooseContent("��������ѡ��");
		for (int i = 1; i <= iEndNum; i++)
			endBox.setChooseContent(arrEndSkill[i].nameEndSkill);
		endBox.setChooseContent("ȫѡ");
		endBox.setChooseContent("��β�������");
		endBox.setChooseContent("�����м̼���");
		delayBox.insert("�����ӳ�����1��");
		delayBox.insert("�����ӳ�����2��");
	}
	void start_CharaFrame() {
		out::clear();
		if (charaBox.playChooseBox(wantChara))
			startSkillFrame();
		else
			return;
	}

	//private:
	IceList& findIce() {
		Ice nowIce(100);
		IceList& iceList = *new IceList;
		for (int i = 1; i <= iCharaNum; i++) {
			if (!wantChara[i]) continue;

			nowIce.indexIn(i);
			for (int j = 1; j <= iStartNum; j++) {
				if (!wantStart[j]) continue;

				nowIce.indexIn(j);

				int canTime = getCantime(i, j);
				for (int k = 1; k <= iEndNum; k++) {
					if (!wantEnd[k]) continue;
					if (!start_end[j][k]) continue;

					int happen = 0, lastHappen = 0;
					if (suitTimeR(canTime, 0, k, happen, lastHappen)) {
						nowIce.indexIn(k);
						nowIce.indexIn(happen);
						nowIce.indexIn(lastHappen);
						iceList.listIn(nowIce);
						nowIce.num -= 3;
					}
				}

				for (int k = 1; k <= iMidNum; k++) {
					if (!wantMid[k]) continue;
					if (!start_mid[j][k]) continue;
					nowIce.indexIn(k);
					findIce(k, arrMidSkill[k].ihappen, canTime, nowIce, iceList);
					nowIce.num--;
				}

				nowIce.num--;
			}
			nowIce.num--;
		}
		return iceList;
	}
	void findIce(int midNumber, int nowTime, int canTime, Ice& nowIce, IceList& iceList) {
		for (int i = 1; i <= iEndNum; i++) {
			if (!wantEnd[i]) continue;
			if (!mid_end[midNumber][i]) continue;
			int happen = 0, lastHappen = 0;
			if (suitTimeR(canTime, nowTime, i, happen, lastHappen)) {
				nowIce.indexIn(i);
				nowIce.indexIn(happen);
				nowIce.indexIn(lastHappen);
				iceList.listIn(nowIce);
				nowIce.num -= 3;
			}
		}
		if (nowTime > canTime) return;
		for (int i = 1; i <= iMidNum; i++) {
			if (!wantMid[i]) continue;
			if (!mid_mid[midNumber][i]) continue;
			nowIce.indexIn(i);
			findIce(i, nowTime + arrMidSkill[i].ihappen, canTime, nowIce, iceList);
			nowIce.num--;
		}
	}
	bool suitTimeR(int canTime, int nowTime, int endNumber, int& iceHappen, int& iceLastHappen) {
		iceHappen = nowTime + arrEndSkill[endNumber].ihappen;
		iceLastHappen = iceHappen + arrEndSkill[endNumber].iremain - 1;
		int min = iceHappen + iDelayMin;
		int max = iceLastHappen + iDelayMax;
		if (canTime >= min && canTime <= max) 
			return 1;
		return 0;
	}


	void startSkillFrame() {
		out::clear();
		if (startBox.playChooseBox(wantStart))
			midSkillFrame();
		else  start_CharaFrame();
	}

	void midSkillFrame() {
		out::clear();
		if (midBox.playChooseBox(wantMid))
			endSkillFrame();
		else startSkillFrame();
	}

	void endSkillFrame() {
		out::clear();
		if (endBox.playChooseBox(wantEnd)) {
			delayFrame();
		}
		else midSkillFrame();
	}

	void delayFrame() {
		out::clear();
		int* res = delayBox.playBox_new();
		if (res[0] > res[1]) swap(res[0], res[1]);
		iDelayMin = res[0];
		iDelayMax = res[1];
		prtIce();
	}

	void prtIce() {
		IceList& iceList = findIce();
		smpAstr smp, file;
		cout << smpAstr(' ').add(' ', 30).add("�ļ�����").getBuffer();
		file.add("Result\\");
		file.add(in::scanStr());
		file.add(".txt");

		out::clear();
		//file.add("�� ").add(smpTime::newWorldTimeStr()).add(".txt");
		ofstream fout(file.getBuffer());
		cout << endl;
		for (int i = 0; i < iceList.iceNum; i++) {
			const char* iceStr = IcetoStr(smp.set0(), iceList.arrIce[i]);
		//	cout << "  " << iceStr << endl << endl;
			fout << iceStr << endl << endl;
		}
		/*cout << "  ����������ؽ�ɫѡ��";
		int c = _getch();
		if (c == 27) exit(0);*/
		start_CharaFrame();
	}

	//index 0��ɫ 1��ʼ 2��(n-4)�м� n-3���� n-2�ӳ� n-1����ӳ�
	const char* IcetoStr(smpAstr& smp, Ice& ice);

	int* wantStart;
	int* wantMid;
	int* wantEnd;
	int* wantChara;
	int iDelayMin;
	int iDelayMax;

	MultyChooseBox charaBox;
	MultyChooseBox startBox;
	MultyChooseBox midBox;
	MultyChooseBox endBox;
	ScanBox delayBox;
};