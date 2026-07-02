class Solution {
public:
    vector<vector<int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> ans(n, vector<int>(m, INT_MAX));

        deque<pair<int, int>> dq;
        ans[0][0] = grid[0][0];
        dq.push_front({0, 0});

        while (!dq.empty()) {
            auto [cur_r, cur_c] = dq.front();
            dq.pop_front();

            for (auto& dir : dirs) {
                int nxt_r = cur_r + dir[0];
                int nxt_c = cur_c + dir[1];

                if (nxt_r < 0 || nxt_r >= n || nxt_c < 0 || nxt_c >= m)
                    continue;

                if (ans[cur_r][cur_c] + grid[nxt_r][nxt_c] <
                    ans[nxt_r][nxt_c]) {
                    ans[nxt_r][nxt_c] = ans[cur_r][cur_c] + grid[nxt_r][nxt_c];

                    if (grid[nxt_r][nxt_c] == 0)
                        dq.push_front({nxt_r, nxt_c});
                    else
                        dq.push_back({nxt_r, nxt_c});
                }
            }
        }

        int minHealth = ans[n - 1][m - 1];

        return health - minHealth > 0;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
