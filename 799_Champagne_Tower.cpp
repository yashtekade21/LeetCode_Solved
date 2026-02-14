class Solution {
public:
    vector<vector<double>> dp;
    double champagneTower(int poured, int query_row, int query_glass) {
        dp.assign(101, vector<double>(101, -1));
        return min(1.0, solve(poured, query_row, query_glass));
    }

private:
    double solve(int fill, int i, int j) {
        if (i < 0 || j < 0 || i < j)
            return 0.0;

        if (i == 0 && j == 0)
            return fill;

        if (dp[i][j] != -1)
            return dp[i][j];

        double fromLeft = (solve(fill, i - 1, j - 1) - 1) / 2.0;
        double fromRight = (solve(fill, i - 1, j) - 1) / 2.0;

        if (fromLeft < 0)
            fromLeft = 0.0;

        if (fromRight < 0)
            fromRight = 0.0;

        return dp[i][j] = fromLeft + fromRight;
    }
};
