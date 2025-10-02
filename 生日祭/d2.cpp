#include"d2.h"

int dy_star = 20;
int dy_star2 = 500;
int dy_starShine = 125;

void GlowMoon()
{
	int a = 20;
	clear(0);
	color(0, 14);
	printf(" Glow under the moon.");
	Sleep(1000);
	clear(0);
	color(0, 14);
	printf(" Glow under the moon");
	
	Sleep(a); clear(0);
	printf(" Glow under the moo");
	
	Sleep(a); clear(0);
	printf(" Glow under the mo");
	
	Sleep(a); clear(0);
	printf(" Glow under the m");
	
	Sleep(a); clear(0);
	printf(" Glow under the ");
	
	Sleep(a); clear(0);
	printf(" Glow under the");
	
	Sleep(a); clear(0);
	printf(" Glow under th");
	
	Sleep(a); clear(0);
	printf(" Glow under t");
	 
	Sleep(a); clear(0);
	printf(" Glow under ");
	
	Sleep(a); clear(0);
	printf(" Glow under");
	
	Sleep(a); clear(0);
	printf(" Glow unde");
	
	Sleep(a); clear(0);
	printf(" Glow und");
	
	Sleep(a); clear(0);
	printf(" Glow un");
	
	Sleep(a); clear(0);
	printf(" Glow u");
	
	Sleep(a); clear(0);
	printf(" Glow ");
	
	Sleep(a); clear(0);
	printf(" Glow");
	
	Sleep(a); clear(0);
	printf(" Glo");
	
	Sleep(a); clear(0);
	printf(" Gl");
	
	Sleep(a); clear(0);
	printf(" G");
	
	Sleep(a); clear(0);
	
	 Sleep(350);
}



void kaguya0()
{
	clear(0);
	int i;
	for (i = 0; i < 3; i++)
	{
		full(33);
		blank2(1);
		//if (i == 1) outO("二");
		//if (i == 2) outO("零");
		line(1);

	}
	for (i = 0; i < 2; i++)
	{
		full(32); blank2(2);
		//if (i == 0) outO("二");
		//if (i == 1) outO("一");
		line(1);
	}
	for (i = 0; i < 2; i++)
	{
		full(31); blank2(3);
		//if (i == 0) outO("年");
		//if (i == 1) outO("·");
		line(1);
	}
	for (i = 30; i >= 26; i--)
	{

		full(i);
		//if (i == 30) { blank2(4); outO("六"); }
		//if (i == 29) { blank2(5); outO("月"); }
		//if (i == 28) { blank2(2);  blank2(4); outO("二"); }
		//if (i == 27) { blank2(3);  blank2(4); outO("日"); }

		line(1);
	}
	full(25);  line(1);//标记
	full(24);  blank2(7); half(3);   line(1);
	full(23); blank2(8); half(1); outO("生"); half(1);    line(1);
	full(21);   blank2(10); half(1); outO("日"); half(1);  line(1);//标记
	full(19);  blank2(12); half(1); outO("祭"); half(1);  line(1);
}
void kaguyaStar()
{
	kaguya0();
	full(17); blank2(6); outO("★ 月  烛 ★"); blank2(2); half(3);  line(1); line(1);
	full(14); blank2(9); outO("★黄昏草月★");  line(1);
	full(11); blank2(12); outO("☆ 場  末 ☆"); line(1);
	full(6); blank2(17); 
}
void kaguya1()
{
	clear(0);
	int c = 10, d=15,a = 20, b = 35, i,e=12;
	//if(cmpcol()!=1)
	for (i = 0; i < 3; i++)
	{
		fullDy(33, c); 
		blank2(1);
	//	if (i == 1) outO("二");
	//	if (i == 2) outO("零");
		line(1);
		
	}
	for (i = 0; i < 2; i++)
	{
		fullDy(32, c); blank2(2);
	//if (i == 0) outO("二");
	//if (i == 1) outO("一");
	line(1);
	}
	
	//	fullDy(31, e);  blank2(3); outO("年"); line(1);
	//	fullDy(31, e);  blank2(3); outO("·"); line(1);
	
	for (i = 30; i >= 26; i--)
	{
		
		fullDy(i, d); 
	//	if (i == 30) { blank2(4); outO("六"); }
	//	if (i == 29) { blank2(5); outO("月"); }
	//	if (i == 28) { blank2(2);  blank2(4); outO("二"); }
	//	if (i == 27) { blank2(3);  blank2(4); outO("日"); }
		if (i == 26) { blank2(4);  blank2(4);  }
		
		line(1);
	}
	fullDy(25, a); blank2(9); line(1);//标记
	fullDy(24, a);  blank2(2); halfDy(3, a); blank2(4);   line(1);
	fullDy(23, a); blank2(3); halfDy(1,a); outO("生"); halfDy(1,a);    line(1);
	fullDy(21,a);   blank2(5); halfDy(1, a); outO("日"); halfDy(1,a);  line(1);//标记
	fullDy(19, a);  blank2(7); halfDy(1, a); outO("祭"); halfDy(1,a);    line(1);
	fullDy(17, a); blank2(9);  halfDy(3, a);  line(1);
	fullDy(14, b); blank2(12);   line(1);
	fullDy(11, b); blank2(15);  line(1);
	fullDy(6, b); line(1);
}
void kaguya10()
{
	clear(0);
	//if(cmpcol()!=1)
	int i;
	for (i = 0; i < 3; i++)
	{
		full(33 );
		blank2(1);
		if (i == 1) outO("二");
		if (i == 2) outO("零");
		line(1);

	}
	for (i = 0; i < 2; i++)
	{
		full(32); blank2(2);
		if (i == 0) outO("二");
		if (i == 1) outO("一");
		line(1);
	}

	full(31);  blank2(3); outO("年"); line(1);
	full(31);  blank2(3); outO("·"); line(1);

	for (i = 30; i >= 26; i--)
	{

		full(i);
		if (i == 30) { blank2(4); outO("六"); }
		if (i == 29) { blank2(5); outO("月"); }
		if (i == 28) { blank2(2);  blank2(4); outO("二"); }
		if (i == 27) { blank2(3);  blank2(4); outO("日"); }
		if (i == 26) { blank2(4);  blank2(4); }

		line(1);
	}
	full(25); blank2(9); line(1);//标记
	full(24);  blank2(2); half(3); blank2(4);   line(1);
	full(23); blank2(3); half(1); outO("月"); half(1);    line(1);
	full(21);   blank2(5); half(1); outO("下"); half(1);  line(1);//标记
	full(19);  blank2(7); half(1); outO("の"); half(1);    line(1);
	full(17); blank2(9);  half(1); outO("辉"); half(1);  line(1);
	full(14); blank2(12);  half(1); outO("夜"); half(1);  line(1);
	full(11); blank2(15); half(3);  line(1);
	full(6); line(1);
}
void kaguya12()
{
	clear(0);
	int  i;
	for (i = 0; i < 3; i++)
	{
		full(33);
		blank2(1);
		if (i == 1) outO("二");
		if (i == 2) outO("零");
		line(1);

	}
	for (i = 0; i < 2; i++)
	{
		full(32); blank2(2);
		if (i == 0) outO("二");
		if (i == 1) outO("一");
		line(1);
	}
	for (i = 0; i < 2; i++)
	{
		full(31); blank2(3);
		if (i == 0) outO("年");
		if (i == 1) outO("·");
		line(1);
	}
	for (i = 30; i >= 26; i--)
	{

		full(i);
		if (i == 30) { blank2(4); outO("六"); }
		if (i == 29) { blank2(5); outO("月"); }
		if (i == 28) { blank2(2);  blank2(4); outO("二"); }
		if (i == 27) { blank2(3);  blank2(4); outO("日"); }
		if (i == 26) { blank2(4); }

		line(1);
	}
	full(25); line(1);//标记
	full(24);  blank(5); half(3); line(1);
	full(23); blank(7); half(1); outO("月"); half(1);    line(1);
	full(21);   blank(11); half(1); outO("下"); half(1);  line(1);//标记
	full(19);  blank(15); half(1); outO("の"); half(1);    line(1);
	full(17); blank(19);  half(1); outO("辉"); half(1); line(1);
	full(14); blank(25);  half(1); outO("夜"); half(1); line(1);
	full(11); blank(31); half(3);  line(1);
	full(6); line(1);
}
void kaguya2()
{
	clear(0);
	int  i;
	for (i = 0; i < 3; i++)
	{
		full(33);
		blank2(1);
		if (i == 1) outO("二");
		if (i == 2) outO("零");
		line(1);

	}
	for (i = 0; i < 2; i++)
	{
		full(32); blank2(2);
		if (i == 0) outO("二");
		if (i == 1) outO("一");
		line(1);
	}
	for (i = 0; i < 2; i++)
	{
		full(31); blank2(3);
		if (i == 0) outO("年");
		if (i == 1) outO("·");
		line(1);
	}
	for (i = 30; i >= 26; i--)
	{

		full(i);
		if (i == 30) { blank2(4); outO("六"); }
		if (i == 29) { blank2(5); outO("月"); }
		if (i == 28) { blank2(2);  blank2(4); outO("二"); }
		if (i == 27) { blank2(3);  blank2(4); outO("日"); }
		if (i == 26) { blank2(4);   }

		line(1);
	}
	full(25); line(1);//标记
	full(24);  blank2(3); half(3); blank2(3);  line(1);
	full(23); blank2(4); half(1); outO("月"); half(1);    line(1);
	full(21);   blank2(6); half(1); outO("下"); half(1);  line(1);//标记
	full(19);  blank2(8); half(1); outO("の"); half(1);    line(1);
	full(17); blank2(10);  half(1); outO("辉"); half(1); line(1);
	full(14); blank2(13);  half(1); outO("夜"); half(1); line(1);
	full(11); blank2(16); half(3);  line(1);
	full(6); line(1);
}
void kaguya22()
{
	clear(0);
	int  i;
	for (i = 0; i < 3; i++)
	{
		full(33);
		blank2(1);
		if (i == 1) outO("二");
		if (i == 2) outO("零");
		line(1);

	}
	for (i = 0; i < 2; i++)
	{
		full(32); blank2(2);
		if (i == 0) outO("二");
		if (i == 1) outO("一");
		line(1);
	}
	for (i = 0; i < 2; i++)
	{
		full(31); blank2(3);
		if (i == 0) outO("年");
		if (i == 1) outO("·");
		line(1);
	}
	for (i = 30; i >= 26; i--)
	{

		full(i);
		if (i == 30) { blank2(4); outO("六"); }
		if (i == 29) { blank2(5); outO("月"); }
		if (i == 28) { blank2(2);  blank2(4); outO("二"); }
		if (i == 27) { blank2(3);  blank2(4); outO("日"); }
		if (i == 26) { blank2(4); }

		line(1);
	}
	full(25); line(1);//标记
	full(24);  blank(7); half(3);   line(1);
	full(23); blank(9); half(1); outO("月"); half(1);    line(1);
	full(21);   blank(13); half(1); outO("下"); half(1);  line(1);//标记
	full(19);  blank(17); half(1); outO("の"); half(1);    line(1);
	full(17); blank(21);  half(1); outO("辉"); half(1); line(1);
	full(14); blank(27);  half(1); outO("夜"); half(1); line(1);
	full(11); blank(33); half(3);  line(1);
	full(6); line(1);
}
void kaguya3()
{
	clear(0);
	int  i;
	for (i = 0; i < 3; i++)
	{
		full(33);
		blank2(1);
		if (i == 1) outO("二");
		if (i == 2) outO("零");
		line(1);

	}
	for (i = 0; i < 2; i++)
	{
		full(32); blank2(2);
		if (i == 0) outO("二");
		if (i == 1) outO("一");
		line(1);
	}
	for (i = 0; i < 2; i++)
	{
		full(31); blank2(3);
		if (i == 0) outO("年");
		if (i == 1) outO("·");
		line(1);
	}
	for (i = 30; i >= 26; i--)
	{

		full(i);
		if (i == 30) { blank2(4); outO("六"); }
		if (i == 29) { blank2(5); outO("月"); }
		if (i == 28) { blank2(2);  blank2(4); outO("二"); }
		if (i == 27) { blank2(3);  blank2(4); outO("日"); }
		if (i == 26) { blank2(4);  blank2(4); }

		line(1);
	}
	full(25); blank2(9);  line(1);//标记
	full(24);  blank2(4); half(3); blank2(3);  line(1);
	full(23); blank2(5); half(1); outO("月"); half(1);    line(1);
	full(21);   blank2(7); half(1); outO("下"); half(1);  line(1);//标记
	full(19);  blank2(9); half(1); outO("の"); half(1);    line(1);
	full(17); blank2(11);  half(1); outO("辉"); half(1); line(1);
	full(14); blank2(14);  half(1); outO("夜"); half(1); line(1);
	full(11); blank2(17); half(3);  line(1);
	full(6); line(1);
}
void kaguya32()
{
	clear(0);
	int  i;
	for (i = 0; i < 3; i++)
	{
		full(33);
		blank2(1);
		if (i == 1) outO("二");
		if (i == 2) outO("零");
		line(1);

	}
	for (i = 0; i < 2; i++)
	{
		full(32); blank2(2);
		if (i == 0) outO("二");
		if (i == 1) outO("一");
		line(1);
	}
	for (i = 0; i < 2; i++)
	{
		full(31); blank2(3);
		if (i == 0) outO("年");
		if (i == 1) outO("·");
		line(1);
	}
	for (i = 30; i >= 26; i--)
	{

		full(i);
		if (i == 30) { blank2(4); outO("六"); }
		if (i == 29) { blank2(5); outO("月"); }
		if (i == 28) { blank2(2);  blank2(4); outO("二"); }
		if (i == 27) { blank2(3);  blank2(4); outO("日"); }
		if (i == 26) { blank2(4);  blank2(4); }

		line(1);
	}
	full(25); blank2(9);  line(1);//标记
	full(24);  blank(9); half(3);  line(1);
	full(23); blank(11); half(1); outO("月"); half(1);    line(1);
	full(21);   blank(15); half(1); outO("下"); half(1);  line(1);//标记
	full(19);  blank(19); half(1); outO("の"); half(1);    line(1);
	full(17); blank(23);  half(1); outO("辉"); half(1); line(1);
	full(14); blank(29);  half(1); outO("夜"); half(1); line(1);
	full(11); blank(35); half(3);  line(1);
	full(6); line(1);
}
void kaguya4()
{
	clear(0);
	int i;
	for (i = 0; i < 3; i++)
	{
		full(33);
		blank2(1);
		if (i == 1) outO("二");
		if (i == 2) outO("零");
		line(1);

	}
	for (i = 0; i < 2; i++)
	{
		full(32); blank2(2);
		if (i == 0) outO("二");
		if (i == 1) outO("一");
		line(1);
	}
	for (i = 0; i < 2; i++)
	{
		full(31); blank2(3);
		if (i == 0) outO("年");
		if (i == 1) outO("·");
		line(1);
	}
	for (i = 30; i >= 26; i--)
	{

		full(i);
		if (i == 30) { blank2(4); outO("六"); }
		if (i == 29) { blank2(5); outO("月"); }
		if (i == 28) { blank2(2);  blank2(4); outO("二"); }
		if (i == 27) { blank2(3);  blank2(4); outO("日"); }
		if (i == 26) { blank2(4);  blank2(4); }

		line(1);
	}
	full(25); blank2(9);  line(1);//标记
	full(24);  blank2(5); half(3); blank2(3);  line(1);
	full(23); blank2(6); half(1); outO("月"); half(1);    line(1);
	full(21);   blank2(8); half(1); outO("下"); half(1);  line(1);//标记
	full(19);  blank2(10); half(1); outO("の"); half(1);    line(1);
	full(17); blank2(12);  half(1); outO("辉"); half(1); line(1);
	full(14); blank2(15);  half(1); outO("夜"); half(1); line(1);
	full(11); blank2(18); half(3);  line(1);
	full(6); line(1);
}
void kaguya42()
{
	clear(0);
	int i;
	for (i = 0; i < 3; i++)
	{
		full(33);
		blank2(1);
		if (i == 1) outO("二");
		if (i == 2) outO("零");
		line(1);

	}
	for (i = 0; i < 2; i++)
	{
		full(32); blank2(2);
		if (i == 0) outO("二");
		if (i == 1) outO("一");
		line(1);
	}
	for (i = 0; i < 2; i++)
	{
		full(31); blank2(3);
		if (i == 0) outO("年");
		if (i == 1) outO("·");
		line(1);
	}
	for (i = 30; i >= 26; i--)
	{

		full(i);
		if (i == 30) { blank2(4); outO("六"); }
		if (i == 29) { blank2(5); outO("月"); }
		if (i == 28) { blank2(2);  blank2(4); outO("二"); }
		if (i == 27) { blank2(3);  blank2(4); outO("日"); }
		if (i == 26) { blank2(4);  blank2(4); }

		line(1);
	}
	full(25); blank2(9);  line(1);//标记
	full(24);  blank(11); half(3);  line(1);
	full(23); blank(13); half(1); outO("月"); half(1);    line(1);
	full(21);   blank(17); half(1); outO("下"); half(1);  line(1);//标记
	full(19);  blank(21); half(1); outO("の"); half(1);    line(1);
	full(17); blank(25);  half(1); outO("辉"); half(1); line(1);
	full(14); blank(31);  half(1); outO("夜"); half(1); line(1);
	full(11); blank(37); half(3);  line(1);
	full(6); line(1);
}
void kaguya5()
{
	clear(0);
	int i;
	for (i = 0; i < 3; i++)
	{
		full(33);
		blank2(1);
		if (i == 1) outO("二");
		if (i == 2) outO("零");
		line(1);

	}
	for (i = 0; i < 2; i++)
	{
		full(32); blank2(2);
		if (i == 0) outO("二");
		if (i == 1) outO("一");
		line(1);
	}
	for (i = 0; i < 2; i++)
	{
		full(31); blank2(3);
		if (i == 0) outO("年");
		if (i == 1) outO("·");
		line(1);
	}
	for (i = 30; i >= 26; i--)
	{

		full(i);
		if (i == 30) { blank2(4); outO("六"); }
		if (i == 29) { blank2(5); outO("月"); }
		if (i == 28) { blank2(2);  blank2(4); outO("二"); }
		if (i == 27) { blank2(3);  blank2(4); outO("日"); }
		if (i == 26) { blank2(4);  blank2(4); }

		line(1);
	}
	full(25); blank2(9);   line(1);//标记
	full(24);  blank2(6); half(3); line(1);
	full(23); blank2(7); half(1); outO("月"); half(1);    line(1);
	full(21);   blank2(9); half(1); outO("下"); half(1);  line(1);//标记
	full(19);  blank2(11); half(1); outO("の"); half(1);    line(1);
	full(17); blank2(13);  half(1); outO("辉"); half(1); line(1);
	full(14); blank2(16);  half(1); outO("夜"); half(1); line(1);
	full(11); blank2(19); half(3);  line(1);
	full(6); line(1);

}
void kaguya52()
	{
		clear(0);
		int i;
		for (i = 0; i < 3; i++)
		{
			full(33);
			blank2(1);
			if (i == 1) outO("二");
			if (i == 2) outO("零");
			line(1);

		}
		for (i = 0; i < 2; i++)
		{
			full(32); blank2(2);
			if (i == 0) outO("二");
			if (i == 1) outO("一");
			line(1);
		}
		for (i = 0; i < 2; i++)
		{
			full(31); blank2(3);
			if (i == 0) outO("年");
			if (i == 1) outO("·");
			line(1);
		}
		for (i = 30; i >= 26; i--)
		{

			full(i);
			if (i == 30) { blank2(4); outO("六"); }
			if (i == 29) { blank2(5); outO("月"); }
			if (i == 28) { blank2(2);  blank2(4); outO("二"); }
			if (i == 27) { blank2(3);  blank2(4); outO("日"); }
			if (i == 26) { blank2(4);  blank2(4); }

			line(1);
		}
		full(25); blank2(9);   line(1);//标记
		full(24);  blank(13); half(3); line(1);
		full(23); blank(15); half(1); outO("月"); half(1);    line(1);
		full(21);   blank(19); half(1); outO("下"); half(1);  line(1);//标记
		full(19);  blank(23); half(1); outO("の"); half(1);    line(1);
		full(17); blank(27);  half(1); outO("辉"); half(1); line(1);
		full(14); blank(33);  half(1); outO("夜"); half(1); line(1);
		full(11); blank(39); half(3);  line(1);
		full(6); line(1);

	}
void kaguya6()
{
	clear(0);
	int i;
	for (i = 0; i < 3; i++)
	{
		full(33);
		blank2(1);
		if (i == 1) outO("二");
		if (i == 2) outO("零");
		line(1);

	}
	for (i = 0; i < 2; i++)
	{
		full(32); blank2(2);
		if (i == 0) outO("二");
		if (i == 1) outO("一");
		line(1);
	}
	for (i = 0; i < 2; i++)
	{
		full(31); blank2(3);
		if (i == 0) outO("年");
		if (i == 1) outO("·");
		line(1);
	}
	for (i = 30; i >= 26; i--)
	{

		full(i);
		if (i == 30) { blank2(4); outO("六"); }
		if (i == 29) { blank2(5); outO("月"); }
		if (i == 28) { blank2(2);  blank2(4); outO("二"); }
		if (i == 27) { blank2(3);  blank2(4); outO("日"); }
		if (i == 26) { blank2(4);  blank2(4); }

		line(1);
	}
	full(25);  line(1);//标记
	full(24);  blank2(7); half(3);  line(1);
	full(23); blank2(8); half(1); outO("月"); half(1);    line(1);
	full(21);   blank2(10); half(1); outO("下"); half(1);  line(1);//标记
	full(19);  blank2(12); half(1); outO("の"); half(1);    line(1);
	full(17); blank2(14);  half(1); outO("辉"); half(1); line(1);
	full(14); blank2(17);  half(1); outO("夜"); half(1); line(1);
	full(11); blank2(20); half(3);  line(1);
	full(6); line(1);

}

void kaguyaStar1()
{ 
	kaguya0();
	full(17); blank2(6); outO("☆"); blank2(7);  half(1); outO("辉"); half(1); line(1);
	full(14); blank2(17);  half(1); outO("夜"); half(1); line(1);
	full(11); blank2(20); half(3);  line(1);
	full(6); line(1); Sleep(dy_star);
}
void kaguyaStar2()
{  
	kaguya0();
	full(17); blank2(6); outO("☆ 月"); blank(11);  half(1); outO("辉"); half(1); line(1);
	full(14); blank2(17);  half(1); outO("夜"); half(1); line(1);
	full(11); blank2(20); half(3);  line(1);
	full(6); line(1); Sleep(dy_star);
}
void kaguyaStar3()
{
	kaguya0();
	full(17); blank2(6); outO("☆ 月  烛"); blank(7);  half(1); outO("辉"); half(1); line(1);
	full(14); blank2(17);  half(1); outO("夜"); half(1); line(1);
	full(11); blank2(20); half(3);  line(1);
	full(6); line(1); Sleep(dy_star);
}
void kaguyaStar4()
{
	kaguya0();
	full(17); blank2(6); outO("☆ 月  烛 ☆"); blank(4);  half(1); outO("辉"); half(1); line(1);
	full(14); blank2(17);  half(1); outO("夜"); half(1); line(1);
	full(11); blank2(20); half(3);  line(1);
	full(6); line(1); Sleep(dy_star2);
}
void kaguyaStar5()
{
	kaguya0();
	full(17); blank2(6); outO("☆ 月  烛 ☆"); blank2(2);  half(1); outO("辉"); half(1); line(1);
	full(14); blank2(9); outO("☆"); blank2(7); half(1); outO("夜"); half(1); line(1);
	full(11); blank2(20); half(3);  line(1);
	full(6); line(1); Sleep(dy_star);
}
void kaguyaStar6()
{
	kaguya0();
	full(17); blank2(6); outO("☆ 月  烛 ☆"); blank2(2);  half(1); outO("辉"); half(1); line(1);
	full(14); blank2(9); outO("☆黄"); blank2(6); half(1); outO("夜"); half(1); line(1);
	full(11); blank2(20); half(3);  line(1);
	full(6); line(1); Sleep(dy_star);
}
void kaguyaStar7()
{
	kaguya0();
	full(17); blank2(6); outO("☆ 月  烛 ☆"); blank2(2);  half(1); outO("辉"); half(1); line(1);
	full(14); blank2(9); outO("☆黄昏"); blank2(5); half(1); outO("夜"); half(1); line(1);
	full(11); blank2(20); half(3);  line(1);
	full(6); line(1); Sleep(dy_star);
}
void kaguyaStar8()
{
	kaguya0();
	full(17); blank2(6); outO("☆ 月  烛 ☆"); blank2(2);  half(1); outO("辉"); half(1); line(1);
	full(14); blank2(9); outO("☆黄昏草"); blank2(4); half(1); outO("夜"); half(1); line(1);
	full(11); blank2(20); half(3);  line(1);
	full(6); line(1); Sleep(dy_star);
}
void kaguyaStar9()
{
	kaguya0();
	full(17); blank2(6); outO("☆ 月  烛 ☆"); blank2(2);  half(1); outO("辉"); half(1); line(1);
	full(14); blank2(9); outO("☆黄昏草月"); blank2(3); half(1); outO("夜"); half(1); line(1);
	full(11); blank2(20); half(3);  line(1);
	full(6); line(1); Sleep(dy_star);
}
void kaguyaStar10()
{
	kaguya0();
	full(17); blank2(6); outO("☆ 月  烛 ☆"); blank2(2);  half(1); outO("辉"); half(1); line(1);
	full(14); blank2(9); outO("☆黄昏草月☆"); blank2(2); half(1); outO("夜"); half(1); line(1);
	full(11); blank2(20); half(3);  line(1);
	full(6); line(1); Sleep(dy_star2);
}
void kaguyaStar11()
{
	kaguya0();
	full(17); blank2(6); outO("☆ 月  烛 ☆"); blank2(2);  half(1); outO("辉"); half(1); line(1);
	full(14); blank2(9); outO("☆黄昏草月☆"); blank2(2); half(1); outO("夜"); half(1); line(1);
	full(11); blank2(12); outO("☆"); blank2(7); half(3);  line(1);
	full(6); line(1); Sleep(dy_star);
}
void kaguyaStar12()
{
	kaguya0();
	full(17); blank2(6); outO("☆ 月  烛 ☆"); blank2(2);  half(1); outO("辉"); half(1); line(1);
	full(14); blank2(9); outO("☆黄昏草月☆"); blank2(2); half(1); outO("夜"); half(1); line(1);
	full(11); blank2(12); outO("☆ 場"); blank(11); half(3);  line(1);
	full(6); line(1); Sleep(dy_star);
}
void kaguyaStar13()
{
	kaguya0();
	full(17); blank2(6); outO("☆ 月  烛 ☆"); blank2(2);  half(1); outO("辉"); half(1); line(1);
	full(14); blank2(9); outO("☆黄昏草月☆"); blank2(2); half(1); outO("夜"); half(1); line(1);
	full(11); blank2(12); outO("☆ 場  末"); blank(7); half(3);  line(1);
	full(6); line(1); Sleep(dy_star);
}
void kaguyaStar14()
{
	kaguya0();
	full(17); blank2(6); outO("☆ 月  烛 ☆"); blank2(2);  half(1); outO("辉"); half(1); line(1);
	full(14); blank2(9); outO("☆黄昏草月☆"); blank2(2); half(1); outO("夜"); half(1); line(1);
	full(11); blank2(12);outO("☆ 場  末 ☆"); blank(4); half(3);  line(1);
	full(6); line(1); Sleep(dy_star2);
}
void kaguyaStar15()
{
	kaguya0();
	full(17); blank2(6); outO("☆ 月  烛 ☆"); blank2(2);  half(1); outO("辉"); half(1); line(1);
	full(14); blank2(9); outO("☆黄昏草月☆"); blank2(2); half(1); outO("夜"); half(1); line(1);
	full(11); blank2(12); outO("☆ 場  末 ☆"); blank(4); half(3);  line(1);
	full(6); blank2(17); outO("☆"); line(1);
	Sleep(dy_star);
}
void kaguyaStar16()
{
	kaguya0();
	full(17); blank2(6); outO("☆ 月  烛 ☆"); blank2(2);  half(1); outO("辉"); half(1); line(1);
	full(14); blank2(9); outO("☆黄昏草月☆"); blank2(2); half(1); outO("夜"); half(1); line(1);
	full(11); blank2(12); outO("☆ 場  末 ☆"); blank(4); half(3);  line(1);
	full(6); blank2(17); outO("☆始"); line(1);
	Sleep(dy_star);
}
void kaguyaStar17()
{
	kaguya0();
	full(17); blank2(6); outO("☆ 月  烛 ☆"); blank2(2);  half(1); outO("辉"); half(1); line(1);
	full(14); blank2(9); outO("☆黄昏草月☆"); blank2(2); half(1); outO("夜"); half(1); line(1);
	full(11); blank2(12); outO("☆ 場  末 ☆"); blank(4); half(3);  line(1);
	full(6); blank2(17); outO("☆始め"); line(1);
	Sleep(dy_star);
}
void kaguyaStar18()
{
	kaguya0();
	full(17); blank2(6); outO("☆ 月  烛 ☆"); blank2(2);  half(1); outO("辉"); half(1); line(1);
	full(14); blank2(9); outO("☆黄昏草月☆"); blank2(2); half(1); outO("夜"); half(1); line(1);
	full(11); blank2(12); outO("☆ 場  末 ☆"); blank(4); half(3);  line(1);
	full(6); blank2(17); outO("☆始める"); line(1);
	Sleep(dy_star);
}
void kaguyaStar19()
{
	kaguya0();
	full(17); blank2(6); outO("☆ 月  烛 ☆"); blank2(2);  half(1); outO("辉"); half(1); line(1);
	full(14); blank2(9); outO("☆黄昏草月☆"); blank2(2); half(1); outO("夜"); half(1); line(1);
	full(11); blank2(12);outO("☆ 場  末 ☆"); blank(4); half(3);  line(1);
	full(6); blank2(17); outO("☆始めるよ"); line(1);
	Sleep(dy_star);
}
void kaguyaStar20()
{
	kaguya0();
	full(17); blank2(6); outO("☆ 月  烛 ☆"); blank2(2);  half(1); outO("辉"); half(1); line(1);
	full(14); blank2(9); outO("☆黄昏草月☆"); blank2(2); half(1); outO("夜"); half(1); line(1);
	full(11); blank2(12); outO("☆ 場  末 ☆"); blank(4); half(3);  line(1);
	full(6); blank2(17); outO("☆始めるよ☆"); line(1);
	Sleep(dy_star2);
}

void kaguyaStar21(int i)
{
	kaguya0();
	full(17); blank2(6); outO("☆ 月  烛 ☆"); blank2(2);  half(1); outO("辉"); half(1); line(1);
	full(14); blank2(9); outO("☆黄昏草月☆"); blank2(2); half(1); outO("夜"); half(1); line(1);
	full(11); blank2(12);outO("☆ 場  末 ☆"); blank(4); half(3);  line(1);
	full(6); blank2(17); outO("☆始めるよ☆"); line(1);
	Sleep(i);
}
void kaguyaStar22(int i)
{
	kaguya0();
	full(17); blank2(6); outO("★ 月  烛 ★"); blank2(2);  half(1); outO("辉"); half(1); line(1);
	full(14); blank2(9); outO("★黄昏草月★"); blank2(2); half(1); outO("夜"); half(1); line(1);
	full(11); blank2(12); outO("★ 場  末 ★"); blank(4); half(3);  line(1);
	full(6); blank2(17); outO("★始めるよ★"); line(1);
	Sleep(i);
}
void kaguyaStar23(int i)
{
	kaguya0();
	full(17); blank2(6); outO("☆ 月  烛 ☆"); blank2(2);  half(1); outO("辉"); half(1); line(1);
	full(14); blank2(9); outO("☆黄昏草月☆"); blank2(2); half(1); outO("夜"); half(1); line(1);
	full(11); blank2(12); outO("☆ 場  末 ☆"); blank(4); half(3);  line(1);
	full(6); blank2(17); outO("☆始めるよ☆"); line(1);
	Sleep(i);
}
void kaguyaStar24()
{
	kaguya0();
	full(17); blank2(6); outO("★ 月  烛 ★"); blank2(2);  half(1); outO("辉"); half(1); line(1);
	full(14); blank2(9); outO("★黄昏草月★"); blank2(2); half(1); outO("夜"); half(1); line(1);
	full(11); blank2(12); outO("☆ 場  末 ☆"); blank(4); half(3);  line(1);
	full(6); blank2(17); outO("★始めるよ★"); line(1);
	Sleep(1500);
}


void kaguyaEStar1()
{
	kaguya0();
	full(17); blank2(6); outO("★"); blank2(7);  half(1); outO("辉"); half(1); line(1);
	full(14); blank2(17);  half(1); outO("夜"); half(1); line(1);
	full(11); blank2(20); half(3);  line(1);
	full(6); line(1); Sleep(dy_star);
}
void kaguyaEStar2()
{
	kaguya0();
	full(17); blank2(6); outO("★ 月"); blank(11);  half(1); outO("辉"); half(1); line(1);
	full(14); blank2(17);  half(1); outO("夜"); half(1); line(1);
	full(11); blank2(20); half(3);  line(1);
	full(6); line(1); Sleep(dy_star);
}
void kaguyaEStar3()
{
	kaguya0();
	full(17); blank2(6); outO("★ 月  烛"); blank(7);  half(1); outO("辉"); half(1); line(1);
	full(14); blank2(17);  half(1); outO("夜"); half(1); line(1);
	full(11); blank2(20); half(3);  line(1);
	full(6); line(1); Sleep(dy_star);
}
void kaguyaEStar4()
{
	kaguya0();
	full(17); blank2(6); outO("★ 月  烛 ★"); blank(4);  half(1); outO("辉"); half(1); line(1);
	full(14); blank2(17);  half(1); outO("夜"); half(1); line(1);
	full(11); blank2(20); half(3);  line(1);
	full(6); line(1); Sleep(dy_star);
}
void kaguyaEStar5()
{
	kaguya0();
	full(17); blank2(6); outO("★ 月  烛 ★"); blank2(2);  half(1); outO("辉"); half(1); line(1);
	full(14); blank2(9); outO("★"); blank2(7); half(1); outO("夜"); half(1); line(1);
	full(11); blank2(20); half(3);  line(1);
	full(6); line(1); Sleep(dy_star);
}
void kaguyaEStar6()
{
	kaguya0();
	full(17); blank2(6); outO("★ 月  烛 ★"); blank2(2);  half(1); outO("辉"); half(1); line(1);
	full(14); blank2(9); outO("★黄"); blank2(6); half(1); outO("夜"); half(1); line(1);
	full(11); blank2(20); half(3);  line(1);
	full(6); line(1); Sleep(dy_star);
}
void kaguyaEStar7()
{
	kaguya0();
	full(17); blank2(6); outO("★ 月  烛 ★"); blank2(2);  half(1); outO("辉"); half(1); line(1);
	full(14); blank2(9); outO("★黄昏"); blank2(5); half(1); outO("夜"); half(1); line(1);
	full(11); blank2(20); half(3);  line(1);
	full(6); line(1); Sleep(dy_star);
}
void kaguyaEStar8()
{
	kaguya0();
	full(17); blank2(6); outO("★ 月  烛 ★"); blank2(2);  half(1); outO("辉"); half(1); line(1);
	full(14); blank2(9); outO("★黄昏草"); blank2(4); half(1); outO("夜"); half(1); line(1);
	full(11); blank2(20); half(3);  line(1);
	full(6); line(1); Sleep(dy_star);
}
void kaguyaEStar9()
{
	kaguya0();
	full(17); blank2(6); outO("★ 月  烛 ★"); blank2(2);  half(1); outO("辉"); half(1); line(1);
	full(14); blank2(9); outO("★黄昏草月"); blank2(3); half(1); outO("夜"); half(1); line(1);
	full(11); blank2(20); half(3);  line(1);
	full(6); line(1); Sleep(dy_star);
}
void kaguyaEStar10()
{
	kaguya0();
	full(17); blank2(6); outO("★ 月  烛 ★"); blank2(2);  half(1); outO("辉"); half(1); line(1);
	full(14); blank2(9); outO("★黄昏草月★"); blank2(2); half(1); outO("夜"); half(1); line(1);
	full(11); blank2(20); half(3);  line(1);
	full(6); line(1); Sleep(dy_star);
}
void kaguyaEStar11()
{
	kaguya0();
	full(17); blank2(6); outO("★ 月  烛 ★"); blank2(2);  half(1); outO("辉"); half(1); line(1);
	full(14); blank2(9); outO("★黄昏草月★"); blank2(2); half(1); outO("夜"); half(1); line(1);
	full(11); blank2(12); outO("★"); blank2(7); half(3);  line(1);
	full(6); line(1); Sleep(dy_star);
}
void kaguyaEStar12()
{
	kaguya0();
	full(17); blank2(6); outO("★ 月  烛 ★"); blank2(2);  half(1); outO("辉"); half(1); line(1);
	full(14); blank2(9); outO("★黄昏草月★"); blank2(2); half(1); outO("夜"); half(1); line(1);
	full(11); blank2(12); outO("★ 場"); blank(11); half(3);  line(1);
	full(6); line(1); Sleep(dy_star);
}
void kaguyaEStar13()
{
	kaguya0();
	full(17); blank2(6); outO("★ 月  烛 ★"); blank2(2);  half(1); outO("辉"); half(1); line(1);
	full(14); blank2(9); outO("★黄昏草月★"); blank2(2); half(1); outO("夜"); half(1); line(1);
	full(11); blank2(12); outO("★ 場  末"); blank(7); half(3);  line(1);
	full(6); line(1); Sleep(dy_star);
}
void kaguyaEStar14()
{
	kaguya0();
	full(17); blank2(6); outO("★ 月  烛 ★"); blank2(2);  half(1); outO("辉"); half(1); line(1);
	full(14); blank2(9); outO("★黄昏草月★"); blank2(2); half(1); outO("夜"); half(1); line(1);
	full(11); blank2(12); outO("★ 場  末 ★"); blank(4); half(3);  line(1);
	full(6); line(1); Sleep(dy_star);
}
void kaguyaEStar15()
{
	kaguya0();
	full(17); blank2(6); outO("★ 月  烛 ★"); blank2(2);  half(1); outO("辉"); half(1); line(1);
	full(14); blank2(9); outO("★黄昏草月★"); blank2(2); half(1); outO("夜"); half(1); line(1);
	full(11); blank2(12); outO("★ 場  末 ★"); blank(4); half(3);  line(1);
	full(6); blank2(17); outO("★"); line(1);
	Sleep(dy_star);
}
void kaguyaEStar16()
{
	kaguya0();
	full(17); blank2(6); outO("★ 月  烛 ★"); blank2(2);  half(1); outO("辉"); half(1); line(1);
	full(14); blank2(9); outO("★黄昏草月★"); blank2(2); half(1); outO("夜"); half(1); line(1);
	full(11); blank2(12); outO("★ 場  末 ★"); blank(4); half(3);  line(1);
	full(6); blank2(17); outO("★始"); line(1);
	Sleep(dy_star);
}
void kaguyaEStar17()
{
	kaguya0();
	full(17); blank2(6); outO("★ 月  烛 ★"); blank2(2);  half(1); outO("辉"); half(1); line(1);
	full(14); blank2(9); outO("★黄昏草月★"); blank2(2); half(1); outO("夜"); half(1); line(1);
	full(11); blank2(12); outO("★ 場  末 ★"); blank(4); half(3);  line(1);
	full(6); blank2(17); outO("★始め"); line(1);
	Sleep(dy_star);
}
void kaguyaEStar18()
{
	kaguya0();
	full(17); blank2(6); outO("★ 月  烛 ★"); blank2(2);  half(1); outO("辉"); half(1); line(1);
	full(14); blank2(9); outO("★黄昏草月★"); blank2(2); half(1); outO("夜"); half(1); line(1);
	full(11); blank2(12); outO("★ 場  末 ★"); blank(4); half(3);  line(1);
	full(6); blank2(17); outO("★始める"); line(1);
	Sleep(dy_star);
}
void kaguyaEStar19()
{
	kaguya0();
	full(17); blank2(6); outO("★ 月  烛 ★"); blank2(2);  half(1); outO("辉"); half(1); line(1);
	full(14); blank2(9); outO("★黄昏草月★"); blank2(2); half(1); outO("夜"); half(1); line(1);
	full(11); blank2(12); outO("★ 場  末 ★"); blank(4); half(3);  line(1);
	full(6); blank2(17); outO("★始めるよ"); line(1);
	Sleep(dy_star);
}
void kaguyaEStar20()
{
	kaguya0();
	full(17); blank2(6); outO("★ 月  烛 ★"); blank2(2);  half(1); outO("辉"); half(1); line(1);
	full(14); blank2(9); outO("★黄昏草月★"); blank2(2); half(1); outO("夜"); half(1); line(1);
	full(11); blank2(12); outO("★ 場  末 ★"); blank(4); half(3);  line(1);
	full(6); blank2(17); outO("★始めるよ★"); line(1);
	Sleep(dy_star);
}

void kaguyaEStar21(int i)
{
	kaguya0();
	full(17); blank2(6); outO("★ 月  烛 ★"); blank2(2);  half(1); outO("辉"); half(1); line(1);
	full(14); blank2(9); outO("★黄昏草月★"); blank2(2); half(1); outO("夜"); half(1); line(1);
	full(11); blank2(12); outO("★ 場  末 ★"); blank(4); half(3);  line(1);
	full(6); blank2(17); outO("★始めるよ★"); line(1);
	Sleep(i);
}

void kaguya()
{
	//kaguya1();
	//Sleep(38); kaguya12(); Sleep(38);// getS();// getS(); 
	//kaguya2(); Sleep(38); kaguya22(); Sleep(38);// getS();// getS();
	//kaguya3(); Sleep(38); kaguya32(); Sleep(38);// getS();// getS();
	//kaguya4(); Sleep(38); kaguya42(); Sleep(38);// getS();// getS();
	//kaguya5(); Sleep(38); kaguya52(); Sleep(38);// getS();// getS();
	//kaguya6(); Sleep(800);
	//kaguyaStar1();
	//kaguyaStar2();
	//kaguyaStar3();
	//kaguyaStar4();
	//kaguyaStar5();
	//kaguyaStar6();
	//kaguyaStar7();
	//kaguyaStar8();
	//kaguyaStar9();
	//kaguyaStar10();
	//kaguyaStar11();
	//kaguyaStar12();
	//kaguyaStar13();
	//kaguyaStar14();
	//kaguyaStar15();
	//kaguyaStar16();
	//kaguyaStar17();
	//kaguyaStar18();
	//kaguyaStar19();
	//kaguyaStar20();
	//int i;
	//for (i = 1; i <= 4; i++)
	//{
	//	int a = 2 * i - 1;
	//	kaguyaStar22(200 + 10 * a); a++;
	//	kaguyaStar21(200 + 10 * a);
	//}
	kaguyaStar23(350);
	kaguyaStar24();
}
void kaguyaEnd()
{
	kaguyaEStar21(dy_star);
	kaguyaEStar20();
	kaguyaEStar19();
	kaguyaEStar18();
	kaguyaEStar17();
	kaguyaEStar16();
	kaguyaEStar15();
	kaguyaEStar14();
	kaguyaEStar13();
	kaguyaEStar12();
	kaguyaEStar11();
	kaguyaEStar10();
	kaguyaEStar9();
	kaguyaEStar8();
	kaguyaEStar7();
	kaguyaEStar6();
	kaguyaEStar5();
	kaguyaEStar4();
	kaguyaEStar3();
	kaguyaEStar2();
	kaguyaEStar1();
	Sleep(38); kaguya6();
	Sleep(500); kaguya52();
	Sleep(38); kaguya5();
	Sleep(38); kaguya42();
	Sleep(38); kaguya4();
	Sleep(38); kaguya32();
	Sleep(38); kaguya3();
	Sleep(38); kaguya22();
	Sleep(38); kaguya2();
	Sleep(38); kaguya12();
	Sleep(38); kaguya10();
	Sleep(700);
}
void huanghun()
{
	color(8, 6);
	Sleep(1000);
	kaguyaEnd();
	endclear2();
	clear(2);
	outGDy("  到了正午，宅邸就和街上的喧嚣相隔地更远了。");
	outGDy("  耸立在山丘上的洋馆。");
	outGDy("  在街的中心就如别的世界般的地域。");
	outDy("  虽然受到街上人人仰望着，但这里对他们来说是过分");
	outGDy("遥远的世界之故，对有谁住在那里漠不关心。");
	line(2);
	outGDy("  而在那边，");
	blank(9);
	outODy("  只要在这里，外面的世界，对于我，");
	Sleep(1000);
	outODy("如同邱隔。",50);
	getS();
	line(2);
	outGMDy("In the next year……");
	outGMDy("■");
	endclear1();
}
void changmo()
{
	color(0, 8);
	Sleep(1000);
	endclear2();
	clear(2);
	outGDy("  很久不见了，丁宁。");
	outGDy("  尽管没有在曾经。");
	outGDy("  关于这份礼物，是否觉得很惊讶呢……");
	outGDy("  总之，先来简单介绍一下这个程序吧。");
	outGDy("  ");
	outGDy("  ");
	outGDy("  ");
	outGDy("  ");
	outGDy("  ");
	outGDy("  ");
	outGDy("  ");
	outGDy("  ");

}
void test1()
{

	out("挂在空中的满月依然散发着美丽的光芒。");
	out("凉爽的风吹过，轻抚着我的脸颊，树木的叶子也摇晃着。");
	out("不知为何，我的心情不可思议地平静。");
	//outInt('@', "黄昏草月", "宵待闲话", "場末");

	gracolor(6);
	out("百看不厌的天气。");
}
void test2()
{
	out("黄昏草月黄昏草月黄昏草月黄昏草月黄昏草月黄昏草月黄昏草月黄昏草月");
}
void FC()
{
	line(1);
	outOOMDy("调整窗口属性："); line(1);
	outOOMDy("字体：大小——36号字  字体——楷体"); line(1);
	outOOMDy("布局：屏幕缓冲区大小——高度:22"); line(7);
	outOOMDy("SanBing一号，芦苇，准备就绪"); line(2);
	outOOMDy("输入F11与回车  开始游戏");
	getS();
	clear(0);
	line(6);
	outOOMDy("选择你的英雄："); line(2);
	blank2(3); out2OMDy("1.探险家", "2.伊泽瑞尔"); line(2);
	blank2(3); out2OMDy("3.EZ", "4.伊泽芮尔"); line(2);
	blank2(3); out2OMDy("5.小黄毛", "6.秘术射击的拥有者"); line(2);
	blank2(5); int a = inIntCan(1, 6, "已找到对局,接受", "听说只有癌症晚期会看到这句话，remake吧"); line(2);
}
void chushi()
{
	line(1);
	outM("●初始化相关●");	line(1);
	outM("在开始之前，请首先设置如下属性...");	line(1);
	out("程序内：  （右键这个应用的上方白框处，点击 属性）");
	out("  1.选项——光标大小：小  (没有提及的部分则不需要修改)");
	out("  2.字体——大小：36        字体：楷体（推荐）");
	out("  3.布局——屏幕缓冲区大小：高度 — 22");
	out("            窗口大小：      宽度 — 71   高度 — 22  ");
	out("                                        ——点击 确定  ");

	out("程序外：  （右键桌面空白处，点击 显示设置(win10系统)）");
	out("  缩放与布局——  （分辨率很重要）");
	out("       缩放200%   屏幕分辨率:2560 x 1600");
	out("    或 缩放150%   屏幕分辨率:1920 x 1200");
	out("    或 缩放100%   屏幕分辨率:1280 x  800");
	out("                                        ——回到本程序");
	outM("看不懂的话可以去找文件里的图片教程"); line(1);
	outM("全部完成后按F11或Fn+F11进入全屏模式");
	outGM("输入确定键（回车）继续...");

	clear(1);
	outGM("●开始之前的最后一点说明●");
	outGMDy("（为了方便以后操作，接下来的说明没有延迟）");
	line(1);
	out("  还记得在高一微机课学过的VB（Visual Basic）吧?");
	line(1);
	out("  通过敲代码操作对象来设计一些程序,我就是在做类");
	out("似的工作。");
	line(1);
	out("  计算机专业的本科生基本都会把C语言作为第一门语");
	out("言来学习，之后再学C++,JAVA……"); line(1);
	out("  这个程序显然并不是用VB码出来的，至少VB会显示图");
	out("形，这个只有黑底白字的文本。");
	line(1);
	out("  这种窗口的“输入信息”的方式也和VB不同，通过鼠标");
	out("点击来操作，虽然这个程序也可以做到，不过我还没有");
	outG("仔细研究过。■");

	clear(5);
	out("  目前也只能处理从键盘上的输入的字符串信息来实现");
	out("读取。"); line(1);
	outG("  需要输入的情况只有两种。");
	out("  第一种是刚才那样，一段话结束后，输入“回车”继");
	out("续出现下一句，并且当出现'■'时，就表示下一次回车");
	outG("会换页了。");
	out("  第二种在输入回车前需要加数字，这种情况的标志");
	out("是出现方括号[],例如下面——"); line(1);
	blank2(5); int a = inIntO(1, 100, "输入“区间内的数字+回车”结束提示 ", "快结束新手村的教程吧……", 0);
}