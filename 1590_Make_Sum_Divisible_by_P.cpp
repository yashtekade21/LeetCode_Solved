class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int reqRem = 0;
        for(auto i:nums)
            reqRem = (reqRem + i)%p;
    
        if(reqRem == 0)
            return 0;

        unordered_map<int,int> mp;
        mp[0] = -1;
        int ans = nums.size(),rem = 0;

        for(int i=0;i<nums.size();i++)
        {
            rem = (rem+nums[i])%p;
            int n = (rem-reqRem+p)%p;
            if(mp.find(n) != mp.end())
                ans = min(ans,i-mp[n]);

            mp[rem] = i;
        }
        if(ans==nums.size())
            return -1;
        
        return ans;
    }
};
static const auto kds = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();
