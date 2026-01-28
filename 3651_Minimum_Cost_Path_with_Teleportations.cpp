class Solution {
public:
    int n, m;
    int minCost(vector<vector<int>>& grid, int k) {
        n = grid.size(), m = grid[0].size();

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

        vector<pair<int, int>> cells;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cells.push_back({i, j});

        auto customSort = [&](auto a, auto b) {
            return grid[a.first][a.second] < grid[b.first][b.second];
        };

        sort(cells.begin(), cells.end(), customSort);

        int cellSize = cells.size();
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (i == n - 1 && j == m - 1) {
                    dist[i][j] = 0;
                    continue;
                }
                if (i + 1 < n)
                    dist[i][j] =
                        min(dist[i][j], dist[i + 1][j] + grid[i + 1][j]);
                if (j + 1 < m)
                    dist[i][j] =
                        min(dist[i][j], dist[i][j + 1] + grid[i][j + 1]);
            }
        }

        for (int t = 1; t <= k; t++) {
            int best = INT_MAX;
            vector<vector<int>> newDist = dist;

            for (int i = 0; i < cellSize; i++) {
                int r = cells[i].first;
                int c = cells[i].second;

                best = min(best, dist[r][c]);

                if (i + 1 < cellSize &&
                    grid[r][c] == grid[cells[i + 1].first][cells[i + 1].second])
                    continue;

                int j = i;
                while (j >= 0 &&
                       grid[cells[j].first][cells[j].second] == grid[r][c]) {
                    newDist[cells[j].first][cells[j].second] =
                        min(newDist[cells[j].first][cells[j].second], best);
                    j--;
                }
            }

            dist = newDist;
            for (int i = n - 1; i >= 0; i--) {
                for (int j = m - 1; j >= 0; j--) {
                    if (i == n - 1 && j == m - 1)
                        continue;
                    if (i + 1 < n)
                        dist[i][j] =
                            min(dist[i][j], dist[i + 1][j] + grid[i + 1][j]);
                    if (j + 1 < m)
                        dist[i][j] =
                            min(dist[i][j], dist[i][j + 1] + grid[i][j + 1]);
                }
            }
        }

        return dist[0][0];
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
