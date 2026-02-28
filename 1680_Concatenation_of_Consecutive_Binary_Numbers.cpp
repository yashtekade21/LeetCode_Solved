class Solution {
public:
    const int MOD = 1e9 + 7;
    int concatenatedBinary(int n) {
        long ans = 0;

        for (int num = 1; num <= n; num++) {
            int digits = log2(num) + 1;

            ans = (((ans << digits) % MOD) + num) % MOD;
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
