class Solution {
public:
    int m, n;
    vector<vector<int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    int countIslands(vector<vector<int>>& grid, int k) {
        int ans = 0;
        n = grid.size();
        m = grid[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] > 0) {
                    long long sum = bfs(grid, i, j);
                    if (sum % k == 0)
                        ans++;
                }
            }
        }

        return ans;
    }

private:
    long long bfs(vector<vector<int>>& grid, int sx, int sy) {
        long long sum = grid[sx][sy];
        queue<pair<int, int>> q;
        q.push({sx, sy});
        grid[sx][sy] = 0;

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (auto& dir : dirs) {
                int x_nxt = x + dir[0], y_nxt = y + dir[1];

                if (x_nxt >= 0 && x_nxt < n && y_nxt >= 0 && y_nxt < m &&
                    grid[x_nxt][y_nxt] != 0) {
                    q.push({x_nxt, y_nxt});
                    sum += grid[x_nxt][y_nxt];
                    grid[x_nxt][y_nxt] = 0;
                }
            }
        }

        return sum;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
