#include "common.h"

class Test {
public:
    int i;

    Test(const Test &) {
        std::cout << "copy construct" << std::endl;
    }

    Test(int i) {
        std::cout << "direct construct" << std::endl;
        this->i = i;
    }
};

int main() {
    Test t = Test(1);//直接初始化，显式调用构造函数
    Test t1 = {1};//直接初始化
    Test t4 = 1;//直接初始化 -> 隐式构造

    Test t2 = t;// 拷贝初始化，这个时候t2是从t复制过来的
    Test t3(t2);//拷贝初始化
    return 0;
}