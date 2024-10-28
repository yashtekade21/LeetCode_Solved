class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int low = 0, high = m - 1;

        while (low <= high) {
            int mid = (low + high) / 2;
            int row_max = maxIndex(mat, n, m, mid);

            int left_el = -1, right_el = -1;
            if (mid - 1 >= 0)
                left_el = mat[row_max][mid - 1];
            if (mid + 1 < m)
                right_el = mat[row_max][mid + 1];

            if (mat[row_max][mid] > left_el && mat[row_max][mid] > right_el)
                return {row_max, mid};
            else if (mat[row_max][mid] > left_el)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return {-1, -1};
    }

private:
    int maxIndex(vector<vector<int>> arr, int n, int m, int mid) {
        int maxi = -1, index = -1;
        for (int i = 0; i < n; i++) {
            if (arr[i][mid] > maxi) {
                maxi = arr[i][mid];
                index = i;
            }
        }
        return index;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
