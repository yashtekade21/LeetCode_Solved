class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        if (min(grid[0][1], grid[1][0]) > 1)
            return -1;
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>> pq;

        pq.push({0, {0, 0}});

        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> visit(m, vector<int>(n, 0));

        while (!pq.empty()) {
            auto it = pq.top();
            int t = it.first;
            int r = it.second.first;
            int c = it.second.second;
            pq.pop();

            if (r == m - 1 && c == n - 1)
                return t;

            int row[] = {0, -1, 0, 1};
            int col[] = {-1, 0, 1, 0};

            for (int i = 0; i < 4; i++) {
                int nxt_row = r + row[i];
                int nxt_col = c + col[i];
                if (nxt_row < 0 || nxt_col < 0 || nxt_row == m || nxt_col == n ||
                    visit[nxt_row][nxt_col] == 1) {
                    continue;
                }
                int wait = 0;
                if (abs(grid[nxt_row][nxt_col] - t) % 2 == 0) {
                    wait = 1;
                }
                int n_time = max(grid[nxt_row][nxt_col] + wait, t + 1);
                pq.push({n_time, {nxt_row, nxt_col}});
                visit[nxt_row][nxt_col] = 1;
            }
        }
        return 0;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();
