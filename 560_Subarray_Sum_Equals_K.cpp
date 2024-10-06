class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int preSum = 0,count=0;
        mp[0] = 1;

        for(int i=0;i<nums.size();i++){
            preSum += nums[i];

            count += mp[preSum-k];
            mp[preSum]++;
        }
        return count;
    }
};
static const auto kds = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();
