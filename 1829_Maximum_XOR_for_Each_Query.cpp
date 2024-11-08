class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int _xor = 0, max_xor = pow(2, maximumBit) - 1, n = nums.size();

        for (auto i : nums)
            _xor ^= i;

        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            ans[i] = max_xor ^ _xor;
            _xor ^= nums[n - i - 1];
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
