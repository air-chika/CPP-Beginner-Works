#include"smpError.h"
using namespace std;
using namespace smpConUI;

namespace smpError
{
	void jdgIF(bool failCondition, const char* failContent) {
		if (failCondition) {
			out::clear();
			cout << failContent;
			in::getChoice(0);
			exit(0);
		}
	}

}