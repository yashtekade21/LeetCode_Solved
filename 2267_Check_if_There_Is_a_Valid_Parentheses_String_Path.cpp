class Solution {
public:
    int m, n;
    vector<vector<vector<int>>> dp;
    bool hasValidPath(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        if ((m + n - 1) % 2 == 1)
            return false;

        dp.resize(101, vector<vector<int>>(101, vector<int>(m + n, -1)));
        return solve(0, 0, 0, grid);
    }

private:
    bool solve(int i, int j, int openBracs, vector<vector<char>>& grid) {
        openBracs += (grid[i][j] == '(' ? 1 : -1);

        if (openBracs < 0)
            return false;

        if (dp[i][j][openBracs] != -1)
            return dp[i][j][openBracs];

        if (i == m - 1 && j == n - 1)
            return dp[i][j][openBracs] = (openBracs == 0);

        bool curAns = false;

        if (i < m - 1)
            curAns = curAns || solve(i + 1, j, openBracs, grid);

        if (j < n - 1)
            curAns = curAns || solve(i, j + 1, openBracs, grid);

        return dp[i][j][openBracs] = curAns;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
