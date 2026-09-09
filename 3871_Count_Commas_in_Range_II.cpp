class Solution {
public:
    long long countCommas(long long n) {
        long long commas = 0;
        long long num = 1000;

        while (num <= n) {
            commas += (n - num + 1);
            num *= 1000;
        }
        return commas;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
