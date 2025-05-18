class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<string> allRGBCombs;
    vector<vector<int>> dp;
    int colorTheGrid(int m, int n) {
        generateRGBCombs("", m, '@');
        int totalCombs = allRGBCombs.size();
        dp = vector<vector<int>>(n + 1,vector<int>(totalCombs + 1,-1));

        int ans = 0;
        for (int i = 0; i < totalCombs; i++)
            ans = (ans + solve(i, n - 1, m)) % MOD;
        return ans;
    }

private:
    int solve(int prevIdx, int remCols, int maxLen) {
        if (remCols == 0)
            return 1;

        if(dp[remCols][prevIdx] != -1)
            return dp[remCols][prevIdx];
        int ways = 0;
        string prevRGBComb = allRGBCombs[prevIdx];

        for (int i = 0; i < allRGBCombs.size(); i++) {
            if (i == prevIdx)
                continue;

            string curRGBComb = allRGBCombs[i];

            if (isEqual(curRGBComb, prevRGBComb, maxLen))
                ways = (ways + solve(i, remCols - 1, maxLen)) % MOD;
        }

        return dp[remCols][prevIdx] = ways;
    }

    bool isEqual(string& str1, string& str2, int m) {
        for (int i = 0; i < m; i++) {
            if (str1[i] == str2[i])
                return false;
        }
        return true;
    }
    void generateRGBCombs(string curState, int len, char prevColor) {
        if (len == 0) {
            allRGBCombs.push_back(curState);
            return;
        }

        for (auto ch : {'R', 'G', 'B'}) {
            if (prevColor == ch)
                continue;

            generateRGBCombs(curState + ch, len - 1, ch);
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
