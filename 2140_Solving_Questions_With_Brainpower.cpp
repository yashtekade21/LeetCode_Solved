class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();

        vector<long long> dp(n, -1);

        return solve(questions, 0, n, dp);
    }

private:
    long long solve(vector<vector<int>>& questions, int idx, int n,
                    vector<long long>& dp) {
        if (idx >= n)
            return 0;

        if (dp[idx] != -1)
            return dp[idx];

        long long take = questions[idx][0] +
                         solve(questions, idx + questions[idx][1] + 1, n, dp);
        long long skip = solve(questions, idx + 1, n, dp);

        return dp[idx] = max(take, skip);
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
