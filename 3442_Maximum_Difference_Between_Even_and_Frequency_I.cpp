class Solution {
public:
    int maxDifference(string s) {
        vector<int> mp(26, 0);

        for (auto& ch : s)
            mp[ch - 'a']++;

        int a1 = 0, a2 = INT_MAX;
        for (auto& freq : mp) {
            if (freq == 0)
                continue;

            if (freq % 2 == 1)
                a1 = max(freq, a1);
            else
                a2 = min(freq, a2);
        }
        return a1 - a2;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
