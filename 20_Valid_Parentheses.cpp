class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (char ch : s) {
            if (ch == '(' || ch == '[' || ch == '{') {
                st.push(ch);
            } else if (!st.empty() && ((ch == ')' && st.top() == '(') ||
                                       (ch == ']' && st.top() == '[') ||
                                       (ch == '}' && st.top() == '{'))) {
                st.pop();
            } else {
                return false;
            }
        }

        return st.empty();
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
