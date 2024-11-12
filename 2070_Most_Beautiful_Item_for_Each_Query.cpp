class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items,
                              vector<int>& queries) {
        sort(items.begin(), items.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[0] < b[0];
             });

        vector<pair<int, int>> new_queries;
        int n = queries.size();
        for (int i = 0; i < n; i++)
            new_queries.emplace_back(queries[i], i);
        sort(new_queries.begin(), new_queries.end());

        vector<int> ans(n, 0);
        int max_bea = 0, j = 0;
        for (auto x : new_queries) {
            while (j < items.size() && items[j][0] <= x.first) {
                max_bea = max(max_bea, items[j][1]);
                j++;
            }
            ans[x.second] = max_bea;
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
