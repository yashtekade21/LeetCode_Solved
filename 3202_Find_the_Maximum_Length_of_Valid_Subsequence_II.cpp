class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();

        vector<vector<int>> dp(1001, vector<int>(1001, 1));

        int maxSubLen = 1;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                int mod = (nums[j] + nums[i]) % k;

                dp[mod][i] = max(dp[mod][i], dp[mod][j] + 1);
                maxSubLen = max(maxSubLen, dp[mod][i]);
            }
        }

        return maxSubLen;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
