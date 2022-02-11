#include "common.h"

class Entity {
private:
    string m_Name;
    int m_Age;
public:
    explicit Entity(const string &name) : m_Name(name), m_Age(-1) {}

    explicit Entity(int age) : m_Name("Unknown"), m_Age(age) {}
};

struct B {
    explicit operator bool() const { return true; }
};


int main() {
    Entity e1(22);
    Entity e2(string("Cherno"));

    B b1;
//    bool flag = b1;  // 不能隐式转换该对象为另一个类型
    bool b6(b1);     // 可以按语境转换
    bool flag = static_cast<bool>(b1); // 显式转换可以

    return 0;
}