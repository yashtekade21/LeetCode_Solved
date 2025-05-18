class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<vector<int>> dp;
    vector<string> allRYGCombs;
    int numOfWays(int n) {
        generateRYGCombs("", 3, '@');

        int totalCombs = allRYGCombs.size();
        dp = vector<vector<int>>(n + 1, vector<int>(totalCombs + 1, -1));

        int ans = 0;
        for (int i = 0; i < totalCombs; i++)
            ans = (ans + solve(i, n - 1, 3)) % MOD;
        return ans;
    }

private:
    int solve(int prevIdx, int remRows, int maxLen) {
        if (remRows == 0)
            return 1;

        if (dp[remRows][prevIdx] != -1)
            return dp[remRows][prevIdx];

        int ways = 0;
        string prevRGBComb = allRYGCombs[prevIdx];

        for (int i = 0; i < allRYGCombs.size(); i++) {
            if (i == prevIdx)
                continue;

            string curRGBComb = allRYGCombs[i];

            if (isEqual(curRGBComb, prevRGBComb, maxLen))
                ways = (ways + solve(i, remRows - 1, maxLen)) % MOD;
        }

        return dp[remRows][prevIdx] = ways;
    }

    bool isEqual(string& str1, string& str2, int m) {
        for (int i = 0; i < m; i++) {
            if (str1[i] == str2[i])
                return false;
        }
        return true;
    }

    void generateRYGCombs(string curState, int len, char prevColor) {
        if (len == 0) {
            allRYGCombs.push_back(curState);
            return;
        }

        for (auto ch : {'R', 'Y', 'G'}) {
            if (prevColor == ch)
                continue;

            generateRYGCombs(curState + ch, len - 1, ch);
        }
        return;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
