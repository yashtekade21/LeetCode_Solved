class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> ans;

        int m = mat.size(), n = mat[0].size();
        map<int, vector<int>> mp;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                mp[i + j].push_back(mat[i][j]);
            }
        }

        for (auto& it : mp) {
            vector<int> vec = it.second;
            if (it.first % 2 == 0)
                reverse(vec.begin(), vec.end());

            ans.insert(ans.end(), vec.begin(), vec.end());
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
