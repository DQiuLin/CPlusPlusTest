#include "common.h"

/*------------------------ const 修饰函数形参 ------------------------*/
// a在函数内部不可变；实参可以是 int 类型，也可以是 const int 类型
void function1(const int a) {}
// a在函数内不可变；实参可以是 int 类型，也可以是 const int 类型
void function2(const int& a) {}
// 可以修改a，不可以修改*a；实参可以是 int 类型，也可以是 const int 类型
void function3(const int* a) {}
// 可以修改*a，不可以修改a；实参只能是 int 类型
void function4(int* const a) {}

void test1() {
    int a = 5;
    const int b = 5;
    function1(a);
    function1(b);
    function2(a);
    function2(b);
    function3(&a);
    function3(&b);
    function4(&a);
//    function4(&b); //出错
}

/*--------------------- const 修饰成员函数和对象 ---------------------*/
class Entity {
private:
    int m_X, m_Y;
    mutable int var; //mutable表示可以改变

public:
    //保证不改变类的成员变量
    int GetX() const {
        var = 2;
        return m_X;
    }

    void SetX(int x) {
        m_X = x;
    }
};

void PrintEntity(const Entity &e) {
    //这个函数中只能调用Entity类的const方法
    cout << e.GetX() << endl;
}

void test2() {
    Entity e{};
    PrintEntity(e);
}

/*------------------------ const 修饰指针引用 ------------------------*/
void test3() {
    const int MAX_AGE = 90;

    //表示指针所指向的值是const类型
    const int *a = new int;
    a = &MAX_AGE;
    std::cout << *a << std::endl;
    //同上
    int const *b = new int;
    b = &MAX_AGE;
    std::cout << *b << std::endl;
    //表示指针是const类型
    int *const c = new int;
    *c = 2;
    std::cout << *c << std::endl;

    int x = 0;
    const int y = 0;
    const int &t1 = x;
    const int &t2 = y;
    int &t3 = x;
//    int &t4 = y; //错误，试图将一个非常量引用指向一个常量对象
}

int main() {
    test1();
    test2();
    test3();
    return 0;
}