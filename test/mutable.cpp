#include "common.h"

class Entity {
private:
    string m_Value;
    mutable int count = 0;
public:
    const string &getValue() const {
        count++;
        return m_Value;
    }
};

int main() {
    const Entity e{};
    e.getValue();

    int x = 8;
    auto f = [=]() mutable {
        x++;
        cout << x << endl;
    };
    f();

    cout << x << endl;

    return 0;
}