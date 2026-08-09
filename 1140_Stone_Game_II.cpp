class Solution {
public:
    int n;
    vector<vector<vector<int>>> dp;
    int solveForAlice(vector<int>& piles, int p, int i, int M) {
        if (i >= n)
            return 0;

        if (dp[p][i][M] != -1)
            return dp[p][i][M];

        int ans = (p == 1) ? -1 : INT_MAX;

        int stones = 0;

        for (int x = 1; x <= min(2 * M, n - i); x++) {

            stones += piles[i + x - 1];

            if (p == 1)
                ans = max(ans,
                          stones + solveForAlice(piles, 0, i + x, max(M, x)));
            else
                ans = min(ans, solveForAlice(piles, 1, i + x, max(M, x)));
        }

        return dp[p][i][M] = ans;
    }

    int stoneGameII(vector<int>& piles) {
        n = piles.size();

        dp.resize(2,vector<vector<int>>(101,vector<int>(101,-1)));
        
        return solveForAlice(piles, 1, 0, 1);
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
