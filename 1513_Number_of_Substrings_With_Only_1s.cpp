class Solution {
public:
    const int MOD = 1e9 + 7;
    int numSub(string s) {
        int n = s.length();
        int cntOnes = 0;
        int ans = 0;

        for (int i = 0; i < n; i++) {
            while (s[i] == '1') {
                cntOnes++;
                i++;
            }

            long long a = cntOnes % MOD;
            long long b = (cntOnes + 1) % MOD;
            long long possibleSubstr = (a * b / 2) % MOD;
            ans = (ans + possibleSubstr) % MOD;
            cntOnes = 0;
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
