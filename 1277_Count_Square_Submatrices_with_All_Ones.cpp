class Solution {
public:
    int m, n;
    vector<vector<int>> dp;
    int countSquares(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        dp.resize(301,vector<int>(301,-1));
        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 1) {
                    ans += solve(i, j, matrix);
                }
            }
        }

        return ans;
    }

private:
    int solve(int i, int j, vector<vector<int>>& matrix) {
        if (i > m - 1 || j > n - 1 || matrix[i][j] == 0)
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];
            
        int right = solve(i, j + 1, matrix);
        int down = solve(i + 1, j, matrix);
        int diag = solve(i + 1, j + 1, matrix);

        return dp[i][j] = 1 + min({right, down, diag});
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
