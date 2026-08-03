class Solution {
public:
    int n;
    vector<int> dp;
    string stoneGameIII(vector<int>& stoneValue) {
        n = stoneValue.size();
        dp.resize(n + 1, -1);

        int diff = solve(stoneValue, 0);

        if (diff < 0)
            return "Bob";
        else if (diff > 0)
            return "Alice";

        return "Tie";
    }

private:
    int solve(vector<int>& stoneValue, int i) {
        if (i == n)
            return 0;

        if (dp[i] != -1)
            return dp[i];

        dp[i] = stoneValue[i] - solve(stoneValue, i + 1);

        if (i + 1 < n)
            dp[i] = max(dp[i], stoneValue[i] + stoneValue[i + 1] -
                                   solve(stoneValue, i + 2));

        if (i + 2 < n)
            dp[i] =
                max(dp[i], stoneValue[i] + stoneValue[i + 1] +
                               stoneValue[i + 2] - solve(stoneValue, i + 3));

        return dp[i];
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
