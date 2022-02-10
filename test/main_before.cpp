#include "common.h"

void before_main()__attribute__((constructor));

void before_main() {
    printf("before the main function\n");
}

void after_main()__attribute__((destructor));

void after_main() {
    printf("after the main function\n");
}

//class Test {
//public:
//    Test() {
//        cout << "construct test..." << endl;
//    }
//
//    ~Test() {
//        cout << "destruct test..." << endl;
//    }
//};
//
//Test test;

int main() {
    printf("Now main function is working\n");
    return 0;
}