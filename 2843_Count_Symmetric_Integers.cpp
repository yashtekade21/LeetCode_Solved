class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int ans = 0;

        for (int num = low; num <= high; num++) {
            if (num >= 10 && num <= 99 && num % 11 == 0)
                ans++;
            else if (num >= 1000 && num <= 9999) {
                int firstDigit = (num / 1000);
                int secondDigit = (num / 100) % 10;
                int thirdDigit = (num / 10) % 10;
                int lastDigit = num % 10;

                if (firstDigit + secondDigit == thirdDigit + lastDigit)
                    ans++;
            }
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
