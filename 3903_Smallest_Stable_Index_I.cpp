class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> maxEl(n), minEl(n);

        maxEl[0] = nums[0];
        minEl[n - 1] = nums[n - 1];
        for (int i = 1; i < n; i++) {
            maxEl[i] = max(maxEl[i - 1], nums[i]);
            minEl[n - i - 1] = min(minEl[n - i], nums[n - i - 1]);
        }

        for (int i = 0; i < n; i++) {
            if (maxEl[i] - minEl[i] <= k)
                return i;
        }
        return -1;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
