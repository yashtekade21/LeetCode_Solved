class Solution {
public:
    bool isCircularSentence(string sentence) {
        int n = sentence.length();
        if(sentence[0] != sentence[n-1])
            return false;

        for(int i=1;i<sentence.length()-1;i++){
            if(sentence[i] == ' '){
                if(tolower(sentence[i-1]) != tolower(sentence[i+1])){
                    return false;
                }
            }
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
