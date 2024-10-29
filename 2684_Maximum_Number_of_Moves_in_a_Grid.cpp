class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size(), moves = 0;
        vector<vector<int>> dp(r, vector<int>(c,-1));

        for (int i = 0; i < r; i++) {
            moves = max(moves, checkBigger(grid, dp, i, 0, r, c));
        }
        return moves;
    }

private:
    int checkBigger(vector<vector<int>>& grid, vector<vector<int>>& dp, int i,
                    int j, int r, int c) {
        if (i == r && j == c)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];

        int moves = 0;

        if (i - 1 >= 0 && j + 1 < c && grid[i - 1][j + 1] > grid[i][j])
            moves = checkBigger(grid, dp, i - 1, j + 1, r, c) + 1;

        if (j + 1 < c && grid[i][j + 1] > grid[i][j])
            moves = max(moves, checkBigger(grid, dp, i, j + 1, r, c) + 1);

        if (i + 1 < r && j + 1 < c && grid[i + 1][j + 1] > grid[i][j])
            moves = max(moves, checkBigger(grid, dp, i + 1, j + 1, r, c) + 1);
        return dp[i][j] = moves;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
