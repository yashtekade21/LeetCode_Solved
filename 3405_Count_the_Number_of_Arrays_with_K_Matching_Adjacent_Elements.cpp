const int MOD = 1e9 + 7;
vector<long long> fact;
vector<long long> fermatFact;
class Solution {
public:
    int countGoodArrays(int n, int m, int k) {
        calcFactorial(n);
        calcInverseFactorial(n);

        int ans = (nCr(n - 1, k) * m) % MOD;
        ans = (ans * power(m - 1, n - k - 1)) % MOD;

        return ans;
    }

private:
    long long power(long long base, long long exp) {
        if (exp == 0)
            return 1;

        long long half = power(base, exp / 2);
        long long result = (half * half) % MOD;
        if (exp % 2 == 1)
            return (result * base) % MOD;

        return result;
    }

    void calcInverseFactorial(int n) {
        fermatFact.resize(n + 1, 1);

        for (int i = 0; i <= n; i++)
            fermatFact[i] = power(fact[i], MOD - 2);
    }

    void calcFactorial(int n) {
        fact.resize(n + 1, 1);

        for (int i = 2; i <= n; i++) {
            fact[i] = (fact[i - 1] * i) % MOD;
        }
    }

    long long nCr(int n, int r) {
        return fact[n] * fermatFact[n - r] % MOD * fermatFact[r] % MOD;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
