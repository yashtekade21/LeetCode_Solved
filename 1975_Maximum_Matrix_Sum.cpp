class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        long long ans = 0;

        int minNum = INT_MAX, negCnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] < 0)
                    negCnt++;

                minNum = min(minNum, abs(matrix[i][j]));
                ans += abs(matrix[i][j]);
            }
        }

        if (negCnt % 2 == 1)
            ans -= (minNum + minNum);
        return ans;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
