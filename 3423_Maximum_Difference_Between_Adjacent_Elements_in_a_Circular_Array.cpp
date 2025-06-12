class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MIN;

        for (int i = 0; i < n; i++) {
            int diff = nums[i] - nums[(i + 1) % n];
            ans = max(ans, abs(diff));
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
