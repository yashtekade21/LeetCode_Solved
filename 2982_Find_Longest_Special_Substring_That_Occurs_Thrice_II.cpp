class Solution {
public:
    int maximumLength(string s) {
        int n=s.length(),l=0;
        vector<vector<int>> table(26,vector<int>(n+1,0));
        
        char prev_ch = s[0];
        for(int i=0;i<n;i++){
            char ch=s[i];
            if(ch == prev_ch){
                l++;
                table[ch-'a'][l]++;
            }
            else{
                l=1;
                table[ch-'a'][l]++;
                prev_ch = ch;
            }
        }
        int ans=0;
        for(int i=0;i<26;i++){
            int cum_freq = 0;
            for(int j=n;j>=1;j--){
                cum_freq += table[i][j];
                if(cum_freq >= 3){
                    ans = max(ans,j);
                    break;
                }
            }
        }
        
        if(ans == 0)
            return -1;
            
        return ans;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
