#include "common.h"

void quickSort(vector<int>& nums) {
    stack<std::pair<int, int>> st;
    st.push({0, nums.size() - 1});
    while (!st.empty()) {
        auto tmp = st.top();
        st.pop();
        int left = tmp.first;
        int right = tmp.second;
        int val = rand() % (right - left + 1) + left;
        std::swap(nums[left], nums[val]);
        int i = left;
        int j = right;
        while (i < j) {
            while (i < j && nums[j] >= nums[i]) {
                j--;
            }
            std::swap(nums[i], nums[j]);
            while (i < j && nums[i] <= nums[j]) {
                i++;
            }
            std::swap(nums[i], nums[j]);
        }
        int l1 = left, r1 = i - 1;
        int l2 = i + 1, r2 = right;
        if (r1 - l1 > 1) {
            st.push({l1, r1});
        }
        if (r2 - l2 > 1) {
            st.push({l2, r2});
        }
    }
}

int main() {
    vector<int> nums{2, 5, 3, 7, 8, 5};
    quickSort(nums);
    for (const auto &i: nums) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}