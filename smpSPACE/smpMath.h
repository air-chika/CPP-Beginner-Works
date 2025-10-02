#pragma once
#include<iostream>

namespace smpMath {

	int minus_divide2(int op1, int op2);
	int getDigit(int num);
	int getDigit_withSign(int num);
	
	int pow(int base,int power);

	int Anum(int sub, int sup = -1);
	int Cnum(int sub, int sup);

	//¶àÏîÊ½
	struct FunctionNode {
		int power=0;
		int factor=0;
		FunctionNode* next = 0;
	};
	class Function {
	private:
		FunctionNode* head, * end;
	public:
		Function() {
			end = head = new FunctionNode();
		}
		void insert(int factor, int power) {
			end = end->next = new FunctionNode();
			end->factor = factor;
			end->power = power;
		}
		int getResult(int x) {
			int sum = 0;
			for (FunctionNode* p = head; p = p->next;)
				sum += p->factor * pow(x, p->power);
			return sum;
		}
	};
}

class Interval {
public:
	Interval(int min,int max):imin(min),imax(max) {}

	bool inRange(int x) {
		return x >= imin && x <= imax;
	}

private:
	int imin;
	int imax;
};

bool operator==(int x, Interval inter);
bool operator==(Interval inter, int x);