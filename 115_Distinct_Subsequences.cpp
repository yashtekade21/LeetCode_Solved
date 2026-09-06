class Solution {
public:
    vector<vector<int>> dp;
    int numDistinct(string s, string t) {
        int m = s.length();
        int n = t.length();

        if (m < n)
            return 0;

        dp.resize(1001, vector<int>(1001, -1));
        return solve(s, t, m, n);
    }

private:
    int solve(string& s, string& t, int m, int n) {
        if (n == 0)
            return dp[m][n] = 1;
        if (m == 0)
            return dp[m][n] = 0;

        if (dp[m][n] != -1)
            return dp[m][n];

        if (s[m - 1] == t[n - 1])
            return dp[m][n] = solve(s, t, m - 1, n) + solve(s, t, m - 1, n - 1);
        else
            return dp[m][n] = solve(s, t, m - 1, n);
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
