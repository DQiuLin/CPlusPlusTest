#include "common.h"

////单继承无覆盖
//class Base {
//public:
//    virtual void f() { cout << "Base::f()" << endl; }
//
//    virtual void g() { cout << "Base::g()" << endl; }
//
//    virtual void h() { cout << "Base::h()" << endl; }
//};
//
//class Derived :public Base {
//public:
//    virtual void f_derived() { cout << "Derived::f_derived()" << endl; }
//
//    virtual void g_derived() { cout << "Derived::g_derived()" << endl; }
//
//    virtual void h_derived() { cout << "Derived::h_derived()" << endl; }
//};
//
////单继承有覆盖
//class Base1 {
//public:
//    virtual void A() { cout << "Base1::A()" << endl; }
//
//    virtual void B() { cout << "Base1::B()" << endl; }
//
//    virtual void C() { cout << "Base1::C()" << endl; }
//};
//
//class Derived1 : public Base1 {
//public:
//    virtual void MyA() { cout << "Derived1::MyA()" << endl; }
//
//    virtual void B() { cout << "Derived1::B()" << endl; }
//};

//多继承无覆盖/有覆盖
class Base1 {
public:
    virtual void f() { cout << "Base1::f()" << endl; }

    virtual void g() { cout << "Base1::g()" << endl; }

    virtual void h() { cout << "Base1::h()" << endl; }
};

class Base2 {
public:
    virtual void f() { cout << "Base2::f()" << endl; }

    virtual void g() { cout << "Base2::g()" << endl; }

    virtual void h() { cout << "Base2::h()" << endl; }
};

class Base3 {
public:
    virtual void f() { cout << "Base3::f()" << endl; }

    virtual void g() { cout << "Base3::g()" << endl; }

    virtual void h() { cout << "Base3::h()" << endl; }
};

class Derived : public Base1, public Base2, public Base3 {
public:
    void f() override { cout << "Derived::f1()" << endl; }

    virtual void g1() { cout << "Derived::g1()" << endl; }
};

int main() {

    return 0;
}