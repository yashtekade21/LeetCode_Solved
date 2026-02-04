class Solution {
public:
    vector<vector<long long>> dp;
    long long maxSumTrionic(vector<int>& nums) {
        int n = nums.size();
        dp.assign(n + 1, vector<long long>(4, LLONG_MIN));
        return solve(nums, n, 0, 0);
    }

private:
    long long solve(vector<int>& nums, int n, int i, int order) {
        if (i == n) {
            if (order == 3)
                return 0;
            else
                return LLONG_MIN / 2;
        }

        long long take = LLONG_MIN / 2, notTake = LLONG_MIN / 2;

        if (dp[i][order] != LLONG_MIN)
            return dp[i][order];

        if (order == 0)
            notTake = solve(nums, n, i + 1, 0);

        if (order == 3)
            take = nums[i];

        if (i + 1 < n) {
            int cur = nums[i], nxt = nums[i + 1];

            if (order == 0 && cur < nxt) {
                take = max(take, cur + solve(nums, n, i + 1, 1));
            } else if (order == 1) {
                if (nxt > cur)
                    take = max(take, cur + solve(nums, n, i + 1, 1));
                else if (nxt < cur)
                    take = max(take, cur + solve(nums, n, i + 1, 2));
            } else if (order == 2) {
                if (nxt < cur)
                    take = max(take, cur + solve(nums, n, i + 1, 2));
                else if (nxt > cur)
                    take = max(take, cur + solve(nums, n, i + 1, 3));
            } else if (order == 3 && cur < nxt) {
                take = max(take, cur + solve(nums, n, i + 1, 3));
            }
        }
        return dp[i][order] = max(take, notTake);
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
