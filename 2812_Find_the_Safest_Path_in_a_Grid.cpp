class Solution {
public:
    int n;
    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        n = grid.size();

        vector<vector<int>> distNearestThief(n, vector<int>(n, -1));
        queue<pair<int, int>> que;
        vector<vector<bool>> visited(n, vector<bool>(n, false));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    que.push({i, j});
                    visited[i][j] = true;
                }
            }
        }

        int level = 0;
        while (!que.empty()) {
            int size = que.size();

            while (size--) {
                int cur_i = que.front().first;
                int cur_j = que.front().second;
                que.pop();
                distNearestThief[cur_i][cur_j] = level;
                for (vector<int>& dir : directions) {
                    int nxt_i = cur_i + dir[0];
                    int nxt_j = cur_j + dir[1];

                    if (nxt_i < 0 || nxt_i >= n || nxt_j < 0 || nxt_j >= n ||
                        visited[nxt_i][nxt_j]) {
                        continue;
                    }

                    que.push({nxt_i, nxt_j});
                    visited[nxt_i][nxt_j] = true;
                }
            }
            level++;
        }

        int l = 0;
        int r = 400;
        int ans = 0;

        while (l <= r) {
            int mid_sf = l + (r - l) / 2;

            if (check(distNearestThief, mid_sf)) {
                ans = mid_sf;
                l = mid_sf + 1;
            } else {
                r = mid_sf - 1;
            }
        }

        return ans;
    }

private:
    bool check(vector<vector<int>>& distNearestThief, int sf) {
        queue<pair<int, int>> que;

        vector<vector<bool>> visited(n, vector<bool>(n, false));
        que.push({0, 0});
        visited[0][0] = true;

        if (distNearestThief[0][0] < sf)
            return false;

        while (!que.empty()) {
            int cur_i = que.front().first;
            int cur_j = que.front().second;

            que.pop();
            if (cur_i == n - 1 && cur_j == n - 1)
                return true;

            for (vector<int>& dir : directions) {
                int nxt_i = cur_i + dir[0];
                int nxt_j = cur_j + dir[1];

                if (nxt_i >= 0 && nxt_i < n && nxt_j >= 0 && nxt_j < n &&
                    visited[nxt_i][nxt_j] != true) {
                    if (distNearestThief[nxt_i][nxt_j] < sf)
                        continue;

                    que.push({nxt_i, nxt_j});
                    visited[nxt_i][nxt_j] = true;
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
