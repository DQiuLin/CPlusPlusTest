#include "common.h"

class Base {
public:
    Base() {}

    virtual ~Base() {}

    void Print() {
        cout << "Base Print..." << endl;
    }
};

class Derived : public Base {
public:
    Derived() {}

    ~Derived() {}

    void Print() {
        cout << "Derived Print..." << endl;
    }
};

class AnotherClass : public Base {
public:
    AnotherClass() {}

    ~AnotherClass() {}

    void Print() {
        cout << "AnotherClass Print..." << endl;
    }
};

void DerivedPrint(Base* base) {
    //Print()不是虚函数
    base->Print(); //Base Print...
    Derived *derived = dynamic_cast<Derived *>(base);
    if (derived) {
        derived->Print(); //Derived Print...
    }
}

int main() {
    Derived *derived = new Derived();
    Base *base = derived;
    AnotherClass *ac = dynamic_cast<AnotherClass *>(base);
    if (ac) {
        cout << "derived cast to anotherClass success..." << endl;
    } else {
        cout << "derived cast to anotherClass failed..." << endl;
    }
    DerivedPrint(base);
    return 0;
}