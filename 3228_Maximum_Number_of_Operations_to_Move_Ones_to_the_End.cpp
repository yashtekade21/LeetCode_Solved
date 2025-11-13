class Solution {
public:
    int maxOperations(string s) {
        int n = s.length();
        int cntOnes = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            cntOnes += (s[i] == '1') ? 1 : 0;
            if (i + 1 < n && s[i] == '0' && s[i + 1] == '1') {
                ans += cntOnes;
            }
        }
        if (s[n - 1] == '0')
            ans += cntOnes;

        return ans;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
