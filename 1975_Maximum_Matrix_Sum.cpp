class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long ans = 0;
        int neg_cnt = 0, mini = INT_MAX;

        for (auto r : matrix) {
            for (auto e : r) {
                ans += abs(e);
                mini = min(mini, abs(e));
                if (e < 0)
                    neg_cnt++;
            }
        }

        if (neg_cnt % 2 != 0)
            ans -= (2 * mini);

        return ans;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
