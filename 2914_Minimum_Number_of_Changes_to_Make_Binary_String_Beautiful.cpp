class Solution {
public:
    int minChanges(string s) {
        int n = s.length(),ans=0;

        for(int i=0;i<n;i+=2)
            if(s[i] != s[i+1])
                ans++;
        return ans;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
