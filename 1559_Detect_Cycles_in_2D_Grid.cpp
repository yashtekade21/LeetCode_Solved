class Solution {
public:
    vector<vector<int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    int m, n;
    bool containsCycle(vector<vector<char>>& grid) {
        m = grid.size(), n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j] && hasCycle(i, j, i, j, grid, visited))
                    return true;
            }
        }
        return false;
    }

private:
    bool hasCycle(int i, int j, int prev_i, int prev_j,
                  vector<vector<char>>& grid, vector<vector<bool>>& visited) {
        if (visited[i][j])
            return true;

        visited[i][j] = true;

        for (auto& dir : dirs) {
            int nxt_i = i + dir[0];
            int nxt_j = j + dir[1];

            if (nxt_i >= 0 && nxt_i < m && nxt_j >= 0 && nxt_j < n &&
                grid[nxt_i][nxt_j] == grid[i][j]) {
                if (nxt_i == prev_i && nxt_j == prev_j)
                    continue;

                if (hasCycle(nxt_i, nxt_j, i, j, grid, visited))
                    return true;
            }
        }
        return false;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
