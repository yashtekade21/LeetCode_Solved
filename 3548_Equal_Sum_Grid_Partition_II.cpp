class Solution {
public:
    typedef long long ll;
    ll total = 0;
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        for (int i = 0; i < m; i++)
            total += accumulate(grid[i].begin(), grid[i].end(), 0LL);

        if (checkCuts(grid))
            return true;

        reverse(grid.begin(), grid.end());

        if (checkCuts(grid))
            return true;

        vector<vector<int>> transposeGrid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                transposeGrid[i][j] = grid[j][i];
            }
        }

        if (checkCuts(transposeGrid))
            return true;

        reverse(transposeGrid.begin(), transposeGrid.end());

        if (checkCuts(transposeGrid))
            return true;

        return false;
    }

private:
    bool checkCuts(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        unordered_set<ll> st;
        ll top = 0;

        for (int i = 0; i < m - 1; i++) {
            for (int j = 0; j < n; j++) {
                st.insert(grid[i][j]);
                top += grid[i][j];
            }

            ll bottom = total - top;
            ll diff = top - bottom;

            if (diff == 0 || diff == (ll)grid[i][0] || diff == (ll)grid[0][0] ||
                diff == (ll)grid[0][n - 1])
                return true;

            if (i > 0 && n > 1 && st.count(diff))
                return true;
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
