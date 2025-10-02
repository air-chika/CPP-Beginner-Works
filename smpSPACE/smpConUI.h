#pragma once
#include <iostream>
#include<Windows.h>
#include<conio.h>
#include"smpStr.h"
#include"smpArr.h"
#include"smpHash.h"

namespace smpConUI
{
	//控制台颜色
	class conColor {
	public:
		conColor(int i = 15) { id = i; }
		conColor(cstr colorname);
		operator int()const { return id; }
	private:
		int id;
	};
	//控制台颜色+字符串 C:console,color
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
		//位置从1开始
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
			纯黑 = 1, 深黑 = 1, 黑 = 1,
			纯蓝, 深蓝 = 2, 蓝 = 2,
			纯绿, 深绿 = 3, 绿 = 3,
			天蓝 = 4,
			纯红, 深红 = 5, 红 = 5,
			纯紫, 深紫 = 6, 紫 = 6,
			棕黄 = 7,
			淡灰, 默认 = 8,
			深灰 = 9,
			湖蓝 = 10,
			草绿, 鲜绿 = 11,
			冰蓝, 蓝绿 = 12,
			粉红 = 13,
			紫红, 品红 = 14,
			月黄, 亮黄 = 15, 明黄 = 15,
			纯白 = 16
		};


		void setWordBack(const conColor word, const conColor back);
		void setWord(const conColor word);
		void setBack(const conColor back);
		void setBlank(const conColor word);
		void setAll(const conColor word, const conColor back);

	}

	namespace out {
		void clear();
		void setHeadBlank(int); //每行都会空出
		void setLineNum(int); //每行都会空出
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
		//遇bc返回0,esc返回-1,自动识别位数
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
//	纯黑 = 1, 深黑 = 1, 黑 = 1,
//	纯蓝, 深蓝 = 2, 蓝 = 2,
//	纯绿, 深绿 = 3, 绿 = 3,
//	天蓝 = 4,
//	纯红, 深红 = 5, 红 = 5,
//	纯紫, 深紫 = 6, 紫 = 6,
//	棕黄 = 7,
//	淡灰, 默认 = 8,
//	深灰 = 9,
//	湖蓝 = 10,
//	草绿, 鲜绿 = 11,
//	冰蓝, 蓝绿 = 12,
//	粉红 = 13,
//	紫红, 品红 = 14,
//	月黄, 亮黄 = 15, 明黄 = 15,
//	纯白 = 16
//};