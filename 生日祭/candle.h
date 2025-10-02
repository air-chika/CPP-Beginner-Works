#pragma once
#include"d1.h"
#include"d2.h"
using namespace std;

//void chooseInt(int num1, int num2, const char a[]);
void cakeDy();
void cake1();
void cake2();
void cake3();
void cakePan();

class candle
{
public:

	candle()
	{
		for (int i = 0; i < 50; i++)
		{
			act1[i] = -1;
			act2[i] = -1;
		}
	}

	void test()
	{
		Dy = 92;
		times = 9;
		num = 4;
		colorf = 14;
		colorBack = 1;
		endColor = 14;
		endColorB = 0;
		touming = 0;//0半透明，1透明,2不透明
		act = 0;//0无炫彩，1炫彩,2染色包
		//蜡烛色
		act1[0] = 7; act1[1] = 14;
		//背景色
		act2[0] = 0;
	}

	void chuhaoji()
	{
		Dy = 92;
		times = 9;
		num = 1;
		colorf = 7; 
		colorBack = 0;
		endColor = 14;
		endColorB = 0;
		touming = 2;//0半透明，1透明,2不透明
		act = 0;//0无炫彩，1炫彩,2染色包
		//蜡烛色
		 act1[0] = 7; act1[1] = 14; 
		//背景色
		 act2[0] = 0; 
	}  
	void fenbing()
	{
		Dy = 92;
		times = 9;
		num = 5;
		colorf = 11;
		colorBack = 12;
		endColor = 15;
		endColorB = 12;
		touming = 0;//0半透明，1透明,2不透明
		act = 0;//0无炫彩，1炫彩,2染色包
		//蜡烛色
		act1[0] = 1; act1[1] = 13; act1[2] = 1; act1[3] = 13;
		//背景色
		act2[0] = 12;  act2[1] = 4; act2[2] = 4; act2[3] = 12;
	}
	void mofa()
	{
		Dy = 92;
		times = 9;
		num = 5;
		colorf = 5;
		colorBack = 7;
		endColor = 5;
		endColorB = 7;
		touming = 0;//0半透明，1透明,2不透明
		act = 0;//0无炫彩，1炫彩,2染色包
		//蜡烛色
		act1[0] = 5; 
		//背景色
		act2[0] = 7; 
	}
	void yueshi()
	{
		Dy = 92;
		times = 9;
		num = 2;
		colorf = 0;
		colorBack = 15;
		endColor = 0;
		endColorB = 15;
		touming = 2;//0半透明，1透明,2不透明
		act = 0;//0无炫彩，1炫彩,2染色包
		//蜡烛色
		act1[0] = 0; act1[1] = 0; act1[2] = 16;
		//背景色
		act2[0] = 15;
	}
	void dingning()
	{
		Dy = 92;
		times = 9;
		num = 5;
		colorf = 6;
		colorBack = 11;
		endColor = 11;
		endColorB = 0;
		touming = 0;//0半透明，1透明,2不透明
		act = 0;//0无炫彩，1炫彩,2染色包
		//蜡烛色
		act1[0] = 6;
		//背景色
		act2[0] = 11;
	}
	void hupo()
	{
		Dy = 92;
		times = 9;
		num = 2;
		colorf = 12;
		colorBack = 6;
		endColor = 4;
		endColorB = 6;
		touming = 1;
		act = 0;//0无炫彩，1炫彩,2染色包
		//蜡烛色
		act1[0] = 12; act1[1] = 1; act1[2] = 6; act1[3] = 8;
		//背景色
		act2[0] = 0; act2[1] = 5; act2[2] = 13; act2[3] = 12;
	}
	void feicui()
	{
		Dy = 92;
		times = 9;
		num = 2;
		colorf = 4;
		colorBack = 9;
		endColor = 4;
		endColorB = 1;
		touming = 1;
		act = 0;//0无炫彩，1炫彩,2染色包
		//蜡烛色
		act1[0] = 12; act1[1] = 7; act1[2] = 1; act1[3] = 15;
		//背景色
		act2[0] = 9; 
	}
	void youyan()
	{
		Dy = 92;
		times = 9;
		num = 3;
		colorf = 4;
		colorBack = 15;
		endColor = 0;
		endColorB = 15;
		touming = 1;
		act = 0;//0无炫彩，1炫彩,2染色包
		//蜡烛色
		act1[0] = 4; act1[1] = 12; act1[2] = 13; act1[3] = 5;
		//背景色
		act2[0] = 15;
	}
	void ciel()
	{
		Dy = 92;
		times = 9;
		num = 3;
		colorf = 1;
		colorBack = 0;
		endColor = 1;
		endColorB = 15;
		touming = 1;
		act = 0;//0无炫彩，1炫彩,2染色包
		//蜡烛色
		act1[0] = 1; act1[1] = 9; act1[2] = 3; act1[3] = 11;
		//背景色
		act2[0] = 8; act2[1] = 7; act2[2] = 9; act2[3] = 1;
	}
	//8


	void haiyuezhu()
	{
		Dy = 92;
		times = 9;
		num = 5;
		colorf = 14;
		colorBack = 1;//??
		endColor = 14;
		endColorB = 1;
		touming = 0;//0半透明，1透明,2不透明
		act = 0;//0无炫彩，1炫彩,2染色包
		//蜡烛色
		act1[0] = 14;
		//背景色
		act2[0] = 1; act2[1] = 9;
	}
	void mengyuechao()

	{
		Dy = 92;
		times = 9;
		num = 3;
		colorf = 14;
		colorBack = 12;
		endColor = 14;
		endColorB = 12;
		touming = 0;
		act = 2;//0无炫彩，1炫彩,2染色包
		//蜡烛色
		act1[0] = 14;
		//背景色
		act2[0] = 0; act2[1] = 8; act2[2] = 7;
	}
	void rixiangzhimeng()
	{
		Dy = 92;
		times = 9;
		num = 5;
		colorf = 14;
		colorBack = 2;
		endColor = 14;
		endColorB = 2;
		touming = 0;
		act = 2;//0无炫彩，1炫彩,2染色包
		//蜡烛色
		act1[0] = 4; act1[1] = 1; act1[2] = 6; act1[3] = 7; act1[4] = 10; 
		//背景色
		act2[0] = 2; 
	}
	void zhenzhouzhiyue()
	{
		Dy = 92;
		times = 9;
		num = 4;
		colorf = 15;
		colorBack = 3;
		endColor = 12;
		endColorB = 3;
		touming = 2;
		act = 2;//0无炫彩，1炫彩,2染色包
		//蜡烛色
		act1[0] = 8; 
		//背景色
		act2[0] = 0; act2[1] = 1; act2[2] = 9; 

	}
	void limingzhiyue()
	{
		Dy = 92;
		times = 9;
		num = 5;
		colorf = 1;
		colorBack = 9;
		endColor = 14;
		endColorB = 9;
		touming = 2;
		act = 2;//0无炫彩，1炫彩,2染色包
		//蜡烛色
		act1[0] = 1; act1[1] = 9; act1[2] = 3;

		//背景色
		act2[0] = 9; act2[1] = 3;  act2[2] = 1;
	}
	void jinhexinnian()
	{
		Dy = 92;
		times = 9;
		num = 5;
		colorf = 12;
		colorBack = 1;
		endColor = 14;
		endColorB = 1;
		touming = 0;
		act = 0;//0无炫彩，1炫彩,2染色包
		//蜡烛色
		act1[0] = 12; 
		//背景色
		act2[0] = 1; 
	}
	void yuezhishanhu()
	{
		Dy = 92;
		times = 9;
		num = 5;
		colorf = 14;
		colorBack = 9;
		endColor = 14;
		endColorB = 9;
		touming = 0;
		act = 2;//0无炫彩，1炫彩,2染色包
		//蜡烛色
		act1[0] = 14; act1[1] = 9; 
		//背景色
		act2[0] = 9; act2[1] = 14;
	}
	void Arcueid()
	{
		Dy = 92;
		times = 9;
		num = 2;
		colorf = 14;
		colorBack = 3;
		endColor = 6;
		endColorB = 3;
		touming = 1;
		act = 0;//0无炫彩，1炫彩,2染色包
		//蜡烛色
		act1[0] = 6; act1[1] = 4; act1[2] = 15; act1[3] = 12;
		//背景色
		act2[0] = 0; act2[1] = 8; act2[2] = 7; act2[3] = 15;
	}
	//8

	void geyueshiye()
	{
		Dy = 92;
		times = 9;
		num = 5;
		colorf = 14;
		colorBack = 6;
		endColor = 8;
		endColorB = 6;
		touming = 0;
		act = 0;//0无炫彩，1炫彩,2染色包
		//蜡烛色
		act1[0] = 14; 
		//背景色
		act2[0] = 6; act2[1] = 15; act2[2] = 3; act2[3] = 12; act2[4] = 4; act2[5] = 8; act2[6] = 0; act2[7] = 8;
	}
	void chizhiguishen()
	{
		Dy = 92;
		times = 9;
		num = 3;
		colorf = 4;
		colorBack = 0;
		endColor = 4;
		endColorB = 0;
		touming = 2;//0半透明，1透明,2不透明
		act = 0;//0无炫彩，1炫彩,2染色包
		//蜡烛色
		act1[0] = 4; 
		//背景色
		act2[0] = 0;

	}
	void zhuhongzhiyue()
	{
		Dy = 92;
		times = 9;
		num = 1;
		colorf = 14;
		colorBack = 4;
		endColor = 14;
		endColorB = 4;
		touming = 0;//0半透明，1透明,2不透明
		act = 2;//0无炫彩，1炫彩,2染色包
		//蜡烛色
		act1[0] = 8; act1[1] = 7; act1[2] = 14; act1[3] = -1; act1[4] = -1;
		//背景色
		act2[0] = 4;
	}
	void huanghuncaoyue()
	{
		Dy = 92;
		times = 9;
		num = 5;
		colorf = 8;
		colorBack = 6;
		endColor = 4;
		endColorB = 6;
		touming = 1;//0无炫彩，1炫彩,2染色包
		act = 0;//0无炫彩，1炫彩,2染色包
		//蜡烛色
		act1[0] = 8; act1[1] = 14; act1[2] = 12; act1[3] = -1; act1[4] = -1;
		//背景色
		act2[0] = 6; act2[1] = 6; act2[2] = 6; act2[3] = 6; act2[4] = 3; act2[5] = 3; act2[6] = 3; act2[7] = 3;
	}
	void xiaodaixianhua()
	{
		Dy = 92;
		times = 9;
		num = 5;
		colorf = 14;
		colorBack = 0;
		endColor = 14;
		endColorB = 0;
		touming = 0;
		act = 0;//0无炫彩，1炫彩,2染色包
		//蜡烛色
		act1[0] = 14; 
		//背景色
		act2[0] = 0; act2[1] = 1; 

	}
	void kisstheinfinitedream()
	{
		Dy = 92;
		times = 9;
		num = 5;
		colorf = 6;
		colorBack = 8;
		endColor = 6;
		endColorB = 8;
		touming = 1;
		act = 2;//0无炫彩，1炫彩,2染色包
		//蜡烛色
		act1[0] = 12; act1[1] = 13; act1[2] = 9;  act1[3] = 8;
		//背景色
		act2[0] = 4; act2[1] = 5; act2[2] = 1;  act2[3] = 0;
	}
	void kongzhijingjie()
	{
		Dy = 92;
		times = 9;
		num = 3;
		colorf = 8;
		colorBack = 14;
		endColor = 15;
		endColorB = 14;
		touming = 0;
		act = 0;//0无炫彩，1炫彩,2染色包
		//蜡烛色
		act1[0] = 15; act1[1] = 6; 
		//背景色
		act2[0] = 14; 
	}
	void ROA()
	{
		Dy = 92;
		times = 9;
		num = 1;
		colorf = 5;
		colorBack = 0;
		endColor = 5;
		endColorB = 14;
		touming = 2;
		act = 0;//0无炫彩，1炫彩,2染色包
		//蜡烛色
		act1[0] = 5; act1[1] = 4; act1[2] = 1; act1[3] = 0;
		//背景色
		act2[0] = 14;
	}
	//8


	void startCol()
	{
		color(mainColorB, mainColor);
	}
	void kirakira()
	{
		for (int i = 0; i < 15; i++)
		{
			color(i, i + 1);
			Sleep(16);
			color(i+8, i + 9);
			Sleep(16);
		}
	}

	void light();    //串联画面
	void arrTest();
	void lightTest();
	void lightTestEnd();
	void end();
	void build();

	void fire(int[]);//打印上6行，火焰
	void core(int);  //打印焰心 
	void root();  //打印低焰心与底部 
	void actC(int);
	

	void setMain()
	{
		int dn = 0;
		for (int a = -1; a != 9;)
		{
			color(colorBack, colorf);//可能会改动
			if (dn == 0)
			{
				dn++; 
				Sleep(1000);
				endclear1();
				
			}
			Sleep(200);

			//选项模板
			clear(0);
			RankDy();
			line(2);
			int i = 4;
			//选项
			blank2(5); outODy0("1.蜡烛の支数:"); outO(num); outODy0("支"); blank(7);
			outODy("2.颜色の设定集"); line(2); i += 2;
			double ff; ff = Dy * 12.0 * times / 1000.0;
			if (ff > 99.9) ff = 99.9;
			blank2(5); outODy0("3.燃烧の时间:"); printf("%4.1f",ff);  outODy0("秒"); blank(7); outODy0("4.火焰の速度:"); outO(Dy);  outODy("ms"); line(2); i += 2;
			blank2(5); outODy0("5.像素の字:");
			//透明显示
			switch (touming)
			{
			case 1:outODy0("  全透明     "); break;
			case 2:outODy0("  不显示     "); break;
			case 0:outODy0("  半透明     "); break;
			default:
				break;
			}
			outODy0("  6.染色の序:");
			switch (act)
			{
			case 0:outODy("    单色"); break;
			case 1:outODy("全部颜色"); break;
			case 2:outODy("自定序列"); break;
			default:
				break;
			}
			line(2); i += 2; 
			out2OMDy("7.使用预设の蜡烛", "8.文本の速度:");
			switch (eve)
			{
			case 0: outODy("    快");  break;
			case 10:outODy("    中");  break;
			case 32:outODy("    慢"); break;
			default:
				break;
			}
		    line(2); i += 2;
			blank2(5); outODy0("?.……为什么要用“の”？"); blank2(1); outODy("?.燃烧の方式:  熵增"); line(2); i += 2;
			line(1); i++;
			blank2(5); outOMDy("9.制作完毕！");


			line(14 - i);
			//提示,共line5

			line(2);
			blank2(5); outOMDy("「这样就是最好看的蜡烛了吧？」"); line(1);
			 line(1);
			blank2(5); outOMDy("——「月之民们是否如是祈愿呢。」");
			line(1);
			

			line(1); blank2(5);
			//输入确认
			a = inIntCan(1, 9, "其实只是想试一下……", "并不是没有，只是未开发……");

			if (a == 9)
			{
				startCol();
				Sleep(1000);
				endclear1();
				Sleep(300);
			}
			else
			endclear1();
			switch (a)
			{
			case 1:setNum(); break;
			case 2:setColor(); break;
			case 3:setTime(); break;
			case 4:setDy(); break;
			case 5:setTou(); break;
			case 6:setAct(); break;
			case 7:setYu(); break;
			case 8:setSu(); break;
			default:
				break;
			}
			
		}
		
	}
	
	void setNum()
	{


		//选项模板
		clear(0);
		Rank();
		line(2);
		int i = 4;
		//选项
		blank2(5); outO("  蜡烛の支数:"); outO(num); outODy("支");  Sleep(choDy);

		//利用问号
		line(8); i += 8;
		blank2(5);  outODy("?.蜡烛多少钱一支？");
		line(14 - i);
		//提示,共line5

		blank2(5);  outOMDy("——「总之原材料是不能制作的」"); line(1);
		line(1);
		blank2(5); outOMDy("不单单是改变支数……"); line(1);
		line(1);
		blank2(5);  outOMDy("——「在蛋糕的周围插上一圈吧」"); line(1);
		

		line(1); blank2(5);
		//输入确认
		num = inIntCan(1, 5, "★欢迎光临★", "这算是“催码”吗……");

		endclear1();
	}
	void setTime()
	{
		//选项模板
		clear(0);
		Rank();
		line(2);
		int i = 4;
		//选项
		line(2); i += 2;

		blank2(5); outO("3.燃烧の次数:"); outO(times);  Sleep(choDy); line(2); i += 2;
		blank2(5); outODy("  当前折算率:  每秒需要"); printf("%.2f", 1000.0 / (12.0 * Dy)); outODy("次");
		line(4); i += 4;
		blank2(5);  outODy("?.……可以手动熄灭吗？");//或者17

		line(15 - i);
		//提示,共line5

		blank2(5); outOMDy0 ("事实上，这里修改的是播放动画的总次数，真正的"); line(1);
		blank2(5); outOMDy  ("燃烧时间是：(火焰速度 x 12 x 次数 / 1000) 秒。"); line(1);
		blank2(5); outOMDy("所以数字越大，时间就会越久。"); line(1);
		blank2(5); outOMDy("在主设定集上显示的是正确的时间(单位:秒)。"); line(1);
		blank2(5); outOMDy("「0次代表不会熄灭」"); line(1);

		line(1); blank2(5);
		//输入确认
		times = inIntCan(0, 9999, "9999恰好是……上限,单位：次", "好大 = =゛");
		endclear1();
	}
	void setDy()
	{

		//选项模板
		clear(0);
		Rank();
		line(2);
		int i = 4;
		//选项
		line(2); i += 2;
		blank2(17);  outO("4.火焰の速度:"); outO(Dy);   outODy("ms"); Sleep(choDy); line(6); i += 6;

		blank2(17);  outODy("?.……什么蜡烛可以改变火焰速度呢？"); 
		line(15 - i);
		//提示,共line5

		blank2(5); outOMDy("——「在染色包模式下的作用比较明显」"); line(1);
		blank2(5); outOMDy0("实际上修改的是每一帧停留的毫秒数，"); line(1);
		blank2(5); outOMDy("所以数字越大烧得越慢。"); line(1);
		blank2(5); outOMDy("如果延迟够大，就可以看到蜡烛(们)是怎么燃烧的……"); line(1);
		blank2(5); outOMDy("——「虽然再怎么快，蜡烛也不会消耗……」"); line(1);
		
		line(1); blank2(5);
		//输入确认
		Dy= inIntCan(1, 1000, "延迟度", "在考虑做更加易懂的单位……");
		endclear1();
	}
	void setTou()
	{


		//选项模板
		clear(0);
		Rank();
		line(2);
		int i = 4;
		//选项

		line(4); i += 4;

		blank2(5); outO("5.像素の字:  ");
		//透明显示
		switch (touming)
		{
		case 1:outO("全透明     "); break;
		case 2:outO("不显示     "); break;
		case 0:outO("半透明     "); break;
		default:
			break;
		}

		Sleep(choDy);

		line(4); i += 4;
		blank2(5);  outODy("?.……半透明真的是透明度50%吗?"); 


		line(14 - i);
		//提示,共line5

		//blank2(5); outOMDy("「……字应该写在蛋糕的上层吧？」"); line(1);
		//blank2(5); outOMDy("「……为什么不画一个爱心呢？」"); line(1);
		line(2);
		blank2(5); outOMDy("「蛋糕和字都不能吃= =」"); line(1);
		blank2(5); outOMDy("「……就算你这么说，我也只是想换别的字...」"); line(1);
		blank2(5); outOMDy("并不是所有蜡烛都有字。"); line(1);
		blank2(5); outOMDy("1 半透明  2 全透明  3 不显示"); line(1);
		
		line(1); blank2(5);
		//输入确认
		touming = inIntCan(1, 3, "不显示既是实心", "就应该试试0.5 = =")-1;
		endclear1();
	}
	void setAct()
	{
		//选项模板
		clear(0);
		Rank();
		line(2);
		int i = 4;
		//选项
        line(4); i += 4;

		blank2(17);
		outO("6.染色の设定:");
		switch (act)
		{
		case 0:outO("    单色"); break;
		case 1:outO("全部颜色"); break;
		case 2:outO("自定序列"); break;
		default:
			break;
		}
		Sleep(choDy);
		line(4); i += 4;

		blank2(17); outODy("?.可以分开染蜡与火焰吗……"); 


		line(15 - i);
		//提示,共line5
		blank2(5); outOMDy("「此功能本会作为一个神秘选项登场……」"); line(1);
		blank2(5); outODy("1     单色  代表蜡烛在点燃后不会变色。"); line(1);
		blank2(5); outODy("2 全部颜色  蜡烛在点燃后会依次轮换全部240种配色。"); line(1);
		blank2(5); outODy0("3 自定序列  开启后会以染色包中的序列开始轮换颜色。"); line(1);
		blank2(5); outOMDy("染色包的设置在 制作——2.颜色の设定 中。"); line(1);

		line(1); blank2(5);
		//输入确认
		act = inIntCan(1, 3, "设置好染色包后不要忘记来这里选3 ", "——我提议增加渐变模式！")-1;
		endclear1();
	}
	void setSu()
	{
		switch (eve)
		{
		case 0:eve = 32; tod = 200; choDy = 500;Dy_Jie=25; break;
		case 10:eve = 0; tod = 0; choDy = 0; Dy_Jie = 0; break;
		case 32:eve = 10; tod = 100; choDy = 200; Dy_Jie = 10; break;
		default:
			eve = 10; tod = 100; choDy = 200; Dy_Jie = 10; break;
		}
		endclear1();
	}
	void setYu()
	{
		int a = 0; int i = 0; int k=25;
		while (a != 25)
		{
			clear(0);
			color(colorBack, colorf); 
			line(2); 
			blank2(8); outO("1.希 耶 尔"); blank(5); outO(" 9.罗 亚"); blank(5); outO("17.爱尔奎特"); if (i == 0)Sleep(tod); line(2);
			blank2(8); outO("2.海 月 烛"); blank(5); outO("10.魔 法"); blank(5); outO("18.歌月十夜"); if (i == 0) Sleep(tod); line(2);
			blank2(8); outO("3.梦 月 抄"); blank(5); outO("11.月 蚀"); blank(5); outO("19.赤之鬼神"); if (i == 0)Sleep(tod); line(2);
			blank2(8); outO("4.日向之梦"); blank(5); outO("12.夏 祭"); blank(5); outO("20.朱红之月"); if (i == 0)Sleep(tod); line(2);
			blank2(8); outO("5.真昼之月"); blank(5); outO("13.丁 寜"); blank(5); outO("21.黄昏草月"); if (i == 0)Sleep(tod); line(2);
			blank2(8); outO("6.黎明之月"); blank(5); outO("14.有 彦"); blank(5); outO("22.宵待闲话"); if (i == 0)Sleep(tod); line(2);
			blank2(8); outO("7.謹賀新年"); blank(5); outO("15.琥 珀"); blank(5); outO("23.空之境界"); if (i == 0)Sleep(tod); line(2);
			blank2(8); outO("8.月之珊瑚"); blank(5); outO("16.翡 翠"); blank(5); outO("24.无限梦之吻"); if (i == 0)Sleep(tod); line(2);
			blank2(8);  blank(13); if (i == 0) outODy("「25.返 回」");
			else outO("「25.返 回」");
			line(2);
			blank2(5); 
				
			switch (k)
			{
				
			case  1:a = inIntCan(1, 25, "原名艾莉茜娅，代号“ciel”，只在夜间出动的“天蓝色”。", "但在喜欢的人面前温柔开朗，拥有容忍一切的包容力。"); break;
			case  2:a = inIntCan(1, 25, "也许就像海中发光的珊瑚吧。", "如果是威空校区那么就是空月烛..."); break;//海的那边，是敌人...
			case  3:a = inIntCan(1, 25, "浪漫且愉悦的故事，让我稍嫌太少而百看不厌。", "笨蛋吸血姬乘坐火箭飞往月球。"); break;
			case  4:a = inIntCan(1, 25, "火车疾驰，像是要消失在阳光下，来到山间的田园。", "哪怕一天也不想等待的相见..."); break;
			case  5:a = inIntCan(1, 25, "下方的坡道如同梯子一般伸到空中，像是在追求晴朗的蓝天。", "一直焦急等待后的平稳世界,,,"); break;
			case  6:a = inIntCan(1, 25, "——天空，无边无际高远深邃的清空。", "为了些细小的事而快乐着，相互笑着。那是永不知足的时间的碎片。"); break;
			case  7:a = inIntCan(1, 25, "今年的祭典，一样要即将不留任何痕迹地结束了。", "因为很好看所以我模仿它画了一张像素画。"); break;
			case  8:a = inIntCan(1, 25, "极致的浪漫物语，并且比梦月抄还要短。", "空蕴水兮，水蕴空。"); break;
			case  9:a = inIntCan(1, 25, "魔法天才，无限转生者(ROA)，却因为未知的情感走向灭亡。", "在他的故事迎来终结之时才明白那是“爱情”。"); break;
			case 10:a = inIntCan(1, 25, "说起魔法，就躲不开ROA吧，现在是他黑化前的配色。", "也是在最强盛的时期遇到了她。"); break;
			case 11:a = inIntCan(1, 25, "", "靠感觉来吧..."); break;
			case 12:a = inIntCan(1, 25, "", "靠感觉来吧..."); break;
			case 13:a = inIntCan(1, 25, "想看这句话吗？", "？？？？？？？？"); break;//自己也无法理解那种感情//真正的感觉是什么呢...
			case 14:a = inIntCan(1, 25, "", "靠感觉来吧..."); break;
			case 15:a = inIntCan(1, 25, "全宇宙第一天真可爱清纯善良的美少女——遠野琥珀。", "而且是我的头像。"); break;
			case 16:a = inIntCan(1, 25, "全宇宙第一天真可爱清纯善良美少女的妹妹——遠野翡翠。", "琥珀厨往往都是翡翠厨。"); break;
			case 17:a = inIntCan(1, 25, "爱尔奎特·布伦史塔德，在各方面都占有绝对的优势。", "尤其是“笨蛋”方面。"); break;
			case 18:a = inIntCan(1, 25, "", "靠感觉来吧..."); break;
			case 19:a = inIntCan(1, 25, "", "靠感觉来吧..."); break;
			case 20:a = inIntCan(1, 25, "觉醒后的爱尔奎特。", "月球的灵魂体。"); break;
			case 21:a = inIntCan(1, 25, "", "靠感觉来吧..."); break;
			case 22:a = inIntCan(1, 25, "", "靠感觉来吧..."); break;
			case 23:a = inIntCan(1, 25, "", "靠感觉来吧..."); break;
			case 24:a = inIntCan(1, 25, "Kiss the Infinite Dream.", "靠感觉来吧..."); break;
			case 25:a = inIntCan(1, 25, "一些《月姬》主题的预设(主要)", "做出来却懒得评价的胡祉旭是屑。");
			default:
				break;
			}

			k = a;
			switch (a)
			{
			case 1:ciel(); break;
			case 2:haiyuezhu();  break;
			case 3:mengyuechao(); break;
			case 4:rixiangzhimeng(); break;
			case 5:zhenzhouzhiyue(); break;
			case 6:limingzhiyue(); break;
			case 7:jinhexinnian(); break;
			case 8:yuezhishanhu(); break;
			case 9:ROA(); break;
			case 10:mofa(); break;
			case 11:yueshi();   break;
			case 12: fenbing(); break;
			case 13:dingning(); break;
			case 14:youyan(); break;
			case 15:hupo(); break;
			case 16:feicui(); break;
			case 17: Arcueid(); break;
			case 18:geyueshiye(); break;
			case 19:chizhiguishen(); break;
			case 20:zhuhongzhiyue(); break;
			case 21:huanghuncaoyue(); break;
			case 22:xiaodaixianhua(); break;
			case 23:kongzhijingjie(); break;
			case 24:kisstheinfinitedream(); break;
			default:
				break;
			}
			i++;
		}

		endclear1();
	}
	void setColor()
	{
		for (int a = -1; a != 9;)
		{
			color(colorBack, colorf);

			//选项模板
			clear(0);
			line(1); blank2(5); blankMid(13);
			outODy("颜色の设定集");
			line(2);
			//选项
			blank(15); outODy0("主界面"); blank(6); outODy0("单色与制作界面"); blank(4); outODy0("熄灭与蛋糕"); Sleep(tod); line(1);
			blank2(6); outODy0("1.背景："); tranColDy0(mainColorB); blank2(2); outODy0("3.背景："); tranColDy0(colorBack); blank2(2); outODy0("5.背景："); tranColDy0(endColorB); Sleep(tod); line(1);
			blank2(6); outODy0("2.文字："); tranColDy0(mainColor); blank2(2); outODy0("4.蜡烛："); tranColDy0(colorf); blank2(2); outODy0("6.蜡烛："); tranColDy0(endColor); Sleep(tod); line(2);

		
			blank2(15); outODy0("染色包："); line(1); //24-4*2=40/3=12种
			int k=3;
			blank2(5); outODy0("7.背景：");for (int i = 0; act2[i] != -1; i++)
			{
				if (i == 6)
				{
					line(1); k--; blank2(9);
				}
				if (i == 13) break;
				tranColDy0(act2[i]);
				if(act2[i + 1] != -1 && i != 11)
				outODy0("→");
			}

			sleepTod();
			line(k);

			k = 3;
			blank2(5); outODy0("8.蜡烛："); for (int i = 0; act1[i] != -1; i++)
			{
				if (i == 6)
				{
					line(1); k--; blank2(9);
				}
				if (i == 12) break;
				tranColDy0(act1[i]); if (act1[i + 1] != -1&&i!=11)outODy0("→");
			}

			sleepTod();
			line(k);
			blank2(5); outOMDy("9.设定完毕！");

			line(2);
			//提示,共line5

			blank2(5); outOMDy("「只有这16种颜色……」"); line(1);
			blank2(5); outOMDy("在自定序列开启后，蜡烛会以染色包的顺序轮换颜色。"); line(1);
			blank2(5); outOMDy("——「没有我最喜欢的颜色……」"); line(1);
			//输入确认
			line(1); blank2(5);
			a = inIntCan(1, 9, "……难道身边就有颜料桶吗", "……为什么这么麻烦呢");
		
			switch (a)
			{
			case 1:case 2:case 3:case 4:case 5:case 6:
				setAColor(a); break;
			case 7:endclear1(); clear(0); setActarr2(); break;
			case 8: endclear1(); clear(0); setActarr1(); break;
			default:
				break;
			}
		}
	}
	void setAColor(int a)
	{
		switch (a)
		{
		case 1:case 2:
			color(mainColorB, mainColor); break;
		case 5:case 6:
			color(endColorB, endColor); break;
		default:
			break;
		}
		Sleep(500);
		endclear1();
		int p = 0;
		while (a != 17)
		{
			switch (a)
			{
			case 1:case 2:
				color(mainColorB, mainColor); break;
			case 3:case 4:
				color(colorBack, colorf); break;
			case 5:case 6:
				color(endColorB, endColor); break;
			default:
				break;
			}
			clear(0);

			line(1); blank2(5); blankMid(13);
			outO("颜色の设定集");
			line(2);
			//颜色表
			if (p == 0)
				colorTableDy();
			else colorTable();
			line(2);
			//选项
			switch (a)
			{
			case 1:
				blank(30); outO("主 界 面"); line(1);
				blank2(13); outO("★背景：  "); outOT(mainColorB+1); tranCol(mainColorB); line(1);
				blank2(13); outO("  文字：  "); outOT(mainColor+1); tranCol(mainColor);
			break; case 2:
				blank(30); outO("主 界 面"); line(1);
				blank2(13); outO("  背景：  "); outOT(mainColorB+1); tranCol(mainColorB); line(1);
				blank2(13); outO("★文字：  "); outOT(mainColor+1); tranCol(mainColor);
				break;
			case 3:
				blank(29); outO("单色与设置"); line(1);
				blank2(13); outO("★背景：  "); outOT(colorBack+1); tranCol(colorBack); line(1);
				blank2(13); outO("  蜡烛：  "); outOT(colorf+1); tranCol(colorf); line(1);
			break; case 4:
				blank(29); outO("单色与设置"); line(1);
				blank2(13); outO("  背景：  "); outOT(colorBack+1); tranCol(colorBack); line(1);
				blank2(13); outO("★蜡烛：  "); outOT(colorf+1); tranCol(colorf); line(1);
				break;
			case 5:
				blank(29); outO("熄灭与蛋糕"); line(1);
				blank2(13); outO("★背景：  "); outOT(endColorB+1); tranCol(endColorB); line(1);
				blank2(13); outO("  蜡烛：  "); outOT(endColor+1); tranCol(endColor); line(1);
			break; case 6:
				blank(29); outO("熄灭与蛋糕"); line(1);
				blank2(13); outO("  背景：  "); outOT(endColorB+1); tranCol(endColorB); line(1);
				blank2(13); outO("★蜡烛：  "); outOT(endColor+1); tranCol(endColor); line(1);
				break;
			default:
				break;
			}



			//blank(15); outO("主界面"); blank(8); outO("单色与设置"); blank(4); outODy("熄灭与蛋糕"); line(1);
			//blank2(6); outO("背景：  "); tranCol(mainColorB); blank2(2); outO("背景：  "); tranCol(colorBack); blank2(2); outO("背景：  "); tranCol(endColorB); line(1);
			//blank2(6); outO("文字：  "); tranCol(mainColor); blank2(2); outO("蜡烛：  "); tranCol(colorf); blank2(2); outO("蜡烛：  "); tranCol(endColor); 


			if(p==0)
			sleepTod();
			line(2);


			
			if (p == 0)
			{
				blank2(5); outOMDy("0.返回  若要修改另一项，可在序号前加上负号表示"); line(1);
				blank2(5); outOMDy("修改后若两部分颜色相同会跳至下一个颜色。"); line(1);
				blank2(5); blankMid(27); outODy("——「A...16...2?(排列数)」"); line(2);
			}
			else
			{
				blank2(5); outOM("0.返回  若要修改另一项，可在序号前加上负号表示"); line(1);
				blank2(5); outOM("修改后若两部分颜色相同会跳至下一个颜色。"); line(1);
				blank2(5); blankMid(27); outO("——「A...16...2?(排列数)」"); line(2);
			}

			blank2(5);
			switch (a) 
			{
				int q;
			case 1:q = inIntCan(-16, 16, "月烛，辉夜中 背景 的颜色序号", "其实前面加多少个0都可以..."); 
				if (q == 0) { endclear1(); return; }
				if (q > 0)
					mainColorB = q - 1;
				else
					mainColor = -1 * q - 1;

				if (mainColorB == mainColor) mainColorB++; 
				break;



			case 2:q = inIntCan(-16, 16, "月烛，辉夜中 文字 的颜色序号", "其实前面加多少个0都可以...") ;  
				if (q == 0) { endclear1(); return; }
				if (q > 0)
					mainColor = q - 1;
				else
					mainColorB = -1 * q - 1;

				if (mainColorB == mainColor) mainColorB++;
				break;
			case 3:q = inIntCan(-16, 16, "单色蜡烛，制作蜡烛中 背景 的颜色序号", "其实前面加多少个0都可以...") ; 
				if (q == 0) { endclear1(); return; }
				if (q > 0)
					colorBack = q - 1;
				else
					colorf = -1 * q - 1;

				if (colorBack == colorf) colorBack++;
				break;
			case 4:q = inIntCan(-16, 16, "单色蜡烛，制作蜡烛中 文字 的颜色序号", "其实前面加多少个0都可以...") ; 
				if (q == 0) { endclear1(); return; }
				if (q > 0)
					colorf = q - 1;
				else
					colorBack = -1 * q - 1;

				if (colorf == colorBack) colorf++;
				break;
			case 5:q = inIntCan(-16, 16, "蜡烛熄灭，蛋糕中 背景 的颜色序号", "其实前面加多少个0都可以...") ; 
				if (q == 0) { endclear1(); return; }
				if (q > 0)
					endColorB = q - 1;
				else
					endColor = -1 * q - 1;

				if (endColor == endColorB) endColorB++;
				break;
			case 6:q = inIntCan(-16, 16, "蜡烛熄灭，蛋糕中 文字 的颜色序号", "其实前面加多少个0都可以...") ;  
				if (q == 0) { endclear1(); return; }
				if (q > 0)
					endColor = q - 1;
				else
					endColorB = -1 * q - 1;

				if (endColorB == endColor) endColor++;
				break;
			default:
				break;
			}
			p++;
		}
	}
	void setActarr1()
	{
		color(colorBack, colorf);
		int a = 0;
		int long2;
		while (a != -1)
		{
			//数组长度

			for (long2 = 0; act1[long2] != -1; long2++);

			clear(0);
			line(1);
			//颜色表
			colorTable();
			line(2);
			//打印现在的染色包
			blank2(5); outO("蜡烛の染色包：");  //24-4*2=40/3=12种
			int k = 4;
			for (int i = 0; act1[i] != -1; i++)
			{
				if (i % 8 == 0)
				{
					line(1); k--; blank2(5);
				}
				if (act1[i + 1] != -1)
				{
					tranCol(act1[i]); outO("→");
				}
				else
				{
					tranColDy(act1[i]); outODy("→");
				}
			}line(k);



			blank2(5); blankMid(39); outO("——「同一颜色可以出现多次，最多填充50个」"); line(1);
			blank2(5); blankMid(21); outO("「共有？？？种组合」"); line(1);
			blank2(5); blank2(5); outO("[ -2 ] 测试染色包"); line(1);
			blank2(5); blank2(5); outO("[ -1 ] 删除最后的颜色并继续填充"); line(1);
			blank2(5); blank2(5); outO("[  0 ] 填充完毕"); line(1);
			blank2(5); blank2(5); outO("[1,16] 填充下一个颜色"); line(1);
			//打印数组
			blank2(3);
			a = inIntCan0(-2, 16, "——无止境的轮回...", "——我火速宣布颜色不够用！") - 1;
			if (a == -3)
			{
				arrTest();
				color(colorBack, colorf);
			}
			else
			{
				if (a == -2) if (long2 != 0) act1[long2 - 1] = -1; else act1[0] = -1;
				else
					act1[long2] = a;
			}
		}
		color(colorBack, colorf);
		Sleep(350);
		endclear1();
		
	}
	void setActarr2()
	{
		color(colorBack,colorf);
		int a = 0;
		int long2;
		while (a != -1)
		{
			//数组长度

			for (long2 = 0; act2[long2] != -1; long2++);

			clear(0);
			line(1); 
			//颜色表
			colorTable();
			//打印现在的染色包
			line(2);
			blank2(5); outO("背景の染色包：");  //24-4*2=40/3=12种
			int k = 4;
			  for (int i = 0; act2[i] != -1; i++)
			{
				if (i % 8 == 0)
				{
					line(1); k--; blank2(5);
				}
				if (act2[i + 1] != -1)
				{
					tranCol(act2[i]); outO("→");
				}
				else
				{
					tranColDy(act2[i]); outODy("→");
				}
			}line(k);

			blank2(5); blankMid(39); outO("——「同一颜色可以出现多次，最多填充50个」"); line(1);
			blank2(5); blankMid(21); outO("「共有？？？种组合」"); line(1);
			blank2(5); blank2(5); outO("[ -2 ] 测试染色包"); line(1);
			blank2(5); blank2(5); outO("[ -1 ] 删除最后的颜色并继续填充"); line(1);
			blank2(5); blank2(5); outO("[  0 ] 填充完毕"); line(1);
			blank2(5); blank2(5); outO("[1,16] 填充下一个颜色"); line(1);
			//打印数组
			blank2(3);
			a = inIntCan0(-2, 16, "——无止境的轮回...", "——我火速宣布颜色不够用！")-1;
			if(a==-3)
			{ 
				arrTest();
				color(colorBack, colorf);
			}
			else
			{
				if (a == -2) if (long2 != 0) act2[long2 - 1] = -1; else act2[0] = -1;
				else
					act2[long2] = a;
			}
		}
		color(colorBack, colorf);
		Sleep(350);
		endclear1();

	}


	void setColorTest()
	{
		for (int a = -1; a != 9;)
		{
			color(colorBack, colorf);

			//选项模板
			clear(0);
			line(1); blank2(5); blankMid(13);
			outO("颜色の设定集");
			line(2);
			//选项
			blank(15); outO("主界面"); blank(6); outO("单色与制作界面"); blank(4); outO("熄灭与蛋糕"); line(1);
			blank2(6); outO("1.背景："); tranCol(mainColorB); blank2(2); outO("3.背景："); tranCol(colorBack); blank2(2); outO("5.背景："); tranCol(endColorB); line(1);
			blank2(6); outO("2.文字："); tranCol(mainColor); blank2(2); outO("4.蜡烛："); tranCol(colorf); blank2(2); outO("6.蜡烛："); tranCol(endColor); line(2);


			blank2(15); outO("染色包："); line(1); //24-4*2=40/3=12种
			int k = 2;
			blank2(5); outO("7.背景："); for (int i = 0; act2[i] != -1; i++)
			{
				if (i == 6)
				{
					line(1); k--; blank2(9);
				}
				if (i == 13) break;
				tranCol(act2[i]);
				if (act2[i + 1] != -1 && i != 11)
					outO("→");
			}

			sleepTod();
			line(k);

			k = 2;
			blank2(5); outO("8.蜡烛："); for (int i = 0; act1[i] != -1; i++)
			{
				if (i == 6)
				{
					line(1); k--; blank2(9);
				}
				if (i == 12) break;
				tranCol(act1[i]); if (act1[i + 1] != -1 && i != 11)outO("→");
			}

			sleepTod();
			line(k);
			blank2(5); outOM("9.设定完毕！");

			line(2);
			//提示,共line5

			blank2(5); outOM("染色包中只有一个颜色则相当于单色。"); line(1);
			blank2(5); outOM("只能使用16种颜色。"); line(2);
			blank2(5); outOM("——「没有我最喜欢的颜色……」"); line(1);
			//输入确认
			line(1); blank2(5);
			a = inIntCan(1, 9, "……难道身边就有颜料桶吗", "……为什么这么麻烦呢");

			switch (a)
			{
			case 1:case 2:case 3:case 4:case 5:case 6:
				setAColorTest(a); break;
			case 7:clear(0); Sleep(500); setActarr2(); break;
			case 8:clear(0); Sleep(500); setActarr1(); break;
			default:
				break;
			}
		}
	}
	void setAColorTest(int a)
	{
		clear(0);
		line(1); blank2(5); blankMid(13);
		outO("颜色の设定集");
		line(2);
		//选项
		blank(15); outO("主界面"); blank(8); outO("单色与设置"); blank(4); outO("熄灭与蛋糕"); line(1);
		blank2(6); outO("1.背景："); tranCol(mainColorB); blank2(2); outO("3.背景："); tranCol(colorBack); blank2(2); outO("5.背景："); tranCol(endColorB); line(1);
		blank2(6); outO("2.文字："); tranCol(mainColor); blank2(2); outO("4.蜡烛："); tranCol(colorf); blank2(2); outO("6.蜡烛："); tranCol(endColor);
		Sleep(500);
		line(2);

		//颜色表
		colorTable();

		line(2);
		blank2(5); outOM("「有颜色的颜色表在文件中」"); line(1);
		blank2(5); outOM("——「因为窗口只有“背景颜色”与“文字颜色”」"); line(1);
		blank2(5); outOM("修改后若两部分颜色相同会跳至下一个颜色。"); line(1);
		blank2(5); blankMid(27); outO("——「A...16...2?(排列数)」"); line(1);

		blank2(5);
		switch (a)
		{
		case 1:mainColorB = inIntCan(0, 15, "界面—背景色  ", "其实前面加多少个0都可以..."); if (mainColorB == mainColor) mainColorB++; break;
		case 2:mainColor = inIntCan(0, 15, "界面—文字色  ", "其实前面加多少个0都可以..."); if (mainColorB == mainColor) mainColor++; break;
		case 3:colorBack = inIntCan(0, 15, "单色—背景色  ", "其实前面加多少个0都可以..."); if (colorBack == colorf) colorBack++; break;
		case 4:colorf = inIntCan(0, 15, "单色—蜡烛色  ", "其实前面加多少个0都可以..."); if (colorBack == colorf) colorf++; break;
		case 5:endColorB = inIntCan(0, 15, "熄灭—背景色  ", "其实前面加多少个0都可以..."); if (endColor == endColorB) endColorB++; break;
		case 6:endColor = inIntCan(0, 15, "熄灭—蜡烛色  ", "其实前面加多少个0都可以..."); if (endColor == endColorB) endColor++; break;
		default:
			break;
		}
	}

	void setColShortTest1()
	{
		clear(5);
		line(5);
			colorf = inIntCan0(0, 15, "蜡烛颜色", "蜡烛颜色");
			line(1);
			colorBack = inIntCan0(0, 15, "背景颜色", "背景颜色");
	}

	void setColShortTest2()
	{
		for (int i = 0; i < 16; i++)
			for (int j = 0; j < 16; j++)
			{
				if (i != j)
				{
					color(i, j);
					lightTest();
				}
			}
	}

	int rank;
	void Rank()
	{
		line(1);
		blank2(5);
		if (rank == 1) outOM("蜡烛壹の制作");
		if (rank == 2) outOM("蜡烛贰の制作");
		if (rank == 3) outOM("蜡烛叁の制作");
	}
	void RankDy()
	{
		line(1);
		blank2(5);
		if (rank == 1) outOM("蜡烛壹の制作");
		if (rank == 2) outOM("蜡烛贰の制作");
		if (rank == 3) outOM("蜡烛叁の制作");
	}

private:
	int num = 5;
	int times = 10;
	int Dy = 50;
	int touming = 0;             //0半透明，1透明,2不透明
	int act = 0;                 //0无炫彩，1炫彩,2染色包
	int anti = 0;                //0熵增燃烧，1熵减燃烧

	int colorf = 15;             //11,12，14，15,3,4,9
	int colorBack = 12;
	int endColor = 12;
	int endColorB = 11;
	static int mainColor;
	static int mainColorB;

	int act1[50] = {11};	      //蜡烛色
	int act2[50] = { 12 };	     //背景色


	int choDy = 200;//小选项后更新的停留时间 750

	int a1[12] = { 0,0,0,0,0,2,1,1,2,1,2,2 };
	int a2[12] = { 0,0,1,1,0,0,0,0,2,1,1,3 };
	int a3[12] = { 0,0,0,0,0,0,0,0,2,2,1,4 };
	int a4[12] = { 0,0,0,0,0,0,1,2,0,4,0,4 };
	int a5[12] = { 0,0,3,1,2,2,2,1,1,1,0,3 };
	int a6[12] = { 3,1,0,0,0,0,0,0,1,3,0,4 };
	void outBuild(const char a[]);
	void outEnd(const char a[]);
	void endBuild();
};

void can(candle&, candle&, candle&);  //“点亮蜡烛”主菜单