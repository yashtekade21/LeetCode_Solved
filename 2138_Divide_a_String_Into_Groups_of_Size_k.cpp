class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n = s.length();
        vector<string> ans;

        string temp = "";
        for(auto& ch:s){
            temp += ch;
            if(temp.length() == k){
                ans.push_back(temp);
                temp = "";
            }
        }

        if(!temp.empty() && temp.length() < k) {
            int x = k - temp.length();
            temp += string(x,fill);
            ans.push_back(temp);
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
