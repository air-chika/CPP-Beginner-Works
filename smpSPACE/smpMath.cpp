#include"smpMath.h"

namespace smpMath {

	int minus_divide2(int op1, int op2) {
		return (op1 - op2) / 2;
	}

	int getDigit(int num) {
		//if (num == 0) return 0;
		int dig = 1;
		while (num /= 10)
			dig++;
		return dig;
	}
	int getDigit_withSign(int num) {
		int dig = getDigit(num);
		if (num < 0) dig++;
		return dig;
	}

	int pow(int base, int power)
	{
		return int(std::pow(base, power));
	}


	int Anum(int sub, int sup) {
		if (sub == 0 || sup == 0) return 1;
		if (sup < 0) sup = sub;
		int sub2 = sub - 1;
		for (int i = 1; i < sup; i++)
			sub *= sub2--;
		return sub;
	}

	int Cnum(int sub, int sup) {
		if (sup > sub / 2) sup = sub - sup;
		return Anum(sub, sup) / Anum(sup);
	}

}

bool operator==(int x, Interval inter) {
	return inter.inRange(x);
}
bool operator==(Interval inter, int x) {
	return inter.inRange(x);
}