#include "common.h"

// test1
int function() {
    static int i = 0; //局部静态变量
    i++;
    return i;
}

// test2
// 单例类1
class Single {
private:
    static Single single; // 静态变量声明，生命周期到程序结束

public:
    static Single &getInstance() { // 静态方法，获取此静态变量
        return single;
    }

private:
    int k = 0;

public:
    Single() = default;

    ~Single() = default;

    void printK() const {
        cout << this->k << endl;
    }
};

Single Single::single = Single(); // 静态变量定义

// test3
// 单例类2
class SingleNew {
public:
    static SingleNew &getInstance() {
        static SingleNew singleNew;
        return singleNew;
    }

private:
    int k = 0;
public:
    SingleNew() = default;

    ~SingleNew() = default;;

    void printK() const {
        cout << this->k << endl;
    }
};

int main() {

    // for test1
    cout << function() << endl;
    cout << function() << endl;
    cout << function() << endl;
    cout << function() << endl;

    // for test2 test3
    Single::getInstance().printK();
    SingleNew::getInstance().printK();

    return 0;
}