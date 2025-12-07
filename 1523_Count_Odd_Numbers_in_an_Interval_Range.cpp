class Solution {
public:
    int countOdds(int low, int high) {
        int nums = high - low;

        int ans = nums / 2;

        return (low % 2 != 0 || high % 2 != 0) ? ans + 1 : ans;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
