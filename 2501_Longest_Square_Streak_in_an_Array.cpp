class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {

        unordered_map<int, int> mp;
        int maxi = -1;
        sort(nums.begin(), nums.end());
        for (auto i : nums) {
            int sroot = (int)sqrt(i);

            if (i == sroot * sroot && mp.find(sroot) != mp.end()) {
                mp[i] = mp[sroot] + 1;
                maxi = max(maxi, mp[i]);
            } else
                mp[i] = 1;
        }
        return maxi;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
