class Solution {
public:
    string makeFancyString(string s) {
        int n = s.length();
        string ans = "";

        ans += s[0];
        int freq = 1;

        for (int i = 1; i < n; i++) {
            if (s[i - 1] == s[i] && freq < 2) {
                freq++;
                ans += s[i];
            } else if (s[i - 1] != s[i]) {
                freq = 1;
                ans += s[i];
            }
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
