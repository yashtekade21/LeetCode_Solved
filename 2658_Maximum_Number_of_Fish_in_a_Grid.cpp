class Solution {
public:
    int n, m;
    vector<vector<int>> dir = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    int findMaxFish(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        int max_fish = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] > 0)
                    max_fish = max(max_fish, bfs(grid, i, j));
            }
        }
        return max_fish;
    }

private:
    int bfs(vector<vector<int>>& grid, int i, int j) {
        int fish_cnt = grid[i][j];
        grid[i][j] = 0;

        queue<pair<int, int>> q;
        q.push({i, j});

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (auto& d : dir) {
                int i_ = x + d[0];
                int j_ = y + d[1];

                if (i_ < 0 || i_ > n - 1 || j_ < 0 || j_ > m - 1 ||
                    grid[i_][j_] == 0)
                    continue;

                q.push({i_, j_});
                fish_cnt += grid[i_][j_];
                grid[i_][j_] = 0;
            }
        }
        return fish_cnt;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
