#include "common.h"

class Base {
public:
    virtual void print() {
        cout << "base" << endl;
    }

    virtual void print(int a) {
        cout << "base:" << a << endl;
    }
};

class A: public Base {
public:
    void print() override {
        cout << "a" << endl;
    }
};

int main() {
    A a;            // 如果父类有一个virtual函数，子类有一个同名的
    a.print();      // 参数个数/类型相同，则会覆盖父类的这个函数
//    a.print(1);   // 参数个数/类型不同，则会隐藏父类的这个函数
    Base *a1 = new A();
    a1->print(); //a，但是如果这个函数不是虚函数，则输出b
    a1->print(2);
}