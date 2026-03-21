class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x,
                                         int y, int k) {
        int m = grid.size(), n = grid[0].size();

        int i = x, j = x + k - 1;

        while (i < j) {
            for (int c = y; c < y + k; c++)
                swap(grid[i][c], grid[j][c]);
            i++;
            j--;
        }

        return grid;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
