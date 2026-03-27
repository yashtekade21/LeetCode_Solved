class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int curIdx = j, futIdx;
                if (i % 2 == 0)
                    futIdx = (j + k) % n;
                else
                    futIdx = (j - k % n + n) % n;

                if (mat[i][curIdx] != mat[i][futIdx])
                    return false;
            }
        }
        return true;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
