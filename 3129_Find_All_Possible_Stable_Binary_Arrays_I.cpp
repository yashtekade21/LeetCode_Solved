class Solution {
public:
    const int MOD = 1e9 + 7;
    int dp[201][201][2];
    int numberOfStableArrays(int zero, int one, int limit) {
        memset(dp, -1, sizeof(dp));
        return ((long long)solve(zero, one, true, limit) +
                (long long)solve(zero, one, false, limit)) %
               MOD;
    }

private:
    int solve(int zeroRem, int oneRem, bool lastUsedOne, int limit) {
        if (zeroRem == 0 && oneRem == 0)
            return 1;

        if (dp[zeroRem][oneRem][lastUsedOne] != -1)
            return dp[zeroRem][oneRem][lastUsedOne];

        int ans = 0;
        if (lastUsedOne) {
            for (int zeroAppend = 1; zeroAppend <= min(zeroRem, limit);
                 zeroAppend++)
                ans =
                    (ans + solve(zeroRem - zeroAppend, oneRem, false, limit)) %
                    MOD;

        } else {
            for (int oneAppend = 1; oneAppend <= min(oneRem, limit);
                 oneAppend++)
                ans = (ans + solve(zeroRem, oneRem - oneAppend, true, limit)) %
                      MOD;
        }

        return dp[zeroRem][oneRem][lastUsedOne] = ans;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
