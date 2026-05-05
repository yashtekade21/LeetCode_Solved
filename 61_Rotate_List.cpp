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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr || k == 0)
            return head;

        int n = 1;
        ListNode* last = head;
        while (last->next != nullptr) {
            n++;
            last = last->next;
        }

        ListNode* temp = head;

        k %= n;
        if (k == 0)
            return head;

        last->next = head;
        int pos = n - k - 1;
        ListNode* tempHead = head;

        while (temp && pos > 0) {
            temp = temp->next;
            pos--;
        }

        head = temp->next;
        temp->next = nullptr;

        return head;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
