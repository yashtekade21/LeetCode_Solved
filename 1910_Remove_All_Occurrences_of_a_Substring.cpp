class Solution {
public:
    string removeOccurrences(string s, string pat) {
        int m = s.length();
        int n = pat.length();

        stack<char> st;
        for(int i=0;i<m;i++){
            st.push(s[i]);
            if(st.size() >= n && check_pat(st,pat,n)){
                for(int j = n-1;j >=0;j--)
                    st.pop();
            }
        }

        string ans = "";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());

        return ans;
    }

private:
    bool check_pat(stack<char>& st,string& pat, int n){
        stack<char> temp_st = st;

        for(int i = n-1; i >= 0 ;i--){
            if(temp_st.top() != pat[i])
                return false;
            temp_st.pop();
        }
        return true;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
