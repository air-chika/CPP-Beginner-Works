#pragma once
#include <cstring>
#include<string>
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<WinBase.h>
#include <iostream>
#include"rand.h"

extern int eve;   //every      32����ԣ��ӿ�  ÿ���ֵ�ͣ��
extern int tod;  //to delay  400����ԣ��ӿ� ÿ��ѡ����ͣ��
extern int Dy_20;  //delay20  ��Զ�������ͼ
extern int Dy_Jie;  //delay20  ��Խ���Ķ�����ͼ

void sleepTod();
void getS();
//int inInt( int num,int color1);
//int inInt(int num, const char b[], const char c[], const char d[], int color1, int color2);
//void outInt(char,const char[],const char[]);
//void outInt(char, const char[], const char[], const char[]);
//void outInt(char, const char[], const char[], const char[], const char[]);
//void outInt(char, const char[], const char[], const char[], const char[], const char[]);
//void outInt(char, const char[], const char[], const char[], const char[], const char[], const char[]);

void clear(int); //����ռ��

// ����ߣ���������
void clearLine();
				 
void color(int); 
//��ɫ
//  0 = ��ɫ       8    = ��ɫ
//  1 = ��ɫ       9    = ����ɫ
//  2 = ��ɫ       10 A = ����ɫ
//  3 = ����ɫ     11 B = ��ǳ��ɫ
//  4 = ��ɫ       12 C = ����ɫ
//  5 = ��ɫ       13 D = ����ɫ
//  6 = ��ɫ       14 E = ����ɫ
//  7 = ��ɫ       15 F = ����ɫ
void color(int,int);
void gracolor(int);
void tranCol(int);
void tranColDy(int);
void tranColDy0(int);
void colorTable();//��ռ8��
void colorTableDy();//��ռ8��


void out(const char[]); //���°˸�������ʽ��  �ı������ ����ȡ�����Զ����У����Ľ���������Ҫ�Լ������ӡ�һ��48�������Լ���
void outDy(const char[]); //���һ����Ҫgets��G���� getS��
void outM(const char[]); //mid��ʾ���У��޶���  9  25*2��  11  ʹ�á�
void outMDy(const char[]);//out���Զ����� line(1); ��G��Ҫ  getS();

void outG(const char[]);
void outGDy(const char[]);
void outGODy(const char[]);
void outGM(const char[]);
void outGMDy(const char[]);

void outTop(const char[]);
void outTopDy(const char[]);
void outODy(const char []);
void outODy(const char[],int);//����
void outODy2(const char []);//���ӳ�
void outODy20(const char[]);//20ms
void outODyJie(const char[]);//��ɫ����õ�,20ms
void outODy0(const char[]);
void outOMDy(const char []);
void outOM(const char[]);
void outOOMDy(const char[]);//only��ӡ������ only�������ֲ�blank
void outOOM(const char[]);
void outOMDy0(const char[]);
void out2OMDy(const char[], const char[]);
void outO(const char[]);
void outO(int);  //�޶�ռ4��
void outODy(int);//�޶�ռ4��,ֻ�������Dy
void outOT(int); //�޶�ռ2��

void line(int);
void lineDy(int);  //ѡ���е�����
void endclear1();//���н���
void lineDy2(int);//ͼ������
void endclear2();//���н���
void lineDy3(int);//����ĺ���

void blank(int);
void blankDy(int);
void blank2(int);
void blank2Dy(int);
void blankMid(int);//��ʾ�ĳ��׺������ȿ�10�����Զ���λ���ᵽ�м�


void full(int);
void fullDy(int);             //����û��Ķ�û��ϵ
void fullDy(int,int);             //���أ��ֶ�֡��
void fullDy20(int);
void fullDyJie(int);          //���涯���ٶȣ�������
void fullDy200(int);  //���ӳ�
void half(int);
void halfDy(int);             //����û��Ķ�û��ϵ
void halfDy(int,int);         //����
void halfDy20(int);
void halfDyJie(int);          //���涯���ٶȣ�������
void halfDy200(int);  //���ӳ�

//�����
void Weizhi(int);
void draw(int[]);
void drawDy(int[]);

int inIntO(int num1, int num2, const char a[], const char b[],int c);//only���룬cΪ�ӳ�
int inIntCan(int num1, int num2, const char a[], const char b[]);//�������õ�����
int inIntCan0(int num1, int num2, const char a[], const char b[]);
int inIntCanM(int num1, int num2, const char a[], const char b[]);

//�����
//void star(int);
//void starDy(int);
//void starDy2(int);  //���ӳ�
//�����
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

