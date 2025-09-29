class Solution {
public:
    vector<vector<int>> dp;
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        dp.resize(51, vector<int>(51, -1));

        return solve(values, 0, n - 1);
    }

private:
    int solve(vector<int>& values, int i, int j) {
        if (j - i + 1 < 3)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int ans = INT_MAX;

        for (int k = i + 1; k < j; k++) {
            int triWeight = solve(values, i, k) +
                            (values[i] * values[j] * values[k]) +
                            solve(values, k, j);

            ans = min(ans, triWeight);
        }
        return dp[i][j] = ans;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
