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
		//if (i == 1) outO("��");
		//if (i == 2) outO("��");
		line(1);

	}
	for (i = 0; i < 2; i++)
	{
		full(32); blank2(2);
		//if (i == 0) outO("��");
		//if (i == 1) outO("һ");
		line(1);
	}
	for (i = 0; i < 2; i++)
	{
		full(31); blank2(3);
		//if (i == 0) outO("��");
		//if (i == 1) outO("��");
		line(1);
	}
	for (i = 30; i >= 26; i--)
	{

		full(i);
		//if (i == 30) { blank2(4); outO("��"); }
		//if (i == 29) { blank2(5); outO("��"); }
		//if (i == 28) { blank2(2);  blank2(4); outO("��"); }
		//if (i == 27) { blank2(3);  blank2(4); outO("��"); }

		line(1);
	}
	full(25);  line(1);//���
	full(24);  blank2(7); half(3);   line(1);
	full(23); blank2(8); half(1); outO("��"); half(1);    line(1);
	full(21);   blank2(10); half(1); outO("��"); half(1);  line(1);//���
	full(19);  blank2(12); half(1); outO("��"); half(1);  line(1);
}
void kaguyaStar()
{
	kaguya0();
	full(17); blank2(6); outO("�� ��  �� ��"); blank2(2); half(3);  line(1); line(1);
	full(14); blank2(9); outO("��ƻ���¡�");  line(1);
	full(11); blank2(12); outO("�� ��  ĩ ��"); line(1);
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
	//	if (i == 1) outO("��");
	//	if (i == 2) outO("��");
		line(1);
		
	}
	for (i = 0; i < 2; i++)
	{
		fullDy(32, c); blank2(2);
	//if (i == 0) outO("��");
	//if (i == 1) outO("һ");
	line(1);
	}
	
	//	fullDy(31, e);  blank2(3); outO("��"); line(1);
	//	fullDy(31, e);  blank2(3); outO("��"); line(1);
	
	for (i = 30; i >= 26; i--)
	{
		
		fullDy(i, d); 
	//	if (i == 30) { blank2(4); outO("��"); }
	//	if (i == 29) { blank2(5); outO("��"); }
	//	if (i == 28) { blank2(2);  blank2(4); outO("��"); }
	//	if (i == 27) { blank2(3);  blank2(4); outO("��"); }
		if (i == 26) { blank2(4);  blank2(4);  }
		
		line(1);
	}
	fullDy(25, a); blank2(9); line(1);//���
	fullDy(24, a);  blank2(2); halfDy(3, a); blank2(4);   line(1);
	fullDy(23, a); blank2(3); halfDy(1,a); outO("��"); halfDy(1,a);    line(1);
	fullDy(21,a);   blank2(5); halfDy(1, a); outO("��"); halfDy(1,a);  line(1);//���
	fullDy(19, a);  blank2(7); halfDy(1, a); outO("��"); halfDy(1,a);    line(1);
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
		if (i == 1) outO("��");
		if (i == 2) outO("��");
		line(1);

	}
	for (i = 0; i < 2; i++)
	{
		full(32); blank2(2);
		if (i == 0) outO("��");
		if (i == 1) outO("һ");
		line(1);
	}

	full(31);  blank2(3); outO("��"); line(1);
	full(31);  blank2(3); outO("��"); line(1);

	for (i = 30; i >= 26; i--)
	{

		full(i);
		if (i == 30) { blank2(4); outO("��"); }
		if (i == 29) { blank2(5); outO("��"); }
		if (i == 28) { blank2(2);  blank2(4); outO("��"); }
		if (i == 27) { blank2(3);  blank2(4); outO("��"); }
		if (i == 26) { blank2(4);  blank2(4); }

		line(1);
	}
	full(25); blank2(9); line(1);//���
	full(24);  blank2(2); half(3); blank2(4);   line(1);
	full(23); blank2(3); half(1); outO("��"); half(1);    line(1);
	full(21);   blank2(5); half(1); outO("��"); half(1);  line(1);//���
	full(19);  blank2(7); half(1); outO("��"); half(1);    line(1);
	full(17); blank2(9);  half(1); outO("��"); half(1);  line(1);
	full(14); blank2(12);  half(1); outO("ҹ"); half(1);  line(1);
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
		if (i == 1) outO("��");
		if (i == 2) outO("��");
		line(1);

	}
	for (i = 0; i < 2; i++)
	{
		full(32); blank2(2);
		if (i == 0) outO("��");
		if (i == 1) outO("һ");
		line(1);
	}
	for (i = 0; i < 2; i++)
	{
		full(31); blank2(3);
		if (i == 0) outO("��");
		if (i == 1) outO("��");
		line(1);
	}
	for (i = 30; i >= 26; i--)
	{

		full(i);
		if (i == 30) { blank2(4); outO("��"); }
		if (i == 29) { blank2(5); outO("��"); }
		if (i == 28) { blank2(2);  blank2(4); outO("��"); }
		if (i == 27) { blank2(3);  blank2(4); outO("��"); }
		if (i == 26) { blank2(4); }

		line(1);
	}
	full(25); line(1);//���
	full(24);  blank(5); half(3); line(1);
	full(23); blank(7); half(1); outO("��"); half(1);    line(1);
	full(21);   blank(11); half(1); outO("��"); half(1);  line(1);//���
	full(19);  blank(15); half(1); outO("��"); half(1);    line(1);
	full(17); blank(19);  half(1); outO("��"); half(1); line(1);
	full(14); blank(25);  half(1); outO("ҹ"); half(1); line(1);
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
		if (i == 1) outO("��");
		if (i == 2) outO("��");
		line(1);

	}
	for (i = 0; i < 2; i++)
	{
		full(32); blank2(2);
		if (i == 0) outO("��");
		if (i == 1) outO("һ");
		line(1);
	}
	for (i = 0; i < 2; i++)
	{
		full(31); blank2(3);
		if (i == 0) outO("��");
		if (i == 1) outO("��");
		line(1);
	}
	for (i = 30; i >= 26; i--)
	{

		full(i);
		if (i == 30) { blank2(4); outO("��"); }
		if (i == 29) { blank2(5); outO("��"); }
		if (i == 28) { blank2(2);  blank2(4); outO("��"); }
		if (i == 27) { blank2(3);  blank2(4); outO("��"); }
		if (i == 26) { blank2(4);   }

		line(1);
	}
	full(25); line(1);//���
	full(24);  blank2(3); half(3); blank2(3);  line(1);
	full(23); blank2(4); half(1); outO("��"); half(1);    line(1);
	full(21);   blank2(6); half(1); outO("��"); half(1);  line(1);//���
	full(19);  blank2(8); half(1); outO("��"); half(1);    line(1);
	full(17); blank2(10);  half(1); outO("��"); half(1); line(1);
	full(14); blank2(13);  half(1); outO("ҹ"); half(1); line(1);
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
		if (i == 1) outO("��");
		if (i == 2) outO("��");
		line(1);

	}
	for (i = 0; i < 2; i++)
	{
		full(32); blank2(2);
		if (i == 0) outO("��");
		if (i == 1) outO("һ");
		line(1);
	}
	for (i = 0; i < 2; i++)
	{
		full(31); blank2(3);
		if (i == 0) outO("��");
		if (i == 1) outO("��");
		line(1);
	}
	for (i = 30; i >= 26; i--)
	{

		full(i);
		if (i == 30) { blank2(4); outO("��"); }
		if (i == 29) { blank2(5); outO("��"); }
		if (i == 28) { blank2(2);  blank2(4); outO("��"); }
		if (i == 27) { blank2(3);  blank2(4); outO("��"); }
		if (i == 26) { blank2(4); }

		line(1);
	}
	full(25); line(1);//���
	full(24);  blank(7); half(3);   line(1);
	full(23); blank(9); half(1); outO("��"); half(1);    line(1);
	full(21);   blank(13); half(1); outO("��"); half(1);  line(1);//���
	full(19);  blank(17); half(1); outO("��"); half(1);    line(1);
	full(17); blank(21);  half(1); outO("��"); half(1); line(1);
	full(14); blank(27);  half(1); outO("ҹ"); half(1); line(1);
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
		if (i == 1) outO("��");
		if (i == 2) outO("��");
		line(1);

	}
	for (i = 0; i < 2; i++)
	{
		full(32); blank2(2);
		if (i == 0) outO("��");
		if (i == 1) outO("һ");
		line(1);
	}
	for (i = 0; i < 2; i++)
	{
		full(31); blank2(3);
		if (i == 0) outO("��");
		if (i == 1) outO("��");
		line(1);
	}
	for (i = 30; i >= 26; i--)
	{

		full(i);
		if (i == 30) { blank2(4); outO("��"); }
		if (i == 29) { blank2(5); outO("��"); }
		if (i == 28) { blank2(2);  blank2(4); outO("��"); }
		if (i == 27) { blank2(3);  blank2(4); outO("��"); }
		if (i == 26) { blank2(4);  blank2(4); }

		line(1);
	}
	full(25); blank2(9);  line(1);//���
	full(24);  blank2(4); half(3); blank2(3);  line(1);
	full(23); blank2(5); half(1); outO("��"); half(1);    line(1);
	full(21);   blank2(7); half(1); outO("��"); half(1);  line(1);//���
	full(19);  blank2(9); half(1); outO("��"); half(1);    line(1);
	full(17); blank2(11);  half(1); outO("��"); half(1); line(1);
	full(14); blank2(14);  half(1); outO("ҹ"); half(1); line(1);
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
		if (i == 1) outO("��");
		if (i == 2) outO("��");
		line(1);

	}
	for (i = 0; i < 2; i++)
	{
		full(32); blank2(2);
		if (i == 0) outO("��");
		if (i == 1) outO("һ");
		line(1);
	}
	for (i = 0; i < 2; i++)
	{
		full(31); blank2(3);
		if (i == 0) outO("��");
		if (i == 1) outO("��");
		line(1);
	}
	for (i = 30; i >= 26; i--)
	{

		full(i);
		if (i == 30) { blank2(4); outO("��"); }
		if (i == 29) { blank2(5); outO("��"); }
		if (i == 28) { blank2(2);  blank2(4); outO("��"); }
		if (i == 27) { blank2(3);  blank2(4); outO("��"); }
		if (i == 26) { blank2(4);  blank2(4); }

		line(1);
	}
	full(25); blank2(9);  line(1);//���
	full(24);  blank(9); half(3);  line(1);
	full(23); blank(11); half(1); outO("��"); half(1);    line(1);
	full(21);   blank(15); half(1); outO("��"); half(1);  line(1);//���
	full(19);  blank(19); half(1); outO("��"); half(1);    line(1);
	full(17); blank(23);  half(1); outO("��"); half(1); line(1);
	full(14); blank(29);  half(1); outO("ҹ"); half(1); line(1);
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
		if (i == 1) outO("��");
		if (i == 2) outO("��");
		line(1);

	}
	for (i = 0; i < 2; i++)
	{
		full(32); blank2(2);
		if (i == 0) outO("��");
		if (i == 1) outO("һ");
		line(1);
	}
	for (i = 0; i < 2; i++)
	{
		full(31); blank2(3);
		if (i == 0) outO("��");
		if (i == 1) outO("��");
		line(1);
	}
	for (i = 30; i >= 26; i--)
	{

		full(i);
		if (i == 30) { blank2(4); outO("��"); }
		if (i == 29) { blank2(5); outO("��"); }
		if (i == 28) { blank2(2);  blank2(4); outO("��"); }
		if (i == 27) { blank2(3);  blank2(4); outO("��"); }
		if (i == 26) { blank2(4);  blank2(4); }

		line(1);
	}
	full(25); blank2(9);  line(1);//���
	full(24);  blank2(5); half(3); blank2(3);  line(1);
	full(23); blank2(6); half(1); outO("��"); half(1);    line(1);
	full(21);   blank2(8); half(1); outO("��"); half(1);  line(1);//���
	full(19);  blank2(10); half(1); outO("��"); half(1);    line(1);
	full(17); blank2(12);  half(1); outO("��"); half(1); line(1);
	full(14); blank2(15);  half(1); outO("ҹ"); half(1); line(1);
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
		if (i == 1) outO("��");
		if (i == 2) outO("��");
		line(1);

	}
	for (i = 0; i < 2; i++)
	{
		full(32); blank2(2);
		if (i == 0) outO("��");
		if (i == 1) outO("һ");
		line(1);
	}
	for (i = 0; i < 2; i++)
	{
		full(31); blank2(3);
		if (i == 0) outO("��");
		if (i == 1) outO("��");
		line(1);
	}
	for (i = 30; i >= 26; i--)
	{

		full(i);
		if (i == 30) { blank2(4); outO("��"); }
		if (i == 29) { blank2(5); outO("��"); }
		if (i == 28) { blank2(2);  blank2(4); outO("��"); }
		if (i == 27) { blank2(3);  blank2(4); outO("��"); }
		if (i == 26) { blank2(4);  blank2(4); }

		line(1);
	}
	full(25); blank2(9);  line(1);//���
	full(24);  blank(11); half(3);  line(1);
	full(23); blank(13); half(1); outO("��"); half(1);    line(1);
	full(21);   blank(17); half(1); outO("��"); half(1);  line(1);//���
	full(19);  blank(21); half(1); outO("��"); half(1);    line(1);
	full(17); blank(25);  half(1); outO("��"); half(1); line(1);
	full(14); blank(31);  half(1); outO("ҹ"); half(1); line(1);
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
		if (i == 1) outO("��");
		if (i == 2) outO("��");
		line(1);

	}
	for (i = 0; i < 2; i++)
	{
		full(32); blank2(2);
		if (i == 0) outO("��");
		if (i == 1) outO("һ");
		line(1);
	}
	for (i = 0; i < 2; i++)
	{
		full(31); blank2(3);
		if (i == 0) outO("��");
		if (i == 1) outO("��");
		line(1);
	}
	for (i = 30; i >= 26; i--)
	{

		full(i);
		if (i == 30) { blank2(4); outO("��"); }
		if (i == 29) { blank2(5); outO("��"); }
		if (i == 28) { blank2(2);  blank2(4); outO("��"); }
		if (i == 27) { blank2(3);  blank2(4); outO("��"); }
		if (i == 26) { blank2(4);  blank2(4); }

		line(1);
	}
	full(25); blank2(9);   line(1);//���
	full(24);  blank2(6); half(3); line(1);
	full(23); blank2(7); half(1); outO("��"); half(1);    line(1);
	full(21);   blank2(9); half(1); outO("��"); half(1);  line(1);//���
	full(19);  blank2(11); half(1); outO("��"); half(1);    line(1);
	full(17); blank2(13);  half(1); outO("��"); half(1); line(1);
	full(14); blank2(16);  half(1); outO("ҹ"); half(1); line(1);
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
			if (i == 1) outO("��");
			if (i == 2) outO("��");
			line(1);

		}
		for (i = 0; i < 2; i++)
		{
			full(32); blank2(2);
			if (i == 0) outO("��");
			if (i == 1) outO("һ");
			line(1);
		}
		for (i = 0; i < 2; i++)
		{
			full(31); blank2(3);
			if (i == 0) outO("��");
			if (i == 1) outO("��");
			line(1);
		}
		for (i = 30; i >= 26; i--)
		{

			full(i);
			if (i == 30) { blank2(4); outO("��"); }
			if (i == 29) { blank2(5); outO("��"); }
			if (i == 28) { blank2(2);  blank2(4); outO("��"); }
			if (i == 27) { blank2(3);  blank2(4); outO("��"); }
			if (i == 26) { blank2(4);  blank2(4); }

			line(1);
		}
		full(25); blank2(9);   line(1);//���
		full(24);  blank(13); half(3); line(1);
		full(23); blank(15); half(1); outO("��"); half(1);    line(1);
		full(21);   blank(19); half(1); outO("��"); half(1);  line(1);//���
		full(19);  blank(23); half(1); outO("��"); half(1);    line(1);
		full(17); blank(27);  half(1); outO("��"); half(1); line(1);
		full(14); blank(33);  half(1); outO("ҹ"); half(1); line(1);
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
		if (i == 1) outO("��");
		if (i == 2) outO("��");
		line(1);

	}
	for (i = 0; i < 2; i++)
	{
		full(32); blank2(2);
		if (i == 0) outO("��");
		if (i == 1) outO("һ");
		line(1);
	}
	for (i = 0; i < 2; i++)
	{
		full(31); blank2(3);
		if (i == 0) outO("��");
		if (i == 1) outO("��");
		line(1);
	}
	for (i = 30; i >= 26; i--)
	{

		full(i);
		if (i == 30) { blank2(4); outO("��"); }
		if (i == 29) { blank2(5); outO("��"); }
		if (i == 28) { blank2(2);  blank2(4); outO("��"); }
		if (i == 27) { blank2(3);  blank2(4); outO("��"); }
		if (i == 26) { blank2(4);  blank2(4); }

		line(1);
	}
	full(25);  line(1);//���
	full(24);  blank2(7); half(3);  line(1);
	full(23); blank2(8); half(1); outO("��"); half(1);    line(1);
	full(21);   blank2(10); half(1); outO("��"); half(1);  line(1);//���
	full(19);  blank2(12); half(1); outO("��"); half(1);    line(1);
	full(17); blank2(14);  half(1); outO("��"); half(1); line(1);
	full(14); blank2(17);  half(1); outO("ҹ"); half(1); line(1);
	full(11); blank2(20); half(3);  line(1);
	full(6); line(1);

}

void kaguyaStar1()
{ 
	kaguya0();
	full(17); blank2(6); outO("��"); blank2(7);  half(1); outO("��"); half(1); line(1);
	full(14); blank2(17);  half(1); outO("ҹ"); half(1); line(1);
	full(11); blank2(20); half(3);  line(1);
	full(6); line(1); Sleep(dy_star);
}
void kaguyaStar2()
{  
	kaguya0();
	full(17); blank2(6); outO("�� ��"); blank(11);  half(1); outO("��"); half(1); line(1);
	full(14); blank2(17);  half(1); outO("ҹ"); half(1); line(1);
	full(11); blank2(20); half(3);  line(1);
	full(6); line(1); Sleep(dy_star);
}
void kaguyaStar3()
{
	kaguya0();
	full(17); blank2(6); outO("�� ��  ��"); blank(7);  half(1); outO("��"); half(1); line(1);
	full(14); blank2(17);  half(1); outO("ҹ"); half(1); line(1);
	full(11); blank2(20); half(3);  line(1);
	full(6); line(1); Sleep(dy_star);
}
void kaguyaStar4()
{
	kaguya0();
	full(17); blank2(6); outO("�� ��  �� ��"); blank(4);  half(1); outO("��"); half(1); line(1);
	full(14); blank2(17);  half(1); outO("ҹ"); half(1); line(1);
	full(11); blank2(20); half(3);  line(1);
	full(6); line(1); Sleep(dy_star2);
}
void kaguyaStar5()
{
	kaguya0();
	full(17); blank2(6); outO("�� ��  �� ��"); blank2(2);  half(1); outO("��"); half(1); line(1);
	full(14); blank2(9); outO("��"); blank2(7); half(1); outO("ҹ"); half(1); line(1);
	full(11); blank2(20); half(3);  line(1);
	full(6); line(1); Sleep(dy_star);
}
void kaguyaStar6()
{
	kaguya0();
	full(17); blank2(6); outO("�� ��  �� ��"); blank2(2);  half(1); outO("��"); half(1); line(1);
	full(14); blank2(9); outO("���"); blank2(6); half(1); outO("ҹ"); half(1); line(1);
	full(11); blank2(20); half(3);  line(1);
	full(6); line(1); Sleep(dy_star);
}
void kaguyaStar7()
{
	kaguya0();
	full(17); blank2(6); outO("�� ��  �� ��"); blank2(2);  half(1); outO("��"); half(1); line(1);
	full(14); blank2(9); outO("��ƻ�"); blank2(5); half(1); outO("ҹ"); half(1); line(1);
	full(11); blank2(20); half(3);  line(1);
	full(6); line(1); Sleep(dy_star);
}
void kaguyaStar8()
{
	kaguya0();
	full(17); blank2(6); outO("�� ��  �� ��"); blank2(2);  half(1); outO("��"); half(1); line(1);
	full(14); blank2(9); outO("��ƻ��"); blank2(4); half(1); outO("ҹ"); half(1); line(1);
	full(11); blank2(20); half(3);  line(1);
	full(6); line(1); Sleep(dy_star);
}
void kaguyaStar9()
{
	kaguya0();
	full(17); blank2(6); outO("�� ��  �� ��"); blank2(2);  half(1); outO("��"); half(1); line(1);
	full(14); blank2(9); outO("��ƻ����"); blank2(3); half(1); outO("ҹ"); half(1); line(1);
	full(11); blank2(20); half(3);  line(1);
	full(6); line(1); Sleep(dy_star);
}
void kaguyaStar10()
{
	kaguya0();
	full(17); blank2(6); outO("�� ��  �� ��"); blank2(2);  half(1); outO("��"); half(1); line(1);
	full(14); blank2(9); outO("��ƻ���¡�"); blank2(2); half(1); outO("ҹ"); half(1); line(1);
	full(11); blank2(20); half(3);  line(1);
	full(6); line(1); Sleep(dy_star2);
}
void kaguyaStar11()
{
	kaguya0();
	full(17); blank2(6); outO("�� ��  �� ��"); blank2(2);  half(1); outO("��"); half(1); line(1);
	full(14); blank2(9); outO("��ƻ���¡�"); blank2(2); half(1); outO("ҹ"); half(1); line(1);
	full(11); blank2(12); outO("��"); blank2(7); half(3);  line(1);
	full(6); line(1); Sleep(dy_star);
}
void kaguyaStar12()
{
	kaguya0();
	full(17); blank2(6); outO("�� ��  �� ��"); blank2(2);  half(1); outO("��"); half(1); line(1);
	full(14); blank2(9); outO("��ƻ���¡�"); blank2(2); half(1); outO("ҹ"); half(1); line(1);
	full(11); blank2(12); outO("�� ��"); blank(11); half(3);  line(1);
	full(6); line(1); Sleep(dy_star);
}
void kaguyaStar13()
{
	kaguya0();
	full(17); blank2(6); outO("�� ��  �� ��"); blank2(2);  half(1); outO("��"); half(1); line(1);
	full(14); blank2(9); outO("��ƻ���¡�"); blank2(2); half(1); outO("ҹ"); half(1); line(1);
	full(11); blank2(12); outO("�� ��  ĩ"); blank(7); half(3);  line(1);
	full(6); line(1); Sleep(dy_star);
}
void kaguyaStar14()
{
	kaguya0();
	full(17); blank2(6); outO("�� ��  �� ��"); blank2(2);  half(1); outO("��"); half(1); line(1);
	full(14); blank2(9); outO("��ƻ���¡�"); blank2(2); half(1); outO("ҹ"); half(1); line(1);
	full(11); blank2(12);outO("�� ��  ĩ ��"); blank(4); half(3);  line(1);
	full(6); line(1); Sleep(dy_star2);
}
void kaguyaStar15()
{
	kaguya0();
	full(17); blank2(6); outO("�� ��  �� ��"); blank2(2);  half(1); outO("��"); half(1); line(1);
	full(14); blank2(9); outO("��ƻ���¡�"); blank2(2); half(1); outO("ҹ"); half(1); line(1);
	full(11); blank2(12); outO("�� ��  ĩ ��"); blank(4); half(3);  line(1);
	full(6); blank2(17); outO("��"); line(1);
	Sleep(dy_star);
}
void kaguyaStar16()
{
	kaguya0();
	full(17); blank2(6); outO("�� ��  �� ��"); blank2(2);  half(1); outO("��"); half(1); line(1);
	full(14); blank2(9); outO("��ƻ���¡�"); blank2(2); half(1); outO("ҹ"); half(1); line(1);
	full(11); blank2(12); outO("�� ��  ĩ ��"); blank(4); half(3);  line(1);
	full(6); blank2(17); outO("��ʼ"); line(1);
	Sleep(dy_star);
}
void kaguyaStar17()
{
	kaguya0();
	full(17); blank2(6); outO("�� ��  �� ��"); blank2(2);  half(1); outO("��"); half(1); line(1);
	full(14); blank2(9); outO("��ƻ���¡�"); blank2(2); half(1); outO("ҹ"); half(1); line(1);
	full(11); blank2(12); outO("�� ��  ĩ ��"); blank(4); half(3);  line(1);
	full(6); blank2(17); outO("��ʼ��"); line(1);
	Sleep(dy_star);
}
void kaguyaStar18()
{
	kaguya0();
	full(17); blank2(6); outO("�� ��  �� ��"); blank2(2);  half(1); outO("��"); half(1); line(1);
	full(14); blank2(9); outO("��ƻ���¡�"); blank2(2); half(1); outO("ҹ"); half(1); line(1);
	full(11); blank2(12); outO("�� ��  ĩ ��"); blank(4); half(3);  line(1);
	full(6); blank2(17); outO("��ʼ���"); line(1);
	Sleep(dy_star);
}
void kaguyaStar19()
{
	kaguya0();
	full(17); blank2(6); outO("�� ��  �� ��"); blank2(2);  half(1); outO("��"); half(1); line(1);
	full(14); blank2(9); outO("��ƻ���¡�"); blank2(2); half(1); outO("ҹ"); half(1); line(1);
	full(11); blank2(12);outO("�� ��  ĩ ��"); blank(4); half(3);  line(1);
	full(6); blank2(17); outO("��ʼ����"); line(1);
	Sleep(dy_star);
}
void kaguyaStar20()
{
	kaguya0();
	full(17); blank2(6); outO("�� ��  �� ��"); blank2(2);  half(1); outO("��"); half(1); line(1);
	full(14); blank2(9); outO("��ƻ���¡�"); blank2(2); half(1); outO("ҹ"); half(1); line(1);
	full(11); blank2(12); outO("�� ��  ĩ ��"); blank(4); half(3);  line(1);
	full(6); blank2(17); outO("��ʼ�����"); line(1);
	Sleep(dy_star2);
}

void kaguyaStar21(int i)
{
	kaguya0();
	full(17); blank2(6); outO("�� ��  �� ��"); blank2(2);  half(1); outO("��"); half(1); line(1);
	full(14); blank2(9); outO("��ƻ���¡�"); blank2(2); half(1); outO("ҹ"); half(1); line(1);
	full(11); blank2(12);outO("�� ��  ĩ ��"); blank(4); half(3);  line(1);
	full(6); blank2(17); outO("��ʼ�����"); line(1);
	Sleep(i);
}
void kaguyaStar22(int i)
{
	kaguya0();
	full(17); blank2(6); outO("�� ��  �� ��"); blank2(2);  half(1); outO("��"); half(1); line(1);
	full(14); blank2(9); outO("��ƻ���¡�"); blank2(2); half(1); outO("ҹ"); half(1); line(1);
	full(11); blank2(12); outO("�� ��  ĩ ��"); blank(4); half(3);  line(1);
	full(6); blank2(17); outO("��ʼ�����"); line(1);
	Sleep(i);
}
void kaguyaStar23(int i)
{
	kaguya0();
	full(17); blank2(6); outO("�� ��  �� ��"); blank2(2);  half(1); outO("��"); half(1); line(1);
	full(14); blank2(9); outO("��ƻ���¡�"); blank2(2); half(1); outO("ҹ"); half(1); line(1);
	full(11); blank2(12); outO("�� ��  ĩ ��"); blank(4); half(3);  line(1);
	full(6); blank2(17); outO("��ʼ�����"); line(1);
	Sleep(i);
}
void kaguyaStar24()
{
	kaguya0();
	full(17); blank2(6); outO("�� ��  �� ��"); blank2(2);  half(1); outO("��"); half(1); line(1);
	full(14); blank2(9); outO("��ƻ���¡�"); blank2(2); half(1); outO("ҹ"); half(1); line(1);
	full(11); blank2(12); outO("�� ��  ĩ ��"); blank(4); half(3);  line(1);
	full(6); blank2(17); outO("��ʼ�����"); line(1);
	Sleep(1500);
}


void kaguyaEStar1()
{
	kaguya0();
	full(17); blank2(6); outO("��"); blank2(7);  half(1); outO("��"); half(1); line(1);
	full(14); blank2(17);  half(1); outO("ҹ"); half(1); line(1);
	full(11); blank2(20); half(3);  line(1);
	full(6); line(1); Sleep(dy_star);
}
void kaguyaEStar2()
{
	kaguya0();
	full(17); blank2(6); outO("�� ��"); blank(11);  half(1); outO("��"); half(1); line(1);
	full(14); blank2(17);  half(1); outO("ҹ"); half(1); line(1);
	full(11); blank2(20); half(3);  line(1);
	full(6); line(1); Sleep(dy_star);
}
void kaguyaEStar3()
{
	kaguya0();
	full(17); blank2(6); outO("�� ��  ��"); blank(7);  half(1); outO("��"); half(1); line(1);
	full(14); blank2(17);  half(1); outO("ҹ"); half(1); line(1);
	full(11); blank2(20); half(3);  line(1);
	full(6); line(1); Sleep(dy_star);
}
void kaguyaEStar4()
{
	kaguya0();
	full(17); blank2(6); outO("�� ��  �� ��"); blank(4);  half(1); outO("��"); half(1); line(1);
	full(14); blank2(17);  half(1); outO("ҹ"); half(1); line(1);
	full(11); blank2(20); half(3);  line(1);
	full(6); line(1); Sleep(dy_star);
}
void kaguyaEStar5()
{
	kaguya0();
	full(17); blank2(6); outO("�� ��  �� ��"); blank2(2);  half(1); outO("��"); half(1); line(1);
	full(14); blank2(9); outO("��"); blank2(7); half(1); outO("ҹ"); half(1); line(1);
	full(11); blank2(20); half(3);  line(1);
	full(6); line(1); Sleep(dy_star);
}
void kaguyaEStar6()
{
	kaguya0();
	full(17); blank2(6); outO("�� ��  �� ��"); blank2(2);  half(1); outO("��"); half(1); line(1);
	full(14); blank2(9); outO("���"); blank2(6); half(1); outO("ҹ"); half(1); line(1);
	full(11); blank2(20); half(3);  line(1);
	full(6); line(1); Sleep(dy_star);
}
void kaguyaEStar7()
{
	kaguya0();
	full(17); blank2(6); outO("�� ��  �� ��"); blank2(2);  half(1); outO("��"); half(1); line(1);
	full(14); blank2(9); outO("��ƻ�"); blank2(5); half(1); outO("ҹ"); half(1); line(1);
	full(11); blank2(20); half(3);  line(1);
	full(6); line(1); Sleep(dy_star);
}
void kaguyaEStar8()
{
	kaguya0();
	full(17); blank2(6); outO("�� ��  �� ��"); blank2(2);  half(1); outO("��"); half(1); line(1);
	full(14); blank2(9); outO("��ƻ��"); blank2(4); half(1); outO("ҹ"); half(1); line(1);
	full(11); blank2(20); half(3);  line(1);
	full(6); line(1); Sleep(dy_star);
}
void kaguyaEStar9()
{
	kaguya0();
	full(17); blank2(6); outO("�� ��  �� ��"); blank2(2);  half(1); outO("��"); half(1); line(1);
	full(14); blank2(9); outO("��ƻ����"); blank2(3); half(1); outO("ҹ"); half(1); line(1);
	full(11); blank2(20); half(3);  line(1);
	full(6); line(1); Sleep(dy_star);
}
void kaguyaEStar10()
{
	kaguya0();
	full(17); blank2(6); outO("�� ��  �� ��"); blank2(2);  half(1); outO("��"); half(1); line(1);
	full(14); blank2(9); outO("��ƻ���¡�"); blank2(2); half(1); outO("ҹ"); half(1); line(1);
	full(11); blank2(20); half(3);  line(1);
	full(6); line(1); Sleep(dy_star);
}
void kaguyaEStar11()
{
	kaguya0();
	full(17); blank2(6); outO("�� ��  �� ��"); blank2(2);  half(1); outO("��"); half(1); line(1);
	full(14); blank2(9); outO("��ƻ���¡�"); blank2(2); half(1); outO("ҹ"); half(1); line(1);
	full(11); blank2(12); outO("��"); blank2(7); half(3);  line(1);
	full(6); line(1); Sleep(dy_star);
}
void kaguyaEStar12()
{
	kaguya0();
	full(17); blank2(6); outO("�� ��  �� ��"); blank2(2);  half(1); outO("��"); half(1); line(1);
	full(14); blank2(9); outO("��ƻ���¡�"); blank2(2); half(1); outO("ҹ"); half(1); line(1);
	full(11); blank2(12); outO("�� ��"); blank(11); half(3);  line(1);
	full(6); line(1); Sleep(dy_star);
}
void kaguyaEStar13()
{
	kaguya0();
	full(17); blank2(6); outO("�� ��  �� ��"); blank2(2);  half(1); outO("��"); half(1); line(1);
	full(14); blank2(9); outO("��ƻ���¡�"); blank2(2); half(1); outO("ҹ"); half(1); line(1);
	full(11); blank2(12); outO("�� ��  ĩ"); blank(7); half(3);  line(1);
	full(6); line(1); Sleep(dy_star);
}
void kaguyaEStar14()
{
	kaguya0();
	full(17); blank2(6); outO("�� ��  �� ��"); blank2(2);  half(1); outO("��"); half(1); line(1);
	full(14); blank2(9); outO("��ƻ���¡�"); blank2(2); half(1); outO("ҹ"); half(1); line(1);
	full(11); blank2(12); outO("�� ��  ĩ ��"); blank(4); half(3);  line(1);
	full(6); line(1); Sleep(dy_star);
}
void kaguyaEStar15()
{
	kaguya0();
	full(17); blank2(6); outO("�� ��  �� ��"); blank2(2);  half(1); outO("��"); half(1); line(1);
	full(14); blank2(9); outO("��ƻ���¡�"); blank2(2); half(1); outO("ҹ"); half(1); line(1);
	full(11); blank2(12); outO("�� ��  ĩ ��"); blank(4); half(3);  line(1);
	full(6); blank2(17); outO("��"); line(1);
	Sleep(dy_star);
}
void kaguyaEStar16()
{
	kaguya0();
	full(17); blank2(6); outO("�� ��  �� ��"); blank2(2);  half(1); outO("��"); half(1); line(1);
	full(14); blank2(9); outO("��ƻ���¡�"); blank2(2); half(1); outO("ҹ"); half(1); line(1);
	full(11); blank2(12); outO("�� ��  ĩ ��"); blank(4); half(3);  line(1);
	full(6); blank2(17); outO("��ʼ"); line(1);
	Sleep(dy_star);
}
void kaguyaEStar17()
{
	kaguya0();
	full(17); blank2(6); outO("�� ��  �� ��"); blank2(2);  half(1); outO("��"); half(1); line(1);
	full(14); blank2(9); outO("��ƻ���¡�"); blank2(2); half(1); outO("ҹ"); half(1); line(1);
	full(11); blank2(12); outO("�� ��  ĩ ��"); blank(4); half(3);  line(1);
	full(6); blank2(17); outO("��ʼ��"); line(1);
	Sleep(dy_star);
}
void kaguyaEStar18()
{
	kaguya0();
	full(17); blank2(6); outO("�� ��  �� ��"); blank2(2);  half(1); outO("��"); half(1); line(1);
	full(14); blank2(9); outO("��ƻ���¡�"); blank2(2); half(1); outO("ҹ"); half(1); line(1);
	full(11); blank2(12); outO("�� ��  ĩ ��"); blank(4); half(3);  line(1);
	full(6); blank2(17); outO("��ʼ���"); line(1);
	Sleep(dy_star);
}
void kaguyaEStar19()
{
	kaguya0();
	full(17); blank2(6); outO("�� ��  �� ��"); blank2(2);  half(1); outO("��"); half(1); line(1);
	full(14); blank2(9); outO("��ƻ���¡�"); blank2(2); half(1); outO("ҹ"); half(1); line(1);
	full(11); blank2(12); outO("�� ��  ĩ ��"); blank(4); half(3);  line(1);
	full(6); blank2(17); outO("��ʼ����"); line(1);
	Sleep(dy_star);
}
void kaguyaEStar20()
{
	kaguya0();
	full(17); blank2(6); outO("�� ��  �� ��"); blank2(2);  half(1); outO("��"); half(1); line(1);
	full(14); blank2(9); outO("��ƻ���¡�"); blank2(2); half(1); outO("ҹ"); half(1); line(1);
	full(11); blank2(12); outO("�� ��  ĩ ��"); blank(4); half(3);  line(1);
	full(6); blank2(17); outO("��ʼ�����"); line(1);
	Sleep(dy_star);
}

void kaguyaEStar21(int i)
{
	kaguya0();
	full(17); blank2(6); outO("�� ��  �� ��"); blank2(2);  half(1); outO("��"); half(1); line(1);
	full(14); blank2(9); outO("��ƻ���¡�"); blank2(2); half(1); outO("ҹ"); half(1); line(1);
	full(11); blank2(12); outO("�� ��  ĩ ��"); blank(4); half(3);  line(1);
	full(6); blank2(17); outO("��ʼ�����"); line(1);
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
	outGDy("  �������磬լۡ�ͺͽ��ϵ���������ظ�Զ�ˡ�");
	outGDy("  ������ɽ���ϵ���ݡ�");
	outGDy("  �ڽֵ����ľ����������ĵ���");
	outDy("  ��Ȼ�ܵ��������������ţ��������������˵�ǹ���");
	outGDy("ңԶ������֮�ʣ�����˭ס������Į�����ġ�");
	line(2);
	outGDy("  �����Ǳߣ�");
	blank(9);
	outODy("  ֻҪ�������������磬�����ң�");
	Sleep(1000);
	outODy("��ͬ�����",50);
	getS();
	line(2);
	outGMDy("In the next year����");
	outGMDy("��");
	endclear1();
}
void changmo()
{
	color(0, 8);
	Sleep(1000);
	endclear2();
	clear(2);
	outGDy("  �ܾò����ˣ�������");
	outGDy("  ����û����������");
	outGDy("  �����������Ƿ���úܾ����ء���");
	outGDy("  ��֮�������򵥽���һ���������ɡ�");
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

	out("���ڿ��е�������Ȼɢ���������Ĺ�â��");
	out("��ˬ�ķ紵�����ḧ���ҵ����գ���ľ��Ҷ��Ҳҡ���š�");
	out("��֪Ϊ�Σ��ҵ����鲻��˼���ƽ����");
	//outInt('@', "�ƻ����", "�����л�", "��ĩ");

	gracolor(6);
	out("�ٿ������������");
}
void test2()
{
	out("�ƻ���»ƻ���»ƻ���»ƻ���»ƻ���»ƻ���»ƻ���»ƻ����");
}
void FC()
{
	line(1);
	outOOMDy("�����������ԣ�"); line(1);
	outOOMDy("���壺��С����36����  ���塪������"); line(1);
	outOOMDy("���֣���Ļ��������С�����߶�:22"); line(7);
	outOOMDy("SanBingһ�ţ�«έ��׼������"); line(2);
	outOOMDy("����F11��س�  ��ʼ��Ϸ");
	getS();
	clear(0);
	line(6);
	outOOMDy("ѡ�����Ӣ�ۣ�"); line(2);
	blank2(3); out2OMDy("1.̽�ռ�", "2.�������"); line(2);
	blank2(3); out2OMDy("3.EZ", "4.�����Ƕ�"); line(2);
	blank2(3); out2OMDy("5.С��ë", "6.���������ӵ����"); line(2);
	blank2(5); int a = inIntCan(1, 6, "���ҵ��Ծ�,����", "��˵ֻ�а�֢���ڻῴ����仰��remake��"); line(2);
}
void chushi()
{
	line(1);
	outM("���ʼ����ء�");	line(1);
	outM("�ڿ�ʼ֮ǰ��������������������...");	line(1);
	out("�����ڣ�  ���Ҽ����Ӧ�õ��Ϸ��׿򴦣���� ���ԣ�");
	out("  1.ѡ�������С��С  (û���ἰ�Ĳ�������Ҫ�޸�)");
	out("  2.���塪����С��36        ���壺���壨�Ƽ���");
	out("  3.���֡�����Ļ��������С���߶� �� 22");
	out("            ���ڴ�С��      ��� �� 71   �߶� �� 22  ");
	out("                                        ������� ȷ��  ");

	out("�����⣺  ���Ҽ�����հ״������ ��ʾ����(win10ϵͳ)��");
	out("  �����벼�֡���  ���ֱ��ʺ���Ҫ��");
	out("       ����200%   ��Ļ�ֱ���:2560 x 1600");
	out("    �� ����150%   ��Ļ�ֱ���:1920 x 1200");
	out("    �� ����100%   ��Ļ�ֱ���:1280 x  800");
	out("                                        �����ص�������");
	outM("�������Ļ�����ȥ���ļ����ͼƬ�̳�"); line(1);
	outM("ȫ����ɺ�F11��Fn+F11����ȫ��ģʽ");
	outGM("����ȷ�������س�������...");

	clear(1);
	outGM("��ʼ֮ǰ�����һ��˵����");
	outGMDy("��Ϊ�˷����Ժ��������������˵��û���ӳ٣�");
	line(1);
	out("  ���ǵ��ڸ�һ΢����ѧ����VB��Visual Basic����?");
	line(1);
	out("  ͨ���ô���������������һЩ����,�Ҿ���������");
	out("�ƵĹ�����");
	line(1);
	out("  �����רҵ�ı��������������C������Ϊ��һ����");
	out("����ѧϰ��֮����ѧC++,JAVA����"); line(1);
	out("  ���������Ȼ��������VB������ģ�����VB����ʾͼ");
	out("�Σ����ֻ�кڵװ��ֵ��ı���");
	line(1);
	out("  ���ִ��ڵġ�������Ϣ���ķ�ʽҲ��VB��ͬ��ͨ�����");
	out("�������������Ȼ�������Ҳ���������������һ�û��");
	outG("��ϸ�о�������");

	clear(5);
	out("  ĿǰҲֻ�ܴ���Ӽ����ϵ�������ַ�����Ϣ��ʵ��");
	out("��ȡ��"); line(1);
	outG("  ��Ҫ��������ֻ�����֡�");
	out("  ��һ���Ǹղ�������һ�λ����������롰�س�����");
	out("��������һ�䣬���ҵ�����'��'ʱ���ͱ�ʾ��һ�λس�");
	outG("�ỻҳ�ˡ�");
	out("  �ڶ���������س�ǰ��Ҫ�����֣���������ı�־");
	out("�ǳ��ַ�����[],�������桪��"); line(1);
	blank2(5); int a = inIntO(1, 100, "���롰�����ڵ�����+�س���������ʾ ", "��������ִ�Ľ̳̰ɡ���", 0);
}