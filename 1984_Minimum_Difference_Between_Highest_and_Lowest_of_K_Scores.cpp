class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = INT_MAX;

        int i = 0, j = 0;
        while (j < n) {
            while (j - i + 1 > k)
                i++;
            
            ans = min(ans, nums[i + k - 1] - nums[i]);
            j++;
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
