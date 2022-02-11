#include "common.h"

//void test();
//
//class Test {
//    friend void test();
//
//public:
//    Test() {
//        //前面需要有函数申明
//        test();
//    }
//
//private:
//    int i;
//};
//
//void test() {
//    Test t;
//    std::cout << t.i << std::endl;
//}

class Friend_Test {
public:
    // 申明必须放到友元类的前面，不然友元类没办法申明友元关系
    void test();//先不定义，定义必须放到友元类的后面，不然没办法使用友元类
};

class Test {
//	friend class Friend_Test; //申明友元类
    friend void Friend_Test::test();//申明友元某个类的成员函数，该成员函数本身必须是 public
public:
    Test() {}

private:
    int i;
};

void Friend_Test::test() {//使用
    Test t;
    std::cout << t.i << std::endl;
}

int main() {
}