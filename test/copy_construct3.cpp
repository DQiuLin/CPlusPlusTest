#include "common.h"

class Test {
public:
    int i;

    Test(int i_) : i(i_) {
        std::cout << "direct construct" << std::endl;
    }

    Test(const Test &) = default; //copy constructor
};

int main() {
    Test t1(1);
    Test t2(t1);
    Test t3(std::move(t2));
    return 0;
}