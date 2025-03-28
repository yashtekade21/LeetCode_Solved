class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int n = grid.size(), m = grid[0].size(), q = queries.size();

        vector<int> ans(q, 0);

        vector<pair<int, int>> sortedQueries;
        for (int i = 0; i < q; i++)
            sortedQueries.push_back({queries[i], i});

        sort(sortedQueries.begin(), sortedQueries.end());

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>
            pq;
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        pq.push({grid[0][0], 0, 0});
        vis[0][0] = true;
        int points = 0;

        for (auto& [query, i] : sortedQueries) {
            ans[i] = bfs(grid, query, m, n, vis, points, pq);
        }
        return ans;
    }

private:
    vector<vector<int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    int bfs(auto& grid, int query, int m, int n, auto& vis, int& points,
            auto& pq) {
        while (!pq.empty() && pq.top()[0] < query) {
            int i = pq.top()[1], j = pq.top()[2];
            pq.pop();
            points++;

            for (auto& dir : dirs) {
                int x = i + dir[0], y = j + dir[1];
                if (x >= 0 && x < n && y >= 0 && y < m && !vis[x][y]) {
                    pq.push({grid[x][y], x, y});
                    vis[x][y] = true;
                }
            }
        }
        return points;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
