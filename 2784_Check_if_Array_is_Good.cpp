class Solution {
public:
    bool isGood(vector<int>& nums) {
        vector<int> mp(201, 0);
        int maxEl = 0;

        for (auto& num : nums) {
            mp[num]++;
            maxEl = max(maxEl, num);
        }

        if (mp[maxEl] != 2)
            return false;

        for (int num = 1; num < maxEl; num++) {
            if (mp[num] != 1)
                return false;
        }
        return true;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
