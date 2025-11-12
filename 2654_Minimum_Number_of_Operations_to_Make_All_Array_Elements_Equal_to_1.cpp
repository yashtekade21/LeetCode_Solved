class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int ones = 0;
        for(auto& num:nums)
            ones += (num == 1) ? 1 : 0;
        if(ones)
            return n- ones;
            
        int minOps = INT_MAX;

        for (int i = 0; i < n; i++) {
            int gcdVal = nums[i];
            for (int j = i + 1; j < n; j++) {
                gcdVal = __gcd(gcdVal, nums[j]);
                if (gcdVal == 1)
                    minOps = min(minOps, j - i);
            }
        }
        return (minOps == INT_MAX) ? -1 : minOps + (n - 1);
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
