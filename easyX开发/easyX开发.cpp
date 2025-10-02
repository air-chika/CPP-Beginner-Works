#include"easyImg.h"
#include"example.h"
using namespace std;
using namespace eGraph;
using namespace Color;
int main()
{
	//Example::mouse();
	initial(900, 500);

	Form form(2,2,100,50,4,Rgb("棕"), Rgb("申布伦"), Rgb("黑4"));
	form.setDes({ 100,100 });
	form.setText("easyX", 1, 1);
	form.setText("Test", 2, 1);
	form.setText("Left", 1, 2);
	form.setText("Right", 2, 2);
	form.load();
	form.graDraw();
	smpConUI::in::getChoice(0);

}

