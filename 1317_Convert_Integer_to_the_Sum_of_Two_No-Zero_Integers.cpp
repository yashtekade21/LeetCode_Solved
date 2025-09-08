class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        int num1, num2;
        for (int i = 1; i < n; i++) {
            num1 = i;
            num2 = n - i;
            if (!containsZero(num1) && !containsZero(num2) && num1 + num2 == n)
                break;
        }

        return {num1, num2};
    }

private:
    bool containsZero(int n) {
        while (n > 0) {
            if (n % 10 == 0)
                return true;
            n /= 10;
        }
        return false;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
