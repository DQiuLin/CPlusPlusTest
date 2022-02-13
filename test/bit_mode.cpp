#include "common.h"

class Test {
public:
    int t: 2;
};

int main() {
    Test test;
    test.t = 6;
    std::cout << test.t << std::endl; //-2
}