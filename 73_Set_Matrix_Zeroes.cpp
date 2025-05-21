class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int> stRow, stCol;
        int m = matrix.size(), n = matrix[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    stRow.insert(i);
                    stCol.insert(j);
                }
            }
        }

        for (auto& idx : stRow) {
            for (int i = 0; i < n; i++)
                matrix[idx][i] = 0;
        }

        for (auto& idx : stCol) {
            for (int i = 0; i < m; i++)
                matrix[i][idx] = 0;
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
