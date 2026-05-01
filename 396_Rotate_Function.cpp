class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        long long F = 0, sum = 0;
        for (int i = 0; i < n; i++) {
            F = F + (i * nums[i]);
            sum += nums[i];
        }

        long long ans = F;

        for (int k = 1; k < n; k++) {
            F = F + sum - (long)n * nums[n - k];
            ans = max(ans, F);
        }

        return (int)ans;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
