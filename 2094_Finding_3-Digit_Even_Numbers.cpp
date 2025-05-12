class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> mp(10, 0);
        for (auto& num : digits)
            mp[num]++;

        vector<int> ans;

        for (int hunds = 1; hunds <= 9; hunds++) {
            if (!mp[hunds])
                continue;
            mp[hunds]--;
            for (int tens = 0; tens <= 9; tens++) {
                if (!mp[tens])
                    continue;
                mp[tens]--;
                for (int ones = 0; ones <= 9; ones += 2) {
                    if (!mp[ones])
                        continue;
                    mp[ones]--;
                    int num = (hunds * 100) + (tens * 10) + (ones);
                    ans.emplace_back(num);
                    mp[ones]++;
                }
                mp[tens]++;
            }
            mp[hunds]++;
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
