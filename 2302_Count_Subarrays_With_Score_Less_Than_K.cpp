class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        long long prefixSum = 0, ans = 0;

        int i = 0, j = 0;

        while (j < n) {
            prefixSum += nums[j];

            while ((prefixSum * (j - i + 1)) >= k) {
                prefixSum -= nums[i];
                i++;
            }
            ans += (j - i + 1);
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
