#include "common.h"

struct Vector2 {
    float x, y;
};

struct Vector4 {
    union {
        struct {
            float x, y, z, w;
        };
        struct {
            Vector2 a, b;
        };
    };

};

void Print(const Vector2& vector) {
    cout << vector.x << ", " << vector.y << endl;
}

int main() {
    Vector4 vec = {1.0f, 2.0f, 3.0f, 4.0f};
    Print(vec.a);
    Print(vec.b);
    cout << "----------" << endl;
    vec.z = 500.0f;
    Print(vec.a);
    Print(vec.b);
    return 0;
}