class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int pref_size = pref.length();
        int n = words.size();
        int ans=0;

        for(int i=0;i<n;i++){
            if(pref_size > words[i].length())
                continue;
            if(words[i].substr(0,pref_size) == pref){
                ans++;
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
