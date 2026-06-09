class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long maxEl = LLONG_MIN, minEl = LLONG_MAX;

        for (int i = 0; i < nums.size(); i++) {
            maxEl = max(maxEl, (long long)nums[i]);
            minEl = min(minEl, (long long)nums[i]);
        }

        return (maxEl - minEl) * k;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
