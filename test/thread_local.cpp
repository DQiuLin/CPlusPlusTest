#include "common.h"

std::mutex cout_mutex;

void thread_func(const std::string& thread_name) {
    for (int i = 0; i < 3; i++) {
        thread_local int x = 1;
        x++;
        std::lock_guard<std::mutex> lock(cout_mutex);
        std::cout << "thread[" << thread_name << "]: x = " << x << std::endl;
    }
}

class A {
private:
    static int k;
    thread_local static int g;
public:
    static void plus() {
        k++;
        cout << k << endl;
    }

    static void thread_func(const string &name) {
        g++;
        cout << name << ": " << g << endl;
    }
};

int A::k = 1;
thread_local int A::g = 1;

int main() {
    std::thread th1(thread_func, "name1");
    std::thread th2(thread_func, "name2");
    th1.join();
    th2.join();

    A::plus();
    A::plus();
    std::thread th3(A::thread_func, "name3");
    std::thread th4(A::thread_func, "name4");
    th3.join();
    th4.join();

    return 0;
}