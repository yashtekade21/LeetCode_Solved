class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> maxLeft(n), minRight(n);
        vector<int> ans(n);

        maxLeft[0] = nums[0];
        minRight[n - 1] = nums[n - 1];

        for (int i = 1; i < n; i++) {
            maxLeft[i] = max(nums[i], maxLeft[i - 1]);
            minRight[n - i - 1] = min(nums[n - i - 1], minRight[n - i]);
        }

        ans[n - 1] = maxLeft[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            if (maxLeft[i] <= minRight[i + 1])
                ans[i] = maxLeft[i];
            else
                ans[i] = ans[i + 1];
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
