class Solution {
public:
    bool isPowerOfThree(int n) { return solve(n, 0); }

private:
    bool solve(int n, int exp) {
        long long powerVal = pow(3, exp);
        if (powerVal > n)
            return false;

        if (powerVal == n)
            return true;

        return solve(n, exp + 1);
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
