class Solution {
public:
    int countCommas(int n) {
        if (n < 1000)
            return 0;

        return n - 999;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
