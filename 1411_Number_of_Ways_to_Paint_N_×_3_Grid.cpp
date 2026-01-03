class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<vector<int>> dp;
    vector<string> opts = {"RYG", "RGY", "RYR", "RGR", "YRG", "YGR",
                           "YGY", "YRY", "GRY", "GYR", "GRG", "GYG"};
    int numOfWays(int n) {
        int ans = 0;
        dp.resize(n,vector<int>(12,-1));
        for (int i = 0; i < 12; i++)
            ans = (ans + solve(n - 1, i)) % MOD;

        return ans;
    }

private:
    int solve(int n, int prevIdx) {
        int res = 0;
        if (n == 0)
            return 1;
        
        if(dp[n][prevIdx] != -1)
            return dp[n][prevIdx];

        string lastPattern = opts[prevIdx];

        for (int curIdx = 0; curIdx < 12; curIdx++) {
            if (curIdx == prevIdx)
                continue;

            string curPattern = opts[curIdx];
            bool flag = false;

            for (int col = 0; col < 3; col++) {
                if (lastPattern[col] == curPattern[col]) {
                    flag = true;
                    break;
                }
            }

            if (!flag)
                res = (res + solve(n - 1, curIdx)) % MOD;
        }
        return dp[n][prevIdx]= res;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
