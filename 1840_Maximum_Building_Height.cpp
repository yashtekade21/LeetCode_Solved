class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        restrictions.push_back({1, 0});
        restrictions.push_back({n, n - 1});
        sort(restrictions.begin(), restrictions.end());

        for (int i = 1; i < restrictions.size(); i++)
            restrictions[i][1] =
                min(restrictions[i][1], restrictions[i - 1][1] +
                                            restrictions[i][0] -
                                            restrictions[i - 1][0]);

        for (int i = restrictions.size() - 2; i >= 0; i--)
            restrictions[i][1] =
                min(restrictions[i][1], restrictions[i + 1][1] +
                                            restrictions[i + 1][0] -
                                            restrictions[i][0]);

        int ans = 0;
        for (int i = 0; i + 1 < restrictions.size(); i++) {
            int d = restrictions[i + 1][0] - restrictions[i][0];
            ans =
                max(ans, (restrictions[i][1] + restrictions[i + 1][1] + d) / 2);
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
