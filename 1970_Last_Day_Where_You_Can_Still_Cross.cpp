class Solution {
public:
    int n, m;
    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        n = row;
        m = col;

        int n = cells.size();

        int l = 0;
        int r = cells.size() - 1;
        int lastDay = 0;

        while (l <= r) {

            int mid = l + (r - l) / 2;

            if (canCross(cells, mid)) {
                lastDay = mid + 1;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return lastDay;
    }

private:
    bool bfs(vector<vector<int>>& grid, int i, int j) {

        queue<pair<int, int>> que;
        que.push({i, j});
        grid[i][j] = 1;

        while (!que.empty()) {

            auto temp = que.front();
            que.pop();

            int x = temp.first;
            int y = temp.second;

            if (x == n - 1)
                return true;

            for (vector<int>& dir : directions) {

                int new_x = x + dir[0];
                int new_y = y + dir[1];

                if (new_x >= 0 && new_x < n && new_y >= 0 && new_y < m &&
                    grid[new_x][new_y] == 0) {
                    que.push({new_x, new_y});
                    grid[new_x][new_y] = true;
                }
            }
        }

        return false;
    }

    bool canCross(vector<vector<int>>& cells, int day) {
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i <= day; ++i) {
            int r = cells[i][0] - 1;
            int c = cells[i][1] - 1;

            grid[r][c] = 1;
        }

        for (int j = 0; j < m; j++) {
            if (grid[0][j] == 0 && bfs(grid, 0, j)) {
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
