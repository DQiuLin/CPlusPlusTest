#include "common.h"

template <typename T>
class UniquePtr {
private:
    T *mResource;
private:
    void del() {
        if (mResource) {
            delete mResource;
            mResource = nullptr;
        }
    }

public:
    UniquePtr(T *resource = nullptr) : mResource(resource) {}

    ~UniquePtr() {
        del();
    }

    UniquePtr(UniquePtr<T> &&ptr) noexcept: mResource(ptr.mResource) {
        ptr.mResource = nullptr;
    }

    UniquePtr &operator=(UniquePtr<T> &&ptr) noexcept {
        reset(ptr.release());
        return *this;
    }

public:
    explicit operator bool() const {
        return mResource != nullptr;
    }

    T &operator*() {
        return *mResource;
    }

    T *operator->() {
        return mResource;
    }

    T *get() {
        return mResource;
    }

public:
    T *release() {
        T *ptr = mResource;
        mResource = nullptr;
        return ptr;
    }

    void reset(T *resource) {
        del();
        mResource = resource;
    }

public:
    UniquePtr(const UniquePtr<T> &ptr) = delete; //禁止拷贝构造

    UniquePtr<T> &operator=(const UniquePtr<T> &ptr) = delete; //禁止赋值运算
};


struct Test {
    int a;
    int b;

    Test(int a, int b) : a(a), b(b) {}
};

class A {
private:
    Test *test = new Test(1, 1);
    Test *test1 = new Test(2, 2);
public:
    void func() {
        UniquePtr<Test> ptr(test);
        if (!ptr) cout << "construct err!" << endl;
        cout << (*ptr).a << (*ptr).b << endl; //11
        cout << ptr->a << ptr->b << endl;//11
        cout << ptr.get() << endl; //0x7fa8905041e0

        ptr.reset(test1);
        cout << (*ptr).a << (*ptr).b << endl; //22
        cout << ptr->a << ptr->b << endl;//22
        cout << ptr.get() << endl; //0x7fa8905044d0

        test = ptr.release();
        cout << test->a << test->b << endl; //22
    }
};

int main() {
    A a;
    a.func();
    return 0;
}