class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        int size = n * m;
        k %= size;

        if (k == 0) return grid;

        auto reverse = [&](int l, int r) {
            while (l < r) {
                swap(grid[l / m][l % m], grid[r / m][r % m]);
                l++;
                r--;
            }
        };

        reverse(0, size - 1);
        reverse(0, k - 1);
        reverse(k, size - 1);

        return grid;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
