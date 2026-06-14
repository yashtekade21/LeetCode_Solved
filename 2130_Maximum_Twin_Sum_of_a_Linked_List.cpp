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
    int pairSum(ListNode* head) {
        int n = 1;
        ListNode* temp = head;
        while (temp->next) {
            n++;
            temp = temp->next;
        }

        temp = head;
        stack<int> st;
        for (int i = 0; i < n / 2; i++) {
            st.push(temp->val);
            temp = temp->next;
        }

        int ans = INT_MIN;
        while (temp) {
            int t1 = st.top();
            st.pop();
            int t2 = temp->val;
            ans = max(ans, (t1 + t2));
            temp = temp->next;
        }
        return ans;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
