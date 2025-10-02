#include"screen.h"


int colortransform(const char a[])
{
	if (strcmp(a, "纯黑") == 0) return 1;
	if (strcmp(a, "深黑") == 0) return 1;
	if (strcmp(a, "纯蓝") == 0) return 2;
	if (strcmp(a, "深蓝") == 0) return 2;
	if (strcmp(a, "纯绿") == 0) return 3;
	if (strcmp(a, "深绿") == 0) return 3;
	if (strcmp(a, "天蓝") == 0) return 4;
	if (strcmp(a, "纯红") == 0) return 5;
	if (strcmp(a, "深红") == 0) return 5;
	if (strcmp(a, "纯紫") == 0) return 6;
	if (strcmp(a, "深紫") == 0) return 6;
	if (strcmp(a, "棕黄") == 0) return 7;
	if (strcmp(a, "淡灰") == 0) return 8;
	if (strcmp(a, "深灰") == 0) return 9;
	if (strcmp(a, "湖蓝") == 0) return 10;
	if (strcmp(a, "草绿") == 0) return 11;
	if (strcmp(a, "鲜绿") == 0) return 11;
	if (strcmp(a, "冰蓝") == 0) return 12;
	if (strcmp(a, "蓝绿") == 0) return 12;
	if (strcmp(a, "粉红") == 0) return 13;
	if (strcmp(a, "紫红") == 0) return 14;
	if (strcmp(a, "品红") == 0) return 14;
	if (strcmp(a, "月黄") == 0) return 15;
	if (strcmp(a, "亮黄") == 0) return 15;
	if (strcmp(a, "纯白") == 0) return 16;
	return 0;
}

char* colortransform(int num, char* a)
{
	switch (num)
	{
	case 1:strcpy_s(a, 5, "纯黑");; break;
	case 2:strcpy_s(a, 5, "纯蓝");; break;
	case 3:strcpy_s(a, 5, "深绿");; break;
	case 4:strcpy_s(a, 5, "天蓝");; break;
	case 5:strcpy_s(a, 5, "纯红");; break;
	case 6:strcpy_s(a, 5, "深紫");; break;
	case 7:strcpy_s(a, 5, "棕黄");; break;
	case 8:strcpy_s(a, 5, "淡灰");; break;
	case 9:strcpy_s(a, 5, "深灰");; break;
	case 10:strcpy_s(a, 5, "湖蓝");; break;
	case 11:strcpy_s(a, 5, "草绿");; break;
	case 12:strcpy_s(a, 5, "冰蓝");; break;
	case 13:strcpy_s(a, 5, "粉红");; break;
	case 14:strcpy_s(a, 5, "紫红");; break;
	case 15:strcpy_s(a, 5, "月黄");; break;
	case 16:strcpy_s(a, 5, "纯白");; break;
	default:
		break;
	}
	return a;
}

int boardtransform(const char a[])
{
	if (strcmp(a, "空白") == 0) return 0;
	if (strcmp(a, "满格") == 0) return 1;
	if (strcmp(a, "四角满格单线") == 0) return 2;
	if (strcmp(a, "四角三满格单线") == 0) return 3;

	if (strcmp(a, "单线") == 0) return 4;
	if (strcmp(a, "双线") == 0) return 5;
	if (strcmp(a, "纵向双线") == 0) return 6;
	if (strcmp(a, "横向双线") == 0) return 7;
	if (strcmp(a, "KOHAtest1") == 0) return 8;
	return 0;
}

char* boardtransform(int num, char* a)
{
	switch (num)
	{
	case 0:strcpy_s(a, 5, "空白");; break;
	case 1:strcpy_s(a, 5, "满格");; break;
	case 2:strcpy_s(a, 5, "四角满格单线");; break;
	case 3:strcpy_s(a, 5, "四角三满格单线");; break;

	case 4:strcpy_s(a, 5, "单线");; break;
	case 5:strcpy_s(a, 5, "双线");; break;
	case 6:strcpy_s(a, 5, "纵向双线");; break;
	case 7:strcpy_s(a, 5, "横向双线");; break;
	case 8:strcpy_s(a, 5, "KOHAtest1");; break;
	default:
		break;
	}
	return a;
}