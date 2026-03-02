class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int> zeros(n, 0);

        for (int i = 0; i < n; i++) {
            int cntZero = 0;
            for (int j = m - 1; j >= 0; j--) {
                if (grid[i][j] == 0)
                    cntZero++;
                else
                    break;
            }
            zeros[i] = cntZero;
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            int reqZero = n - i - 1;
            int j = i;

            while (j < m && zeros[j] < reqZero)
                j++;

            if (j == m)
                return -1;

            ans += j - i;

            while (j > i) {
                swap(zeros[j], zeros[j - 1]);
                j--;
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
