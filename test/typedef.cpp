#include "common.h"

// 1.
// 声明了一个返回 bool 类型并带有两个 (int和double) 形参的函数的指针类型 FuncPointer
typedef bool (*FuncPointer)(int, double);

// 声明了一个FuncPointer类型的函数指针对象pFunc
FuncPointer pFunc;

// 2.
// 定义与平台无关的类型
// 比如定义一个叫 REAL 的浮点类型，在目标平台一上，让它表示最高精度的类型为：
typedef long double REAL;
// 在不支持 long double 的平台二上，改为：
// typedef double REAL;
// 在连 double 都不支持的平台三上，改为：
// typedef float REAL;

// 当跨平台时，只要改下 typedef 本身就行，不用对其他源码做任何修改。
// 标准库就广泛使用了这个技巧，比如size_t。
// 另外，因为typedef是定义了一种类型的新别名，不是简单的字符串替换，所以它比宏来得稳健

// 3.
// 与 struct 结合使用
// C语言中，struct的定义和声明要用typedef
typedef struct __Person {
    string name;
    int age;
    float height;
} Person1;	//Person1是结构体的一个别名
Person1 person1;

// 如果没有typedef就必须用struct Person person;来声明，如：
struct Person2 {
    string name;
    int age;
    float height;
};
struct Person2 person2;

struct Person3 {
    string name;
    int age;
    float height;
} person3;	//person3是Person3的对象

int main() {
    return 0;
}