class Solution {
public:
    int n;
    vector<int> dp;
    int maximumJumps(vector<int>& nums, int target) {
        n = nums.size();
        dp.assign(n, -2);
        int ans = solve(0, nums, target);
        return ans < 0 ? -1 : ans;
    }

private:
    int solve(int i, vector<int>& nums, int& target) {
        if (i == n - 1)
            return 0;

        if (dp[i] != -2)
            return dp[i];

        int ans = INT_MIN;
        for (int j = i + 1; j < n; j++) {
            if (abs(nums[j] - nums[i]) <= target) {
                int nxt = solve(j, nums, target);
                if (nxt != -1)
                    ans = max(ans, 1 + nxt);
            }
        }

        return dp[i] = ans;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
