#include"IceUI.h"
#include <iostream>
using namespace std;

void main1();
void main2();
int main()
{
	main2();
}

void main1() {
	mainWindow::setWindowSize(100, 40);
	font::setFontName(L"楷体");
	color::setWord(color::月黄);
	cursor::hideCursor();
	IceUI ice;
	ice.wantChara[28] = 1;
	for (int i = 1; i <= ice.iStartNum; i++)
		ice.wantStart[i] = 1;

	for (int i = 1; i <= ice.iMidNum; i++) 
		ice.wantMid[i] = 1;

	for (int i = 1; i <= ice.iEndNum; i++) 
		ice.wantEnd[i] = 0;

	for (int i = 6; i <=8; i++) 
		ice.wantEnd[i] = 1;
	

	ice.iDelayMin = 0;
	ice.iDelayMax = 1;
	ice.prtIce();
}

void main2() {
	mainWindow::setWindowSize(100, 40);
	font::setFontName(L"楷体");
	
	cursor::hideCursor();
	IceUI ice;
	ice.start_CharaFrame();
}