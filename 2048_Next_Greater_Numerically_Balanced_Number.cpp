class Solution {
public:
    int nextBeautifulNumber(int n) {
        for (int num = n + 1; num <= 1224444; num++) {
            if (isBalanced(num))
                return num;
        }
        return 0;
    }

private:
    bool isBalanced(int n) {
        vector<int> freq(10, 0);
        while (n != 0) {
            int rem = n % 10;
            freq[rem]++;
            n /= 10;
        }

        for (int num = 0; num <= 9; num++) {
            if (num > 0 && freq[num] == 0)
                continue;
            else if (num != freq[num])
                return false;
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
