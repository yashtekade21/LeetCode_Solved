class Solution {
public:
    int MOD = 1e9 + 7;
    vector<int> dp, prev;

    int distinctSubseqII(string s) {
        int n = s.length();

        dp.resize(2001, -1);
        prev.assign(n + 1, 0);

        vector<int> lastSeen(26, 0);
        for (int i = 1; i <= n; i++) {
            int idx = s[i - 1] - 'a';

            prev[i] = lastSeen[idx];
            lastSeen[idx] = i;
        }

        return (solve(n) - 1 + MOD) % MOD;
    }

private:
    int solve(int n) {
        if (n == 0)
            return 1;

        if (dp[n] != -1)
            return dp[n];

        int total = (2 * solve(n - 1)) % MOD;

        if (prev[n] != 0) {
            int duplicates = solve(prev[n] - 1);
            total = (total - duplicates + MOD) % MOD;
        }

        return dp[n] = total;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
