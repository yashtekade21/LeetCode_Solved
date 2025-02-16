class Solution {
public:
    vector<int> constructDistancedSequence(int n) {
        vector<int> result(2 * n - 1, 0);
        vector<bool> vis(n+1, false);

        solve(result, vis, n, 0); // 0 -> index

        return result;
    }

private:
    bool solve(vector<int>& result, vector<bool>& vis, int n, int idx) {
        if (idx > result.size() - 1)
            return true;

        if (result[idx] != 0) {
            return solve(result, vis, n, idx + 1);
        }

        for (int num = n; num >= 1; num--) {
            if (!vis[num]) {
                vis[num] = true;
                result[idx] = num;

                if (num == 1) {
                    if (solve(result, vis, n, idx + 1))
                        return true;
                } else {
                    int j = idx + result[idx];

                    if (j < result.size() && result[j] == 0) {
                        result[j] = num;
                        if (solve(result, vis, n, idx + 1))
                            return true;

                        result[j] = 0;
                    }
                }

                vis[num] = false;
                result[idx] = 0;
            }
        }
        return false;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
