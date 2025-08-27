class Solution {
public:
    vector<vector<int>> dir = {{1, 1}, {1, -1}, {-1, -1}, {-1, 1}};
    int m, n;
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    for (int d = 0; d < dir.size(); d++) {
                        bool turned = false;
                        ans = max(1 + solve(2, i, j, d, turned, grid), ans);
                    }
                }
            }
        }
        return ans;
    }

private:
    int solve(int reqVal, int i, int j, int d, bool turned,
              vector<vector<int>>& grid) {
        int i_next = i + dir[d][0];
        int j_next = j + dir[d][1];

        int len = 0;
        if (i_next < 0 || i_next > m - 1 || j_next < 0 || j_next > n - 1 ||
            grid[i_next][j_next] != reqVal) {
            return len;
        }

        int sameDir =
            1 + solve(reqVal == 2 ? 0 : 2, i_next, j_next, d, turned, grid);
        len = max(len, sameDir);

        if (!turned) {
            turned = true;
            int turnDir = 1 + solve(reqVal == 2 ? 0 : 2, i_next, j_next,
                                    (d + 1) % dir.size(), turned, grid);
            len = max(len, turnDir);
        }
        return len;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
