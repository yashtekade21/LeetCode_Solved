class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> ans(m - k + 1, vector<int>(n - k + 1, INT_MAX));

        for (int i = 0; i < m - k + 1; i++) {
            for (int j = 0; j < n - k + 1; j++) {
                set<int> st;
                for (int r = i; r < i + k; r++) {
                    for (int c = j; c < j + k; c++) {
                        st.insert(grid[r][c]);
                    }
                }

                auto x = st.begin(), y = next(x);
                while (y != st.end()) {
                    ans[i][j] = min(ans[i][j], abs(*x - *y));
                    x = y;
                    y++;
                }
                if (st.size() == 1)
                    ans[i][j] = 0;
            }
        }
        return ans;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
