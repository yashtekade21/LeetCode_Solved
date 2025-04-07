class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        long long totalSum = accumulate(nums.begin(), nums.end(), 0);

        if (totalSum % 2 != 0)
            return false;

        vector<vector<int>> dp(n, vector<int>((totalSum/2)+1, -1));

        return solve(nums, 0, totalSum / 2, dp);
    }

private:
    bool solve(vector<int>& nums, int idx, int reqSum,
               vector<vector<int>>& dp) {
        if (reqSum == 0)
            return true;

        if (idx >= nums.size())
            return false;

        if(dp[idx][reqSum] != -1)
            return dp[idx][reqSum];

        bool take = false;
        if(reqSum-nums[idx] >= 0)
            take = solve(nums, idx + 1, reqSum - nums[idx], dp);
        bool notTake = solve(nums, idx + 1, reqSum, dp);

        return dp[idx][reqSum] = take || notTake;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
