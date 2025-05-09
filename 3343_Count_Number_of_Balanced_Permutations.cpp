class Solution {
public:
    const int MOD = 1e9 + 7;
    long long totalSum = 0, totalPermPossible = 0;
    int n;

    int countBalancedPermutations(string num) {
        n = num.size();
        vector<int> mp(10, 0);
        for (int i = 0; i < n; i++) {
            totalSum += (num[i] - '0');
            mp[num[i] - '0']++;
        }

        if (totalSum % 2 == 1)
            return 0;

        vector<long long> factorial(n + 1, 1);
        fact(factorial);

        vector<long long> fermatFactorial(n + 1, 1);
        fermatTheorem(fermatFactorial, factorial);

        totalPermPossible =
            (long long)(factorial[(n + 1) / 2] * factorial[n / 2]) % MOD;

        int number = 0, evenIdxCnt = 0, curSum = 0;
        vector<vector<vector<int>>> dp(
            10, vector<vector<int>>(
                    (n + 1) / 2 + 1,
                    vector<int>(totalSum + 1, -1))); // +1 dues to indexing
        return solve(number, evenIdxCnt, curSum, mp, factorial, fermatFactorial,
                     dp);
    }

private:
    int solve(int number, int evenIdxCnt, int curSum, vector<int>& mp,
              vector<long long>& factorial, vector<long long>& fermatFactorial,
              vector<vector<vector<int>>>& dp) {
        if (number == 10) {
            if (curSum == totalSum / 2 && evenIdxCnt == (n + 1) / 2)
                return totalPermPossible;
            return 0;
        }

        if (dp[number][evenIdxCnt][curSum] != -1) {
            return dp[number][evenIdxCnt][curSum];
        }
        int ways = 0;
        for (int freq = 0; freq <= min((n + 1) / 2 - evenIdxCnt, mp[number]);
             freq++) {
            int evenPosCnt = freq;
            int oddPosCnt = mp[number] - evenPosCnt;

            long long duplicates =
                (fermatFactorial[evenPosCnt] * fermatFactorial[oddPosCnt]) %
                MOD;

            long long val = solve(number + 1, evenIdxCnt + evenPosCnt,
                                  curSum + number * freq, mp, factorial,
                                  fermatFactorial, dp);

            ways = (ways + (val * duplicates) % MOD) % MOD;
        }
        return dp[number][evenIdxCnt][curSum] = ways;
    }

    void fact(vector<long long>& factorial) {
        for (int i = 2; i <= n; i++)
            factorial[i] = (i * factorial[i - 1]) % MOD;
    }

    long long power(long long base, long long exp) {
        if (exp == 0)
            return 1;

        long long half = power(base, exp / 2);
        if (exp % 2 == 0)
            return (half * half) % MOD;

        return ((half * half) % MOD * base) % MOD;
    }

    void fermatTheorem(vector<long long>& fermatFactorial,
                       vector<long long>& factorial) {
        for (int i = 0; i <= n; i++)
            fermatFactorial[i] = power(factorial[i], MOD - 2) % MOD;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
