#include "common.h"

std::deque<int> q;
std::mutex mu;
std::condition_variable cond;

void function_1() {
    int count = 10;
    while (count > 0) {
        std::unique_lock<std::mutex> locker(mu);
        q.push_front(count);
        locker.unlock();    // 唤醒前释放锁
        cond.notify_one();  // 唤醒
        std::this_thread::sleep_for(std::chrono::seconds(1));
        count--;
    }
}

void function_2() {
    int data = 0;
    while (data != 1) {
        std::unique_lock<std::mutex> locker(mu);
//        while (q.empty())//等待
        cond.wait(locker, [&]() { return !q.empty(); }); // Unlock mu and wait to be notified
        data = q.back();
        q.pop_back();
        std::cout << "t2 got a value from t1: " << data << std::endl;
    }
}

int main() {
    std::thread t1(function_1);
    std::thread t2(function_2);
    t1.join();
    t2.join();

    //------------------------------------------------------
    bool flag;
    std::mutex mu;
    std::condition_variable cv;

    std::unique_lock<std::mutex> locker(mu);
    while (flag) {//第一种方式
        cv.wait(locker);
    }

    //第二种方式
    cv.wait(locker, [flag]() { return flag; });
    return 0;
}