class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n = nums.size();

        int ans = nums[0];
        int firstMin = INT_MAX, secMin = INT_MAX;

        for (int i = 1; i < n; i++) {
            if (nums[i] < firstMin) {
                secMin = firstMin;
                firstMin = nums[i];
            } else if (nums[i] < secMin)
                secMin = nums[i];
        }
        ans += (firstMin + secMin);
        return ans;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
