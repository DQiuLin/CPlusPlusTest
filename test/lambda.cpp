#include "common.h"

void ForEach(const vector<int>& values, const std::function<void(int)>& func) {
    for (int value: values) {
        func(value);
    }
}

int main () {
    vector<int> values{2, 3, 5, 7, 8, 9};
    int a = 2022;
    auto lambda = [=](int value) {
        cout << a << ": " << value << endl;
    };
    ForEach(values, lambda);

    auto it = std::find_if(values.begin(), values.end(), [](int value) { return value > 3; });
    cout << *it << endl;

    return 0;
}