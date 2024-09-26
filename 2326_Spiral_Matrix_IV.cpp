/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m, vector<int>(n, -1));
        int left = 0, right = n - 1, top = 0, down = m - 1;
        int dir = 0;

        while (head != nullptr && top <= down && left <= right) {
            if (dir == 0) {
                for (int i = left; i <= right && head != nullptr; i++) {
                    ans[top][i] = head->val;
                    head = head->next;
                }
                ++top;
            } else if (dir == 1) {
                for (int i = top; i <= down && head != nullptr; i++) {
                    ans[i][right] = head->val;
                    head = head->next;
                }
                --right;
            } else if (dir == 2) {
                for (int i = right; i >= left && head != nullptr; i--) {
                    ans[down][i] = head->val;
                    head = head->next;
                }
                --down;
            } else if (dir == 3) {
                for (int i = down; i >= top && head != nullptr; i--) {
                    ans[i][left] = head->val;
                    head = head->next;
                }
                ++left;
            }
            dir = (dir + 1) % 4;
        }
        return ans;
    }
};

static const auto kds = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();
