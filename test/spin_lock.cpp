#include "common.h"

using std::thread;
using std::atomic_flag;

// 自旋锁的实现
class spin_lock {
public:
    spin_lock() = default;

    spin_lock(const spin_lock &) = delete;

    spin_lock &operator=(const spin_lock) = delete;

    void lock() {   // acquire spin lock
        while (flag.test_and_set()) {}
    }

    void unlock() {   // release spin lock
        flag.clear();
    }

private:
    atomic_flag flag;
};

spin_lock splock;
void addFunc(int n) {
    splock.lock();
    cout << "num = " << n << endl;
    splock.unlock();
}

int main() {
    cout << "程序开始执行" << endl;
    thread t1(addFunc, 1);
    thread t2(addFunc, 2);
    thread t3(addFunc, 3);
    t1.join();
    t2.join();
    t3.join();
    return 0;
}