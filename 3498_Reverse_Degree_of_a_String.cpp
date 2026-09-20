class Solution {
public:
    int reverseDegree(string s) {
        int n = s.length();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            int chRevPos = 26 - (s[i] - 'a');
            ans += (chRevPos * (i + 1));
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
