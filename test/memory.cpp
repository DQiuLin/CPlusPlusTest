#include "common.h"

class A {
public:
    void PrintA1() {
        cout << "A" << endl;
    }

    virtual void PrintA2() {
        cout << "A" << endl;
    }
};

class B {
public:
    void PrintB1() {
        cout << "B" << endl;
    }

    virtual void PrintB2() {
        cout << "B" << endl;
    }
};

int main() {
    A *pa = new A();
    B *pb = (B *) pa;
    pb->PrintB1();
    pb->PrintB2();
    return 0;
}