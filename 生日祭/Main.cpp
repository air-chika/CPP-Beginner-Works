#include <iostream>
#include"d1.h"
#include"d2.h"
#include"candle.h"
using namespace std;
int main()
{

	//candle can1;
	//can1.test();
	//can1.lightTest();
	//SetConsoleTitle("生日祭");
	int ding = 0;
	//chushi();
	color(0, 8);
	//outODy(" Glow under the moon.",38);
	//getS();
	//GlowMoon();

	clear(0);
	candle can1; can1.rank = 1; can1.haiyuezhu();
	candle can2; can2.rank = 2; can2.rixiangzhimeng();
	candle can3; can3.rank = 3; can3.kisstheinfinitedream();
	while (1)
	{
		kaguya();
		kaguyaStar();
		int a = inIntO(1, 2, "★始", "意味わからない……", 40);
		switch (a)
		{
		case 1:  can(can1,can2,can3); break;
		case 2:  huanghun(); break;
	//	case 3:kaguyaEnd(); Sleep(500);  changmo();  break;
		case 3:  endclear2();
		default:
			break;
		}
	}
}