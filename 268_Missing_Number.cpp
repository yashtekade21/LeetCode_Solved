class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // int n= nums.size();
        // unordered_map<int,int> mp;
        // for(int i=0;i<n;i++)
        //     mp[nums[i]]++;

        // for(int i=0;i<=n;i++)
        //     if(mp[i] == 0)
        //         return i;

        int sum = 0;
        for(int i:nums)
            sum += i;
        
        int n = nums.size();
        int idealsum = n*(n+1)/2;

        return idealsum-sum;
    }
};

static const auto kds = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();
