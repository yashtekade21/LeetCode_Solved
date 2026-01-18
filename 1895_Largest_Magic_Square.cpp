class Solution {
public:
    vector<vector<int>> rowSum, colSum;
    int largestMagicSquare(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        rowSum.assign(n, vector<int>(m));
        colSum.assign(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            rowSum[i][0] = grid[i][0];
            for (int j = 1; j < m; j++)
                rowSum[i][j] = rowSum[i][j - 1] + grid[i][j];
        }

        for (int j = 0; j < m; j++) {
            colSum[0][j] = grid[0][j];
            for (int i = 1; i < n; i++)
                colSum[i][j] = colSum[i - 1][j] + grid[i][j];
        }

        for (int side = min(n, m); side >= 2; side--) {
            for (int i = 0; i + side <= n; i++) {
                for (int j = 0; j + side <= m; j++) {
                    if (isMagical(grid, i, j, side))
                        return side;
                }
            }
        }
        return 1;
    }

private:
    bool isMagical(vector<vector<int>>& grid, int i, int j, int side) {
        long long target =
            rowSum[i][j + side - 1] - (j > 0 ? rowSum[i][j - 1] : 0);

        for (int r = i; r < i + side; r++) {
            long long curr =
                rowSum[r][j + side - 1] - (j > 0 ? rowSum[r][j - 1] : 0);
            if (curr != target)
                return false;
        }

        for (int c = j; c < j + side; c++) {
            long long curr =
                colSum[i + side - 1][c] - (i > 0 ? colSum[i - 1][c] : 0);
            if (curr != target)
                return false;
        }

        long long diag = 0, anti = 0;
        for (int k = 0; k < side; k++) {
            diag += grid[i + k][j + k];
            anti += grid[i + k][j + side - 1 - k];
        }

        return diag == target && anti == target;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
