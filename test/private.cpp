#include "common.h"

class Base {
public:
    int a;
private:
    int b;
protected:
    int c;
};

class Son : private Base {

    void test() {
        std::cout << this->a << std::endl;//ok!
//		std::cout << this->b << std::endl;//error!
        std::cout << this->c << std::endl;//ok!
    }
};

class Son2 : public Base{

};

int main() {
    Son s;
//    s.a;//error 此时 a 为 private 权限
    Son2 s2;
    s2.a;//ok!
//    s2.c;//error 此时 c 为 protected 权限
}