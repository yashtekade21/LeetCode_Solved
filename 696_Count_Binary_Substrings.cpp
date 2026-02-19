class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.length();
        int i = 1, prev = 0, cur = 1;
        int ans = 0;

        while (i < n) {
            if (s[i] == s[i - 1]) {
                cur++;
            } else {
                ans += min(cur, prev);
                prev = cur;
                cur = 1;
            }
            i++;
        }
        ans += min(cur, prev);
        return ans;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
