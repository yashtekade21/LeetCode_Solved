class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int ans = 0;
        for (int num = left; num <= right; num++) {
            int setBits = __builtin_popcount(num);
            if (checkPrime(setBits))
                ans++;
        }
        return ans;
    }

private:
    bool checkPrime(int n) {
        if (n <= 1)
            return false;
        int cnt = 0;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0)
                cnt++;
        }
        return cnt > 0 ? false : true;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
