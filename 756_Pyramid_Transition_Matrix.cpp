class Solution {
public:
    unordered_map<string, bool> dp;
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_map<string, vector<char>> mp;

        for (auto& pattern : allowed)
            mp[pattern.substr(0, 2)].push_back(pattern[2]);

        return solve(bottom, "", 0, mp);
    }

private:
    bool solve(string curr, string next, int idx,
               unordered_map<string, vector<char>>& mp) {
        string key = curr + "-" + next + "-" + to_string(idx);

        if (curr.length() == 1)
            return dp[key] = true;

        if (idx + 1 == curr.length())
            return solve(next, "", 0, mp);

        if (dp.find(key) != dp.end())
            return dp[key];

        string pattLR = curr.substr(idx, 2);

        if (mp.find(pattLR) == mp.end())
            return dp[key] = false;

        for (auto& top : mp[pattLR]) {
            next += top;

            if (solve(curr, next, idx + 1, mp))
                return dp[key] = true;

            next.pop_back();
        }
        return dp[key] = false;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
