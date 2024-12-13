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
        if (!head || k == 0)
            return head;

        ListNode* node = head;
        int size = 1;
        while (node->next) {
            size++;
            node = node->next;
        }

        node->next = head;
        k = k % size;
        int newTailPosition = size - k - 1;

        node = head;
        for (int i = 0; i < newTailPosition; i++) 
            node = node->next;
        
        ListNode* newHead = node->next;
        node->next = nullptr;

        return newHead;
    }
};

static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
