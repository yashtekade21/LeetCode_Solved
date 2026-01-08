class Solution {
public:
    int n, m;
    vector<vector<int>> dp;
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        n = nums1.size(), m = nums2.size();
        dp.resize(501, vector<int>(501, INT_MIN));
        return solve(nums1, nums2, 0, 0);
    }

private:
    int solve(vector<int>& nums1, vector<int>& nums2, int i, int j) {
        if (i > n - 1 || j > m - 1)
            return INT_MIN;

        if (dp[i][j] != INT_MIN)
            return dp[i][j];

        int val = nums1[i] * nums2[j];
        int take_i_j = val;
        int next = solve(nums1, nums2, i + 1, j + 1);
        if (next != INT_MIN)
            take_i_j += next;
        int take_i = solve(nums1, nums2, i, j + 1);
        int take_j = solve(nums1, nums2, i + 1, j);

        return dp[i][j] = max({val, take_i_j, take_i, take_j});
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
