class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int w1 = word1.length(), w2 = word2.length();

        int i=0,j=0;
        string ans = "";
        while(i < w1 && j < w2){
            ans += word1[i++];
            ans += word2[j++];
        }

        if(i < w1){
            ans.append(word1.begin() + i,word1.end());
        }
        else{
            ans.append(word2.begin() + j,word2.end());
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
