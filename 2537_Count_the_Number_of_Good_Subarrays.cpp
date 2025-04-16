class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> mp;

        int i = 0, j = 0, pairs = 0;
        long long ans = 0;

        while (j < n) {
            pairs += mp[nums[j]];
            mp[nums[j]]++;

            while (pairs >= k) {
                ans += (n - j);
                mp[nums[i]]--;
                pairs -= mp[nums[i]];
                i++;
            }
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
