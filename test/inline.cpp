#include "common.h"

/*---------- 普通函数 ----------*/
//第一种是在声明的时候增加
inline int functionName1(int first, int second,...);

//第二种是在定义的时候增加
int functionName2(int first, int second,...);
inline int functionName2(int first, int second,...) { return 0; }

/*---------- 成员函数 ----------*/
class Test {
private:
    int m_Value;
public:
    int add(int i, int j) {
        m_Value = i + j;
        return m_Value;
    }

    int add_(int i, int j);
};

inline int Test::add_(int i, int j) { //显式内联
    m_Value = i + j;
    return i + j;
}

/*---------- inline 内联空间 ----------*/
// inline 还可以修饰命名空间，在同一个编译单元中可以不用使用前缀，而直接使用内部的函数、变量、类
// 有一个使用场景是，如果类库有多个版本，新版本的命名空间使用内联
// 调用的时候不用使用前缀就可以使用到最新的类库
inline namespace n1 {
    class A {};
}

namespace n1 { //因为 n1 上面被声明为内联，此处的命名空间也是内联，为"隐式内联"
    class B {};
}

int main() {
    A a;
    B b;
}
