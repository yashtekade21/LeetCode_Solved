class Solution {
public:
    const int MOD = 1e9 + 7;
    int numTilings(int n) {
        vector<int> dp(n + 1, -1);
        return solve(n, dp);
    }
private:
    int solve(int n, vector<int>& dp) {
        if (n == 1 || n == 2)
            return dp[n] = n;

        if(n == 3)
            return dp[n] = 5;

        if (dp[n] != -1)
            return dp[n];

        return dp[n] = (2 * solve(n - 1, dp) % MOD + solve(n - 3, dp)%MOD) % MOD;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
