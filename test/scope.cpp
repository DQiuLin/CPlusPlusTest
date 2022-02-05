#include "common.h"

class Entity {

};

class ScopePointer {
private:
    Entity *e;
public:
    ScopePointer(Entity *e) : e(e) {
        cout << "Construct ScopePointer..." << endl;
    }

    ~ScopePointer() {
        cout << "Destruct ScopePointer..." << endl;
    }
};

int main() {
    {
        ScopePointer e = new Entity();
        cout << "End Scope..." << endl;
    }
    cout << "Out Scope..." << endl;
    return 0;
}