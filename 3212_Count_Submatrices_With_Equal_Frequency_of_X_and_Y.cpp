class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();

        vector<vector<long long>> prefSum(n, vector<long long>(m, 0)),
            xCount(n, vector<long long>(m, 0));
        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                prefSum[i][j] = (grid[i][j] == 'X') - (grid[i][j] == 'Y');
                xCount[i][j] = grid[i][j] == 'X';

                if (i - 1 >= 0) {
                    prefSum[i][j] += prefSum[i - 1][j];
                    xCount[i][j] += xCount[i - 1][j];
                }

                if (j - 1 >= 0) {
                    prefSum[i][j] += prefSum[i][j - 1];
                    xCount[i][j] += xCount[i][j - 1];
                }

                if (i - 1 >= 0 && j - 1 >= 0) {
                    prefSum[i][j] -= prefSum[i - 1][j - 1];
                    xCount[i][j] -= xCount[i - 1][j - 1];
                }

                if (prefSum[i][j] == 0 && xCount[i][j])
                    ans++;
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
