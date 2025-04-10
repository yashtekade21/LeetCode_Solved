class Solution {
public:
    string removeStars(string s) {
        string ans = "";
        stack<int> st;

        for (auto& ch : s) {
            if (ch == '*' && !st.empty()) {
                st.pop();
            } else {
                st.push(ch);
            }
        }
        
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
