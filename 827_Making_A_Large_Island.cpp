class Solution {
public:
    vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int largest_size = 0;
        int uniq_id = 2; // cannot take 0 & 1 becoz they are already in grid;
        unordered_map<int, int> mp;
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && !vis[i][j]) {
                    int cur_size = dfs(grid, i, j, vis, uniq_id);
                    largest_size = max(largest_size, cur_size);
                    mp[uniq_id] = cur_size;
                    uniq_id++;
                }
            }
        }

        if (largest_size == (n * n))
            return largest_size;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    unordered_set<int> unique_islands;
                    int cur_size = 1;

                    for (auto& d : dir) {
                        int i_ = i + d[0];
                        int j_ = j + d[1];

                        if (i_ >= 0 && i_ < n && j_ >= 0 && j_ < n &&
                            grid[i_][j_] != 0)
                            unique_islands.insert(grid[i_][j_]);
                    }

                    for (int id : unique_islands)
                        cur_size += mp[id];

                    largest_size = max(largest_size, cur_size);
                }
            }
        }
        return largest_size;
    }

private:
    int dfs(vector<vector<int>>& grid, int u, int v, vector<vector<bool>>& vis,
            int uniq_id) {
        int n = grid.size();
        if (u < 0 || u > n - 1 || v < 0 || v > n - 1 || grid[u][v] == 0 ||
            vis[u][v])
            return 0;

        vis[u][v] = true;
        grid[u][v] = uniq_id;
        int size = 1;

        for (auto& d : dir) {
            int u_ = u + d[0];
            int v_ = v + d[1];

            size += dfs(grid, u_, v_, vis, uniq_id);
        }
        return size;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
