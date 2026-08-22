class Solution {
public:
    bool checkDivisibility(int n) {
        int temp = n;
        int prod = 1, sum = 0;

        while (temp > 0) {
            int lastDigit = temp % 10;
            temp /= 10;

            sum += lastDigit;
            prod *= lastDigit;
        }

        return n % (sum + prod) == 0;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
