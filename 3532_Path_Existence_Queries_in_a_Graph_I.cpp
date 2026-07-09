class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff,
                                      vector<vector<int>>& queries) {
        vector<int> group(n, -1);
        vector<bool> ans;

        int id = 0;
        group[0] = id;
        for (int i = 1; i < n; i++) {
            if (nums[i] - nums[i - 1] > maxDiff)
                id++;

            group[i] = id;
        }

        for (auto& query : queries)
            ans.push_back(group[query[0]] == group[query[1]]);

        return ans;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
