class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        long long ans = 0;
        long long cumSum = 0;
        unordered_map<long long, long long> mp;

        mp[0] = 1;
        int validSubArr = 0;

        for (auto& num : nums) {
            validSubArr = (num == target) ? validSubArr + mp[cumSum]
                                          : validSubArr - mp[cumSum - 1];
            cumSum = (num == target) ? cumSum + 1 : cumSum - 1;
            mp[cumSum]++;
            ans += validSubArr;
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
