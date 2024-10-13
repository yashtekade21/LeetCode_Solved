class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prefix = 1,suffix =1,n=nums.size(),maxprosub = INT_MIN;
        for(int i=0;i<n;i++){
            if(prefix == 0)
                prefix = 1;
            if(suffix == 0)
                suffix = 1;
            
            prefix *= nums[i];
            suffix *= nums[n-i-1];
            maxprosub = max(maxprosub,max(prefix,suffix));
        }
        return maxprosub;
    }
};
static const auto kds = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();
