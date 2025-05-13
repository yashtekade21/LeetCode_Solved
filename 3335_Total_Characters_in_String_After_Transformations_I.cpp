class Solution {
public:
    const int MOD = 1e9 + 7;
    int lengthAfterTransformations(string s, int t) {
        vector<int> mp(26, 0);
        int n = s.length();
        int ans = 0;

        for (int i = 0; i < n; i++)
            mp[s[i] - 'a']++;

        for (int i = 0; i < t; i++) {
            vector<int> temp(26, 0);
            for (int j = 0; j < 26; j++) {
                int freq = mp[j];
                char ch = j + 'a';
                if (freq == 0)
                    continue;

                if (ch != 'z') {
                    temp[(ch + 1) - 'a'] = (temp[(ch + 1) - 'a'] + mp[ch - 'a']) % MOD;
                } else {
                    temp[0] = (temp[0] + mp[ch - 'a']) % MOD; // a
                    temp[1] = (temp[1] + mp[ch - 'a']) % MOD; // b
                }
            }
            mp = move(temp);
        }

        for (auto& freq : mp)
            ans = (ans + freq) % MOD;

        return ans;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
