#include "common.h"

class Empty {
public:

    Empty(); // 缺省构造函数

    Empty(const Empty &); // 拷贝构造函数

    ~Empty(); // 析构函数

    Empty &operator=(const Empty &); // 赋值运算符

    Empty *operator&(); // 取址运算符

    const Empty *operator&() const; // 取址运算符 const

};

int main() {
    cout << sizeof(Empty) << endl;
    return 0;
}