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
    ListNode* middleNode(ListNode* head) {
        ListNode* node = head;
        int size = 0;
        while(node){
            size++;
            node = node->next;
        }

        int mid=0;
        if(size%2==0)
            mid = ceil(size/2.0)+1;
        else
            mid = ceil(size/2.0);

        node = head;
        while(--mid){
            node = node->next;
        }
        return node;

    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
