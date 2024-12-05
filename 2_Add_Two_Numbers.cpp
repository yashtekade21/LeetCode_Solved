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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *t1=l1,*t2=l2,*curr,*dummyHead,*node;
        dummyHead = new ListNode(-1);
        curr = dummyHead;
        int carry=0;
        long long sum=0;

        while(t1 || t2){
            sum = (long long)carry;

            if(t1)
                sum += t1->val;
            if(t2)
                sum += t2->val;
            
            node = new ListNode(sum%10);
            carry = sum/10;
        
            curr->next = node;
            curr = curr->next;

            if(t1)
                t1 = t1->next;
            if(t2)
                t2 = t2->next;
        }
        if(carry){
            node = new ListNode(carry);
            curr->next = node;
        }
        return dummyHead->next;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
