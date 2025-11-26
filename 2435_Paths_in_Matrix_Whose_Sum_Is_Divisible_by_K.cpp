class Solution {
public:
    int m, n;
    vector<vector<vector<int>>> dp;
    const int MOD = 1e9 + 7;
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        m = grid.size(), n = grid[0].size();

        dp.resize(m, vector<vector<int>>(n, vector<int>(k, -1)));

        return solve(0, 0, 0, grid, k);
    }

private:
    int solve(int i, int j, int curSum, vector<vector<int>>& grid, int k) {
        if (i >= m || j >= n)
            return 0;

        if (i == m - 1 && j == n - 1)
            return (curSum + grid[i][j]) % k == 0;

        if (dp[i][j][curSum] != -1)
            return dp[i][j][curSum];

        int right = solve(i, j + 1, (curSum + grid[i][j]) % k, grid, k);
        int down = solve(i + 1, j, (curSum + grid[i][j]) % k, grid, k);

        return dp[i][j][curSum] = (right + down) % MOD;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
