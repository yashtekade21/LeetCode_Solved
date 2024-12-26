class Solution {
public:
    vector<vector<int>> dp;
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (int num : nums) 
            sum += num;
        

        int offset = sum;
        int dp_size = 2 * sum + 1;
        dp.resize(nums.size(), vector<int>(dp_size, -1));

        return calc_exp(nums, target, offset);
    }

private:
    int calc_exp(vector<int>& nums, int& target, int& offset, int i = 0, int cur_sum = 0) {
        if (i == nums.size()) 
            return (cur_sum == target) ? 1 : 0;
        
        if (dp[i][cur_sum + offset] != -1) 
            return dp[i][cur_sum + offset];
        

        int add = calc_exp(nums, target, offset, i + 1, cur_sum + nums[i]);
        int subtract = calc_exp(nums, target, offset, i + 1, cur_sum - nums[i]);

        dp[i][cur_sum + offset] = add + subtract;

        return dp[i][cur_sum + offset];
    }
};

static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
