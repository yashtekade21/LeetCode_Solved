class Solution {
public:
    string processStr(string s) {
        string ans;
        for (auto& ch : s) {
            if (ch == '*') {
                if (!ans.empty())
                    ans.pop_back();
            } else if (ch == '#')
                ans += ans;
            else if (ch == '%')
                reverse(ans.begin(), ans.end());
            else
                ans += ch;
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
