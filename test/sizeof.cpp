#include "common.h"

class baseClass {
    int i;
    int c;
};

class inheritClass : public baseClass {
    int c;
};

int main() {
    int arr[10];
    int *q = arr;
    std::cout << sizeof(arr) << std::endl;//40
    std::cout << sizeof(q) << std::endl;//8，这个指针本身所占用的内存大小
    cout << arr << " " << q << endl;
    int a = 10;
    int *p = &a;
    cout << sizeof(a) << endl; //4
    cout << sizeof(p) << endl; //8
    cout << &a << " " << p << endl;

    //由编译器决定
    std::cout << sizeof(int) << std::endl;       //4
    std::cout << sizeof(long) << std::endl;      //8
    std::cout << sizeof(long long) << std::endl; //8
    std::cout << sizeof(float) << std::endl;     //4
    std::cout << sizeof(double) << std::endl;    //8
    std::cout << sizeof(char) << std::endl;      //1
    std::cout << sizeof(bool) << std::endl;      //1
    //与编译器无关
    std::cout << sizeof(int8_t) << std::endl;    //1
    std::cout << sizeof(int16_t) << std::endl;   //2
    std::cout << sizeof(int32_t) << std::endl;   //4
    std::cout << sizeof(int64_t) << std::endl;   //8
    std::cout << sizeof(uint8_t) << std::endl;   //1
    std::cout << sizeof(uint16_t) << std::endl;  //2
    std::cout << sizeof(uint32_t) << std::endl;  //4
    std::cout << sizeof(uint64_t) << std::endl;  //8

    //单继承
    cout << sizeof(baseClass) << endl;
    cout << sizeof(inheritClass) << endl;
    return 0;
}