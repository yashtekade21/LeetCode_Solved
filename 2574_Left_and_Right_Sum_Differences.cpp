class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftSum(n), rightSum(n), ans(n);
        int l = 0, r = 0;

        for (int i = 0; i < n; i++) {
            leftSum[i] = l;
            l += nums[i];

            rightSum[n - i - 1] = r;
            r += nums[n - i - 1];
        }

        for (int i = 0; i < n; i++)
            ans[i] = abs(leftSum[i] - rightSum[i]);

        return ans;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
