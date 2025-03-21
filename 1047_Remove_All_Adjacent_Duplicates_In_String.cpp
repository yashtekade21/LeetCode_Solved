class Solution {
public:
    string removeDuplicates(string s) {
        int n = s.length();

        stack<char> st;
        for(int i=0;i<n;i++){
            if(!st.empty() && st.top() == s[i])
                st.pop();
            else
                st.push(s[i]);
        }

        string ans="";
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
