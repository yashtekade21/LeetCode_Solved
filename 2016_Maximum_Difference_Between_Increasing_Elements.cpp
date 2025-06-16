class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();

        int curMinIdx = INT_MAX, curMaxIdx = INT_MIN;
        for (int i = 0; i < n; i++) {
            if (curMinIdx == INT_MAX || nums[curMinIdx] > nums[i])
                curMinIdx = i;

            ans = max(ans, abs(nums[i] - nums[curMinIdx]));
        }
        return (ans == 0) ? -1 : ans;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
