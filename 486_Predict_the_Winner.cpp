class Solution {
public:
    int n;
    vector<vector<int>> dp;

    bool predictTheWinner(vector<int>& nums) {
        n = nums.size();
        dp.resize(23, vector<int>(23, -1));
        return maxDiff(nums, 0, n - 1) >= 0;
    }

private:
    int maxDiff(vector<int>& nums, int l, int r) {
        if (l == r)
            return nums[l];

        if (dp[l][r] != -1)
            return dp[l][r];

        int take_left = nums[l] - maxDiff(nums, l + 1, r);
        int take_right = nums[r] - maxDiff(nums, l, r - 1);

        return dp[l][r] = max(take_left, take_right);
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
