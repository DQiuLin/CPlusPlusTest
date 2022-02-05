#include "common.h"
#include <memory>

class Entity {
public:
    Entity() {
        cout << "Construct Entity..." << endl;
    }
    ~Entity() {
        cout << "Destruct Entity..." << endl;
    }
    void Print() {
        cout << "print entity..." << endl;
    }
};

int main() {
    {
        std::weak_ptr<Entity> e0;
        {
            std::shared_ptr<Entity> sharedEntity = std::make_shared<Entity>();
            e0 = sharedEntity;
            cout << "End Scope1..." << endl;
        }
        cout << "End Scope2..." << endl;
    }
    cout << "Out Scope..." << endl;
    return 0;
}