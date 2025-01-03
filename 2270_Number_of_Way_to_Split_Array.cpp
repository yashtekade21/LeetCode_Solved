class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        vector<long long> prefix_sum;
        long long cur_sum = 0;
        int ans = 0;

        for (int i = 0; i < n; i++) {
            cur_sum += nums[i];
            prefix_sum.emplace_back(cur_sum);
        }

        for (int i = 0; i < n - 1; i++)
            if (prefix_sum[i] >= prefix_sum[n - 1] - prefix_sum[i])
                ans++;

        return ans;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
