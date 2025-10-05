class Solution {
public:
    int n, m;
    vector<vector<int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> ans;

        n = heights.size(), m = heights[0].size();

        vector<vector<bool>> pacific(n, vector<bool>(m, false));
        vector<vector<bool>> atlantic(n, vector<bool>(m, false));
        queue<pair<int, int>> q1;

        for (int i = 0; i < n; i++) {
            pacific[i][0] = true;
            q1.push({i, 0});
        }

        for (int j = 0; j < m; j++) {
            pacific[0][j] = true;
            q1.push({0, j});
        }
        bfs(heights, q1, pacific);

        queue<pair<int, int>> q2;
        for (int i = 0; i < n; i++) {
            atlantic[i][m - 1] = true;
            q2.push({i, m - 1});
        }

        for (int j = 0; j < m; j++) {
            atlantic[n - 1][j] = true;
            q2.push({n - 1, j});
        }
        bfs(heights, q2, atlantic);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (pacific[i][j] && atlantic[i][j])
                    ans.push_back({i, j});
            }
        }
        return ans;
    }

private:
    void bfs(vector<vector<int>>& heights, queue<pair<int, int>>& q,
             vector<vector<bool>>& visited) {
        while (!q.empty()) {
            auto i = q.front().first;
            auto j = q.front().second;
            q.pop();

            for (auto dir : dirs) {
                int i_next = i + dir[0];
                int j_next = j + dir[1];

                if (i_next < n && i_next >= 0 && j_next < m && j_next >= 0 &&
                    !visited[i_next][j_next]) {
                    if (heights[i_next][j_next] >= heights[i][j]) {
                        visited[i_next][j_next] = true;
                        q.push({i_next, j_next});
                    }
                }
            }
        }
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
