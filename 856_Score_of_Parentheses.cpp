class Solution {
public:
    int scoreOfParentheses(string s) {
        int ans = 0, depth = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(')
                depth++;
            else {
                depth--;
                if (s[i - 1] == '(')
                    ans += (1 << depth);
            }
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
