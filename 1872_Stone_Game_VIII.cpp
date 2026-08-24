class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        vector<int> prefSum(n, 0);

        prefSum[0] = stones[0];
        for (int i = 1; i < n; i++)
            prefSum[i] = prefSum[i - 1] + stones[i];

        vector<int> dp(n);
        dp[n - 1] = prefSum[n - 1];

        for (int i = n - 2; i >= 1; i--) {
            int take = prefSum[i] - dp[i + 1];
            int skip = dp[i + 1];

            dp[i] = max(take, skip);
        }

        return dp[1];
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
