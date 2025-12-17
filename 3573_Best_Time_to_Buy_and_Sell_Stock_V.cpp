class Solution {
public:
    long long dp[1001][501][3];
    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        for (int i = 0; i < n; i++)
            for (int j = 0; j <= k; j++)
                for (int l = 0; l < 3; l++)
                    dp[i][j][l] = INT_MIN;

        return solve(0, k, 0, prices);
    }

private:
    long long solve(int idx, int k, int transactionType, vector<int>& prices) {
        if (idx >= prices.size()) {
            if (transactionType == 0)
                return 0;
            return INT_MIN;
        }

        if (dp[idx][k][transactionType] != INT_MIN)
            return dp[idx][k][transactionType];

        long long buy = INT_MIN;
        long long skip = solve(idx + 1, k, transactionType, prices);

        if (k > 0) {
            if (transactionType == 1)
                buy = prices[idx] + solve(idx + 1, k - 1, 0, prices);
            else if (transactionType == 2)
                buy = -prices[idx] + solve(idx + 1, k - 1, 0, prices);
            else
                buy =
                    max(-prices[idx] + solve(idx + 1, k, 1, prices), // buy
                        prices[idx] + solve(idx + 1, k, 2, prices) // short sell
                    );
        }
        return dp[idx][k][transactionType] = max(buy, skip);
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
