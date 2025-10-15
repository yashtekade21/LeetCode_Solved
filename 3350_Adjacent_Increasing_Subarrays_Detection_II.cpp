class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();

        int curLen = 1, prevLen = 0;
        int ans = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i - 1] < nums[i]) {
                curLen++;
            } else {
                prevLen = curLen;
                curLen = 1;
            }
            ans = max(ans, curLen / 2);
            if (ans < min(prevLen, curLen))
                ans = min(prevLen, curLen);
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
