#include"smpTime.h"

namespace smpRdm {

	int refresh()
	{
		srand(unsigned int(time(0)));
		return 1;
	}
	const int JUSTDEFINE = refresh();

	int intRdm(int min, int max)
	{
		return (rand() % (max - min)) + min;
	}

}

namespace smpTime
{
	char* newWorldTimeStr()
	{
		char* str = new char[50]{};
		time_t t;
		tm* lt = new tm;
		time(&t);//获取Unix时间戳。
		localtime_s(lt, &t);//转为时间结构。
		//sprintf_s(str, 50, "%d.%d.%d %d时%d分%d秒 ", lt->tm_year + 1900, lt->tm_mon, lt->tm_mday, lt->tm_hour, lt->tm_min, lt->tm_sec);
		sprintf_s(str, 50, "%d.%d %d时%d分%d秒", lt->tm_mon, lt->tm_mday, lt->tm_hour, lt->tm_min, lt->tm_sec);
		delete lt;
		return str;
	}
}
