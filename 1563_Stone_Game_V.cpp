class Solution {
public:
    vector<vector<int>> dp;
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();

        vector<int> cumSum(n, 0);
        dp.resize(501, vector<int>(501, -1));
        cumSum[0] = stoneValue[0];

        for (int i = 1; i < n; i++)
            cumSum[i] = cumSum[i - 1] + stoneValue[i];

        return solve(0, n - 1, cumSum);
    }

private:
    int solve(int l, int r, vector<int>& cumSum) {
        if (l >= r)
            return 0;

        if (dp[l][r] != -1)
            return dp[l][r];

        int score = 0;
        for (int m = l; m <= r; m++) {
            int leftSum = cumSum[m] - (l > 0 ? cumSum[l - 1] : 0);
            int rightSum = cumSum[r] - cumSum[m];

            if (leftSum < rightSum)
                score = max(score, leftSum + solve(l, m, cumSum));
            else if (rightSum < leftSum)
                score = max(score, rightSum + solve(m + 1, r, cumSum));
            else
                score = max({score, leftSum + solve(l, m, cumSum),
                             rightSum + solve(m + 1, r, cumSum)});
        }
        return dp[l][r] = score;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
