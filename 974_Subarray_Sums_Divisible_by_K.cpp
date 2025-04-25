class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int ans = 0;
        int sum = 0;
        mp[0] = 1;

        for (int i = 0; i < n; i++) {
            sum += nums[i];
            int rem = sum % k;

            if (rem < 0)
                rem += k;

            ans += mp[rem];
            mp[rem]++;
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
