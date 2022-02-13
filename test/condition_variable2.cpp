#include "common.h"

std::mutex _mutex;
std::condition_variable cv;
int _index = 0;

//顺序打印ABC
//void _print(char ch) {
//    std::unique_lock<std::mutex> lock(_mutex);
//    cv.wait(lock, [ch]() { //使用index控制打印的顺序
//        return ch == _index + 'A';
//    });
//    _index++;
//    std::cout << ch << std::endl;
//    cv.notify_all();
//}

//顺序打印十次ABC，即ABCABCABC...
void _print(char ch) {
    for (int i = 0; i < 10; ++i) {
        std::unique_lock<std::mutex> lock(_mutex);
        cv.wait(lock, [ch]() { //使用index控制打印的顺序
            return ch == _index + 'A';
        });
        std::cout << ch;
        _index++;
        _index = _index % 3;
        cv.notify_all(); //这里不能使用notify_one
    }
}

int main() {
    vector<std::thread> vector;
    vector.reserve(3);

    for (int i = 0; i < 3; ++i) {
        vector.emplace_back(_print, i + 'A');
    }
    for (int i = 0; i < 3; ++i) {
        vector[i].join();
    }

    return 0;
}