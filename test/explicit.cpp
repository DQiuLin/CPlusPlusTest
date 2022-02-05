#include "common.h"

class Entity {
private:
    string m_Name;
    int m_Age;
public:
    explicit Entity(const string &name) : m_Name(name), m_Age(-1) {}

    explicit Entity(int age) : m_Name("Unknown"), m_Age(age) {}
};

int main() {
    Entity e1(22);
    Entity e2(string("Cherno"));
    return 0;
}