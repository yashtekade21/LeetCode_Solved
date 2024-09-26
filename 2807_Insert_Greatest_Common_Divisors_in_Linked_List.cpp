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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* fron = head;
        ListNode* pres = head;

        if(pres->next == nullptr)
        {
            return head;
        }
        else
        {
            while(pres->next!=nullptr && fron != nullptr)
            {
                if(pres==fron)
                {
                    fron = fron->next;
                    int gcdnum = __gcd(pres->val, fron->val);
                    ListNode* temp = new ListNode(gcdnum, fron);
                    pres->next = temp;
                    pres = pres->next->next;
                    fron = fron->next;
                }
                else
                {
                    int gcdnum = __gcd(pres->val, fron->val);
                    ListNode* temp = new ListNode(gcdnum, fron);
                    pres->next = temp;
                    pres = pres->next->next;
                    fron = fron->next;
                }
            }
        }
        return head;
    }
};

static const auto kds = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();
