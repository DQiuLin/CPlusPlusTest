#include "common.h"

using std::unique_ptr;
using std::make_unique;

class Test {
private:
    int a;
    int b;
public:
    Test(int a_, int b_) : a(a_), b(b_) {
        cout << "construct " << a << ", " << b << endl;
    }

    ~Test() {
        cout << "destruct " << a << ", " << b << endl;
    }
};

void func(Test *) {
    std::cout << "ok" << std::endl;
}

//int main() {
//    // 1. 初始化空的unique_ptr
//    unique_ptr<Test> up0;
//
//    //2. 从普通指针中初始化
//    Test *p0 = new Test(1, 0);
//    unique_ptr<Test> up1(p0); //p0仍然可以赋值给其他指针，这种初始化方式不安全；重复析构同一个指针带来的问题
//    unique_ptr<Test> up2(new Test(2, 0)); //使用临时指针更安全
//
//    //3. c++14支持
//    unique_ptr<Test> up3 = make_unique<Test>(3, 0);
//    up2 = make_unique<Test>(2, 1); //先分配新的对象，再将原来的对象释放掉，然后进行赋值
//
//    //4.1 从普通指针中赋值
//    up2.reset(p0);
//    //4.2 从另一个 unique_ptr 中的裸指针赋值
//    up2 = std::move(up1);
//
//    //5. 携带自定义删除函数
//    unique_ptr<Test, decltype(func) *> up4(new Test(4, 0), func);
//    //需要注意这里和 shared_ptr 不一样的是，在模版参数里面需要指定删除的函数的函数指针类型
//
//    return 0;
//}

//struct A {
//    int a;
//
//    A(int a) : a(a) {}
//
//    ~A() { std::cout << "~A" << std::endl; }
//};
//int main() {
//    unique_ptr<A> up2 = make_unique<A>(2);
//    up2.reset();//释放了A对象，打印 ~A
//
//    unique_ptr<A> up1 = make_unique<A>(1);
//    up2 = std::move(up1);
////    int a = up1->a;//报错, 'up1' used after it was moved
//
//    A *q = up2.get(); //q或者up2被释放掉，内部指针就会被释放掉
//    return 0;
//}

struct A {
    int a = 10;

    A(int a) : a(a) {}

    ~A() {
        std::cout << "~A:" << a << std::endl;
    }
};
unique_ptr<A> test() {
    unique_ptr<A> up = make_unique<A>(2);
    up->a = 20;
    return up;
}
int main() {
    unique_ptr<A> up2 = make_unique<A>(3);
    std::cout << "begin" << std::endl;
    up2 = test();//移动赋值操作，打印 ~A:3 之前 up2 中的对象会被释放
    unique_ptr<A> up3 = test();//移动构造操作
    unique_ptr<A> up4(test());//移动构造操作
    std::cout << "end" << std::endl;
    std::cout << up2->a << std::endl;
}