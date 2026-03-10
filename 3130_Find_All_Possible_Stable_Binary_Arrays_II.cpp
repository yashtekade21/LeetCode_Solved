class Solution {
public:
    const int MOD = 1e9 + 7;
    int dp[1001][1001][2];
    int numberOfStableArrays(int zero, int one, int limit) {
        memset(dp, -1, sizeof(dp));

        return (solve(zero, one, true, limit) +
                solve(zero, one, false, limit)) %
               MOD;
    }

private:
    int solve(int zeroRem, int oneRem, bool lastUsedOne, int limit) {
        if (zeroRem == 0 && oneRem == 0)
            return 1;

        if (zeroRem == 0) {
            if (lastUsedOne)
                return 0;
            return oneRem <= limit ? 1 : 0;
        }

        if (oneRem == 0) {
            if (!lastUsedOne)
                return 0;
            return zeroRem <= limit ? 1 : 0;
        }

        if (dp[zeroRem][oneRem][lastUsedOne] != -1)
            return dp[zeroRem][oneRem][lastUsedOne];

        int ans = 0;

        if (!lastUsedOne) {
            ans = (solve(zeroRem, oneRem - 1, true, limit) +
                   solve(zeroRem, oneRem - 1, false, limit)) %
                  MOD;

            if (oneRem - 1 >= limit)
                ans = (ans - solve(zeroRem, oneRem - 1 - limit, true, limit) +
                       MOD) %
                      MOD;
        } else {
            ans = (solve(zeroRem - 1, oneRem, true, limit) +
                   solve(zeroRem - 1, oneRem, false, limit)) %
                  MOD;

            if (zeroRem - 1 >= limit)
                ans = (ans - solve(zeroRem - 1 - limit, oneRem, false, limit) +
                       MOD) %
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
