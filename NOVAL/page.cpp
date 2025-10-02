#include "page.h"

Para::Para(int i)
{
	str = 0;
}
Para::Para()
{
	str = new char[300]{};
}
Para::~Para()
{
	if (str)
	    delete[] str;
}

Page::Page()
{
	parahead = new Para(0);
	paraend = parahead;
}
Page::~Page()
{
	while (parahead)
	{
		p = parahead;
		parahead = parahead->next;
		delete p;
	}
}
Para* Page::add()
{
	paraend->next = new Para;
	paraend->next->pre = paraend;
	paraend = paraend->next;
	return paraend;
}
void Page::Delete()
{
	paraend = paraend->pre;
	delete paraend->next;
	paraend->next = 0;
}



Page* Pagelist::add()
{
	end->next= new Page;
	end->next->pre = end;
	end = end->next;
	return end;
}
