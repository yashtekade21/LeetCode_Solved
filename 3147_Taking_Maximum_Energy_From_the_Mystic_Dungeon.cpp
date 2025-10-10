class Solution {
public:
    vector<int> dp;
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        int ans = INT_MIN;

        dp.resize(n, 0);
        for (int i = n - 1; i >= 0; i--) {
            dp[i] = energy[i] + (i + k < n ? dp[i + k] : 0);
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
