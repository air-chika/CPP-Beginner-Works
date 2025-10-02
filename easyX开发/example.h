#pragma once
#include<iostream>
#include <conio.h>
#include<easyx.h>
using namespace std;

namespace Example {

	int zifu()
	{
		// �����������
		srand((unsigned)time(NULL));

		// ��ʼ��ͼ��ģʽ
		initgraph(640, 480);

		int  x, y;
		char c;

		settextstyle(16, 8, _T("Courier"));	// ��������

		// ������ɫ
		settextcolor(GREEN);
		setlinecolor(BLACK);

		for (int i = 0; i <= 479; i++)
		{
			// �����λ����ʾ���������ĸ
			for (int j = 0; j < 3; j++)
			{
				x = (rand() % 80) * 8;
				y = (rand() % 20) * 24;
				c = (rand() % 26) + 65;
				outtextxy(x, y, c);
			}

			// ���߲���һ��������
			line(0, i, 639, i);

			Sleep(10);					// ��ʱ
			if (i >= 479)	i = -1;
			if (_kbhit())	break;		// ��������˳�
		}

		// �ر�ͼ��ģʽ
		closegraph();
		return 0;
	}

#define MAXSTAR 200	// ��������

	struct STAR
	{
		double	x;
		int		y;
		double	step;
		int		color;
	};

	STAR star[MAXSTAR];

	// ��ʼ������
	void InitStar(int i)
	{
		star[i].x = 0;
		star[i].y = rand() % 480;
		star[i].step = (rand() % 5000) / 1000.0 + 1;
		star[i].color = (int)(star[i].step * 255 / 6.0 + 0.5);	// �ٶ�Խ�죬��ɫԽ��
		star[i].color = RGB(star[i].color, star[i].color, star[i].color);
	}

	// �ƶ�����
	void MoveStar(int i)
	{
		// ����ԭ��������
		putpixel((int)star[i].x, star[i].y, 0);

		// ������λ��
		star[i].x += star[i].step;
		if (star[i].x > 640)	InitStar(i);

		// ��������
		putpixel((int)star[i].x, star[i].y, star[i].color);
	}

	// ������
	int stars()
	{
		srand((unsigned)time(NULL));	// �������
		initgraph(640, 480);			// ������ͼ����

		// ��ʼ����������
		for (int i = 0; i < MAXSTAR; i++)
		{
			InitStar(i);
			star[i].x = rand() % 640;
		}

		// �����ǿգ���������˳�
		while (!_kbhit())
		{
			for (int i = 0; i < MAXSTAR; i++)
				MoveStar(i);
			Sleep(20);
		}

		closegraph();					// �رջ�ͼ����
		return 0;
	}



	int mouse()
	{
		// ��ʼ��ͼ�δ���
		initgraph(640, 480);

		ExMessage m;		// ������Ϣ����

		while (true)
		{
			// ��ȡһ�����򰴼���Ϣ
			m = getmessage(3);

			switch (m.message)
			{
			case WM_MOUSEMOVE:
				// ����ƶ���ʱ�򻭺�ɫ��С��
				putpixel(m.x, m.y, RED);
				break;

			case WM_LBUTTONDOWN:
				// ����������ͬʱ������ Ctrl ��
				if (m.ctrl)
					// ��һ���󷽿�
					rectangle(m.x - 10, m.y - 10, m.x + 10, m.y + 10);
				else
					// ��һ��С����
					rectangle(m.x - 5, m.y - 5, m.x + 5, m.y + 5);
				break;

			case WM_KEYDOWN:
				if (m.vkcode == VK_ESCAPE)
					return 0;	// �� ESC ���˳�����
			}
		}

		// �ر�ͼ�δ���
		closegraph();
		return 0;
	}


	int rainbow()
	{
		// ������ͼ����
		initgraph(640, 480);

		// ����������(ͨ������������)
		float H = 190;		// ɫ��
		float S = 1;		// ���Ͷ�
		float L = 0.7f;		// ����
		for (int y = 0; y < 480; y++)
		{
			L += 0.0005f;
			setlinecolor(HSLtoRGB(H, S, L));
			line(0, y, 639, y);
		}

		// ���ʺ�(ͨ��ɫ��������)
		H = 0;
		S = 1;
		L = 0.5f;
		setlinestyle(PS_SOLID, 2);		// �����߿�Ϊ 2
		for (int r = 400; r > 344; r--)
		{
			H += 5;
			setlinecolor(HSLtoRGB(H, S, L));
			circle(500, 480, r);
		}

		// ��������˳�
		_getch();
		closegraph();
		return 0;
	}

}
