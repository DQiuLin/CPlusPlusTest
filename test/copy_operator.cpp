#include "common.h"


class Person {
public:
    Person() {}

    //拷贝构造函数
    Person(const Person &p) {
        cout << "Copy Constructor" << endl;
    }

    //重载拷贝构造运算符，有返回值的
    Person &operator=(const Person &p) {
        cout << "Assign" << endl;
        return *this;//返回此对象的引用，这个「此对象」指的是=运算符左侧对象的引用
    }
};

int main() {
    Person p;
    Person p1 = p;   // 1 拷贝构造
    Person p3(p);    // 1 拷贝构造

    Person p2;
    p2 = p;          // 2 拷贝赋值
    return 0;
}