class Solution {
public:
    bool isSubsequence(string s, string t) {
        int s1 = s.length(), t1 = t.length();

        int i = 0, j = 0;
        while (i < s1 && j < t1) {
            if (s[i] == t[j]) {
                i++;
            }
            j++;
        }
        return i == s1;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
