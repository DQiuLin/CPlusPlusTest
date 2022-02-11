#include "common.h"

class A {
public:
    A(int a) {
        std::cout << "A: " << a << std::endl;
    }

    ~A() {
        std::cout << "~A" << std::endl;
    }
};

class B {
public:
    B() {
        std::cout << "B" << std::endl;
    }

    ~B() {
        std::cout << "~B" << std::endl;
    }
};

class C_base {
public:
    C_base() {
        std::cout << "C_base" << std::endl;
    }

    ~C_base() {
        std::cout << "~C_base" << std::endl;
    }
};

class C : public C_base {
public:
    C(int a_) : a(new A(a_)) {
        std::cout << "C" << std::endl;
    }

    ~C() {
        delete a;
        std::cout << "~C" << std::endl;
    }

    B b;
    A *a = new A(10);
};

int main() {
    C *c = new C(5);
    delete c;
}