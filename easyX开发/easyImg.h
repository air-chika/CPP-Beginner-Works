#pragma once
#include<smpSPACE.h>
#include<easyx.h>
using namespace std;

namespace eGraph {
	typedef unsigned int rgb; //color
	typedef const char* name;
	typedef const char* text;
	typedef char* atext;

	namespace Color {
		smpHash<name, unsigned int> colorMap;
		int ColorMap()
		{
			std::ifstream fin("颜色.txt");
			char* name = new char[30]{};
			while (fin >> name) {
				int rgb[3]{};
				for (int i = 0; i < 3; i++)
					fin >> rgb[i];
				colorMap.tryInsert(name, RGB(rgb[0], rgb[1], rgb[2]));
				name = new char[30]{};
			}
			return 1;
		}
		const int JUSTDEFINE = ColorMap();

		//get color name
		name getColorName(const unsigned int number) {
			return colorMap.tryGetKey(number);
		}
		//get color number
		const unsigned int Rgb(name colorName) {
			return colorMap.tryGetValue(colorName);
		}
	}
	using namespace Color;

	LOGFONT font;
	int iTextSizeHei = 30;
	name nameTextStyle = "Source Code Pro Semibold";
	//name nameTextStyle = "楷体";
	void initial(int xmax, int ymax, rgb backColor = Rgb("黑4")) {
		initgraph(xmax, ymax, 1);
		setbkmode(1);
		font.lfHeight = iTextSizeHei;
		smpStr::cpy(font.lfFaceName, nameTextStyle);
		settextstyle(&font);
		setbkcolor(backColor);
		cleardevice();
	}

	void midOutText(text ctt, POINT mid) {
		mid.x -= textwidth(ctt) / 2;
		mid.y -= textheight(ctt) / 2;
		outtextxy(mid.x, mid.y, ctt);
	}

	void workMain() { SetWorkingImage(); }

	class Image {
	public:
		//protected:
		IMAGE* img;
		DWORD* clrBuffer; //double word
		POINT des;
		Image* next;

	public:
		Image(int wid, int hei, rgb bkcolor = 0) {
			img = new IMAGE(wid, hei);
			clrBuffer = GetImageBuffer(img);
			clear(bkcolor);
		}

		void clear(rgb bkcolor) {
			int max = getWid() * getHei();
			for (int i = 0; i < max; i++)
				clrBuffer[i] = BGR(bkcolor);
		}

		virtual void work(int c1 = 1) {
			switch (c1) {
			case 1:
				SetWorkingImage(img);
				break;

			}
		}


		int getWid()const { return img->getwidth(); }
		int getHei()const { return img->getheight(); }
		rgb getpixColor(int x, int y) const { return BGR(clrBuffer[y * getWid() + x]); }
		void setpixColor(int x, int y, rgb color) { clrBuffer[y * getWid() + x] = BGR(color); }
		virtual bool getpixVisible(int x, int y) const { return 1; }

		void setDes(POINT p) { des = p; }
		void setMidDes(POINT p) {
			des = p;
			des.x -= getWid() / 2;
			des.y -= getHei() / 2;
		}


		virtual void load() {}
		void draw() {
			workMain();
			BeginBatchDraw();
			for (int x = 0; x < getWid(); x++)
				for (int y = 0; y < getHei(); y++)
					if (getpixVisible(x, y))
						putpixel(x + des.x, y + des.y, getpixColor(x, y));
			EndBatchDraw();
		}

		void graDraw() {
			workMain();
			BeginBatchDraw();
			for (int y = 0; y < getHei(); y++) {
				for (int x = 0; x < getWid(); x++)
					if (getpixVisible(x, y))
						putpixel(x + des.x, y + des.y, getpixColor(x, y));
				FlushBatchDraw();
				Sleep(10);
			}
			EndBatchDraw();
		}

	};

	class TpImage :virtual public Image {
	public:
		//protected:
		IMAGE* visible;
		DWORD* visBuffer; //double word

	public:
		TpImage(int wid, int hei, rgb bkcolor = 0) :
			Image(wid, hei, bkcolor) {
			visible = new IMAGE(wid, hei);
			visBuffer = GetImageBuffer(visible);
			setTransparent();
		}

		void setTransparent(bool isVisible = 0) {
			int max = getWid() * getHei();
			for (int i = 0; i < max; i++)
				visBuffer[i] = isVisible;
		}
		void setTransparent(rgb chsClr, bool isVisible = 1) {
			int max = getWid() * getHei();
			int a = BGR(clrBuffer[0]);
			for (int i = 0; i < max; i++)
				if (BGR(clrBuffer[i]) == chsClr)
					visBuffer[i] = isVisible;
		}

		void work(int c1_v2 = 1) {
			switch (c1_v2) {
			case 1:
				SetWorkingImage(img);
				break;
			case 2:
				SetWorkingImage(visible);
				break;
			}
		}
		bool getpixVisible(int x, int y) const { return BGR(visBuffer[y * getWid() + x]); }

	};

	class CpImage :virtual public Image {
	public:
		Image* headStack, * endStack;

	public:
		CpImage(int wid, int hei, rgb bkcolor = 0, bool tp0_1 = 0)
			:Image(wid, hei, bkcolor) {
			headStack = endStack = new Image(0, 0);
		}


		Image* getpre(Image& img) {
			for (Image* i = headStack; i->next; i = i->next)
				if (i->next == &img)
					return i;
			return 0;
		}
		void add(Image& img) {
			endStack = endStack->next = &img;
		}
		void add(Image* img) { add(*img); }
		void remove(Image& img) {
			Image* pre = getpre(img);
			if (!pre) return;
			if (pre == headStack)
				endStack = headStack;
			pre->next = img.next;
		}
		void remove(Image* img) { remove(*img); }

		void load() {
			if (!headStack) return;
			for (Image* i = headStack->next; i; i = i->next) {
				i->load();
				//	for (int j = 0; j < getHei(); j++) smpDebug::intpDebug(i->visBuffer + getWid() * j, getWid());
				for (int x = 0, xm = i->getWid(); x < xm; x++)
					for (int y = 0, ym = i->getHei(); y < ym; y++)
						if (i->getpixVisible(x, y))
							setpixColor(x + i->des.x, y + i->des.y, i->getpixColor(x, y));
			}

		}

	};

	class CpTpImage :public CpImage, TpImage {
	public:
		CpTpImage(int wid, int hei, rgb bkcolor = 0) :
			TpImage(wid, hei, bkcolor)
			, CpImage(wid, hei, bkcolor)
			, Image(wid, hei, bkcolor) {}
	};


	class Form :public CpImage {
	private:
		int iLineThick;		//线宽
		int iEveHeight;		//文本高
		int iEveWidth;		//文本长

		int iRowSquare;		//横排网格数
		int iColumnSquare;	//竖排网格数
		int iBlockNum;

		POINT des;

		rgb lineColor;		//线色
		rgb textColor;		//文本色
		rgb fillColor;		//填充色

		TpImage* table;
		TpImage** prrimgText;
		atext* arrText;

		int getSub(int row, int col) { return row + (col - 1) * iRowSquare - 1;; }

		//从0开始
		POINT getmid(int row, int column) {
			POINT p;
			p.x = --row * iEveWidth + (iEveWidth + iLineThick + 1) / 2;
			p.y = --column * iEveHeight + (iEveHeight + iLineThick + 1) / 2;
			return p;
		}
		POINT getmid(int sub) {
			return getmid(sub % iRowSquare + 1, sub / iRowSquare + 1);
		}


	public:
		//排块 列块 块长 块高 线宽 线色 填充色 文本色
		Form(int rowSquare, int columnSquare, int eveWid, int eveHei, int lineThick, rgb lineClr, rgb fill, rgb text) :
			iRowSquare(rowSquare), iColumnSquare(columnSquare), iBlockNum(rowSquare* columnSquare),
			iLineThick(lineThick), iEveWidth(eveWid), iEveHeight(eveHei),
			lineColor(lineClr), fillColor(fill), textColor(text), des{ 0,0 },
			Image(eveWid* rowSquare + lineThick, eveHei* columnSquare + lineThick, fill),
			CpImage(eveWid* rowSquare + lineThick, eveHei* columnSquare + lineThick, fill),
			arrText(new atext[rowSquare * columnSquare]{})
		{
			//制作网格
			table = new TpImage(getWid(), getHei());
			table->work(1);
			setfillcolor(lineColor);
			for (int i = 0; i <= iColumnSquare; i++)
				solidrectangle(0, i* iEveHeight, getWid() - 1, i* iEveHeight + iLineThick - 1);
			for (int i = 0; i <= iRowSquare; i++)
				solidrectangle(i* iEveWidth, 0, i* iEveWidth + iLineThick - 1, getHei() - 1);
			table->setTransparent(lineColor, 1);

			add(table);

			prrimgText = new TpImage * [iBlockNum];
			for (int i = 0; i < iBlockNum; i++) {
				prrimgText[i] = new TpImage(iEveWidth, iEveHeight, textColor);
				prrimgText[i]->work(2);
				settextstyle(iTextSizeHei, 0, nameTextStyle, 0, 0, 0, 0, 0, 0);
				prrimgText[i]->setMidDes(getmid(i));
				add(prrimgText[i]);
			}


		}


		void setText(text tx, int row, int col) {
			int sub = getSub(row, col);
			if (arrText[sub]) {
				prrimgText[sub]->setTransparent();
				delete arrText;
			}
			arrText[sub] = smpStr::cpyNew(tx);
			prrimgText[sub]->work(2);
			settextcolor(1);
			midOutText(tx, { iEveWidth / 2, iEveHeight / 2 });
		}



	};
















	void maxScreen() {
		int rW = GetSystemMetrics(SM_CXSCREEN); // 屏幕宽度 像素
		int rH = GetSystemMetrics(SM_CYSCREEN); // 屏幕高度 像素
		HWND hwnd = initgraph(rW, rH); // 初始化绘图窗口并获取窗口句柄（以 EasyX 为例）
		LONG l_WinStyle = GetWindowLong(hwnd, GWL_STYLE); // 获取窗口信息
		// 设置窗口信息 最大化 取消标题栏及边框
		SetWindowLong(hwnd, GWL_STYLE, (l_WinStyle | WS_POPUP | WS_MAXIMIZE) & ~WS_CAPTION & ~WS_THICKFRAME & ~WS_BORDER);// 直接修改窗口样式
		SetWindowPos(hwnd, HWND_TOP, 0, 0, rW, rH, 0);
	}



};
