#include"smpDebug.h"
#include<conio.h>
using namespace std;
using namespace smpMath;
using namespace smpStr;
constexpr int TAB = 1;

namespace smpDebug {

	void intpDebug(int* arr, int num) {
		smpAstr smp, reg;
		int* dgt = new int[num] {};
		for (int i = 0; i < num; i++)
			dgt[i] = max(getDigit_withSign(arr[i]), getDigit_withSign(i));

		cout << "\n#数组debug.START\n";
		smp.addbl(len("int[]="));
		for (int i = 0; i < num; i++)
			smp.addRightInBlank(i, dgt[i]+ TAB);
		cout << smp.addln(1).getBuffer();

		smp.set0().add("int[]=");
		for (int i = 0; i < num; i++)
			smp.addRightInBlank(arr[i], dgt[i]+ TAB);
		cout << smp.addln(1).getBuffer();

		cout << "#数组debug.END .getch";
		int debug = _getch();
		cout << "\n\n";
		delete[] dgt;
	}

	void intpDebug(unsigned long* arr, int num) {
		int* debug=new int[num];
		for (int i = 0; i < num; i++)
			debug[i] = arr[i];
		smpDebug::intpDebug(debug, num);
		delete[] debug;
	}

	void intppDebug(int** arrr, int len1, int len2) {
		smpAstr smp;
		int dgt1 = getDigit_withSign(len1 - 1);
		int* dgt = new int[len2] {};
		for (int i = 0; i < len2; i++) {
			dgt[i] = getDigit_withSign(i);
			for (int j = 0; j < len1; j++)
				dgt[i] = max(getDigit_withSign(arrr[j][i]), dgt[i]);
		}

		cout << "\n#二维数组[y][x]debug.START\n";
		smp.addbl(dgt1);
		for (int i = 0; i < len2; i++)
			smp.addRightInBlank(i, dgt[i] + TAB);
		cout << smp.addln(1).getBuffer();

		for (int i = 0; i < len1; i++) {
			smp.set0().addRightInBlank(i, dgt1);
			for (int j = 0; j < len2; j++)
				smp.addRightInBlank(arrr[i][j], dgt[j] + TAB);
			cout << smp.addln(1).getBuffer();
		}
		cout << "#二维数组[y][x]debug.END .getch";
		int debug = _getch();
		cout << "\n\n";
		delete[] dgt;
	}

}