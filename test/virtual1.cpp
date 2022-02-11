#include "common.h"

// 接口
class Printable {
public:
    virtual const string getClassName() = 0; //纯虚函数，子类没有实现则不能初始化
};

class Entity : public Printable {
public:
    virtual string getName() { return "Entity"; } //虚函数

    const string getClassName() override { return "Entity"; } //实现接口
};

class Player : public Entity {
private:
    string m_name;
public:
    Player(const string &name) : m_name(name) {}

    string getName() override { return m_name; } //覆写父类中 getName() 函数

    const string getClassName() override { return "Player"; } //实现接口
};

void printName(Entity& e) {
    cout << e.getName() << endl;
}

void print(Printable& p) {
    cout << p.getClassName() << endl;
}

int main() {
    Entity e;
    Player p("Player");
    printName(e); // "Entity"
    printName(p); // "Player"
    print(e); // "Entity"
    print(p); // "Player"
    return 0;
}