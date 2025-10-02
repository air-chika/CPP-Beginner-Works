#pragma once
#include"smpStr.h"

template<typename Key>
class smpHashNode
{
public:
	smpHashNode(const char* key, smpHashNode* next = 0) {
		this->key = smpStr::cpyNew(key);
		this->next = next;
	}
	/*~smpHashNode() {
		delete key;
	}*/

	//重载对象  模糊查找or精确查找
	bool isSameKey(const char* key) {
		if (smpStr::search(this->key, key))return 1;
		return 0;
	}
	Key getKey() {
		return key;
	}
	/*void setKey(const char* key) {
		this->key = key;
	}*/

	smpHashNode* next;
private:
	Key key;
};


template<typename Key, typename Value>
class smpHashLink
{
	typedef smpHashNode<Key> hashNode;
public:
	smpHashLink(Value value, Key keyFailSign = 0, smpHashLink* next = 0) {
		head = new hashNode(0);
		iMaxKeyNum = 0;
		this->value = value;
		this->keyFailSign = keyFailSign;
		this->next = next;
	}
	~smpHashLink() {
		dltAllKey();
		delete head;
	}

	void setValue(Value value) {
		this->value = value;
	}

	Value getValue() {
		return value;
	}
	//重点重载对象
	bool isSameValue(Value value) {
		if (this->value == value) return 1;
		return 0;
	}

	void dltAllKey() {
		hashNode* tmp = head->next, * tmr = tmp;
		if (!tmp) return;
		while (tmp = tmp->next) {
			delete tmr;
			tmr = tmp;
		}
		delete tmr;
		iMaxKeyNum = 0;
	}
	int getKeyNum() {
		return iMaxKeyNum;
	}
	bool tryInsertKey(Key key) {
		hashNode* tmp = head;
		while (tmp->next) {
			tmp = tmp->next;
			if (tmp->isSameKey(key))return 0;
		}
		tmp->next = new hashNode(key);
		iMaxKeyNum++;
		return 1;
	}
	bool tryDltKey(Key key) {
		hashNode* tmp = head->next, * tmr = head;
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
	bool hasKey(Key key) {
		for (hashNode* tmp = head; tmp = tmp->next;)
			if (tmp->isSameKey(key)) return 1;
		return 0;
	}
	Key tryGetKey(int number = 1) {
		if (number > iMaxKeyNum) return keyFailSign;
		hashNode* tmp = head;
		for (int i = 0; i < number; i++)
			tmp = tmp->next;
		return tmp->getKey();
	}
	int getAllKeyR(Key*& rtnPrrKey) {
		rtnPrrKey = new  Key[iMaxKeyNum + 1]{};
		hashNode* tmp = head;
		for (int i = 0; tmp = tmp->next; i++) {
			rtnPrrKey[i] = tmp->getKey();
		}
		return iMaxKeyNum;
	}

	smpHashLink* next;

private:
	hashNode* head;
	Key keyFailSign;
	int iMaxKeyNum;
	Value value;
};


//每个键对应一个值，但值可以相同
template<typename Key, typename Value>
class smpHash
{
public:
	typedef smpHashLink<Key, Value> hashLink;


	//哈希集以值为一层节点，键为二层节点
	smpHash(Key keyFailSign = 0, Value valueFailSign = 0) {
		iMaxKeyNum = iMaxValueNum = 0;
		this->keyFailSign = keyFailSign;
		this->valueFailSign = valueFailSign;
		head = new hashLink(valueFailSign);
	}
	~smpHash() {
		//clearHash();
		delete head;
	}
	smpHash<Key, Value>& clearHash() {
		hashLink* tmp = head->next, * tmr = tmp;
		while (tmp = tmp->next) {
			delete tmr;
			tmr = tmp;
		}
		delete tmr;
		iMaxValueNum = iMaxValueNum = 0;
		return *this;
	}

	bool tryDltValue(Value value) {
		hashLink* tmp = head->next, * tmr = head;
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
	bool tryInsert(Key key, Value value) {
		hashLink* tmp = head;
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
		tmp->next = new hashLink(value);
		tmp->next->tryInsertKey(key);
		iMaxKeyNum++;
		iMaxValueNum++;
		return 1;
	}
	//返回成功个数
	int tryInsert(Key key[], Value value[], int num) {
		int realIst = 0;
		for (int i = 0; i < num; i++) {
			if (tryInsert(key[i], value[i]))
				realIst++;
		}
		return realIst;
	}


	hashLink* tryGetValueLink(Value value) {
		for (hashLink* tmp = head; tmp = tmp->next;)
			if (tmp->isSameValue(value)) return tmp;
		return 0;
	}
	int tryGetValue(Key key) {
		for (hashLink* tmp = head; tmp = tmp->next;) {
			if (tmp->hasKey(key)) return tmp->getValue();
		}
		return valueFailSign;
	}

	Key tryGetKey(Value value) {
		hashLink* tmp = tryGetValueLink(value);
		if (!tmp) return keyFailSign;
		return tryGetValueLink(value)->tryGetKey();
	}
	int getNewAllKeyR(Value value, Key*& rtnPrrKey) {
		hashLink* tmp = tryGetValueLink(value);
		return tmp->getAllKeyR(rtnPrrKey);
	}


private:
	int iMaxValueNum;
	int iMaxKeyNum;
	Value valueFailSign;
	Key keyFailSign;
	hashLink* head;
};




