class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();
        int ans = 0;
        stack<char> st;

        for (int i = 0; i < n; i++) {
            if (!st.empty() && s[i] == 'a' && st.top() == 'b') {
                st.pop();
                ans++;
            }

            else {
                st.push(s[i]);
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
