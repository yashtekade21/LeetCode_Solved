class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans = 0, sum = 0;
        unordered_map<int, int> mp;
        int l = 0, n = nums.size();
        for (int r = 0; r < n; r++) {
            sum += nums[r];
            mp[nums[r]]++;

            if (r - l + 1 > k) {
                mp[nums[l]]--;
                if (mp[nums[l]] == 0)
                    mp.erase(nums[l]);
                sum -= nums[l];
                l++;
            }

            if (r - l + 1 == k && mp.size() == k)
                ans = max(sum, ans);
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
