class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1 = 0, cnt2 = 0;
        int el1 , el2;
        int freq = (nums.size()/3);

        for (int i = 0; i < nums.size(); i++) {
            if (cnt1 == 0 && nums[i] != el2) {
                cnt1 = 1;
                el1 = nums[i];
            } else if (cnt2 == 0 && nums[i] != el1) {
                cnt2 = 1;
                el2 = nums[i];
            } else if (el1 == nums[i])
                cnt1++;
            else if (el2 == nums[i])
                cnt2++;
            else {
                cnt1--;
                cnt2--;
            }
        }

        cnt1 = 0,cnt2 =0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] == el1)
                cnt1++;
            else if(nums[i] == el2)
                cnt2++;
        }
        
        vector<int> ans;
        if(cnt1 > freq)
            ans.emplace_back(el1);
        if(cnt2 > freq)
            ans.emplace_back(el2);
        sort(ans.begin(),ans.end());
        return ans;
    }
};
static const auto kds = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();
