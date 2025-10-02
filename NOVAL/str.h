#pragma once
#include <cstring>
#include <iostream>
#include<stdio.h>
using namespace std;
class Str
{
public:
    void copy(char a[], const char b[]);
    //复制至b[n-1],a[n-1]
    void copy(char a[], const char b[],int n);
    //只复制有效位
    void cop(char a[], const char b[]);
    void cate(char a[], const char b[]);
    //链接n位，n后位设为0
    void cate(char a[], const char b[],int n);
    //交换a与b
    void exch(char a[], char b[]);
    //a是b的循环（n位） 有优化负数的必要
    void set(char a[],const char b,int n);
    void set(char a[],const char b[],int n);
    void set_time(char a[],const char b[],int n);
    //b中所有非32的元素覆盖到a上
    void add(char a[], const char b[]);
    int len(const char a[]);
    char* build(const char a[]);
    void free(char* a);
    int numline(const char a[]);
    int firstline(const char a[]);//a方括号返回值 a[n]=10
    int asc(char a, char b);
    int asc(char a);
    int asc2(char a);
    int full(char* a);
    int conf(const char* a, const char* b);
    void clear(char* a);
    void rish(char* a, int num);
    void lesh(char* a, int num);
    void sign(char* a, int row);
};

