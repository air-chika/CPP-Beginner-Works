#include"str.h"

void Str::copy(char a[], const char b[])
{
    strcpy_s(a, len(b) + 1, b);
}

void Str::copy(char a[], const char b[],int n)
{
    //cout << (int)a[0];
    for (int i = 0; i < n; i++)
        a[i] = b[i];
}

void Str::cop(char a[], const char b[])
{
    for (int i = 0; i < len(b); i++)
        a[i] = b[i];
}

void Str::cate(char a[], const char b[])
{
    if (b[0] != 0)
        strcat_s(a, len(a) + len(b) + 1, b);
}

void Str::cate(char a[], const char b[], int n)
{
    int x = len(a),y=len(b);
    strcat_s(a, x + y + 1, b);
    set(&a[x +n], '\0', y-n);
}

void Str::exch(char a[], char b[])
{
    char *c=build(a);
    copy(a, b);
    copy(b, c);
    free(c);
}

void Str::set(char a[], const char b, int n)
{
    for (int i = 0; i < n; i++)
        a[i] = b;
}

void Str::set(char a[],const char b[], int n)
{
    int leng = len(b) - 1;
    for (int i = 0; i < n; i++)
        a[i] = b[i%leng];
}

void Str::set_time(char a[], const char b[], int time)
{
    int leng = len(b) - 1;
    for (int i = 0; i < time*(leng+1); i++)
        a[i] = b[i % leng];
}

void Str::add(char a[], const char b[])
{
    int al = len(a),bl=len(b);
    int leng = al > bl ? al: bl;
    for (int i = 0; i < leng; i++)
    {
        if (!asc(b[i], 32))
        {
            a[i] = b[i];
        }
    }
     
}
int Str::len(const char a[])
{
    return strlen(a);
}
char* Str::build(const char a[])
{
    char* p = new char[300];
    copy(p, a);
    return p;
}
void Str::free(char* a)
{
    delete[] a;
     
}
int Str::numline(const char a[])
{
    int n = 0;
    for (int i = 0; i < len(a); i++)
    {
        if (a[i] == '\n') n++;
    }
    return n;
}
int Str::firstline(const char a[])
{
    int i;
    for (i = 0; a[i] != 10; i++);
    return i;
}
int Str::asc(char a, char b)
{
    if (a == b)return 1;
    else return 0;
}
int Str::asc(char a)
{
    if (a >= 0 && a < 128) return 1;
    return 0;
}
int Str::asc2(char a)
{
    if (a >= 32 && a < 128)
        return 1;
    return 0;
}
int Str::full(char* a)
{
    const char *f= "¨€";
    const char* h = "¨ˆ";
    if((a[0]==f[0]&&a[1]==f[1])|| (a[0] == h[0] && a[1] == h[1]))
    return 1;
    return 0;
}
int Str::conf(const char* a, const char* b)
{
    int n = 0;
    int len = b - a + 1;
    for (int i = 0; i <= len; i++)
    {
        if (asc2(a[i]))
            n++;
    }
    return (len - n) % 2;
}
void Str::clear(char* a)
{
    set(a, '\0', len(a) - 1);
}
void Str::rish(char* a, int num)
{
    int i;
    for (i = len(a) + num; i >= num; i--)
    {
        a[i] = a[i - num];
    }
    for (; i >= 0; i--)
    {
        a[i] = 32;
    }
     
}
void Str::lesh(char* a, int num)
{
    int i;
    int end = len(a) - num;
    for (i = 0; i <= end; i++)
    {
        a[i] = a[i + num];
    }
    end += num;
    for (; i < end; i++)
    {
        a[i] = 0;
    }
     
}
void Str::sign(char* a, int row)
{
    int leng = len(a);
    for (int i = row; i < leng++; i += row)
    {
        if (asc2(a[i]) || !conf(a + i - row, a + i - 1))
        {
            rish(a + i, 1); a[i++] = 10;
        }
        else
        {
            rish(a + i - 1, 1);
            a[i - 1] = '\n';
        }
    }
    cate(a, "\n");
     
}
