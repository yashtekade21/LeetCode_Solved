class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int odd = 0, even = 0;
        for (int i = 1; i <= 2 * n; i = i + 2) {
            odd += i;
            even += (i + 1);
        }

        return __gcd(odd, even);
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
