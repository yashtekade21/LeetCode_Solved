class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> ans(n, vector<int>(n, 0));

        for (auto& q : queries) {
            int r1 = q[0], c1 = q[1], r2 = q[2], c2 = q[3];
            for (int i = r1; i <= r2; i++) {
                ans[i][c1] += 1;
                if (c2 + 1 < n)
                    ans[i][c2 + 1] -= 1;
            }
        }

        for (int i = 0; i < n; i++) {
            int cumSum = ans[i][0];
            for (int j = 1; j < n; j++) {
                int temp = ans[i][j];
                ans[i][j] += cumSum;
                cumSum += temp;
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
