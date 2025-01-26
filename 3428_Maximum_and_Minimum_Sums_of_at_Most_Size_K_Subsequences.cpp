class Solution {
public:
    const int MOD = 1e9 + 7;
    int minMaxSums(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<vector<int>> nCr(n + 1, vector<int>(k + 1, 0));

        nCr[0][0] = 1;

        for (int i = 1; i <= n; i++) {
            nCr[i][0] = 1;
            for (int j = 1; j <= k; j++)
                nCr[i][j] = (nCr[i - 1][j - 1] + nCr[i - 1][j]) % MOD;
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            int num_of_subseq = 0;
            for (int j = 0; j < k; j++)
                if (i >= j)
                    num_of_subseq = (num_of_subseq + nCr[i][j]) % MOD;

            ans = (ans + (long long)(nums[i] + nums[n - i - 1]) * num_of_subseq) %
                    MOD;
            
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
