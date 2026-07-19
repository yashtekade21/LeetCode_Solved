class Solution {
public:
    string smallestSubsequence(string s) {
        vector<bool> used(26, false);
        vector<int> lastIdx(26, -1);
        string ans;

        for (int i = 0; i < s.length(); i++) {
            int idx = s[i] - 'a';
            lastIdx[idx] = i;
        }

        for (int i = 0; i < s.length(); i++) {
            if (used[s[i] - 'a'])
                continue;

            while (ans.length() > 0 && ans.back() > s[i] &&
                   lastIdx[ans.back() - 'a'] > i) {
                used[ans.back() - 'a'] = false;
                ans.pop_back();
            }
            used[s[i] - 'a'] = true;
            ans += s[i];
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
