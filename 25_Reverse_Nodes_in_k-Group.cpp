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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *node = head, *nextNode = nullptr, *prevNode = nullptr;

        while (node) {
            ListNode* kthNode = findkthNode(node, k);
            if (!kthNode) {
                if (prevNode)
                    prevNode->next = node;
                break;
            }
            nextNode = kthNode->next;
            kthNode->next = nullptr;
            reverseLL(node);
            if (node == head)
                head = kthNode;
            else
                prevNode->next = kthNode;
            prevNode = node;
            node = nextNode;
        }
        return head;
    }

private:
    ListNode* findkthNode(ListNode* node, int k) {
        while (node && --k)
            node = node->next;
        return node;
    }

    ListNode* reverseLL(ListNode* head) {
        if (!head || !head->next)
            return head;

        ListNode *node = head, *prev = nullptr, *next = nullptr;
        while (node) {
            next = node->next;
            node->next = prev;
            prev = node;
            node = next;
        }
        return prev;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
