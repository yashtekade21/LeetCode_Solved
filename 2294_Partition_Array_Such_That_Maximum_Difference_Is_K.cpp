class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = 1;
        int maxIdx = n - 1;
        for (int i = n - 1; i >= 0; i--) {
            if (nums[maxIdx] - nums[i] > k) {
                maxIdx = i;
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
