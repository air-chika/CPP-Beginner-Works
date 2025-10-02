#include"file.h"
#include"out.h"
int main()
{
	Screen scr;
	Save save;
	File file;
	file.dataread(scr, save);

	Cursor cursor(scr);
	Pagelist list[6];
	OutWord outword(scr);
	Color color;

	file.novelread(list[1], "KOHA 1.txt");
	file.novelread(list[2], "KOHA 2.txt");
	file.novelread(list[3], "KOHA 3.txt");
	file.novelread(list[4], "KOHA 4.txt");
	file.novelread(list[5], "KOHA 5.txt");
	char* a = list[1].name;
	char* b = list[2].name;
	char* c = list[3].name;
	char* d = list[4].name;
	char* e = list[5].name;

	cursor.hide();

	char reg1, reg2;
	int control;
	Get in(reg1, reg2, control);

	//打印模板
	OutPattern outboard(scr);
	Pattern board;
	board.boardline(scr.wide,scr.high,5,3);
	outboard.backcolor = 1;
	outboard.out(board, 1, 1);

	//省略号的outpattern类
	OutPattern out(scr);
	out.backcolor = 1;

	//初始化省略号
	Pattern count;
	count.countmode();

	int end=0;
	int counts = 1;//计数，用于更改时钟周期
	int nowchoose = 1;//高亮选项
	int time = 0;//作为时钟周期数，如果要用%的话应为所有数的 最小公倍数
	int timeee = 0;
	int leftposition = (scr.wide - strlen(a)) / 2;
	int upposition = (scr.high - 3) / 2;

	//选取操作，需要获取起始坐标值，双颜色（不涉及修改背景颜色）
	//control是键盘打出的符号值
	while (1)
	{
		
		//无等待获取且完成转换
		in.getcontrol();
		//i指向选项的编号，指向哪里那里既是高亮
		switch (control)
		{
			//说明区间位于[1,3]
		case 'w':
		case 'a':
	        nowchoose--;
			if (nowchoose == 0) nowchoose = 5;
			break;
		case 's':
		case 'd':
			nowchoose++;
			if (nowchoose == 6) nowchoose = 1; 
			break;
		case 13:
		case 32:
			outword.outlist(list[nowchoose]);
			cursor.setxy(leftposition, upposition);
			cout << "over"; in.wait();
			outboard.out(board, 1, 1);
		    break;
		case 8:
		case 27:
			return 0; 
		default:
			break;
		}

		//对3个选项的逐个操作 option选项 nowchoose现在的选项
		//在一次循环(画面)中，3个选项都会打印
		//这里应该封装一下，初始化为四种颜色，入口只有高亮
		//应该是pattern
		for (int option = 1; option < 6; option++)
		{
			//对选项填色
			if (option == nowchoose)
				color.set(15, 1);
			else
				color.set(7, 1);

			switch (option)
			{
				//这里的字符串自己带有换行，但是应该修改cursor
			case 1:
				//可改
				cursor.setxy(leftposition, upposition);
				cout << a;
				cursor.addy(1);
				cursor.setx(leftposition);
				break;
			case 2:cout << b;
				cursor.addy(1);
				cursor.setx(leftposition);
				break;
			case 3:cout << c;
				cursor.addy(1);
				cursor.setx(leftposition);
				break;
			case 4:cout << d;
				cursor.addy(1);
				cursor.setx(leftposition);
				break;
			case 5:cout << e; break;
			default:
				break;
			}
		}

		//sleep500(自周期)比上sleep100(同步时钟周期)
		//如果要封装，应该在定义时给予同步时钟秒数，而这里每执行一次都会+1，加至比例则out一帧
		//                                                         大概是两个判断的样子,并且里面不自带循环
		counts++;
		counts %= (500 / 100);
		if (!counts)
		{
			//从0到3改变的图案
			timeee++;
			timeee %= 12;//这里应该除以动画帧数
			out.out(count.count(timeee), leftposition-2, upposition);
		}
		Sleep(100);
		time++;
	}

	
	
	/*file.novelwrite(list[1], "KOHA 1.txt");
	file.novelwrite(list[2], "KOHA 2.txt");
	file.novelwrite(list[3], "KOHA 3.txt");
	file.novelwrite(list[4], "KOHA 4.txt");
	file.novelwrite(list[5], "KOHA 5.txt");
	file.datawrite(scr, save);*/
}
