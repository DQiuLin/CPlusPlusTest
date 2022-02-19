#include "common.h"

int main() {
    vector<int> vec = {1, 2, 3, 3, 4, 5, 6};
    auto f = std::find(vec.begin(), vec.end(), 3); //3
    auto lb = std::lower_bound(vec.begin(), vec.end(), 3); //3
    auto ub = std::upper_bound(vec.begin(), vec.end(), 3); //4
    auto er = std::equal_range(vec.begin(), vec.end(), 3); //3,4
    auto bs = std::binary_search(vec.begin(), vec.end(), 3); //1
    cout << *f << *lb << *ub << *er.first << *er.second << bs << endl;
    return 0;
}