class Solution {
public:
    int punishmentNumber(int n) {
        int ans = 0;

        for (int num = 1; num <= n; num++) {
            int sq = num * num;

            string s = to_string(sq);
            vector<vector<int>> dp(s.length(), vector<int>(num + 1, -1));
            if (check_punish_num(s, num, 0, 0, dp)) {
                ans += sq;
            }
        }
        return ans;
    }

private:
    bool check_punish_num(string& s, int& num, int i, int cur_sum,
                          vector<vector<int>>& dp) {
        if (i == s.length()) {
            return cur_sum == num;
        }

        if (cur_sum > num) {
            return false;
        }

        if (dp[i][cur_sum] != -1)
            return dp[i][cur_sum];

        bool possible = false;
        for (int j = i; j < s.length(); j++) {
            string sub = s.substr(i, j - i + 1);
            int val = stoi(sub);

            possible =
                possible || check_punish_num(s, num, j + 1, cur_sum + val, dp);

            if (possible)
                return true;
        }
        return dp[i][cur_sum] = possible;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
