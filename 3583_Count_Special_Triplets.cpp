class Solution {
public:
    const int MOD = 1e9 + 7;
    int specialTriplets(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        unordered_map<int, long long> mp_right, mp_left;
        for (auto& num : nums)
            mp_right[num]++;

        for (int i = 0; i < n; i++) {
            mp_right[nums[i]]--;
            if (mp_right[nums[i]] == 0)
                mp_right.erase(nums[i]);

            int require = nums[i] * 2;

            if (mp_left[require] > 0 && mp_right[require] > 0)
                ans =
                    (ans + (mp_left[require] * mp_right[require]) % MOD) % MOD;

            mp_left[nums[i]]++;
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
