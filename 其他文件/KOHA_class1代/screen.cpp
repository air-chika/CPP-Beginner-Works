#include"screen.h"


int colortransform(const char a[])
{
	if (strcmp(a, "����") == 0) return 1;
	if (strcmp(a, "���") == 0) return 1;
	if (strcmp(a, "����") == 0) return 2;
	if (strcmp(a, "����") == 0) return 2;
	if (strcmp(a, "����") == 0) return 3;
	if (strcmp(a, "����") == 0) return 3;
	if (strcmp(a, "����") == 0) return 4;
	if (strcmp(a, "����") == 0) return 5;
	if (strcmp(a, "���") == 0) return 5;
	if (strcmp(a, "����") == 0) return 6;
	if (strcmp(a, "����") == 0) return 6;
	if (strcmp(a, "�ػ�") == 0) return 7;
	if (strcmp(a, "����") == 0) return 8;
	if (strcmp(a, "���") == 0) return 9;
	if (strcmp(a, "����") == 0) return 10;
	if (strcmp(a, "����") == 0) return 11;
	if (strcmp(a, "����") == 0) return 11;
	if (strcmp(a, "����") == 0) return 12;
	if (strcmp(a, "����") == 0) return 12;
	if (strcmp(a, "�ۺ�") == 0) return 13;
	if (strcmp(a, "�Ϻ�") == 0) return 14;
	if (strcmp(a, "Ʒ��") == 0) return 14;
	if (strcmp(a, "�»�") == 0) return 15;
	if (strcmp(a, "����") == 0) return 15;
	if (strcmp(a, "����") == 0) return 16;
	return 0;
}

char* colortransform(int num, char* a)
{
	switch (num)
	{
	case 1:strcpy_s(a, 5, "����");; break;
	case 2:strcpy_s(a, 5, "����");; break;
	case 3:strcpy_s(a, 5, "����");; break;
	case 4:strcpy_s(a, 5, "����");; break;
	case 5:strcpy_s(a, 5, "����");; break;
	case 6:strcpy_s(a, 5, "����");; break;
	case 7:strcpy_s(a, 5, "�ػ�");; break;
	case 8:strcpy_s(a, 5, "����");; break;
	case 9:strcpy_s(a, 5, "���");; break;
	case 10:strcpy_s(a, 5, "����");; break;
	case 11:strcpy_s(a, 5, "����");; break;
	case 12:strcpy_s(a, 5, "����");; break;
	case 13:strcpy_s(a, 5, "�ۺ�");; break;
	case 14:strcpy_s(a, 5, "�Ϻ�");; break;
	case 15:strcpy_s(a, 5, "�»�");; break;
	case 16:strcpy_s(a, 5, "����");; break;
	default:
		break;
	}
	return a;
}

int boardtransform(const char a[])
{
	if (strcmp(a, "�հ�") == 0) return 0;
	if (strcmp(a, "����") == 0) return 1;
	if (strcmp(a, "�Ľ�������") == 0) return 2;
	if (strcmp(a, "�Ľ���������") == 0) return 3;

	if (strcmp(a, "����") == 0) return 4;
	if (strcmp(a, "˫��") == 0) return 5;
	if (strcmp(a, "����˫��") == 0) return 6;
	if (strcmp(a, "����˫��") == 0) return 7;
	if (strcmp(a, "KOHAtest1") == 0) return 8;
	return 0;
}

char* boardtransform(int num, char* a)
{
	switch (num)
	{
	case 0:strcpy_s(a, 5, "�հ�");; break;
	case 1:strcpy_s(a, 5, "����");; break;
	case 2:strcpy_s(a, 5, "�Ľ�������");; break;
	case 3:strcpy_s(a, 5, "�Ľ���������");; break;

	case 4:strcpy_s(a, 5, "����");; break;
	case 5:strcpy_s(a, 5, "˫��");; break;
	case 6:strcpy_s(a, 5, "����˫��");; break;
	case 7:strcpy_s(a, 5, "����˫��");; break;
	case 8:strcpy_s(a, 5, "KOHAtest1");; break;
	default:
		break;
	}
	return a;
}