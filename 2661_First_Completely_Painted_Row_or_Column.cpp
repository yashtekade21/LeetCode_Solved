class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();

        unordered_map<int, int> locate;
        for (int i = 0; i < arr.size(); i++)
            locate[arr[i]] = i;

        int ans = INT_MAX;

        for (int i = 0; i < n; i++) {
            int max_idx = INT_MIN;
            for (int j = 0; j < m; j++) {
                int val = mat[i][j];
                max_idx = max(max_idx, locate[val]);
            }
            ans = min(ans, max_idx);
        }

        for (int i = 0; i < m; i++) {
            int max_idx = INT_MIN;
            for (int j = 0; j < n; j++) {
                int val = mat[j][i];
                max_idx = max(max_idx, locate[val]);
            }
            ans = min(ans, max_idx);
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
