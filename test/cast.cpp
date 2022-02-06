#include "common.h"

class Base {
public:
    Base() {}

    virtual ~Base() {}
};

class Derived : public Base {
public:
    Derived() {}

    ~Derived() {}
};

class AnotherClass : public Base {
public:
    AnotherClass() {}

    ~AnotherClass() {}
};

int main() {
    Derived *derived = new Derived();
    Base *base = derived;
    AnotherClass *ac = dynamic_cast<AnotherClass *>(base);
    if (ac) {
        cout << "cast success..." << endl;
    }
    return 0;
}