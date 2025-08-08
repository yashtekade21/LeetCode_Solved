class Solution {
public:
    vector<vector<double>> dp;
    double soupServings(int n) {
        if (n > 5000)
            return 1;
        dp.resize(n + 1, vector<double>(n + 1, -1));
        return solve(n, n);
    }

private:
    double solve(int A, int B) {
        double ans = 0;
        if (A <= 0 && B <= 0)
            return 0.5;
        else if (A <= 0)
            return 1.0;
        else if (B <= 0)
            return 0.0;

        if (dp[A][B] != -1)
            return dp[A][B];

        ans += 0.25 * solve(A - 100, B);
        ans += 0.25 * solve(A - 75, B - 25);
        ans += 0.25 * solve(A - 50, B - 50);
        ans += 0.25 * solve(A - 25, B - 75);
        return dp[A][B] = ans;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
