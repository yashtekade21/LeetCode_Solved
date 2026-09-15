class Solution {
public:
    vector<vector<bool>> isPalindrome;

    int maxPalindromes(string s, int k) {
        int n = s.size();
        if (k == 1)
            return n;

        isPalindrome.assign(n + 1, vector<bool>(n + 1));
        for (int L = 1; L <= n; L++) {
            for (int i = 0; i + L <= n; i++) {
                int j = i + L - 1;

                if (i == j) {
                    isPalindrome[i][i] = true;
                } else if (i + 1 == j) {
                    isPalindrome[i][j] = (s[i] == s[j]);
                } else {
                    isPalindrome[i][j] =
                        ((s[i] == s[j]) && isPalindrome[i + 1][j - 1] == true);
                }
            }
        }

        vector<vector<int>> dp(n, vector<int>(n, -1));

        return solve(s, k, 0, k - 1, dp);
    }

private:
    int solve(const string& s, int k, int i, int j, vector<vector<int>>& dp) {
        int n = s.size();
        if (i >= n || j >= n)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (isPalindrome[i][j]) {
            int growWindow = solve(s, k, i, j + 1, dp);
            int takeIt = 1 + solve(s, k, j + 1, j + k, dp);
            int slideWindow = solve(s, k, i + 1, j + 1, dp);

            return dp[i][j] = max({growWindow, takeIt, slideWindow});
        }

        int slideWindow = solve(s, k, i + 1, j + 1, dp);
        int growWindow = solve(s, k, i, j + 1, dp);

        return dp[i][j] = max(slideWindow, growWindow);
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
