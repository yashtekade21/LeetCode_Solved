class Solution {
public:
    vector<vector<int>> dp;
    int n, k;
    int minDeletionSize(vector<string>& strs) {
        n = strs.size();
        k = strs[0].size();
        dp.resize(k + 1, vector<int>(k + 1, -1));

        return k - solve(0, -1, strs);
    }

private:
    int solve(int idx, int prevIdx, vector<string>& strs) {
        if (idx >= k)
            return 0;

        if (dp[idx][prevIdx + 1] != -1) // prevIdx = -1
            return dp[idx][prevIdx + 1];

        int take = 0;
        if (prevIdx == -1 || checkIncreasing(idx, prevIdx, strs))
            take = 1 + solve(idx + 1, idx, strs);

        int notTake = solve(idx + 1, prevIdx, strs);

        return dp[idx][prevIdx + 1] = max(take, notTake);
    }

    bool checkIncreasing(int idx, int prevIdx, vector<string>& strs) {
        for (int i = 0; i < n; i++) {
            if (strs[i][idx] < strs[i][prevIdx])
                return false;
        }
        return true;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
