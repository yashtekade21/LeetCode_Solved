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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }

        ListNode* prev = head;
        ListNode* pres = head;

        while (pres != nullptr) {
            if(mp[pres->val] >= 1)
            {
                if(prev == pres){
                    if(pres == head)
                        head = head->next;
                    pres = pres->next;
                    prev = pres;
                }
                else
                {
                    pres = pres->next;
                    prev->next = pres;
                }

            }
            else
            {
                prev = pres;
                pres = pres->next;
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
