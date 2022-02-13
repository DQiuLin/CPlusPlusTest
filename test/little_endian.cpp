#include "common.h"

union MyUnion {
    int a;
    char c;
} test;

int main() {
    test.a = 1;
    if (test.c == 1) {
        cout << "little endian" << endl;
    } else {
        cout << "big endian" << endl;
    }
}