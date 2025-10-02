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
		time(&t);//��ȡUnixʱ�����
		localtime_s(lt, &t);//תΪʱ��ṹ��
		//sprintf_s(str, 50, "%d.%d.%d %dʱ%d��%d�� ", lt->tm_year + 1900, lt->tm_mon, lt->tm_mday, lt->tm_hour, lt->tm_min, lt->tm_sec);
		sprintf_s(str, 50, "%d.%d %dʱ%d��%d��", lt->tm_mon, lt->tm_mday, lt->tm_hour, lt->tm_min, lt->tm_sec);
		delete lt;
		return str;
	}
}
