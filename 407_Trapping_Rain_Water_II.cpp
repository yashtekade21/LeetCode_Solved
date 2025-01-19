class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int n = heightMap.size(), m = heightMap[0].size();

        priority_queue<vector<int>, vector<vector<int>>, greater<>> boundary;
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++) {
            for (int j : {0, m - 1}) {
                boundary.push({heightMap[i][j], i, j});
                vis[i][j] = true;
            }
        }

        for (int j = 0; j < m; j++) {
            for (int i : {0, n - 1}) {
                boundary.push({heightMap[i][j], i, j});
                vis[i][j] = true;
            }
        }

        int total_water = 0;
        vector<vector<int>> dir = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

        while (!boundary.empty()) {
            auto top = boundary.top();
            boundary.pop();

            int height = top[0], i = top[1], j = top[2];

            for (int d = 0; d <= 3; d++) {
                int i_next = i + dir[d][0];
                int j_next = j + dir[d][1];

                if (i_next >= 0 && i_next < n && j_next >= 0 && j_next < m &&
                    !vis[i_next][j_next]) {
                    total_water += max(height - heightMap[i_next][j_next], 0);

                    boundary.push({max(height,heightMap[i_next][j_next]),i_next,j_next});
                    vis[i_next][j_next] = true;
                }
            }
        }
        return total_water;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
