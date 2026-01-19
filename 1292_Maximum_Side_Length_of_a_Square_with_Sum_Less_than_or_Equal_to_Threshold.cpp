class Solution {
public:
    vector<vector<int>> prefSum;
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n = mat.size(), m = mat[0].size();

        prefSum.assign(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                prefSum[i][j] = (i > 0 ? prefSum[i - 1][j] : 0) +
                                (j > 0 ? prefSum[i][j - 1] : 0) -
                                ((i > 0 && j > 0) ? prefSum[i - 1][j - 1] : 0) +
                                mat[i][j];
            }
        }

        int maxSide = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int sqSide = 0; sqSide < min(n - i, m - j); sqSide++) {
                    int i_next = i + sqSide;
                    int j_next = j + sqSide;

                    int sum = findSum(i, j, i_next, j_next);

                    if (sum <= threshold)
                        maxSide = max(maxSide, sqSide + 1);
                    else
                        break;
                }
            }
        }
        return maxSide;
    }

private:
    int findSum(int i1, int j1, int i2, int j2) {
        int sum = prefSum[i2][j2];
        if (i1 > 0)
            sum -= prefSum[i1 - 1][j2];

        if (j1 > 0)
            sum -= prefSum[i2][j1 - 1];

        if (i1 > 0 && j1 > 0)
            sum += prefSum[i1 - 1][j1 - 1];

        return sum;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
