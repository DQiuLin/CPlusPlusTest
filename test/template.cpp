#include "common.h"

// 1
template <typename T>
void Print(T value) {
    cout << value << endl;
}

// 2
template <typename T, int N>
class Array {
private:
    T m_Array[N];
public:
    int GetSize() { return N; }
};

// 3
template <class T>
T max(T a, T b) {
    return a > b ? a : b;
}

int main() {
    // 1
    Print<int>(8);
    Print<string>("Cherno");
    Print<float>(5.6);

    // 2
    Array<string, 5> arr;
    cout << arr.GetSize() << endl;

    // 3
    std::cout << ::max(9, 5) << std::endl;     // 9
    std::string foo("foo"), bar("bar");
    std::cout << ::max(foo, bar) << std::endl; // "foo"

    return 0;
}