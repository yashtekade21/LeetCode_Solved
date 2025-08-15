class Solution {
public:
    bool isPowerOfFour(int n) { return solve(n, 0); }

private:
    bool solve(int n, int exp) {
        long long powVal = pow(4, exp);

        if (powVal > n)
            return false;
        if (powVal == n)
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
