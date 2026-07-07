class Solution {
public:
    long long sumAndMultiply(int n) {
        long long x = 0, reversed = 0;
        long long sum = 0;

        int digitCnt = 1;

        while (n != 0) {
            int last = n % 10;
            n /= 10;

            if (last == 0)
                continue;

            reversed = reversed * 10 + last;
            sum += last;
        }

        while (reversed != 0) {
            int last = reversed % 10;
            x = x * 10 + last;
            reversed /= 10;
        }
        return (long long)x * sum;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
