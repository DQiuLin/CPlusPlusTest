#include "common.h"
#include "staticTest.h"

int staticTest::s_var = 1;

void staticTest::test() {
    s_var++;
}

void staticTest::print() {
    cout << s_var << endl;
}
