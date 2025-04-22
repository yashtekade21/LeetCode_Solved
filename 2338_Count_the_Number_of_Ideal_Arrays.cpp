class Solution {
public:
    const int MOD = 1e9 + 7;
    int idealArrays(int n, int maxValue) {
        int ans = 0;
        vector<vector<int>> dp(maxValue + 1, vector<int>(15, 0));
        vector<int> cnt(15, 0);  // constraint = 10^4 < 2^14 so can take max upto 2^13 #taken 15 because need to write in size + 1
        vector<long long> fact(n + 1, 1);
        findFact(n, fact);

        for (int num = 1; num <= maxValue; num++)
            solve(num, cnt, dp);

        for (int size = 1; size < 15; size++) {
            if (n < size)
                break;

            if (cnt[size] != 0) {
                long long possible = fermatTheorem(n - 1, size - 1, fact);
                ans = (ans + (cnt[size] * possible) % MOD) % MOD;
            }
        }
        return ans;
    }

private:
    void solve(int m, vector<int>& cnt, vector<vector<int>>& dp) {
        if (dp[m][1] != 0)
            return;

        dp[m][1] = 1;
        cnt[1]++;
        for (int i = 2; i <= m; i++) {
            if (m % i == 0) {
                solve(m / i, cnt, dp);
                for (int size = 1; size < 15; size++) {
                    if (dp[m / i][size] != 0) {
                        dp[m][size + 1] += dp[m / i][size];
                        cnt[size + 1] += dp[m / i][size];
                    }
                }
            }
        }
    }

    int fermatTheorem(int n, int r, vector<long long>& fact) {
        if (r < 0 || r > n)
            return 0;

        long long x = fact[n];
        long long y = fact[r] * fact[n - r] % MOD;

        return x * power(y, MOD - 2) % MOD;
    }

    long long findFact(int num, vector<long long>& fact) {
        for (int i = 2; i <= num; i++)
            fact[i] = (fact[i - 1] * i) % MOD;

        return fact[num];
    }

    long long power(long long base, long long exp) {
        if (exp == 0)
            return 1;

        long long half = power(base, exp / 2);
        if (exp % 2 == 0)
            return (long long)((__int128)half * half % MOD);
        return (long long)((__int128)half * half * base % MOD);
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
