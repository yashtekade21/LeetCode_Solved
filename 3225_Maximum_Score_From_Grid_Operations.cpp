class Solution {
public:
    int n;
    vector<vector<vector<long long>>> dp;

    long long maximumScore(vector<vector<int>>& grid) {
        n = grid.size();

        dp = vector<vector<vector<long long>>>(
            2, vector<vector<long long>>(n + 1, vector<long long>(n + 1, -1)));

        vector<vector<long long>> colPrefSum(n + 1,
                                             vector<long long>(n + 1, 0));

        for (int col = 1; col <= n; col++) {
            for (int row = 1; row <= n; row++) {
                colPrefSum[row][col] =
                    colPrefSum[row - 1][col] + grid[row - 1][col - 1];
            }
        }

        return solve(false, 0, 0, grid, colPrefSum);
    }

private:
    long long solve(bool prevTaken, int prevHeight, int col,
                    vector<vector<int>>& grid,
                    vector<vector<long long>>& colPrefSum) {

        if (col == n) {
            return 0;
        }

        long long result = 0;

        if (dp[prevTaken][prevHeight][col] != -1) {
            return dp[prevTaken][prevHeight][col];
        }

        for (int height = 0; height <= n; height++) {
            long long prevColScore = 0;
            long long currColScore = 0;

            if (!prevTaken && col - 1 >= 0 && height > prevHeight) {
                prevColScore +=
                    colPrefSum[height][col] - colPrefSum[prevHeight][col];
            }

            if (prevHeight > height) {
                currColScore += colPrefSum[prevHeight][col + 1] -
                                colPrefSum[height][col + 1];
            }

            long long currColScoreTaken =
                currColScore + prevColScore +
                solve(true, height, col + 1, grid, colPrefSum);
            long long currColScoreNotTaken =
                prevColScore + solve(false, height, col + 1, grid, colPrefSum);

            result = max({result, currColScoreTaken, currColScoreNotTaken});
        }

        return dp[prevTaken][prevHeight][col] = result;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
