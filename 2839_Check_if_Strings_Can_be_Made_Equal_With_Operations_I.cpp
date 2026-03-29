class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        int n = s1.length();

        for (int i = 0; i < 2; i++) {
            if ((s1[i] != s2[i] || s1[i + 2] != s2[i + 2]) &&
                (s1[i] != s2[i + 2] || s1[i + 2] != s2[i]))
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
