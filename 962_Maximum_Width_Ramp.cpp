class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        int maxLen = 0;
        vector<int> small(n), large(n);
        small[0] = nums[0];
        large[n - 1] = nums[n - 1];

        for (int i = 1; i < n; i++){
            small[i] = min(small[i - 1], nums[i]);
            large[n - i - 1] = max(large[n - i], nums[n - i -1]);
        }
        int i = 0, j = 0;
        while (j < n) {
            if (small[i] <= large[j]) {
                maxLen = max(maxLen, j - i);
                j++;
            } else
                i++;
        }
        return maxLen;
    }
};
static const auto kds = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();
