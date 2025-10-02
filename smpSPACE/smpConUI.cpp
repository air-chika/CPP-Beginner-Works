#include"smpConUI.h"
using namespace std;

using namespace smpConUI;
using namespace mainWindow;
using namespace cursor;
using namespace in;
using namespace out;
using namespace color;



namespace smpConUI
{

	namespace mainWindow {

		int iMainWindowHeight = 0;
		int iMainWindowWidth = 0;
		void setWindowSize(int  wid, int hei)
		{
			setWindowSize(wid, hei, 9000);
		}
		void setWindowSize(int  wid, int hei, int bufferHei)
		{
			iMainWindowWidth = wid;
			iMainWindowHeight = hei;
			char chCmd[32];
			sprintf_s(chCmd, "mode con cols=%d lines=%d", iMainWindowWidth, iMainWindowHeight);
			system(chCmd);
			//����������:
			SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), { short(iMainWindowWidth),short(bufferHei) });
		}
		int getMainWide() { return iMainWindowWidth; }
		int getMainHeight() { return iMainWindowHeight; }

	}

	namespace cursor {
		void hideCursor() {
			CONSOLE_CURSOR_INFO info = { 1, 0 };
			SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
		}
		void unhideCursor() {
			CONSOLE_CURSOR_INFO info = { 1, 1 };
			SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
		}

		COORD getCursor() {
			CONSOLE_SCREEN_BUFFER_INFO csbi;
			GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
			return csbi.dwCursorPosition;
		}
		void setCursor(COORD pos) {
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
		}

	}

	namespace color
	{

		smpHash<const char*, int> colorMap;

		void ColorMap()
		{
			const char* colorKey[30] = \
			{"����", "����", "����", "����", "����", "����", "�ػ�", "����", "���", "����"\
				, "����", "����", "�ۺ�", "Ʒ��", "�»�", "����"};
			int  colorValue[16]{};
			for (int i = 0; i < 16; i++) colorValue[i] = i + 1;
			colorMap.tryInsert(colorKey, colorValue, 16);
			colorMap.tryInsert("���", 1);
			colorMap.tryInsert("��", 1);
			colorMap.tryInsert("����", 2);
			colorMap.tryInsert("��", 2);
			colorMap.tryInsert("����", 3);
			colorMap.tryInsert("��", 3);
			colorMap.tryInsert("���", 5);
			colorMap.tryInsert("��", 5);
			colorMap.tryInsert("����", 6);
			colorMap.tryInsert("��", 6);
			colorMap.tryInsert("ϵͳ����", 8);
			colorMap.tryInsert("����", 11);
			colorMap.tryInsert("����", 12);
			colorMap.tryInsert("Ʒ��", 14);
			colorMap.tryInsert("�»�", 15);
			colorMap.tryInsert("����", 15);
		}

		const char* getColorName(const int number) {
			return colorMap.tryGetKey(number);
		}
		const int getColorNumber(const char* cstr) {
			return colorMap.tryGetValue(cstr);
		}

		//private
		HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
		int nowword = �»�, nowbg = ��, nowmainbg = ��;
		//int blankturn;
		void paintword() {
			SetConsoleTextAttribute(hCon, (nowword - 1) + (nowbg - 1) * 16);
		}
		void paintblank() {
			SetConsoleTextAttribute(hCon, (nowword - 1) * 16);
		}



		//public
		void setWordBack(const conColor word, const conColor back)
		{
			if (word)
				nowword = word;
			if (back)
				nowbg = back;
			paintword();
		}
		void setWord(const conColor word)
		{
			if (word)
				nowword = word;
			paintword();
		}
		void setBack(const conColor back)
		{
			if (back)
				nowbg = back;
			paintword();
		}
		void setBlank(const conColor word)
		{
			if (word)
				nowword = word;
			paintblank();
		}
		void setAll(const conColor word, const conColor back)
		{
			nowword = word;
			nowmainbg = back;
			char a[10] = "color 00";
			sprintf_s(a, 10, "color %x%x", nowmainbg - 1, nowword - 1);//�ȱ�����������
			system(a);
		}

	}

	conColor::conColor(cstr colorname) { id = color::getColorNumber(colorname); }
	smpCstr& smpCstr::setMainColor() { strColor = getMainTextColor(); return *this; }

	namespace out {
		void clear() { system("cls"); }
		char hb[41] = "   "; //headBlank Ĭ��3��
		char ln[21] = "\n"; //line Ĭ��һ�λ���
		int delay;
		conColor textMainColor;
		ostream* pout = &cout;

		int getMidx(int len) { return 1 + (iMainWindowWidth - len) / 2; }
		int getMidy(int height) { return 1 + (iMainWindowHeight - height) / 2; }
		void setHeadBlank(int num) { smpAstr().addbl(num).getCpy(hb); } //���40��
		void setLineNum(int num) { smpAstr().addln(num).getCpy(ln); } //���20��
		void setOstream(std::ostream& out) { pout = &out; }
		void setSleepTime(int dy) { delay = dy; }
		void setMainTextColor(conColor clrName) {
			textMainColor = clrName;
		}
		conColor getMainTextColor() {
			return textMainColor;
		}

		void spaceLn(int num) {
			*pout << smpAstr().addln(num);
		}


		void outln(const smpCstr& str) {
			setWord(str.getColor());
			*pout << hb << str << ln;
			Sleep(delay);

		}
		void outln(smpCstrSet& str) {
			*pout << hb;
			for (int i = 0; i < str.num; i++) {
				setWord(str[i].getColor());
				*pout << str[i];
			}
			*pout << ln;
			Sleep(delay);
		}
		void outlnMid(const smpCstr& str) {
			int len = str.getLen();
			setWord(str.getColor());
			*pout << smpAstr().addbl((getMainWide() - len) / 2) << str << ln;
		}
		void outlnMid(smpCstrSet& str) {
			int len = 0;
			for (int i = 0; i < str.num; i++)
				len += str[i].getLen();
			*pout << smpAstr().addbl((getMainWide() - len) / 2);

			for (int i = 0; i < str.num; i++) {
				setWord(str[i].getColor());
				*pout << str[i];
			}
			*pout << ln;
			Sleep(delay);
		}
		void outend(const smpCstr& str) {
			setWord(str.getColor());
			*pout << hb << str;
			Sleep(delay);
		}

	}
	namespace in {

		void clearLine(COORD p) {
			cout << smpAstr().addbl(iMainWindowWidth - p.X);
			setCursor(p);
		}

		//����Դ
		//��bc����0,esc(�˳�����?����������),�����ȡָ������,�Զ�ʶ��λ��
		int scanInt() {
			COORD pos = getCursor();
			unhideCursor();
			int i = 0;
			while (!(cin >> i)) {
				cin.clear();
				cin.ignore(5000, '\n');
				setCursor(pos);
				clearLine(pos);
			}
			cin.ignore(5000, '\n');
			hideCursor();
			return i;
		}
		char* scanStr() {
			unhideCursor();
			char* str = new char[300] {};
			cin >> str;
			cin.ignore(5000, '\n');
			hideCursor();
			return str;
		}
		void scanStr(char* str) {
			unhideCursor();
			cin >> str;
			cin.ignore(5000, '\n');
			hideCursor();
		}
		int getChoice(int maxallowed)
		{
			if (maxallowed == 0) {
				while (1) {
					int c = _getch();
					if (c == 8) return 0;
					if (c == 27) {
						exit(0);//return -1;
						getChoice(0);
					}
					if (c == 13) return 0;
				}
			}
			int digit = 1;
			for (int i = maxallowed; i /= 10;)
				digit++;

			int* c = new int[digit] {};
			while (1) {
				int sum = 0;
				for (int i = 0; 1; i++) {
					c[i] = _getch();
					if (c[i] == 8) {
						delete[]c;
						return 0;
					}
					if (c[i] == 27) {
						delete[]c;
						//return -1;
						exit(0);
					}
					if (c[i] == 13) {
						if (sum > 0 && sum <= maxallowed) {
							delete[]c;
							return sum;
						}
						else break;
					}
					sum *= 10;
					c[i] -= '0';
					if (!(c[i] >= 0 && c[i] < 10))
						break;
					sum += c[i];
					if (i == digit - 1) {
						if (sum > 0 && sum <= maxallowed) {
							delete[]c;
							return sum;
						}
						else break;
					}
				}
			}
		}
		//����ֵ:����=2468,enter=5,space=1,esc=7,bc=9,pgup=18,pgdn=12
		int getchDirection() {
			while (1) {
				char c = _getch(), c2 = 0;
				if (c < 0)	c2 = _getch();
				switch (c) {
				case 8:return 9;	//BackSpace
				case 13:return 5;	//enter
				case 27:return 7;	//esc
				case 'w':return 8;
				case 's':return 2;
				case 'a':return 4;
				case 'd':return 6;
				case ' ':return 1;	//space
				case -32:
					switch (c2) {
					case 72:return 8; //up
					case 80:return 2; //down
					case 75:return 4; //left
					case 77:return 6; //right

					case 73:return 18; //pgup
					case 81:return 12; //pgdn
					default:
						break;
					}
				default:
					break;
				}
			}
		}

	}

	namespace font
	{
		//private
		CONSOLE_FONT_INFOEX cfi;
		void font()
		{
			cfi.cbSize = sizeof cfi;
			cfi.nFont = 0;
			cfi.dwFontSize.X = 0; //�ֿ�
			cfi.dwFontSize.Y = 23;//�ָ�
			cfi.FontFamily = FF_DONTCARE;
			cfi.FontWeight = FW_BOLD;//��ϸ
			wcscpy_s(cfi.FaceName, L"����");
			SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
		}

		//public
		void setMaxScreenHeight(int maxLine) {
			int winHeight = GetSystemMetrics(SM_CYFULLSCREEN);
			setHeight(winHeight / maxLine);
		}

		void setHeight(int iMainWindowHeight)
		{
			cfi.dwFontSize.Y = iMainWindowHeight;
			SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
		}

		void setFontName(const wchar_t* cstr)
		{
			wcscpy_s(cfi.FaceName, cstr);
			SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
		}

	}

	void initUI(int wid, int hei, conColor textClr) {
		font::font();
		color::ColorMap();
		mainWindow::setWindowSize(wid, hei);
		textMainColor = textClr;
	}
	void ChooseBox::add() {
	}

	void ChooseBox::go() {

	}

}

namespace frame {
	//�������
	//	cout << "�������X�[�T�W�Z�V�Y\n"; ��
	//	cout << "�������^�a�U�]�`�\�_\n"; 6(12)��ģ��
		//���������ռ����������
		//���˸�
		//char* ul, * ur, * dl, * dr, * up, * down, * left, * right;
		//���ϣ����ϣ����£����£����ϣ��ң���

	char full[8][3]{ "bb","bb","bb","bb","bb","bb","bb","bb" };
	char singleline[8][3]{ "��","��","��","��","��","��","��","��" };
	char doubleline[8][3]{ "�X","�[","�^","�a","�U","�T","�U","�T" };
	char highdoubleline[8][3]{ "�W","�Z","�]","�`","�U","��","�U","��" };
	char widedoubleline[8][3]{ "�V","�Y","�\","�_","��","�T","��","�T" };
	char fullcorners[8][3]{ "bb","bb","bb","bb","|","��"," |","��" };

	int boardtransform(const char a[])
	{
		if (strcmp(a, "�հ�") == 0) return 0;
		if (strcmp(a, "����") == 0) return 1;
		if (strcmp(a, "�Ľ�������") == 0) return 2;
		if (strcmp(a, "�Ľ���������") == 0) return 3;

		if (strcmp(a, "����") == 0) return 4;
		if (strcmp(a, "˫��") == 0) return 5;
		if (strcmp(a, "����˫��") == 0) return 6;
		if (strcmp(a, "����˫��") == 0) return 7;
		if (strcmp(a, "KOHAtest1") == 0) return 8;
		return 0;
	}

	char* boardtransform(int num, char* a)
	{
		switch (num)
		{
		case 0:strcpy_s(a, 5, "�հ�");; break;
		case 1:strcpy_s(a, 5, "����");; break;
		case 2:strcpy_s(a, 5, "�Ľ�������");; break;
		case 3:strcpy_s(a, 5, "�Ľ���������");; break;

		case 4:strcpy_s(a, 5, "����");; break;
		case 5:strcpy_s(a, 5, "˫��");; break;
		case 6:strcpy_s(a, 5, "����˫��");; break;
		case 7:strcpy_s(a, 5, "����˫��");; break;
		case 8:strcpy_s(a, 5, "KOHAtest1");; break;
		default:
			break;
		}
		return a;
	}
}

