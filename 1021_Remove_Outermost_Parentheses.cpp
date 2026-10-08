class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;
        int n = s.length();
        stack<char> st;

        for (int i = 0; i < n; i++) {
            if (s[i] == ')')
                st.pop();

            if (!st.empty())
                ans += s[i];

            if (s[i] == '(')
                st.push(s[i]);
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
