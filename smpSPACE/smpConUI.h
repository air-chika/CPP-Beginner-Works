#pragma once
#include <iostream>
#include<Windows.h>
#include<conio.h>
#include"smpStr.h"
#include"smpArr.h"
#include"smpHash.h"

namespace smpConUI
{
	//����̨��ɫ
	class conColor {
	public:
		conColor(int i = 15) { id = i; }
		conColor(cstr colorname);
		operator int()const { return id; }
	private:
		int id;
	};
	//����̨��ɫ+�ַ��� C:console,color
	class smpCstr :public smpAstr {
	public:
		smpCstr() { setMainColor(); }
		template<class t>
		smpCstr(const t& str) : smpAstr(str) { setMainColor(); }
		smpCstr& setMainColor();
		smpCstr& setColor(conColor color) { strColor = color; return *this; }
		conColor getColor()const { return strColor; }
	private:
		conColor strColor;
	};
	class smpCstrSet :public smpArr<smpCstr> {
	public:
	};

	void initUI(int wid = 100, int hei = 40, conColor textClr = 15);

	namespace mainWindow {
		void setWindowSize(int  wid, int hei);
		void setWindowSize(int  wid, int hei, int bufferHei);
		int getMainWide();
		int getMainHeight();
	}
	namespace cursor {
		//λ�ô�1��ʼ
		void hideCursor();
		void unhideCursor();
		COORD getCursor();
		void setCursor(COORD);
	}
	namespace font {
		void font();
		void setHeight(int num);
		void setMaxScreenHeight(int maxLine);
		void setFontName(const wchar_t*);
	}
	namespace color
	{
		enum colorname
		{
			���� = 1, ��� = 1, �� = 1,
			����, ���� = 2, �� = 2,
			����, ���� = 3, �� = 3,
			���� = 4,
			����, ��� = 5, �� = 5,
			����, ���� = 6, �� = 6,
			�ػ� = 7,
			����, Ĭ�� = 8,
			��� = 9,
			���� = 10,
			����, ���� = 11,
			����, ���� = 12,
			�ۺ� = 13,
			�Ϻ�, Ʒ�� = 14,
			�»�, ���� = 15, ���� = 15,
			���� = 16
		};


		void setWordBack(const conColor word, const conColor back);
		void setWord(const conColor word);
		void setBack(const conColor back);
		void setBlank(const conColor word);
		void setAll(const conColor word, const conColor back);

	}

	namespace out {
		void clear();
		void setHeadBlank(int); //ÿ�ж���ճ�
		void setLineNum(int); //ÿ�ж���ճ�
		void setSleepTime(int dy);
		void setOstream(std::ostream&);
		void setMainTextColor(conColor clrName);
		conColor getMainTextColor();

		void spaceLn(int num);
		void outln(const smpCstr& str);
		void outln(smpCstrSet& str);
		void outlnMid(const smpCstr& str);
		void outlnMid(smpCstrSet& str);
		void outend(const smpCstr& str);

	}

	namespace in {
		int scanInt();
		char* scanStr();
		//��bc����0,esc����-1,�Զ�ʶ��λ��
		int getChoice(int maxallowed);
		int getchDirection();
	}

	class ChooseBox {
	public:
		ChooseBox() { ichoosing = 0; }

		void add();
		void go();

	private:
		smpCstrSet option;
		int ichoosing;
	};



}


//enum colorname
//{
//	���� = 1, ��� = 1, �� = 1,
//	����, ���� = 2, �� = 2,
//	����, ���� = 3, �� = 3,
//	���� = 4,
//	����, ��� = 5, �� = 5,
//	����, ���� = 6, �� = 6,
//	�ػ� = 7,
//	����, Ĭ�� = 8,
//	��� = 9,
//	���� = 10,
//	����, ���� = 11,
//	����, ���� = 12,
//	�ۺ� = 13,
//	�Ϻ�, Ʒ�� = 14,
//	�»�, ���� = 15, ���� = 15,
//	���� = 16
//};