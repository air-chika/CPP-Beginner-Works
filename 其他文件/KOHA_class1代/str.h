#pragma once
#include <cstring>
#include <iostream>
#include<stdio.h>
using namespace std;
class Str
{
public:
    void copy(char a[], const char b[]);
    //������b[n-1],a[n-1]
    void copy(char a[], const char b[],int n);
    //ֻ������Чλ
    void cop(char a[], const char b[]);
    void cate(char a[], const char b[]);
    //����nλ��n��λ��Ϊ0
    void cate(char a[], const char b[],int n);
    //����a��b
    void exch(char a[], char b[]);
    //a��b��ѭ����nλ�� ���Ż������ı�Ҫ
    void set(char a[],const char b,int n);
    void set(char a[],const char b[],int n);
    void set_time(char a[],const char b[],int n);
    //b�����з�32��Ԫ�ظ��ǵ�a��
    void add(char a[], const char b[]);
    int len(const char a[]);
    char* build(const char a[]);
    void free(char* a);
    int numline(const char a[]);
    int firstline(const char a[]);//a�����ŷ���ֵ a[n]=10
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

