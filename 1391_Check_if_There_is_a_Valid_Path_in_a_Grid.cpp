class Solution {
public:
    int m, n;
    unordered_map<int, vector<vector<int>>> dirs = {
        {1, {{0, -1}, {0, 1}}},  {2, {{-1, 0}, {1, 0}}},
        {3, {{0, -1}, {1, 0}}},  {4, {{0, 1}, {1, 0}}},
        {5, {{0, -1}, {-1, 0}}}, {6, {{-1, 0}, {0, 1}}}};
    bool hasValidPath(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        return DFS(grid, 0, 0, visited);
    }

private:
    bool DFS(vector<vector<int>>& grid, int i, int j,
             vector<vector<bool>>& visited) {
        if (i == m - 1 && j == n - 1)
            return true;

        visited[i][j] = true;

        for (auto& dir : dirs[grid[i][j]]) {
            int nxt_i = i + dir[0], nxt_j = j + dir[1];

            if (nxt_i >= 0 && nxt_i < m && nxt_j >= 0 && nxt_j < n &&
                !visited[nxt_i][nxt_j]) {
                for (auto& prevDir : dirs[grid[nxt_i][nxt_j]]) {
                    if (nxt_i + prevDir[0] == i && nxt_j + prevDir[1] == j) {
                        if (DFS(grid, nxt_i, nxt_j, visited))
                            return true;
                    }
                }
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
