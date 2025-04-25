class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int n = nums.size();
        vector<int> prefixCnt(n, 0);
        for (int i = 0; i < n; i++) {
            if (nums[i] % modulo == k)
                prefixCnt[i] = 1;
        }

        long long ans = 0, sum = 0;
        unordered_map<int, int> mp;
        mp[sum] = 1;

        for (int i = 0; i < n; i++) {
            sum += prefixCnt[i];
            int rem1 = sum % modulo;
            int rem2 = (rem1 - k) % modulo;

            if (rem2 < 0)
                rem2 += modulo;
            ans += mp[rem2];
            mp[rem1]++;
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
