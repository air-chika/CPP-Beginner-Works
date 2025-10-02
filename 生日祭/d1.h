#pragma once
#include <cstring>
#include<string>
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<WinBase.h>
#include <iostream>
#include"rand.h"

extern int eve;   //every      32因测试，加快  每个字的停顿
extern int tod;  //to delay  400因测试，加快 每个选项间的停顿
extern int Dy_20;  //delay20  针对动画的作图
extern int Dy_Jie;  //delay20  针对界面的动画作图

void sleepTod();
void getS();
//int inInt( int num,int color1);
//int inInt(int num, const char b[], const char c[], const char d[], int color1, int color2);
//void outInt(char,const char[],const char[]);
//void outInt(char, const char[], const char[], const char[]);
//void outInt(char, const char[], const char[], const char[], const char[]);
//void outInt(char, const char[], const char[], const char[], const char[], const char[]);
//void outInt(char, const char[], const char[], const char[], const char[], const char[], const char[]);

void clear(int); //清屏占格

// 新玩具，还不会用
void clearLine();
				 
void color(int); 
//颜色
//  0 = 黑色       8    = 灰色
//  1 = 蓝色       9    = 淡蓝色
//  2 = 绿色       10 A = 淡绿色
//  3 = 湖蓝色     11 B = 淡浅绿色
//  4 = 红色       12 C = 淡红色
//  5 = 紫色       13 D = 淡紫色
//  6 = 黄色       14 E = 淡黄色
//  7 = 白色       15 F = 亮白色
void color(int,int);
void gracolor(int);
void tranCol(int);
void tranColDy(int);
void tranColDy0(int);
void colorTable();//共占8行
void colorTableDy();//共占8行


void out(const char[]); //以下八个用来格式化  文本输出。 首先取消了自动换行，待改进，所以需要自己数格子。一共48，用完自己换
void outDy(const char[]); //最后一句需要gets，G代表 getS。
void outM(const char[]); //mid表示居中，限定在  9  25*2字  11  使用。
void outMDy(const char[]);//out是自动换行 line(1); ，G需要  getS();

void outG(const char[]);
void outGDy(const char[]);
void outGODy(const char[]);
void outGM(const char[]);
void outGMDy(const char[]);

void outTop(const char[]);
void outTopDy(const char[]);
void outODy(const char []);
void outODy(const char[],int);//重载
void outODy2(const char []);//长延迟
void outODy20(const char[]);//20ms
void outODyJie(const char[]);//颜色表会用到,20ms
void outODy0(const char[]);
void outOMDy(const char []);
void outOM(const char[]);
void outOOMDy(const char[]);//only打印不换行 only输入文字不blank
void outOOM(const char[]);
void outOMDy0(const char[]);
void out2OMDy(const char[], const char[]);
void outO(const char[]);
void outO(int);  //限定占4格
void outODy(int);//限定占4格,只在输入后Dy
void outOT(int); //限定占2格

void line(int);
void lineDy(int);  //选项中的清行
void endclear1();//清行进阶
void lineDy2(int);//图案清行
void endclear2();//清行进阶
void lineDy3(int);//蛋糕的后续

void blank(int);
void blankDy(int);
void blank2(int);
void blank2Dy(int);
void blankMid(int);//提示的初阶函数，先空10，再自动把位置提到中间


void full(int);
void fullDy(int);             //现在没别的都没关系
void fullDy(int,int);             //重载，手动帧数
void fullDy20(int);
void fullDyJie(int);          //界面动画速度，大蜡烛
void fullDy200(int);  //高延迟
void half(int);
void halfDy(int);             //现在没别的都没关系
void halfDy(int,int);         //重载
void halfDy20(int);
void halfDyJie(int);          //界面动画速度，大蜡烛
void halfDy200(int);  //高延迟

//新玩具
void Weizhi(int);
void draw(int[]);
void drawDy(int[]);

int inIntO(int num1, int num2, const char a[], const char b[],int c);//only输入，c为延迟
int inIntCan(int num1, int num2, const char a[], const char b[]);//真正好用的输入
int inIntCan0(int num1, int num2, const char a[], const char b[]);
int inIntCanM(int num1, int num2, const char a[], const char b[]);

//老玩具
//void star(int);
//void starDy(int);
//void starDy2(int);  //高延迟
//老玩具
//void drawLine(int, int);
//void drawLine(int, int, int, int);
//void drawLine(int, int, int, int, int, int);
//void drawLine(int, int, int, int, int, int, int, int);
//void drawLineAllDy(int, int);
//void drawLineAllDy(int, int, int, int);
//void drawLineAllDy(int, int, int, int, int, int);
//void drawLineAllDy(int, int, int, int, int, int, int, int);
//void drawLineStarDy(int, int);
//void drawLineStarDy(int, int, int, int);
//void drawLineStarDy(int, int, int, int, int, int);
//void drawLineStarDy(int, int, int, int, int, int, int, int);
//void drawLineFroDy(int, int);
//void drawLineFroDy(int, int, int, int);
//void drawLineFroDy(int, int, int, int, int, int);
//void drawLineFroDy(int, int, int, int, int, int, int, int);

