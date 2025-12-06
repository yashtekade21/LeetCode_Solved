class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<long long> dp;
    int n;
    int countPartitions(vector<int>& nums, int k) {
        n = nums.size();
        dp.resize(n + 1, -1);
        vector<long long> prefix(n + 1, 0);

        dp[0] = 1;
        prefix[0] = 1;

        multiset<int> st;

        int j = 0;

        for (int i = 0; i < n; i++) {
            st.insert(nums[i]);

            while (j <= i && ((*st.rbegin() - *st.begin()) > k))
                st.erase(st.find(nums[j++]));

            if (j > 0)
                dp[i + 1] = (prefix[i] - prefix[j - 1] + MOD) % MOD;
            else
                dp[i + 1] = prefix[i] % MOD;
            prefix[i + 1] = (prefix[i] + dp[i + 1]) % MOD;
        }
        return dp[n];
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
