class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 1 && i > 0)
                    matrix[i][j] += matrix[i - 1][j];
            }

            vector<int> currRow = matrix[i];
            sort(begin(currRow), end(currRow), greater<int>());
            for (int j = 0; j < m; j++) {
                int base = (j + 1);
                int height = currRow[j];

                ans = max(ans, base * height);
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
