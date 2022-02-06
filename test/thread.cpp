#include "common.h"

static bool is_Finished = false;

void DoWork() {
    cout << "This thread id is: " << std::this_thread::get_id() << endl;
    while (!is_Finished) {
        cout << "working..." << endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}

int main () {
    std::thread worker(DoWork);

    std::cin.get();
    is_Finished = true;

    cout << "Finished" << endl;
    cout << "This thread id is: " << std::this_thread::get_id() << endl;
    worker.join();

    std::cin.get();
    return 0;
}