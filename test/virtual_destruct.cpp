#include "common.h"

class Base {
public:
    Base() {
        cout << "Base Constructor.\n";
    }

    virtual ~Base() {
        cout << "Base Destructor.\n";
    }
};

class Derived : public Base {
public:
    Derived() {
        cout << "Derived Constructor.\n";
    }

    ~Derived() {
        cout << "Derived Destructor.\n";
    }
};

int main() {
    Base *base = new Base();
    delete base;
    cout << "----------\n";
    Derived *derived = new Derived();
    delete derived;
    cout << "----------\n";
    Base *poly = new Derived();
    delete poly;
    return 0;
}