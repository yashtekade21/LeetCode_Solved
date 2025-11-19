class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        vector<int> mp(1001, 0);
        for (auto& num : nums) {
            mp[num]++;
        }

        int ans = original;
        while (ans <= 1000 && mp[ans])
            ans *= 2;

        return ans;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
