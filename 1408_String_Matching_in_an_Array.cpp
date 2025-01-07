class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        int n = words.size();
        vector<string> ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j && search_str(words[i],words[j])){
                    ans.emplace_back(words[i]);
                    break;
                }
            }
        }
        return ans;
    }
private:
    bool search_str(string& pat, string& txt) {
        int m = pat.length(),n=txt.length();
        vector<int> LPS(m,0);        
        int i=0,j=0;
        
        LPS[i++] = 0;
        while(i < m){
            if(pat[i] == pat[j]){
                j++;
                LPS[i] = j;
                i++;
            }
            else{
                if(j != 0){
                    j = LPS[j-1];
                }
                else{
                    LPS[i] = 0;
                    i++;
                }
            }
            
        }
        
        i = 0,j =0;
        while(i < n){
            if(pat[j] == txt[i]){
                i++;
                j++;
            }
            if(j == m){
                return true;
            }
            else if(pat[j] != txt[i]){
                if(j != 0)
                    j = LPS[j-1];
                else
                    i++;
            }
        }
        return false;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
