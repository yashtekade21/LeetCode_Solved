class Solution {
public:
    int m, n;
    vector<vector<vector<int>>> dp;

    int maximumAmount(vector<vector<int>>& coins) {
        m = coins.size();
        n = coins[0].size();

        dp.assign(m, vector<vector<int>>(n, vector<int>(3, INT_MIN)));
        return solve(coins, 0, 0, 2);
    }

private:
    int solve(vector<vector<int>>& coins, int i, int j, int nr) {
        if (i >= m || j >= n)
            return INT_MIN;

        if (dp[i][j][nr] != INT_MIN)
            return dp[i][j][nr];

        if (i == m - 1 && j == n - 1) {
            if (coins[i][j] < 0 && nr > 0)
                return dp[i][j][nr] = 0;
            return dp[i][j][nr] = coins[i][j];
        }

        int take = INT_MIN;

        int down = solve(coins, i + 1, j, nr);
        if (down != INT_MIN)
            take = max(take, coins[i][j] + down);

        int right = solve(coins, i, j + 1, nr);
        if (right != INT_MIN)
            take = max(take, coins[i][j] + right);

        int skip = INT_MIN;
        if (coins[i][j] < 0 && nr > 0) {
            int skipDown = solve(coins, i + 1, j, nr - 1);
            int skipRight = solve(coins, i, j + 1, nr - 1);
            skip = max(skipDown, skipRight);
        }

        return dp[i][j][nr] = max(skip, take);
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
