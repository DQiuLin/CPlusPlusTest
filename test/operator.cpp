#include "common.h"

class Vector2 {
public:
    double x;
    double y;

    Vector2(double x, double y) : x(x), y(y) {}

    Vector2 Add(const Vector2 &other) {
        return Vector2(x + other.x, y + other.y);
    }

    Vector2 operator+(const Vector2 &other) {
        return this->Add(other);
    }

    Vector2 Multiply(const Vector2 &other) {
        return Vector2(x * other.x, y * other.y);
    }

    Vector2 operator*(const Vector2 &other) {
        return this->Multiply(other);
    }

    bool operator==(const Vector2 &other) {
        return x == other.x && y == other.y;
    }

    bool operator!=(const Vector2 &other) {
        return !(*this == other);
    }
};

std::ostream& operator<< (std::ostream& stream, const Vector2& vec) {
    stream << vec.x << ", " << vec.y;
    return stream;
}

int main() {
    Vector2 position(4.0, 5.0);
    Vector2 speed(0.5, 0.6);
    Vector2 powerup(1.1, 1.2);
    Vector2 res1 = position.Add(speed.Multiply(powerup)); // 4.55, 5.72
    Vector2 res2 = position + speed * powerup; // 4.55, 5.72
    cout << res1 << endl;
    cout << res2 << endl;
    return 0;
}