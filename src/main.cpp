#include "common.h"

struct TreeNode {
    int val;
    TreeNode* next;
    TreeNode(): val(0), next(nullptr) {}
    TreeNode(int val): val(val), next(nullptr) {}
    TreeNode(int val, TreeNode* next): val(val), next(next) {}
};

class Solution {
public:
    TreeNode* reverseTree(TreeNode* head, int k) {
       if (!head) return head;
       if (!head->next) return head;
       if (k <= 1) return head;
       TreeNode* newHead = new TreeNode();
       newHead->next = head;
       TreeNode* pre = newHead;
       TreeNode* cur = head;
       TreeNode* next = cur->next;
       while (next) {
           int cnt = k - 1;
           while (next && cnt--) {
               TreeNode *tmp = next;
               next = next->next;
               cur->next = next;
               tmp->next = pre->next;
               pre->next = tmp;
           }
           pre = cur;
           cur = next;
           if (cur) {
               next = cur->next;
           } else {
               next = nullptr;
           }

       }
       return newHead->next;
    }
};

int main() {
    TreeNode* head = new TreeNode(1);
    TreeNode* tmp = head;
    for (int i = 0; i < 4; i++) {
        TreeNode* node = new TreeNode(i + 2);
        tmp->next = node;
        tmp = tmp->next;
    }
    tmp = head;
    while (tmp) {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl;
    Solution solution;
    tmp = solution.reverseTree(head, 6);
    while (tmp) {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl;
    return 0;
}