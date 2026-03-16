class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        set<int> st;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                manageSet(st, grid[i][j]); // for zero rhombus sum

                for (int side = 1; i - side >= 0 && i + side < n &&
                                   j - side >= 0 && j + side < m;
                     side++) {
                    long long sum = 0;

                    for (int k = 0; k < side; k++) {
                        sum += grid[i - side + k][j + k];
                        sum += grid[i + k][j + side - k];
                        sum += grid[i + side - k][j - k];
                        sum += grid[i - k][j - side + k];
                    }

                    manageSet(st, sum);
                }
            }
        }
        return vector<int>(st.rbegin(), st.rend());
    }

private:
    void manageSet(set<int>& st, int val) {
        st.insert(val);
        if (st.size() > 3)
            st.erase(st.begin());
        return;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
