class Solution {
public:
    int n, m;
    int minCost(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();

        vector<vector<int>> result(n, vector<int>(m, INT_MAX));

        dijkstra_algo(0, 0, grid, result);

        return result[n - 1][m - 1];
    }

private:
    vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    void dijkstra_algo(int i, int j, vector<vector<int>>& grid,
                       vector<vector<int>>& result) {
                        
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        pq.push({0, i, j});
        result[i][j] = 0;

        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();

            int cur_cost = top[0];
            int i_dir = top[1];
            int j_dir = top[2];

            if (cur_cost > result[i_dir][j_dir])
                continue;
            
            for (int d = 0; d <= 3; d++) {
                int i_next = i_dir + dir[d][0];
                int j_next = j_dir + dir[d][1];

                if (i_next >= 0 && i_next < n && j_next >= 0 && j_next < m) {
                    int grid_dir = grid[i_dir][j_dir];
                    int dir_cost = (grid_dir != d + 1) ? 1 : 0;

                    int new_cost = cur_cost + dir_cost;

                    if (new_cost < result[i_next][j_next]) {
                        result[i_next][j_next] = new_cost;
                        pq.push({new_cost, i_next, j_next});
                    }
                }
            }
        }
        return;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
