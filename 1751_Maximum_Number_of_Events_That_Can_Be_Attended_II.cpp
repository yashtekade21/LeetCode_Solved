class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        sort(events.begin(), events.end());

        vector<int> nextIndex(n, n);
        for (int i = 0; i < n; ++i) {
            int endTime = events[i][1];
            vector<int> temp = {endTime + 1, 0, 0};
            nextIndex[i] = lower_bound(events.begin(), events.end(), temp) - events.begin();
        }

        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
        for (int i = n - 1; i >= 0; --i) {
            for (int j = 1; j <= k; ++j) {
                int take = events[i][2] + dp[nextIndex[i]][j - 1];
                int skip = dp[i + 1][j];
                dp[i][j] = max(take, skip);
            }
        }

        return dp[0][k];
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
