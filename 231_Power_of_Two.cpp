class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0)
            return false;

        int num = n;
        while (num > 1) {
            if (num % 2 == 1)
                return false;
            num /= 2;
        }
        return true;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
