class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.length();

        vector<int> dp(n, 0);
        dp[0] = 1;
        int count = 0;

        for (int j = 1; j <= n - 1; j++) {
            if (j - minJump >= 0)
                count += dp[j - minJump];

            if (j - maxJump - 1 >= 0)
                count -= dp[j - maxJump - 1];

            if (count > 0 && s[j] == '0')
                dp[j] = 1;
        }

        return dp[n - 1] > 0;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
