#pragma once
#include<smpSPACE.h>

using namespace std;
using namespace smpStr;
using namespace smpError;

constexpr const char* chara= "Sourse\\CharacterList.txt";
constexpr const char* graph= "Sourse\\SkillGraph.txt";
constexpr const char* point= "Sourse\\SkillPoint.txt";

class Character
{
public:
	void set(const char* characterName0, int fwd, int rvs) {
		characterName = getNew(characterName0);
		forward = fwd;
		reverse = rvs;
	}

	bool isSame(const char* characterName) {
		return !cmp(characterName, this->characterName);
	}

	const char* characterName;
	int forward;
	int reverse;
};
class StartSkill {
public:
	void set(const char* name, int cantime, bool isforward) {
		nameStartSkill = getNew(name);
		canTime = cantime;
		isForward = isforward;
	}
	~StartSkill() { delete[]nameStartSkill; }
	const char* nameStartSkill = 0;
	int canTime = 0;
	bool isForward = 0;
};
class MidSkill {
public:
	void set(const char* name, int happen) {
		nameMidSkill = getNew(name);
		ihappen = happen;
	}
	~MidSkill() { delete[]nameMidSkill; }
	bool isSame(const char* name, int happen) {
		if (happen == ihappen && cmp(name, nameMidSkill) == 0)return 1;
		return 0;
	}
	const char* nameMidSkill = 0;
	int ihappen = 0;
};
class EndSkill {
public:
	void set(const char* name, int happen, int remain) {
		nameEndSkill = getNew(name);
		ihappen = happen;
		iremain = remain;
	}
	~EndSkill() { delete[]nameEndSkill; }
	bool isSame(const char* name) {
		if (cmp(name, nameEndSkill) == 0)return 1;
		return 0;
	}

	const char* nameEndSkill = 0;
	int ihappen = 0;
	int iremain = 0;
};

class SkillGraph {
public:
	Character* arrCharater;
	StartSkill* arrStartSkill;
	MidSkill* arrMidSkill;
	EndSkill* arrEndSkill;
	int iCharaNum;
	int iStartNum;
	int iMidNum;
	int iEndNum;
	int** start_mid;
	int** start_end;
	int** mid_mid;
	int** mid_end;
	//��1��ʼ��
	SkillGraph() {
		ifstream fin(point);
		char name[200]{};
		fin.getline(name, 200);
		jdgIF(cmp(name, "StartSkill"), "SkillPoint.txt��StartSkillλ�ô���");
		iStartNum = 0;
		while (1) {
			fin.getline(name, 200);
			if (name[0] == '0') break;
			iStartNum++;
//			jdgIF(name[0] != iStartNum + '0', smpAstr("SkillPoint.txt��StartSkill�б��� ").add(iStartNum).add("������").getBuffer());
		}
		fin.getline(name, 200);
		fin.getline(name, 200);
		jdgIF(cmp(name, "MidSkill"), "SkillPoint.txt��MidSkillλ�ô���");
		iMidNum = 0;
		while (1) {
			fin.getline(name, 200);
			if (name[0] == '0') break;
			iMidNum++;
//			jdgIF(name[0] != iStartNum + '0', smpAstr("SkillPoint.txt��MidSkill�б��� ").add(iStartNum).add("������").getBuffer());
		}
		fin.getline(name, 200);
		fin.getline(name, 200);
		jdgIF(cmp(name, "EndSkill"), "SkillPoint.txt��EndSkillλ�ô���");
		iEndNum = 0;
		while (1) {
			fin.getline(name, 200);
			if (name[0] == '0') break;
			iEndNum++;
//			jdgIF(name[0] != iStartNum + '0', smpAstr("SkillPoint.txt��EndSkill�б��� ").add(iStartNum).add("������").getBuffer());
		}
		fin.close();

		arrStartSkill = new StartSkill[iStartNum + 1];
		arrMidSkill = new MidSkill[iMidNum + 1];
		arrEndSkill = new EndSkill[iEndNum + 1];
		fin.open(point);
		fin >> name;
		for (int i = 1; i <= iStartNum; i++) {
			int number, canTime, isfor;
			fin >> number >> name >> canTime >> isfor;
			arrStartSkill[i].set(name, canTime, isfor);
		}
		fin >> name >> name;
		for (int i = 1; i <= iMidNum; i++) {
			int number, happen;
			fin >> number >> name >> happen;
			arrMidSkill[i].set(name, happen);
		}
		fin >> name >> name;
		for (int i = 1; i <= iEndNum; i++) {
			int number, happen, remain;
			fin >> number >> name >> happen >> remain;
			arrEndSkill[i].set(name, happen, remain);
		}
		fin.close();
		start_mid = getNewpp<int>(iStartNum + 1, iMidNum + 1);
		start_end = getNewpp<int>(iStartNum + 1, iEndNum + 1);
		mid_mid = getNewpp<int>(iMidNum + 1, iMidNum + 1);
		mid_end = getNewpp<int>(iMidNum + 1, iEndNum + 1);

		fin.open(graph);
		fin >> name;
		jdgIF(cmp(name, "start_mid"), "SkillGraph.txt��start_midλ�ô���");
		for (int i = 1; i <= iStartNum; i++) {
			int number;
			fin >> number;
			jdgIF(number != i, "SkillGraph.txt��start_mid�б��ʽ����");
			while (1) {
				fin >> number;
				if (!number) break;
				start_mid[i][number] = 1;
			}
		}

		fin >> name;
		jdgIF(cmp(name, "start_end"), "SkillGraph.txt��start_endλ�ô���");
		for (int i = 1; i <= iStartNum; i++) {
			int number;
			fin >> number;
			jdgIF(number != i, "SkillGraph.txt��start_end�б��ʽ����");
			while (1) {
				fin >> number;
				if (!number) break;
				start_end[i][number] = 1;
			}
		}

		fin >> name;
		jdgIF(cmp(name, "mid_mid"), "SkillGraph.txt��mid_midλ�ô���");
		for (int i = 1; i <= iMidNum; i++) {
			int number;
			fin >> number;
			jdgIF(number != i, "SkillGraph.txt��mid_mid�б��ʽ����");
			while (1) {
				fin >> number;
				if (!number) break;
				mid_mid[i][number] = 1;
			}
		}

		fin >> name;
		jdgIF(cmp(name, "mid_end"), "SkillGraph.txt��mid_endλ�ô���");
		for (int i = 1; i <= iMidNum; i++) {
			int number;
			fin >> number;
			jdgIF(number != i, "SkillGraph.txt��mid_end�б��ʽ����");
			while (1) {
				fin >> number;
				if (!number) break;
				mid_end[i][number] = 1;
			}
		}

		iCharaNum = smpFile::CntFileLine(chara);
		arrCharater = new Character[iCharaNum + 1];
		fin.close();
		fin.open(chara);
		for (int i = 1; i <= iCharaNum; i++) {
			char characterName[20]{};
			int forward = 0, reverse = 0;
			fin >> characterName >> forward >> reverse;
			jdgIF(fin.fail(), "CharacterList.txt����ɫ���ݸ�ʽ����");
			arrCharater[i].set(characterName, forward, reverse);
		}
	}
	int getCantime(int chara,int start) {
		return arrStartSkill[start].canTime + ((arrStartSkill[start].isForward) ? (arrCharater[chara].forward) : (arrCharater[chara].reverse));
	}

};
