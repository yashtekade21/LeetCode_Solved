class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        int sub = INT_MAX, num1, num2;
        num1 = num2 = -1;

        vector<int> primes;
        for (int i = left; i <= right; i++) {
            if (isPrime(i)) {
                primes.emplace_back(i);
            }
        }

        if (primes.size() <= 1) {
            return {num1, num2};
        }

        for (int i = 0; i < primes.size() - 1; i++) {
            if (sub > abs(primes[i] - primes[i + 1])) {
                num1 = primes[i];
                num2 = primes[i + 1];
                sub = abs(primes[i] - primes[i + 1]);
            }
        }

        return {num1, num2};
    }

private:
    bool isPrime(int& n) {
        if (n <= 1)
            return false;
    
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0)
                return false;
        }
        return true;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
