class Solution {
public:
    long long coloredCells(int n) {
        int time = 1;
        long long ans = 1;

        for (; time <= n; time++) {
            ans += 4 * (time - 1);
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
