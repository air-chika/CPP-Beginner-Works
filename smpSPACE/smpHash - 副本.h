#pragma once
#include"smpStr.h"

class smpHashNode;
class smpHashLink;

class smpHash
{
public:
	//��ϣ����ֵΪһ��ڵ㣬��Ϊ����ڵ�
	smpHash(const char* keyFailSign = 0, int valueFailSign = 0);
	~smpHash();
	smpHash& clearHash();

	int tryDltValue(int value);
	int tryInsert(const char* key, int value);
	//���سɹ�����
	int tryInsert(const char* key[], int value[], int num);

	int tryGetValue(const char* key);

	const char* tryGetKey(int value);
	int getNewAllKeyR(int value, const char**& rtnPrrKey);

private:
	int iMaxValueNum;
	int iMaxKeyNum;
	int valueFailSign;
	const char* keyFailSign;
	smpHashLink* head;
	smpHashLink* tryGetValueLink(int value);
};


class smpHashLink
{
public:
	smpHashLink(int value, const char* keyFailSign = 0, smpHashLink* next = 0);
	~smpHashLink();

	void setValue(int value);
	int getValue();
	//�ص����ض���
	int isSameValue(int value);

	void dltAllKey();
	int getKeyNum();
	int tryInsertKey(const char* key);
	int tryDltKey(const char* key);
	int hasKey(const char* key);
	const char* tryGetKey(int number = 1);
	int getAllKeyR(const char**& rtnPrrKey);

	smpHashLink* next;

private:
	smpHashNode* head;
	const char* keyFailSign;
	int iMaxKeyNum;
	int value;
};


class smpHashNode
{
public:
	smpHashNode(const char* key, smpHashNode* next = 0);
	~smpHashNode();

	//���ض���
	int isSameKey(const char* key);
	const char* getKey();
	void setKey(const char* key);

	smpHashNode* next;

private:
	const char* key;
};
