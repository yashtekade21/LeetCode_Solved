class Solution {
public:
    vector<int> dp;
    bool winnerSquareGame(int n) {
        dp.assign(n + 1, -1);
        return solve(n);
    }

private:
    bool solve(int n) {
        if (n == 0)
            return false;

        if (dp[n] != -1)
            return dp[n] == 1 ? true : false;

        for (int k = 1; k * k <= n; k++) {
            if (solve(n - (k * k)) == false)
                return dp[n] = true;
        }
        return dp[n] = false;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
