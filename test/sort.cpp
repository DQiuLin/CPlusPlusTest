#include "common.h"

int main () {
    vector<int> values = {3, 2, 4, 5, 1};

//    std::sort(values.begin(), values.end(), std::greater<int>());

    std::sort(values.begin(), values.end(), [](int a, int b) {
        return a > b;
    });
    for (int value: values) {
        cout << value << endl;
    }
    return 0;
}