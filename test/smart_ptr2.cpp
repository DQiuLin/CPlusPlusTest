#include "common.h"

std::shared_ptr<int> ptr =  std::make_shared<int>(0);
std::mutex mux;

void func() {
    std::shared_ptr<int> ptr1 = ptr;
    std::unique_lock<std::mutex> lock(mux);
    for (int i = 0; i < 100000000; i++) {
        (*ptr1)++;
    }
}

int main() {
    std::thread th1 = std::thread(func);
    std::thread th2 = std::thread(func);
    th1.join();
    th2.join();
    cout << *(ptr) << endl;
}

//OutPut
//没有加锁的情况下输出102905412
//加锁后输出200000000