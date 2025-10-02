#pragma once
#include"d1.h"

void test1();
void test2();

void chushi();
void kaguya();
void kaguyaEnd();

void kaguyaStar();
void kaguya1();
void kaguya2();
void kaguya3();
void kaguya4();
void kaguya5();
void kaguya6();
void kaguya0();//动画用,预算问题，没有全部实用到吧。

void huanghun();
void changmo();

void GlowMoon();
/*for (int a = -1; a != 7; a++)
{
	color(mainColorB, mainColor);
	Sleep(1000);

	//选项模板
	clear(0);
	line(1); blank2(15);
	outODy("蜡烛の设定");
	line(2);
	int i = 4;
	//选项
	blank2(5); outODy("1.点亮蜡烛"); blank2(7); outODy("1.点亮蜡烛"); line(2); i += 2;
	blank2(5); outODy("1.点亮蜡烛"); blank2(7); outODy("1.点亮蜡烛"); line(2); i += 2;
	blank2(5); outODy("1.点亮蜡烛"); blank2(7); outODy("1.点亮蜡烛"); line(2); i += 2;
	blank2(5); outODy("1.点亮蜡烛"); blank2(7); outODy("1.点亮蜡烛"); line(2); i += 2;
	blank2(5); outODy("1.点亮蜡烛"); blank2(7); outODy("1.点亮蜡烛"); line(2); i += 2;

	line(14 - i);
	//提示,共line5

	//输入确认
	a = inIntCan(1, 10, "选择吧", "我是故意的=-=");

	switch (a)
	{
	case 1:light(); break;
	case 2:setMain(); break;
	default:
		break;
	}
}*/

/*

Sleep(1000);

//选项模板
clear(0);
line(1); blank2(15);
outODy("蜡烛の设定");
line(2);
int i = 4;
//选项

blank2(5); outODy("1.蜡烛の支数:"); outODy(num); blank(7);
outODy("2.颜色の设定集");                                      line(2); i += 2;

blank2(5); outODy("3.燃烧の时间:"); outODy(Dy * 6 * times / 1000); blank(7); outODy("4.燃烧の速度:"); outODy(Dy);  line(2); i += 2;
blank2(5); outODy("5.像素の字:  ");
//透明显示
switch (touming)
{
case 1:outODy("全透明     "); break;
case 2:outODy("不显示     "); break;
case 0:outODy("半透明     "); break;
default:
	break;
}
outODy("6.染色の设定:");
switch (act)
{
case 0:outODy("    单色"); break;
case 1:outODy("默认染色"); break;
case 2:outODy("  染色包"); break;
default:
	break;
}
     line(2); i += 2;

blank2(17); outODy("?.为什么要用“の”"); line(2); i += 2;


line(14 - i);
//提示,共line5
blank2(5); outODy("「在染色包模式下的作用比较明显」"); line(1);
		blank2(5); outODy("实际上修改的是每一帧停留的毫秒数,所以数字越大烧"); line(1);
		blank2(5); outODy("得越慢。"); line(1);
		blank2(5); outODy("如果延迟够大的话,可以看到它(们)是怎么燃烧的……"); line(1);
		blank2(5); outODy("再怎么快蜡也不会消耗……"); line(1);

blank2(5);
//输入确认
a = inIntCan(1, 7, "就选它吧の", "并不是没有，只是未开发……");

*/