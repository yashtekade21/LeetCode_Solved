class Solution {
public:
    const int MOD = 1e9 + 7;
    int peopleAwareOfSecret(int n, int delay, int forget) {
        int ans = 0;

        vector<int> dp(n + 1, -1);

        for (int day = n - forget + 1; day <= n; day++) {
            if (day > 0)
                ans = (ans + solve(day, delay, forget, dp)) % MOD;
        }

        return ans;
    }

private:
    int solve(int& day, int& delay, int& forget, vector<int>& dp) {
        if (day == 1)
            return 1;

        if (dp[day] != -1)
            return dp[day];

        int total = 0;

        for (int d = day - forget + 1; d <= day - delay; d++) {
            if (d > 0)
                total = (total + solve(d, delay, forget, dp)) % MOD;
        }

        return dp[day] = total;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
