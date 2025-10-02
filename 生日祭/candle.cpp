#include"candle.h"
using namespace std;
const char r1[] = "                              █▓▓▓█\n                                ▓▓▓\n                                  ▄\n                                ███\n                              █████\n                          █████████\n                          ██▓▓▓▓▓██\n                          ████▓████\n                          ████▓████\n                          ████▓████\n                          ███▓▓████\n                          █████████";
const char r12[] = "                              █▓▓▓█\n                                ▓▓▓\n                                  ▄\n                                ███\n                              █████\n                          █████████\n                          ██          ██\n                          ████  ████\n                          ████  ████\n                          ████  ████\n                          ███    ████\n                          █████████";
const char r13[] = "                              █▓▓▓█\n                                ▓▓▓\n                                  ▄\n                                ███\n                              █████\n                          █████████\n                          █████████\n                          █████████\n                          █████████\n                          █████████\n                          █████████\n                          █████████";
const char r2[] = "                █▓▓▓█                  █▓▓▓█\n                  ▓▓▓                      ▓▓▓\n                    ▆                          ▆\n                  ███                      ███\n                  ███                      ███\n                  ███                      ███\n                  ███                      ███\n                  ███                      ███\n                █████                  █████\n                █████                  █████\n              ███████              ███████\n              ███████              ███████";
const char r3[] = "          █▓▓▓█          █▓▓▓█          █▓▓▓█\n            ▓▓▓              ▓▓▓              ▓▓▓\n              ▄                  ▄                  ▄\n            ███              ███              ███\n            ███              ███              ███\n            ███              ███              ███\n            ███              ███              ███\n            ███              ███              ███\n          █████          █████          █████\n          █████          █████          █████\n        ███████      ███████      ███████\n        ███████      ███████      ███████";
const char r4[] = "      █▓▓▓█      █▓▓▓█      █▓▓▓█      █▓▓▓█\n        ▓▓▓          ▓▓▓          ▓▓▓          ▓▓▓\n          ▃              ▃              ▃              ▃\n        ███          ███          ███          ███\n        ███          ███          ███          ███\n        ███          ███          ███          ███\n        ███          ███          ███          ███\n        ███          ███          ███          ███\n        ███          ███          ███          ███\n    ███████████████████████████████\n  █████████████████████████████████\n  █████████████████████████████████";//      █████      █████      █████      █████
const char r5[] = "  █▓▓▓█    █▓▓▓█    █▓▓▓█    █▓▓▓█    █▓▓▓█\n    ▓█▓        ▓▓▓        ▓▓▓        ▓▓▓        ▓▓▓\n      █            █            █            █            █\n    ███        ███        ███        ███        ███\n    ███        ███        ███        ███        ███\n  █████████████████████████████████\n██▓▓▓█▓███▓▓▓███▓▓▓███▓▓▓███▓███▓██\n████▓█▓███▓███████▓███▓██▓██▓▓██▓██\n██▓▓▓█▓███▓▓▓███▓▓▓███▓██▓██▓█▓█▓██\n██▓███▓███▓█▓███▓█████▓██▓██▓██▓▓██\n██▓▓▓█▓█▓█▓▓▓█▓█▓▓▓███▓▓▓███▓███▓██\n███████████████████████████████████";
const char r52[] = "  █▓▓▓█    █▓▓▓█    █▓▓▓█    █▓▓▓█    █▓▓▓█\n    ▓█▓        ▓▓▓        ▓▓▓        ▓▓▓        ▓▓▓\n      █            █            █            █            █\n    ███        ███        ███        ███        ███\n    ███        ███        ███        ███        ███\n  █████████████████████████████████\n██      █  ███      ███      ███      ███  ███  ██\n████  █  ███  ███████  ███  ██  ██    ██  ██\n██      █  ███      ███      ███  ██  ██  █  █  ██\n██  ███  ███  █  ███  █████  ██  ██  ██    ██\n██      █  █  █      █  █      ███      ███  ███  ██\n███████████████████████████████████";
const char r53[] = "  █▓▓▓█    █▓▓▓█    █▓▓▓█    █▓▓▓█    █▓▓▓█\n    ▓█▓        ▓▓▓        ▓▓▓        ▓▓▓        ▓▓▓\n      █            █            █            █            █\n    ███        ███        ███        ███        ███\n    ███        ███        ███        ███        ███\n  █████████████████████████████████\n███████████████████████████████████\n███████████████████████████████████\n███████████████████████████████████\n███████████████████████████████████\n███████████████████████████████████\n███████████████████████████████████";
int Lhuan=2;
int LhuanJie = 2;//生日祭与kirakira
void candle::light()
{
	color(colorBack,colorf);
	Sleep(1000);
	endclear1();
	Sleep(200);
	 build();
	int i = 0;
	int j = -1;
	while (times == 0)
	{
		if (act == 1)
		{
			if (i % 16 == 0)
				j++;
			if (i %16== j%16)
			{
				i++;
				continue;
			}
			else {
				color(j, i);
			}
		}
		if (act == 2) actC(i);
		clear(0); cout << endl << endl; fire(a1); core(1);   root();
		Sleep(Dy);
		clear(0); cout << endl << endl; fire(a2); core(2);   root();
		Sleep(Dy);
		clear(0); cout << endl << endl; fire(a3); core(3);  root();
		Sleep(Dy);
		clear(0); cout << endl << endl;	fire(a4); core(4); root();
		Sleep(Dy);
		clear(0); cout << endl << endl;	fire(a5); core(5); root();
		Sleep(Dy);
		clear(0); cout << endl << endl;	fire(a6); core(6); root();
		Sleep(Dy);
		clear(0); cout << endl << endl; fire(a1); core(1);   root();
		Sleep(Dy);
		clear(0); cout << endl << endl; fire(a2); core(2);   root();
		Sleep(Dy);
		clear(0); cout << endl << endl; fire(a3); core(3);  root();
		Sleep(Dy);
		clear(0); cout << endl << endl;	fire(a4); core(4); root();
		Sleep(Dy);
		clear(0); cout << endl << endl;	fire(a5); core(5); root();
		Sleep(Dy);
		clear(0); cout << endl << endl;	fire(a6); core(6); root();
		Sleep(Dy);
		i++;
	}
	for (; i < times; i++)
	{
		if (act == 1)
		{
			if (i % 16 == 0)
				j++;
			if (i %16== j%16) continue;
			color(j, i);
		}
		if (act == 2) actC(i);
		clear(0); 
		cout << endl << endl; fire(a1); core(1);   root();
		Sleep(Dy);
		clear(0); 
		cout << endl << endl; fire(a2); core( 2);   root();
		Sleep(Dy);
		clear(0);
		cout << endl << endl; fire(a3); core( 3) ;  root();
		Sleep(Dy);
		clear(0);
		cout << endl << endl;	fire(a4); core(4); root();
		Sleep(Dy);
		clear(0);
		cout << endl << endl;	fire(a5); core( 5); root();
		Sleep(Dy);
		clear(0); 
		cout << endl << endl;	fire(a6); core(6); root();
		Sleep(Dy);
		clear(0);
		cout << endl << endl; fire(a1); core(1);   root();
		Sleep(Dy);
		clear(0);
		cout << endl << endl; fire(a2); core(2);   root();
		Sleep(Dy);
		clear(0);
		cout << endl << endl; fire(a3); core(3);  root();
		Sleep(Dy);
		clear(0);
		cout << endl << endl;	fire(a4); core(4); root();
		Sleep(Dy);
		clear(0);
		cout << endl << endl;	fire(a5); core(5); root();
		Sleep(Dy);
		clear(0);
		cout << endl << endl;	fire(a6); core(6); root();
		Sleep(Dy);
	}
	end();
	Sleep(1000);
	getS();

	lineDy3(2);
	if (Lhuan == 1) Lhuan = 2;
	else Lhuan = 1;
	if (Lhuan == 1)
	{
		line(1);
		blank2(5); outOMDy0("「如果那些正在思考的芦苇停止他们的所思所想」"); lineDy3(3);
		blank2(5); outOMDy0("「地上想必能成为一片纯洁无瑕的草原」");
		if (num != 5)
			lineDy3(1);
		lineDy3(4);
	}
	else
	{
		blank2(5); outOM("  「空蕴水兮    水蕴空」"); lineDy3(3);
		blank2(5); outOM("  「月夜之空兮    洋散四方」"); lineDy3(1);
		if (num != 5)
			lineDy3(1);
		lineDy3(4);
	}
	getS();
	endclear2();

	Sleep(500);
	clear(0);
	cakeDy();
	Sleep(500);
	cake1();
	Sleep(500);
	cake2();
	Sleep(1000);

	clear(3);
	cakePan();
	Sleep(2000);
	getS();
	lineDy3(1);
	blank2(5); outOMDy0("    「月之民们如是祈愿」");	lineDy3(1);
	getS();
	startCol();
	Sleep(1000);
	endclear2();
	Sleep(300);  //待修改
}
void candle::arrTest()
{
	for (int i = 0; i < times * 2; i++)
	{
		actC(i);
		Sleep(Dy * 6);
	}
}
void candle::lightTest()
{
	color(colorBack, colorf);
	for (int i=0; i < times; i++)
	{
		if (act == 1)
		{
			int j = 0;
			if (i % 16 == 0)
				j++;
			color(i, i + j);
		}
		if (act == 2) actC(i);
		clear(0);
		cout << endl << endl; fire(a1); core(1);   root();
		Sleep(Dy);
		clear(0);
		cout << endl << endl; fire(a2); core(2);   root();
		Sleep(Dy);
		clear(0);
		cout << endl << endl; fire(a3); core(3);  root();
		Sleep(Dy);
		clear(0);
		cout << endl << endl;	fire(a4); core(4); root();
		Sleep(Dy);
		clear(0);
		cout << endl << endl;	fire(a5); core(5); root();
		Sleep(Dy);
		clear(0);
		cout << endl << endl;	fire(a6); core(6); root();
		Sleep(Dy);
	}
	Sleep(1000);
	getS();
}
void candle::lightTestEnd()
{
	end();
	Sleep(1000);
	getS();

	lineDy3(2);
	if (Lhuan == 1) Lhuan = 2;
	else Lhuan = 1;
	if (Lhuan == 1)
	{
		line(1);
		blank2(5); outOMDy0("「如果那些正在思考的芦苇停止他们的所思所想」"); lineDy3(3);
		blank2(5); outOMDy0("「地上想必能成为一片纯洁无瑕的草原」");
		if (num != 5)
			lineDy3(1);
		lineDy3(4);
	}
	else
	{
		blank2(5); outOM("  「空蕴水兮    水蕴空」"); lineDy3(3);
		blank2(5); outOM("  「月夜之空兮    洋散四方」"); lineDy3(1);
		if (num != 5)
			lineDy3(1);
		lineDy3(4);
	}
	getS();
}
void candle::end()
{
	int dly = 250; //结束的ms数
	color(endColorB, endColor);

	clear(0); cout << endl << endl; fire(a1); core(1);   root();
	Sleep(dly);
	clear(0); cout << endl << endl; fire(a2); core(2);   root();
	Sleep(dly);
	clear(0); cout << endl << endl; fire(a3); core(3);  root();
	Sleep(dly);
	clear(0); cout << endl << endl;	fire(a4); core(4); root();
	Sleep(dly);
	clear(0); cout << endl << endl;	fire(a5); core(5); root();
	Sleep(dly);
	clear(0); cout << endl << endl;	fire(a6); core(6); root();
	Sleep(dly);

	clear(0); cout << endl << endl; fire(a1); core(1);   root();
	Sleep(dly);
	clear(0); cout << endl << endl; fire(a2); core(2);   root();
	Sleep(dly);
	clear(0); cout << endl << endl; fire(a3); core(3);  root();
	Sleep(dly);
	clear(0); cout << endl << endl;	fire(a4); core(4); root();
	Sleep(dly);
	clear(0); cout << endl << endl;	fire(a5); core(5); root();
	Sleep(dly);
	clear(0); cout << endl << endl;	fire(a6); core(6); root();
	Sleep(dly);
	endBuild();

}
void candle::build()
{
	clear(0);
	line(12);

	switch (num)
	{
	case 1:
		if (touming == 0)
			outBuild(r1);
		else
		{
			if (touming == 1)outBuild(r12);
			else outBuild(r13);
		}
		break;
	case 2:
		outBuild(r2); break;
	case 3:
		outBuild(r3); break;
	case 4:
		outBuild(r4); break;
	case 5:
		if (touming == 0)
			outBuild(r5);
		else
		{
			if (touming == 1)outBuild(r52);
			else outBuild(r53);
		}
		break;
	default:
		break;
	}
}

void candle::endBuild()
{
	clear(0);
	line(12);

	switch (num)
	{
	case 1:
		if (touming == 0)
			outEnd(r1);
		else
		{
			if (touming == 1)outEnd(r12);
			else outEnd(r13);
		}
		break;
	case 2:
		outEnd(r2); break;
	case 3:
		outEnd(r3); break;
	case 4:
		outEnd(r4); break;
	case 5:
		if (touming == 0)
			outEnd(r5);
		else
		{
			if (touming == 1)outEnd(r52);
			else outEnd(r53);
		}
		break;
	default:
		break;
	}
}
void candle::outBuild(const char a[])
{
	int i;
	int j = 0;
	for ( i = 0; j!= 2; i++)
	{
		if (a[i] == '\n')j++;
	}
	while (a[i] != '\0')
	{
		if(a[i]!=' '&&a[i] != '\n')
		Sleep(Dy_20);
		putchar(a[i]);
		i++;
	}
}
void candle::outEnd(const char a[])
{
	int i;
	int j = 0;
	for (i = 0; j != 2; i++)
	{
		if (a[i] == '\n')j++;
	}
	cout << &a[i];
}
void coreA(int a)
{
	switch (a)
	{
	case 1: cout << "  ████"; break;
	case 2: full(5); break;
	case 3: cout << "██▓██"; break;
	case 4:cout << "██▓██";   break;
	case 5:cout << "████  "; break;
	case 6:cout << "█████"; break;
	default:
		break;
	}
}
void coreB(int a)
{
	switch (a)
	{
	case 1:cout << "███▓█"; break;
	case 2:cout << "█▓▓▓█"; break;
	case 3: cout << "█▓▓▓█"; break;
	case 4:cout << "█▓▓▓█";  break;
	case 5:cout << "██▓██"; break;
	case 6:cout << "██▓▓█"; break;
	default:
		break;
	}
}
void rootA()
{
	cout << "█▓▓▓█";

}
void rootB(int a)
{
	switch (a)
	{
	case 0:return;
	case 1:cout << "    ▓▓▓  "; return;
	case 2:cout << "      ▓▓▓  "; return;
	case 3:cout << "        ▓▓▓  "; return;
	case 4:cout << "          ▓▓▓  "; return;
	case 5:cout << "            ▓▓▓  "; return;
	case 6:cout << "              ▓▓▓  "; return;
	case 7:cout << "                ▓▓▓  "; return;
	case 8:cout << "                  ▓▓▓  "; return;
	case 9:cout << "                    ▓▓▓  "; return;
	case 10:cout << "                     ▓▓▓  "; return;
	case 11:cout << "                       ▓▓▓  "; return;
	case 12:cout << "                         ▓▓▓  "; return;
	case 13:cout << "                           ▓▓▓  "; return;
	case 14:cout << "                             ▓▓▓  "; return;
	case 15:cout << "                               ▓▓▓  "; return;
	case 16:cout << "                                 ▓▓▓  "; return;
	case 17:cout << "                                   ▓▓▓  "; return;
	case 18:cout << "                                     ▓▓▓  "; return;
	case 19:cout << "                                       ▓▓▓  "; return;
	case 20:cout << "                                         ▓▓▓  "; return;
	case 21:cout << "                                           ▓▓▓  "; return;
	case 22:cout << "                                             ▓▓▓  "; return;
	case 23:cout << "                                               ▓▓▓  "; return;
	default:
		break;
	}
}
void candle::fire(int a[])
{
	switch (num)
	{
	case 1:
		for (int i = 0; i<12; i += 2)
		{
			blank2(a[i]+15);
			full(a[i + 1]);
			line(1);
		}break;
	case 2:
		for (int i = 0; i < 12; i += 2)
		{
			blank2(a[i]+8 ); 
			full(a[i + 1]);
			blank2(14- a[i + 1]);
			full(a[i + 1]);
			line(1);
		}break;
	case 3:
		for (int i = 0; i < 12; i += 2)
		{
			blank2(a[i]+5);
			full(a[i + 1]);
			blank2(10  - a[i + 1]);
			full(a[i + 1]);
			blank2(10  - a[i + 1]);
			full(a[i + 1]);
			line(1);
		}break;
	case 4:
		for (int i = 0; i < 12; i += 2)
		{
			blank2(a[i]+3);
			full(a[i + 1]);
			blank2(8 - a[i + 1]);
			full(a[i + 1]);
			blank2(8 - a[i + 1]);
			full(a[i + 1]);
			blank2(8 - a[i + 1]);
			full(a[i + 1]);
			line(1);
		}break;
	case 5:
		for (int i = 0; i < 12; i += 2)
		{
			blank2(a[i]+1);
			full(a[i + 1]);
			blank2(7 - a[i + 1]);
			full(a[i + 1]);
			blank2(7 - a[i + 1]);
			full(a[i + 1]);
			blank2(7 - a[i + 1]);
			full(a[i + 1]);
			blank2(7 - a[i +1]);
			full(a[i + 1]);
			line(1);
		}break;
	default:
		break;
	}
}
void candle::core(int a)
{
	switch (num)
	{
	case 1:
		
			blank2(15);
			coreB(a);
			line(1);

			blank2(15);
			coreB(a);
			line(1);
		break;
	case 2:
		
		blank2(8);
		coreA(a);
		blank2(9);
		coreA(a);
		line(1);

		blank2(8);
		coreB(a);
		blank2(9);
		coreB(a);
		line(1);


		break;
	case 3:
	
			blank2(5);
			coreA(a);
			blank2(5);
			coreA(a);
			blank2(5);
			coreA(a);
			line(1);

			blank2(5);
			coreB(a);
			blank2(5);
			coreB(a);
			blank2(5);
			coreB(a);
			line(1);

		
			break;
	case 4:
			blank2(3);
			coreA(a);
			blank2(3);
			coreA(a);
			blank2(3);
			coreA(a);
			blank2(3);
			coreA(a);
			line(1);

			blank2(3);
			coreB(a);
			blank2(3);
			coreB(a);
			blank2(3);
			coreB(a);
			blank2(3);
			coreB(a);
			line(1);
		break;
	case 5:
		
			blank2(1);
			coreA(a);
			blank2(2);
			coreA(a);
			blank2(2);
			coreA(a);
			blank2(2);
			coreA(a);
			blank2(2);
			coreA(a);
			line(1);

			blank2(1);
			coreB(a);
			blank2(2);
			coreB(a);
			blank2(2);
			coreB(a);
			blank2(2);
			coreB(a);
			blank2(2);
			coreB(a);
			line(1);
		break;

	default:
		break;
	}
}
void candle::root()
{
	switch (num)
	{
	case 1:
		if(touming==0)
		cout << r1; 
		else
		{
			if (touming == 1)cout << r12;
			else cout << r13;
		}
		return;
	case 2:
		cout << r2; return;
	case 3:
		cout << r3; return;
	case 4:
		cout << r4; return;
	case 5:
		if (touming == 0)
			cout << r5;
		else
		{
			if (touming == 1)cout << r52;
			else cout << r53;
		}
		return;
	default:
		break;
	}
}
void candle::actC(int i)
{
	int a=0, b=0,j;
	for (j = 0; act1[j] != -1; j++);
		a = j;
		for (j = 0; act2[j] != -1; j++);
		b = j;
		if (a == 0)
		{
			if (b == 0)
				color(15, 4);
			else color(act2[i % b], 4);
		}
		else
		{
			if (b == 0)
				color(15, act1[i % a]);
			else
				color(act2[i % b], act1[i % a]);
		}
}



int candle::mainColor = 14;
int candle::mainColorB = 12;


void can(candle& can1, candle& can2, candle& can3)
{

	if (LhuanJie == 1)
	{
		can1.kirakira();
		LhuanJie = 2;
		can1.startCol();
		Sleep(500);
	}
	else
	{
		can1.startCol();
		Sleep(500);
		LhuanJie = 1;
	}
	kaguyaEnd();
	endclear2();
	for (int a = -1; a != 7;)
	{
		can1.startCol();
		//选项模板
		clear(0);
		//blank2(17); outODy20("▄▄"); 
		line(1);
		blank2(15); halfDyJie(6); line(1);
		blank2(15); halfDyJie(1); outODyJie(" 月  烛 "); halfDyJie(1); line(1);
		blank2(15); halfDyJie(6); line(1);


		blank2(7); fullDyJie(22); line(1); 
		blank2(7);  fullDyJie(1); outODyJie("1.点燃蜡烛壹"); halfDyJie(1); outODyJie("2.点燃蜡烛贰"); halfDyJie(1); outODyJie("3.点燃蜡烛叁"); fullDyJie(1);	line(1);
		blank2(7);  fullDyJie(1); outODyJie("4.制作蜡烛壹"); halfDyJie(1); outODyJie("5.制作蜡烛贰"); halfDyJie(1); outODyJie("6.制作蜡烛叁"); fullDyJie(1);	line(1);
		blank2(7);  fullDyJie(1); fullDyJie(6); fullDyJie(1); fullDyJie(6); fullDyJie(1); fullDyJie(6); fullDyJie(1);	line(1);


		blank2(3); fullDyJie(5);  fullDyJie(6); fullDyJie(1); fullDyJie(6); fullDyJie(1);  fullDyJie(6); fullDyJie(5);	line(1);
		blank2(3); fullDyJie(30); line(1);

	
		blank2(3); fullDyJie(2); halfDyJie(10); fullDyJie(1); halfDyJie(4); fullDyJie(1); halfDyJie(10); fullDyJie(2);line(1);
		blank2(3); fullDyJie(2); halfDyJie(1);  outODyJie("「点燃已制作的  ");   halfDyJie(1);    fullDyJie(1); halfDyJie(1); outODyJie("快生"); halfDyJie(1); fullDyJie(1); halfDyJie(1);  outODyJie("「在六个设定下  ");   halfDyJie(1);             fullDyJie(2); line(1);
		blank2(3); fullDyJie(2); halfDyJie(1);  outODyJie("  蜡烛直至熄灭」");   halfDyJie(1);    fullDyJie(1); halfDyJie(1); outODyJie("乐日"); halfDyJie(1); fullDyJie(1); halfDyJie(1);  outODyJie("  制作新的蜡烛」");   halfDyJie(1);             fullDyJie(2); line(1);
		blank2(3); fullDyJie(2); halfDyJie(10); fullDyJie(1); halfDyJie(4); fullDyJie(1); halfDyJie(10); fullDyJie(2); line(1);
		blank2(3); fullDyJie(30); line(1);
		blank2(3); fullDyJie(30); line(1);

		line(2);


		//提示,共line5// 12字  修改蜡烛的设 定制作蜡烛  点燃制作后的  蜡烛直至熄灭
		blank2(5);  outOMDy("    7.生日祭"); line(2);
		//	blank2(5); blankMid(21); outODy("蜡烛熄灭后输入回车继续。"); line(1);
		//输入确认
		 blank2(6);
		a = inIntCan(1, 7, "稍后再见……", "我只是想再看看……");
		switch (a)
		{
		case 1:can1.light(); break;
		case 4:can1.setMain(); break;
		case 2:can2.light(); break;
		case 5:can2.setMain(); break;
		case 3:can3.light(); break;
		case 6:can3.setMain(); break;
		default:
			break;
		}
	}
}

void cakeDy()
{
	int a1[] = { 0,1,   13,6 ,-1 };
	drawDy(a1);
	int a2[] = { 0,1,0,1,  11,2,6,2 ,-1 };
	drawDy(a2);
	int a3[] = { 0,1,0,2,0,1,  9,2,3,1,6,2 ,-1 };
	drawDy(a3);
	int a4[] = { 0,1,0,2,0,2,0,1,  9,1,2,1,5,1,3,1 ,-1 };
	drawDy(a4);
	int a5[] = { 0,1,0,2,0,2,0,1,    9,1,6,1,3,1,1,1, -1 };
	drawDy(a5);
	int a6[] = { 0,1,0,2,0,1,      9,1,3,1,8,1 ,-1 };
	drawDy(a6);
	int a7[] = { 0,2,1,0,2,0,1,2,       8, 1,2,6,1,3,2,1 ,-1 };
	drawDy(a7);
	int a11[] = { 0,2,1,0,1,2,   7,2,4,6,4,2,-1 };
	drawDy(a11);
	int a12[] = { 0, 2,1,2,   7,2,14,2,-1 };
	drawDy(a12);
	int a13[] = { 0,2,1,2,   7,3,12,3,-1 };
	drawDy(a13);
	int a14[] = { 0,2,1,2,        7,5,8,5,-1 };
	drawDy(a14);
	int a15[] = { 0,2,  7,18, -1 };
	drawDy(a15);
	int a16[] = { 0,2,  7,18, -1 };
	drawDy(a16);


	int a17[] = { 0,2,  9,14,-1 };
	drawDy(a17);
	int a18[] = { 0,2,  11,10, -1 };
	drawDy(a18);
}
void cake1()
{
	clear(1);
	int a1[] = { 0,1,   13,6 ,-1 };
	draw(a1);
	int a2[] = { 0,1,0,1,  11,2,6,2 ,-1 };
	draw(a2);
	int a3[] = { 0,1,0,2,0,1,  9,2,3,1,6,2 ,-1 };
	draw(a3);
	int a4[] = { 0,1,0,2,0,2,0,1,  9,1,2,1,5,1,3,1 ,-1 };
	draw(a4);
	int a5[] = { 0,1,0,2,0,2,0,1,    9,1,6,1,3,1,1,1, -1 };
	draw(a5);
	int a6[] = { 0,1,0,2,0,1,      9,1,3,1,8,1 ,-1 };
	draw(a6);
	int a7[] = { 0,2,1,0,2,0,1,2,       8, 1,2,6,1,3,2,1 ,-1 };
	draw(a7);
	int a11[] = { 0,2,1,0,1,2,   7,2,4,6,4,2,-1 };
	draw(a11);
	int a12[] = { 0, 2,1,2,   7,2,14,2,-1 };
	draw(a12);
	int a13[] = { 0,2,1,2,   7,3,12,3,-1 };
	draw(a13);
	int a14[] = { 0,2,1,2,        7,5,8,5,-1 };
	draw(a14);
	int a15[] = { 0,2,  7,18, -1 };
	draw(a15);
	int a16[] = { 0,2,  7,18, -1 };
	draw(a16);


	int a17[] = { 0,2,  9,14,-1 };
	draw(a17);
	int a18[] = { 0,2,  11,10, -1 };
	draw(a18);
}
void cake2()
{
	clear(1);
	line(1);
	int a1[] = { 0,1,   13,6 ,-1 };
	draw(a1);
	int a2[] = { 0,1,0,1,  11,2,6,2 ,-1 };
	draw(a2);
	int a3[] = { 0,1,0,2,0,1,  9,2,3,1,6,2 ,-1 };
	draw(a3);
	int a4[] = { 0,1,0,2,0,2,0,1,  9,1,2,1,5,1,3,1 ,-1 };
	draw(a4);
	int a5[] = { 0,1,0,2,0,2,0,1,    9,1,6,1,3,1,1,1, -1 };
	draw(a5);
	int a6[] = { 0,1,0,2,0,1,      9,1,3,1,8,1 ,-1 };
	draw(a6);
	int a7[] = { 0,2,1,0,2,0,1,2,       8, 1,2,6,1,3,2,1 ,-1 };
	draw(a7);
	int a11[] = { 0,2,1,0,1,2,   7,2,4,6,4,2,-1 };
	draw(a11);
	int a12[] = { 0, 2,1,2,   7,2,14,2,-1 };
	draw(a12);
	int a13[] = { 0,2,1,2,   7,3,12,3,-1 };
	draw(a13);
	int a14[] = { 0,2,1,2,        7,5,8,5,-1 };
	draw(a14);
	int a15[] = { 0,2,  7,18, -1 };
	draw(a15);
	int a16[] = { 0,2,  7,18, -1 };
	draw(a16);


	int a17[] = { 0,2,  9,14,-1 };
	draw(a17);
	int a18[] = { 0,2,  11,10, -1 };
	draw(a18);
}
void cake3()
{
	clear(1);
	line(2);
	int a1[] = { 0,1,   13,6 ,-1 };
	draw(a1);
	int a2[] = { 0,1,0,1,  11,2,6,2 ,-1 };
	draw(a2);
	int a3[] = { 0,1,0,2,0,1,  9,2,3,1,6,2 ,-1 };
	draw(a3);
	int a4[] = { 0,1,0,2,0,2,0,1,  9,1,2,1,5,1,3,1 ,-1 };
	draw(a4);
	int a5[] = { 0,1,0,2,0,2,0,1,    9,1,6,1,3,1,1,1, -1 };
	draw(a5);
	int a6[] = { 0,1,0,2,0,1,      9,1,3,1,8,1 ,-1 };
	draw(a6);
	int a7[] = { 0,2,1,0,2,0,1,2,       8, 1,2,6,1,3,2,1 ,-1 };
	draw(a7);
	int a11[] = { 0,2,1,0,1,2,   7,2,4,6,4,2,-1 };
	draw(a11);
	int a12[] = { 0, 2,1,2,   7,2,14,2,-1 };
	draw(a12);
	int a13[] = { 0,2,1,2,   7,3,12,3,-1 };
	draw(a13);
	int a14[] = { 0,2,1,2,        7,5,8,5,-1 };
	draw(a14);
	int a15[] = { 0,2,  7,18, -1 };
	draw(a15);
	int a16[] = { 0,2,  7,18, -1 };
	draw(a16);


	int a17[] = { 0,2,  9,14,-1 };
	draw(a17);
	int a18[] = { 0,2,  11,10, -1 };
	draw(a18);
}
void cakePan()
{
	int a1[] = { 0,1,   13,6 ,-1 };
	draw(a1);
	int a2[] = { 0,1,0,1,  11,2,6,2 ,-1 };
	draw(a2);
	int a3[] = { 0,1,0,2,0,1,  9,2,3,1,6,2 ,-1 };
	draw(a3);
	int a4[] = { 0,1,0,2,0,2,0,1,  9,1,2,1,5,1,3,1 ,-1 };
	draw(a4);


	int a5[] = { 0,2,  1,0,2,0,2,0,1,2,    6,3,1,6,1,3,1,1,1, 9,-1 };
	draw(a5);
	int a6[] = { 0,2,0,1,0,2,0,1,0,2,      5,1,3,1,3,1,8,1 ,8,1,-1 };
	draw(a6);
	int a7[] = { 0,2,0,2,1,0,2,0,1,2,0,2,       5,1,2, 1,2,6,1,3,2,1,6,1 ,-1 };
	draw(a7);
	int a11[] = { 0,2,0,2,1,0,1,2,0,2,   4,1,2,2,4,6,4,2,5,1,-1 };
	draw(a11);
	int a12[] = { 0,2,0, 2,1,2,0,2,        4,1,2,2,14,2,4,1,-1 };
	draw(a12);
	int a13[] = { 0,2,0,2,1,2,0,2,   3,1,3,3,12,3,4,1,-1 };
	draw(a13);
	int a14[] = { 0,2,0,2,1,2,0,2,        3,1,3,5,8,5,3,1,-1 };
	draw(a14);
	int a15[] = { 0,2,0,2,0,2,  2,1,4,18,3,1,-1 };
	draw(a15);
	int a16[] = { 0,2,0,2,0,2,  2,1,4,18,2,1,-1 };
	draw(a16);

	int a17[] = { 0,2,0,2,0,2,  1,1,7,14,4,1,-1 };
	draw(a17);
	int a18[] = { 0,2,0,2,0,2,  1,1,9,10,5,1,-1 };
	draw(a18);
	int a19[] = { 2,0,2,  1,25,1,-1 };
	draw(a19);
	int a20[] = { 2, 26 ,-1};
	draw(a20);
}
