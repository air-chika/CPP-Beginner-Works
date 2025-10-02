#include"pattern.h"
//	cout << "│┌┐╔╗═╓╖╒╕\n"; —
//	cout << "─└┘╚╝║╙╜╘╛\n"; 6(12)种模板
	//考虑命名空间的析构函数
	//共八个
	//char* ul, * ur, * dl, * dr, * up, * down, * left, * right;
	//左上，右上，左下，右下，左，上，右，下

char boardlinemodel::full[8][3]{ "bb","bb","bb","bb","bb","bb","bb","bb" };
char boardlinemodel::singleline[8][3]{ "┌","┐","└","┘","│","—","│","—" };
char boardlinemodel::doubleline[8][3]{ "╔","╗","╚","╝","║","═","║","═" };
char boardlinemodel::highdoubleline[8][3]{ "╓","╖","╙","╜","║","─","║","─" };
char boardlinemodel::widedoubleline[8][3]{ "╒","╕","╘","╛","│","═","│","═" };
char boardlinemodel::fullcorners[8][3]{ "bb","bb","bb","bb","|","—"," |","—" };