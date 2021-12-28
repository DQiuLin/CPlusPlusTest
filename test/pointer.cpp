#include <iostream>
#include <cstring>

using std::cin;
using std::cout;
using std::endl;

void Increment(int *p)
{
    (*p)++;
}

void Increment(int &a)
{
    a++;
}

int main()
{
    // int var = 8;
    // cout << var << endl; // 8
    // int *p = &var; // 取地址
    // *p = 10; // 改变这个地址的值
    // cout << var << endl; // 10

    // char *p = new char[8];
    // memset(p, 0, 8);
    // char **ptr = &p;
    // delete[] p;

    // int a = 2;
    // int &ref = a;
    // ref = 5;
    // cout << a << endl;

    // int a = 5;
    // Increment(&a);
    // Increment(a);
    // cout << a << endl;

    int a = 5;
    int b = 8;
    int &ref = a;
    ref = b;
    cout << a << b << endl;
    a = 5;
    b = 8;
    int *p = &a;
    *p = 2;
    p = &b;
    *p = 1;
    cout << *p << a << b << endl;
    return 0;
}