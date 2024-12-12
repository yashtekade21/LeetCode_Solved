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
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next)
            return head;

        ListNode* mid = findMid(head);
        ListNode *leftList = head, *rightList = mid->next;
        mid->next = nullptr;

        leftList = sortList(leftList);
        rightList = sortList(rightList);

        return mergelist(leftList, rightList);
    }

private:
    ListNode* findMid(ListNode* head) {
        ListNode *slow = head, *fast = head->next;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* mergelist(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(-1);
        ListNode* temp = dummyHead;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                temp->next = l1;
                temp = l1;
                l1 = l1->next;
            } else {
                temp->next = l2;
                temp = l2;
                l2 = l2->next;
            }
        }
        if (l1)
            temp->next = l1;
        else
            temp->next = l2;

        return dummyHead->next;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
