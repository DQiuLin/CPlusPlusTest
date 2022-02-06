#include "common.h"

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

int main() {
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

    Entity e;

    int *x1, x2;
    x1 = &x2;
    *x1 = 2;
    cout << x1 << " " << x2 << endl;

    return 0;
}