class Solution {
public:
    const int MOD = 1e9 + 7;

    int possibleStringCount(string word, int k) {
        if (k > word.length())
            return 0;

        vector<int> freq;
        int count = 1;
        for (int i = 1; i < word.length(); i++) {
            if (word[i] == word[i - 1])
                count++;
            else {
                freq.push_back(count);
                count = 1;
            }
        }
        freq.push_back(count);

        long long totalPossStr = 1;
        for (int& f : freq)
            totalPossStr = (totalPossStr * f) % MOD;

        int n = freq.size();
        if (n >= k)
            return totalPossStr;

        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

        for (int curLen = k - 1; curLen >= 0; curLen--)
            dp[n][curLen] = 1;

        for (int i = n - 1; i >= 0; i--) {

            vector<int> prefix(k + 1, 0);
            for (int h = 1; h <= k; h++) {
                prefix[h] = (prefix[h - 1] + dp[i + 1][h - 1]) % MOD;
            }

            for (int curLen = k - 1; curLen >= 0; curLen--) {

                int l = curLen + 1;
                int r = curLen + freq[i];

                if (r + 1 > k)
                    r = k - 1;

                if (l <= r)
                    dp[i][curLen] = (prefix[r + 1] - prefix[l] + MOD) % MOD;
            }
        }

        long long invalidCount = dp[0][0];

        return (totalPossStr - invalidCount + MOD) %
               MOD; // prevent negative technique
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
