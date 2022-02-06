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

int main() {
    // 1
    Print<int>(8);
    Print<string>("Cherno");
    Print<float>(5.6);

    // 2
    Array<string, 5> arr;
    cout << arr.GetSize() << endl;

    return 0;
}