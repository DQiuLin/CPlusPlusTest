#include "common.h"

template <typename T>
class SmartPtr {
private:
    int *cnt; //将引用计数声明为指针是为了所有的SmartPtr对象共享数据
    T *p;
public:
    SmartPtr(T *p);

    ~SmartPtr();

    SmartPtr(const SmartPtr<T> &ptr); //浅拷贝

    SmartPtr<T> &operator=(const SmartPtr<T> &ptr); //浅拷贝
};

template <typename T>
SmartPtr<T>::SmartPtr(T *p) : p(p) {
    try {
        cnt = new int(1);
    }
    catch (...) {
        delete p;
        p = nullptr;
        cnt = nullptr;
        cout << "Allocate memory for SmartPtr::cnt is failed." << endl;
        exit(1);
    }
    cout << "Construct SmartPtr..." << endl;
}

template <typename T>
SmartPtr<T>::~SmartPtr<T>() {
    cout << "destruct, cnt = " << *cnt << endl;
    if (--(*cnt) == 0) {
        delete cnt;
        delete p;
        cnt = nullptr;
        p = nullptr;
        cout << "Destruct SmartPtr..." << endl;
    }
}

template <typename T>
SmartPtr<T>::SmartPtr(const SmartPtr<T> &ptr) {
    (*ptr.cnt)++;
    cnt = ptr.cnt;
    p = ptr.p;
    cout << "Copy Construct SmartPtr..." << endl;
}

//重载等号函数不等于拷贝赋值运算符
//左边的对象引用计数需要减一，如果等于0则需要进行内存的释放
//右边的对象引用计数需要加一，然后进行复制操作
template <typename T>
SmartPtr<T> & SmartPtr<T>::operator=(const SmartPtr<T> &ptr) {
    (*ptr.cnt)++; //避免内存提前释放
    if (--(*cnt) == 0) {
        delete cnt;
        delete p;
        cnt = nullptr;
        p = nullptr;
        cout << "Left SmartPtr is deleted..." << endl;
    }
    cnt = ptr.cnt;
    p = ptr.p;

    return *this;
}

int main() {
    // Test Constructor and Assignment Operator Overloaded
    SmartPtr<int> p1(new int(0));
    p1 = p1;
    // Test Copy Constructor
    SmartPtr<int> p2(p1);
    // Test Assignment Operator Overloaded
    SmartPtr<int> p3(new int(1));
    p3 = p1;
    return 0;
}
//OutPut
//Construct SmartPtr...
//Copy Construct SmartPtr...
//Construct SmartPtr...
//Left SmartPtr is deleted...
//destruct, cnt = 3
//destruct, cnt = 2
//destruct, cnt = 1
//Destruct SmartPtr...