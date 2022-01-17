//
// Created by 段秋琳 on 2022/1/17.
//

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