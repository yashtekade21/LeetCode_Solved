class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.length();
        vector<long long> numUpto(n), cumSum(n, 0), nonZero(n), pow10(n + 1, 0);
        int q = queries.size();
        vector<int> ans(q);

        numUpto[0] = s[0] - '0';
        cumSum[0] = s[0] - '0';
        nonZero[0] = s[0] != '0' ? 1 : 0;
        pow10[0] = 1;

        for (int i = 1; i <= n; i++)
            pow10[i] = (pow10[i - 1] * 10) % MOD;

        for (int i = 1; i < n; i++) {
            int digit = s[i] - '0';
            cumSum[i] = cumSum[i - 1] + digit;
            nonZero[i] = nonZero[i - 1] + ((digit != 0) ? 1 : 0);
            if (digit == 0) {
                numUpto[i] = numUpto[i - 1];
                continue;
            }
            numUpto[i] = (numUpto[i - 1] * 10 + digit) % MOD;
        }

        for (int i = 0; i < q; i++) {
            int s = queries[i][0];
            int e = queries[i][1];

            int startCount = (s == 0) ? 0 : nonZero[s - 1];
            long long numBefore = (s == 0) ? 0 : numUpto[s - 1];

            int endCount = nonZero[e];
            int subStrLen = endCount - startCount;

            if (subStrLen == 0) {
                ans[i] = 0;
                continue;
            }

            long long x =
                (numUpto[e] - (numBefore * pow10[subStrLen] % MOD) + MOD) % MOD;
            long long sum = cumSum[e] - ((s == 0) ? 0 : cumSum[s - 1]);

            ans[i] = (int)((x * sum) % MOD);
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
