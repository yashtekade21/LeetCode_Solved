class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans="";
        int idx = 0,n = spaces.size();
        for(int i=0;i<n;i++){
            ans += s.substr(idx,spaces[i]-idx);
            ans += ' ';
            idx = spaces[i];
        }
        ans += s.substr(idx);
        return ans;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
