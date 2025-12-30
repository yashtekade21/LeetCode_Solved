class Solution {
public:
    int n, m;
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        int ans = 0;

        for (int i = 0; i <= n - 3; i++) {
            for (int j = 0; j <= m - 3; j++) {
                if (isMagical(grid, i, j))
                    ans++;
            }
        }
        return ans;
    }

private:
    bool isMagical(vector<vector<int>>& grid, int i, int j) {
        unordered_set<int> st;

        for (int r = 0; r < 3; r++) {
            for (int c = 0; c < 3; c++) {
                int num = grid[r + i][c + j];
                if (num == 0 || num > 9 || st.find(num) != st.end())
                    return false;
                st.insert(num);
            }
        }

        long long sum = grid[i][j] + grid[i][j + 1] + grid[i][j + 2];

        for (int k = 0; k < 3; k++) {
            long long rowSum =
                grid[i + k][j] + grid[i + k][j + 1] + grid[i + k][j + 2];
            if (sum != rowSum)
                return false;

            long long colSum =
                grid[i][j + k] + grid[i + 1][j + k] + grid[i + 2][j + k];
            if (sum != colSum)
                return false;
        }

        long long diagSum =
            grid[i][j] + grid[i + 1][j + 1] + grid[i + 2][j + 2];
        if (sum != diagSum)
            return false;

        long long antiDiagSum =
            grid[i][j + 2] + grid[i + 1][j + 1] + grid[i + 2][j];
        if (sum != antiDiagSum)
            return false;

        return true;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
