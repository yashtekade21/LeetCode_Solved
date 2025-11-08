class Solution {
public:
    int minimumOneBitOperations(int n) {
        if (n == 0)
            return 0;

        vector<long long> DP(31, 0);
        DP[0] = 1;

        for (int i = 1; i <= 30; i++)
            DP[i] = 2 * DP[i - 1] + 1;

        int ans = 0;
        int sign = 1;

        for (int i = 30; i >= 0; i--) {
            int ith_bit = (1 << i) & n;
            if (ith_bit) {
                if (sign > 0)
                    ans += DP[i];
                else
                    ans -= DP[i];

                sign *= -1;
            }
        }
        return ans;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
