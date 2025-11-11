class Solution {
public:
    int q;
    vector<vector<vector<int>>> dp;
    int findMaxForm(vector<string>& strs, int m, int n) {
        q = strs.size();

        dp.resize(601,vector<vector<int>>(101,vector<int>(101,-1)));
        vector<pair<int, int>> vec(q);

        for (int i = 0; i < q; i++) {
            string s = strs[i];
            int one = 0, zero = 0;
            for (auto& ch : s) {
                one += (ch == '1' ? 1 : 0);
                zero += (ch == '0' ? 1 : 0);
            }
            vec[i] = {zero, one};
        }
        return solve(vec, 0, m, n);
    }

private:
    int solve(vector<pair<int, int>>& vec, int idx, int m, int n) {
        if ((m == 0 && n == 0) || (idx >= q))
            return 0;
        
        if(dp[idx][m][n] != -1)
            return dp[idx][m][n];
            
        int one = vec[idx].second;
        int zero = vec[idx].first;

        int take = 0;
        if (m >= zero && n >= one)
            take = 1 + solve(vec, idx + 1, m - zero, n - one);
        int not_take = solve(vec, idx + 1, m, n);

        return dp[idx][m][n] = max(take, not_take);
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
