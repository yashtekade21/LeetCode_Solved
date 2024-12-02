class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        vector<string> s;
        string temp="";
        int n = sentence.length(),m = searchWord.length();

        for(int i=0;i<n;i++){
            if(sentence[i] == ' '){
                s.push_back(temp);
                temp = "";
            }
            else
                temp += sentence[i];
        }
        s.push_back(temp);

        for(int i=0;i<s.size();i++)
            if(s[i].length() >= m && s[i].substr(0, m) == searchWord) 
                return i + 1;
        
        return -1;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
