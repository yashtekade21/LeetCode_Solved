class Solution {
public:
    int n;
    vector<vector<int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    int swimInWater(vector<vector<int>>& grid) {
        n = grid.size();
        int l = 0, r = n * n - 1;
        int ans = 0;

        while (l <= r) {
            int mid = (l + r) / 2;

            vector<vector<bool>> visited(n, vector<bool>(n, false));
            if (solve(0, 0, mid, grid, visited)) {
                ans = mid;
                r = mid - 1;
            } else
                l = mid + 1;
        }
        return ans;
    }

private:
    bool solve(int s, int e, int curTime, vector<vector<int>>& grid,
               vector<vector<bool>>& visited) {
        queue<pair<int, int>> q;

        if (grid[s][e] <= curTime) {
            q.push({s, e});
            visited[s][e] = true;
        }

        while (!q.empty()) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            if (i == n - 1 && j == n - 1)
                return true;

            for (auto& dir : dirs) {
                int i_next = i + dir[0], j_next = j + dir[1];

                if (i_next < n && i_next >= 0 && j_next < n && j_next >= 0 &&
                    grid[i_next][j_next] <= curTime &&
                    !visited[i_next][j_next]) {
                    visited[i_next][j_next] = true;
                    q.push({i_next, j_next});
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
