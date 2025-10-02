#pragma once
#include<iostream>
using std::ostream;
using std::endl;
using std::cout;

template<class t>
class smpArr {
public:
	int num = 0;
	smpArr(int baseLimit = 10) :limit(baseLimit) {
		head = new t[limit]{};
	}
	~smpArr() { delete[] head; }

	t& operator[](int sub) {
		while (sub >= limit) expand();
		if (sub >= num)num = sub + 1;
		return head[sub];
	}
	template<class t2>
	t& add(const t2& one) {
		if (num >= limit) expand();
		return head[num++] = one;
	}
	t& add() {
		if (num >= limit) expand();
		return head[num++];
	}
	template<class t2>
	t* search(const t2& one)const {
		for (int i = 0; i < num; i++) {
			if (head[i] == one)
				return head + i;
		}
		return 0;
	}

	template<class t2>
	int remove(const t2& one) {
		t* i = search(one);
		if (!i) return 0;
		num--;
		for (; i < head + num; i++)
			*t = *(t + 1);
		return 1;
	}

	template<class t2>
	t* setAdd(const t2& one) {
		t* p = search(one);
		if (!p)
			return &(add(one));
		return p;
	}

	int getSub(t* one) {
		return int(one - head);
	}

	smpArr& operator=(const smpArr& arr) {
		while (arr.limit > limit) expand();
		for (int i = 0; i < arr.num; i++)
			head[i] = arr.head[i];
		num = arr.num;
		return *this;
	}

	void reset() {
		delete[] head;
		limit = 10;
		num = 0;
		head = new t[limit]{};
	}

	void sort(int (*cmp)(const void* a, const void* b)) {
		std::qsort(head, num, sizeof(*head), cmp);
	}

	class iterator {
		friend class smpArr;
	public:
		iterator(const iterator& ite) { tmp = ite.tmp; }
		iterator(t* const head) { tmp = head; }
		void operator++(int) { tmp++; }
		t* operator->()const { return tmp; }
		t& operator*()const { return *tmp; }
	private:
		t* tmp;
	};
	iterator begin() {
		return iterator(head);
	}
	bool end(iterator& tmp) {
		if (tmp.tmp == head + num)
			return 0;
		return 1;
	}

protected:
	t* head;
private:
	int limit;
	void expand() {
		t* old = head;
		head = new t[limit * 2]{};
		for (int i = 0; i < limit; i++)
			head[i] = old[i];
		delete[] old;
		limit *= 2;
	}
};

template<class t>
ostream& operator<<(ostream& out, smpArr<t>& arr) {
	for (int i = 0; i < arr.num; i++)
		out << arr[i] << ' ';
	out << arr.num << "\n\n";
	return out;
}