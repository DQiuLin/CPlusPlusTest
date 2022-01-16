//
// Created by 段秋琳 on 2021/12/12.
//
#include "common.h"
#include "staticTest.h"

int staticTest::s_var = 1;

void staticTest::test() {
    s_var++;
}

void staticTest::print() {
    cout << s_var << endl;
}
