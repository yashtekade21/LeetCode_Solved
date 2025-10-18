class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int prev = INT_MIN, ans = 0;

        for (int i = 0; i < n; i++) {
            int minNum = nums[i] - k;

            if (prev < minNum) {
                ans++;
                prev = minNum;
            } else if (prev < nums[i] + k) {
                prev++;
                ans++;
            }
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
