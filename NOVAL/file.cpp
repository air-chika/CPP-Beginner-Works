#include "file.h"

File& File::novelread(Pagelist& list,const char a[])
{
	fin.open(a);
	//页结束另起一行用#，链结束用$,链结束时不需要#
	Page* page;
	Para* para;
	int i = 0;//如果有决策形page，这里应该改进
	int end = 0;
	char reg[30]{};
	fin >> reg>>reg;
	strcpy_s(list.name, reg);
	fin >> reg;
	fin >> i;
	list.number = i;
	fin >> reg;
	fin >> reg;
	list.mainwordcolor = colortransform(reg);
	fin >> reg;
	fin >> reg;
	list.mainwordbackcolor = colortransform(reg);
	fin >> reg;
	fin >> reg;
	list.mainbackcolor = colortransform(reg);
	fin >> reg;
	fin >> reg;
	list.boardmode = boardtransform(reg);
	fin >> reg;
	fin >> reg;
	list.boardcolor = colortransform(reg);

	i = 0;
	do 
	{
		i++;
        page = list.add();
		page->rank = i;
		int j = 0;
		do
		{
			j++;
			para = page->add();
			fin >> para->str;
			para->rank = j;
		} while (para->str[0] != '#' && para->str[0] != '$');
		if (para->str[0] == '$') end = 1;
		para->pre->str[strlen(para->pre->str)] = para->str[0];
		page->Delete();
	} while (!end);
	fin.close();
	return *this;
}

File& File::novelwrite(Pagelist& list, const char a[])
{
	fout.open(a);
	//页结束另起一行用#，链结束用$,链结束时不需要#
	Page* page;
	Para* para;
	int i = 0;//如果有决策形page，这里应该改进
	int end = 0;
	char reg;
	char regc[10];
	fout << "编号: ";
	fout << list.name;
	fout << "编号: ";
	fout << list.number;
	fout << "\n文字主色调: ";
	fout << colortransform(list.mainwordcolor, regc);
	fout << "\n文字副色调: ";
	fout << colortransform(list.mainwordbackcolor, regc);
	fout << "\n背景主色调: ";
	fout << colortransform(list.mainbackcolor, regc);
	fout << "\n背景板: ";
	fout << boardtransform(list.boardmode,regc);
	fout << "\n背景板色调: ";
	fout << colortransform(list.boardcolor, regc) <<"\n\n";


	page = list.pagehead;
	do
	{
		page = page->next;
		para = page->parahead;
		int j = 0;
		do
		{
			j++;
			para = para->next;
			fout << para->str<<endl;
		} while (para->next->next!=0);
		para = para->next;
		reg = para->str[strlen(para->str)-1];
		para->str[strlen(para->str)-1]=0;
		fout << para->str << endl;

		if (reg == '$')
		{
			end = 1;
			fout << '$';
		}
		else
			fout << "#\n\n";
	} while (!end);
	fout.close();
	return *this;
}

