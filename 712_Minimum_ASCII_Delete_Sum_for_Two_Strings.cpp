class Solution {
public:
    vector<vector<int>> dp;
    int n, m;
    int minimumDeleteSum(string s1, string s2) {
        n = s1.length(), m = s2.length();

        dp.resize(1001, vector<int>(1001, -1));
        return solve(0, 0, s1, s2);
    }

private:
    int solve(int i, int j, string& s1, string& s2) {
        if (i > n - 1 && j > m - 1)
            return 0;

        if (i > n - 1)
            return int(s2[j]) + solve(i, j + 1, s1, s2);

        if (j > m - 1)
            return int(s1[i]) + solve(i + 1, j, s1, s2);

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s1[i] == s2[j])
            return solve(i + 1, j + 1, s1, s2);

        int take_s1 = int(s1[i]) + solve(i + 1, j, s1, s2);
        int take_s2 = int(s2[j]) + solve(i, j + 1, s1, s2);

        return dp[i][j] = min(take_s1, take_s2);
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
