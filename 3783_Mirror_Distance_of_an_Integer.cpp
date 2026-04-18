class Solution {
public:
    int mirrorDistance(int n) { return abs(n - reverse(n)); }

private:
    int reverse(int num) {
        int revNum = 0;
        while (num > 0) {
            revNum = (revNum * 10) + num % 10;
            num /= 10;
        }
        return revNum;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
