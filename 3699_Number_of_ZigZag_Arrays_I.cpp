class Solution {
public:
    const int MOD = 1e9 + 7;
    int zigZagArrays(int n, int l, int r) {
        int len = r - l + 1;
        vector<int> dp1(len, 1);
        vector<int> dp2(len, 1);
        vector<int> sum1(len + 1, 0);
        vector<int> sum2(len + 1, 0);

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < len; j++) {
                sum1[j + 1] = (sum1[j] + dp1[j]) % MOD;
                sum2[j + 1] = (sum2[j] + dp2[j]) % MOD;
            }

            for (int j = 0; j < len; j++) {
                dp1[j] = (sum2[len] - sum2[j + 1] + MOD) % MOD;
                dp2[j] = sum1[j];
            }
        }

        auto op = [this](int acc, int x) { return (acc + x) % MOD; };
        auto ans1 = reduce(dp1.begin(), dp1.end(), 0, op);
        auto ans2 = reduce(dp2.begin(), dp2.end(), 0, op);

        return (ans1 + ans2) % MOD;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
