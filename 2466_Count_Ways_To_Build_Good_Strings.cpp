class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<int> dp;
    Solution(): dp(100001,-1){};
    int countGoodStrings(int low, int high, int zero, int one) {
        return calc_strings(0, low, high, one, zero);
    }

private:
    int calc_strings(int len, int l, int h, int o, int z) {
        if (len > h)
            return 0;

        if(dp[len] != -1)
            return dp[len];
        bool add = 0;
        if (len >= l) // need not to check for h because already checked above
            add = 1;

        int take_one = calc_strings(len + o, l, h, o, z);
        int take_zero = calc_strings(len + z, l, h, o, z);

        return dp[len] = (add + take_one + take_zero)%MOD;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
