class Solution {
public:
    int n, m;
    int countNegatives(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int ans = 0;

        for (auto& vec : grid)
            ans += binSearch(vec);

        return ans;
    }

private:
    int binSearch(vector<int>& vec) {
        int l = 0, r = m - 1;

        while (l <= r) {
            int mid = (l + r) / 2;

            if (vec[mid] >= 0) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return m - l;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
