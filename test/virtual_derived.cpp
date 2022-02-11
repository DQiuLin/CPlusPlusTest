#include "common.h"

class base {
public:
    base() {
        a = 5;
        cout << "base = " << a << endl;
    }

protected:
    int a;
};

class base1 : virtual public base {
public:
    base1() {
        a = a + 10;
        cout << "base1 = " << a << endl;
    }
};
class base2 : virtual public base {
public:
    base2() {
        a = a + 20;
        cout << "base2 = " << a << endl;
    }
};
class derived : public base1, public base2 {
public:
    derived() {
        cout << "base1::a = " << base1::a << endl;
        cout << "base2::a = " << base2::a << endl;
    }
};

int  main() {
    derived obj;
    return 0;
}