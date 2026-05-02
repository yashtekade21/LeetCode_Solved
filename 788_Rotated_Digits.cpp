class Solution {
public:
    int rotatedDigits(int n) {
        int ans = 0;
        vector<int> dp(n + 1, 0);

        for (int i = 0; i <= n; i++) {
            if (i < 10) {
                if (i == 0 || i == 1 || i == 8)
                    dp[i] = 1;
                else if (i == 2 || i == 5 || i == 6 || i == 9) {
                    dp[i] = 2;
                    ans++;
                }
            } else {
                int left = dp[i / 10], last = dp[i % 10];
                if (left == 1 && last == 1)
                    dp[i] = 1;
                else if (left >= 1 && last >= 1) {
                    dp[i] = 2;
                    ans++;
                }
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
