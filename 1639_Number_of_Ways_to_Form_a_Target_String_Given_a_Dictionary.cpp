class Solution {
public:
    int m, k;
    int dp[1001][1001]; 
    const int MOD = 1e9 + 7;

    int numWays(vector<string>& words, string target) {
        m = words[0].size();
        k = target.size();
        
        vector<vector<long long>> freq(26, vector<long long>(m, 0));
        memset(dp, -1, sizeof(dp));
        
        for (int j = 0; j < m; j++) {
            for (const auto& word : words) {
                char ch = word[j];
                freq[ch - 'a'][j]++;
            }
        }
        return calc_no_of_ways(freq, target, 0, 0);
    }

private:
    int calc_no_of_ways(vector<vector<long long>>& freq, string& t, int i, int j) {
        if (i == k) 
            return 1;
        if (j == m) 
            return 0;
        if (dp[i][j] != -1) 
            return dp[i][j];
        
        long long  add_j = (freq[t[i] - 'a'][j] * calc_no_of_ways(freq, t, i + 1, j + 1)) % MOD;
        long long not_add_j = calc_no_of_ways(freq, t, i, j + 1) % MOD;

        return dp[i][j] = (add_j + not_add_j) % MOD;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
