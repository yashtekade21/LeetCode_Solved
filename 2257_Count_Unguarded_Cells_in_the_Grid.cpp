class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards,
                       vector<vector<int>>& walls) {
        vector<vector<int>> mat(m, vector<int>(n, 0));
        // 1 = guard, 2 = wall, 3 = guard can see
        for (auto g : guards)
            mat[g[0]][g[1]] = 1;
        for (auto w : walls)
            mat[w[0]][w[1]] = 2;

        for (auto g : guards)
            check_guardable(g[0], g[1], mat, m, n);

        int ans = 0;
        for (auto i : mat) {
            for (auto j : i) {
                if (j == 0)
                    ans++;
            }
        }
        return ans;
    }

private:
    void check_guardable(int r, int c, vector<vector<int>>& mat, int m, int n) {
        for (int i = r + 1; i < m; i++) {
            if (mat[i][c] == 1 || mat[i][c] == 2)
                break;
            mat[i][c] = 3;
        }
        for (int i = r - 1; i >= 0; i--) {
            if (mat[i][c] == 1 || mat[i][c] == 2)
                break;
            mat[i][c] = 3;
        }
        for (int i = c + 1; i < n; i++) {
            if (mat[r][i] == 1 || mat[r][i] == 2)
                break;
            mat[r][i] = 3;
        }
        for (int i = c - 1; i >= 0; i--) {
            if (mat[r][i] == 1 || mat[r][i] == 2)
                break;
            mat[r][i] = 3;
        }
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
