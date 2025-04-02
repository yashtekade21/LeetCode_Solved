class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();

        long long maxDiff = 0, maxNum = 0, ans = 0;

        for (int k = 0; k < n; k++) {
            ans = max(ans, maxDiff * nums[k]);

            maxDiff = max(maxDiff, (long long)(maxNum - nums[k]));
            maxNum = max(maxNum, (long long)nums[k]);
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
