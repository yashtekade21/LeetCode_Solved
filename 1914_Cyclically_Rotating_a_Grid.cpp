class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();

        int layers = min(m, n) / 2;

        for (int l = 0; l < layers; l++) {
            vector<int> nums;
            int top = l, bottom = m - l - 1, left = l, right = n - l - 1;

            for (int i = top; i <= right; i++)
                nums.push_back(grid[top][i]);

            for (int i = top + 1; i < bottom; i++)
                nums.push_back(grid[i][right]);

            for (int i = right; i >= left; i--)
                nums.push_back(grid[bottom][i]);

            for (int i = bottom - 1; i > top; i--)
                nums.push_back(grid[i][left]);

            int len = nums.size();
            int new_k = k % len;

            rotate(nums.begin(), nums.begin() + new_k, nums.end());

            int idx = 0;
            for (int i = left; i <= right; i++)
                grid[top][i] = nums[idx++];

            for (int i = top + 1; i < bottom; i++)
                grid[i][right] = nums[idx++];

            for (int i = right; i >= left; i--)
                grid[bottom][i] = nums[idx++];

            for (int i = bottom - 1; i > top; i--)
                grid[i][left] = nums[idx++];
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
