#include "common.h"

static bool cmp(const std::pair<int, int> &a, const std::pair<int, int> &b) {
    return a.second < b.second;
}

class MyCompare {
public:
    bool operator()(const std::pair<int, int> &a, const std::pair<int, int> &b) {
        return a.second < b.second;
    }
};

int main() {

    // priority_queue 默认使用 less (a < b)，从大到小排列 (大根堆)
    // 使用 greater (a > b)，从大到小排列 （小根堆）
    vector<std::pair<int, int>> vec = {{0, 1},
                                       {0, 2},
                                       {0, 3},
                                       {0, 4},
                                       {0, 5},
                                       {0, 6}};
    priority_queue<std::pair<int, int>, vector<std::pair<int, int>>, decltype(&cmp)> q(cmp);
    priority_queue<std::pair<int, int>, vector<std::pair<int, int>>, MyCompare> que(vec.begin(), vec.end());
    for (auto &v: vec) {
        q.push(v);
    }
    while (!q.empty()) {
        cout << q.top().second << " ";
        q.pop();
    }
    cout << endl;
    while (!que.empty()) {
        cout << que.top().second << " ";
        que.pop();
    }
    return 0;
}