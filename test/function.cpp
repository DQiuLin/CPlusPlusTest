#include "common.h"

// std::function
std::function<int(int, int)> SumFunction;

// 普通函数
int func_sum(int a, int b) {
    return a + b;
}

class Calcu {
public:
    int base = 20;

    // 类的成员方法，参数包含this指针
    int class_func_sum(const int &a, const int &b) const { return this->base + a + b; };

    // 类的静态成员方法，不包含this指针
    static int class_static_func_sum(const int &a, const int &b) { return a + b; };
};

// 仿函数
class ImitateAdd {
public:
    int operator()(const int &a, const int &b) const { return a + b; };
};

// lambda函数
auto lambda_func_sum = [](int a, int b) -> int { return a + b; };

// 函数指针
int (*func_pointer)(int, int);

int main() {
    int x = 2;
    int y = 5;

    // 普通函数
    SumFunction = func_sum;
    int sum = SumFunction(x, y);
    std::cout << "func_sum：" << sum << std::endl;

    // 类成员函数
    Calcu obj;
    SumFunction = std::bind(&Calcu::class_func_sum, obj,
                            std::placeholders::_1, std::placeholders::_2); // 绑定this对象
    sum = SumFunction(x, y);
    std::cout << "Calcu::class_func_sum：" << sum << std::endl;

    // 类静态函数
    SumFunction = Calcu::class_static_func_sum;
    sum = SumFunction(x, y);
    std::cout << "Calcu::class_static_func_sum：" << sum << std::endl;

    // lambda函数
    SumFunction = lambda_func_sum;
    sum = SumFunction(x, y);
    std::cout << "lambda_func_sum：" << sum << std::endl;

    // 带捕获的lambda函数
    int base = 10;
    auto lambda_func_with_capture_sum = [&base](int x, int y) -> int { return x + y + base; };
    SumFunction = lambda_func_with_capture_sum;
    sum = SumFunction(x, y);
    std::cout << "lambda_func_with_capture_sum：" << sum << std::endl;

    // 仿函数
    ImitateAdd imitate;
    SumFunction = imitate;
    sum = SumFunction(x, y);
    std::cout << "imitate func：" << sum << std::endl;

    // 函数指针
    func_pointer = func_sum;
    SumFunction = func_pointer;
    sum = SumFunction(x, y);
    std::cout << "function pointer：" << sum << std::endl;

    return 0;
}