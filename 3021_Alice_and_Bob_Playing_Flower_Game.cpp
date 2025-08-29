class Solution {
public:
    long long flowerGame(int n, int m) {
        return 1LL * ((n + 1) / 2) * (m / 2) + 1LL * (n / 2) * ((m + 1) / 2);
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
