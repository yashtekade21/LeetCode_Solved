class Solution {
public:
    int findKthNumber(int n, int k) {
        long long ans = 1, i = 1;

        while (i < k) {
            long long index = jump(ans, n);
            if (i + index <= k) {
                ans += 1;
                i += index;
            } else {
                ans *= 10;
                i++;
            }
        }
        return ans;
    }

private:
    long long jump(long long ans, int n) {
        long long sib = ans + 1,steps = 0;

        while (ans <= n) {
            steps += min(sib , static_cast<long long>(n + 1)) - ans;
            ans *= 10;
            sib *= 10;
        }
        return steps;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
