class Solution {
public:
    const int MOD = 1e9 + 7;
    int countGoodNumbers(long long n) {
        return power(5, (n + 1) / 2) * power(4, n / 2) % MOD;
    }

private:
    long long power(long long base, long long exp) {
        if (exp == 0)
            return 1;

        long long halfPower = power(base, exp / 2);
        if (exp % 2 == 0)
            return (halfPower * halfPower) % MOD;
        return (base * halfPower * halfPower) % MOD;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
