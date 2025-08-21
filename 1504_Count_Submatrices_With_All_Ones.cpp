class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();

        int ans = 0;

        for (int i = 0; i < m; i++) {

            vector<int> temp(n, 1);
            for (int j = i; j < m; j++) {

                for (int col = 0; col < n; col++)
                    temp[col] = temp[col] & mat[j][col];

                ans += cntSubmatrices(temp);
            }
        }
        return ans;
    }

private:
    int cntSubmatrices(vector<int>& temp) {
        int one = 0;
        int totalSubs = 0;

        for (int& num : temp) {
            if (num == 0)
                one = 0;
            else
                one++;

            totalSubs += one;
        }
        return totalSubs;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
