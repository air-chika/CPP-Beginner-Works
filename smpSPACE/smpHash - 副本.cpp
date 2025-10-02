#include"smpHash.h"

using namespace smpStr;

smpHash::smpHash(const char* keyFailSign , int valueFailSign ) {
	iMaxKeyNum = iMaxValueNum = 0;
	this->keyFailSign = keyFailSign;
	this->valueFailSign = valueFailSign;
	head = new smpHashLink(valueFailSign);
}
smpHash::~smpHash() {
	clearHash();
	delete head;
}
smpHash& smpHash::clearHash() {
	smpHashLink* tmp = head->next, * tmr = tmp;
	while (tmp = tmp->next) {
		delete tmr;
		tmr = tmp;
	}
	delete tmr;
	iMaxValueNum = iMaxValueNum = 0;
	return *this;
}

int smpHash::tryDltValue(int value) {
	smpHashLink* tmp = head->next, * tmr = head;
	while (1) {
		if (!tmp) return 0;
		if (tmp->isSameValue(value)) {
			tmr->next = tmp->next;
			iMaxKeyNum -= tmp->getKeyNum();
			iMaxValueNum--;
			delete tmp;
			return 1;
		}
		tmp = tmp->next;
		tmr = tmp;
	}
}
int smpHash::tryInsert(const char* key, int value) {
	smpHashLink* tmp = head;
	while (tmp->next) {
		tmp = tmp->next;
		if (tmp->getValue() == value) {
			if (tmp->tryInsertKey(key)) {
				iMaxKeyNum++;
				return 1;
			}
			else return 0;
		}
	}
	tmp->next = new smpHashLink(value);
	tmp->next->tryInsertKey(key);
	iMaxKeyNum++;
	iMaxValueNum++;
	return 1;
}
//返回成功个数
int smpHash::tryInsert(const char* key[], int value[], int num) {
	int realIst = 0;
	for (int i = 0; i < num; i++) {
		if (tryInsert(key[i], value[i]))
			realIst++;
	}
	return realIst;
}


smpHashLink* smpHash::tryGetValueLink(int value) {
	for (smpHashLink* tmp = head; tmp = tmp->next;)
		if (tmp->isSameValue(value)) return tmp;
	return 0;
}
int smpHash::tryGetValue(const char* key) {
	for (smpHashLink* tmp = head; tmp = tmp->next;) {
		if (tmp->hasKey(key)) return tmp->getValue();
	}
	return valueFailSign;
}

const char* smpHash::tryGetKey(int value) {
	smpHashLink* tmp = tryGetValueLink(value);
	if (!tmp) return keyFailSign;
	return tryGetValueLink(value)->tryGetKey();
}
int smpHash::getNewAllKeyR(int value, const char**& rtnPrrKey) {
	smpHashLink* tmp = tryGetValueLink(value);
	return tmp->getAllKeyR(rtnPrrKey);
}




smpHashLink::smpHashLink(int value, const char* keyFailSign , smpHashLink* next ) {
	head = new smpHashNode(0);
	iMaxKeyNum = 0;
	this->value = value;
	this->keyFailSign = keyFailSign;
	this->next = next;
}
smpHashLink::~smpHashLink() {
	dltAllKey();
	delete head;
}

void smpHashLink::setValue(int value) {
	this->value = value;
}
int smpHashLink::getValue() {
	return value;
}
//重点重载对象
int smpHashLink::isSameValue(int value) {
	if (this->value == value) return 1;
	return 0;
}

void smpHashLink::dltAllKey() {
	smpHashNode* tmp = head->next, * tmr = tmp;
	if (!tmp) return;
	while (tmp = tmp->next) {
		delete tmr;
		tmr = tmp;
	}
	delete tmr;
	iMaxKeyNum = 0;
}
int smpHashLink::getKeyNum() {
	return iMaxKeyNum;
}
int smpHashLink::tryInsertKey(const char* key) {
	smpHashNode* tmp = head;
	while (tmp->next) {
		tmp = tmp->next;
		if (tmp->isSameKey(key))return 0;
	}
	tmp->next = new smpHashNode(key);
	iMaxKeyNum++;
	return 1;
}
int smpHashLink::tryDltKey(const char* key) {
	smpHashNode* tmp = head->next, * tmr = head;
	while (1) {
		if (!tmp) return 0;
		if (tmp->isSameKey(key)) {
			tmr->next = tmp->next;
			delete tmp;
			iMaxKeyNum--;
			return 1;
		}
		tmp = tmp->next;
		tmr = tmp;
	}
}
int smpHashLink::hasKey(const char* key) {
	for (smpHashNode* tmp = head; tmp = tmp->next;)
		if (tmp->isSameKey(key)) return 1;
	return 0;
}
const char* smpHashLink::tryGetKey(int number ) {
	if (number > iMaxKeyNum) return keyFailSign;
	smpHashNode* tmp = head;
	for (int i = 0; i < number; i++)
		tmp = tmp->next;
	return tmp->getKey();
}
int smpHashLink::getAllKeyR(const char**& rtnPrrKey) {
	rtnPrrKey = new  const char* [iMaxKeyNum + 1]{};
	smpHashNode* tmp = head;
	for (int i = 0; tmp = tmp->next; i++) {
		rtnPrrKey[i] = tmp->getKey();
	}
	return iMaxKeyNum;
}







smpHashNode::smpHashNode(const char* key, smpHashNode* next ) {
	this->key = cpyNew(key);
	this->next = next;
}
smpHashNode::~smpHashNode() {
	delete[] key;
}

//重载对象
int smpHashNode::isSameKey(const char* key) {
	if (!cmp(key, this->key))return 1;
	return 0;
}
const char* smpHashNode::getKey() {
	return key;
}
void smpHashNode::setKey(const char* key) {
	this->key = key;
}

