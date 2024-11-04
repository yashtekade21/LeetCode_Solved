class Solution {
public:
    string compressedString(string word) {
        string comp = "";
        int count = 0;
        char c;
        for(int i=0;i<word.length();i++){
            if(count < 9 && c == word[i])
                count++;
            else{
                if(count>0){
                    comp += to_string(count);
                    comp+= c;
                }
                c = word[i];
                count = 1;
            }
        }
        comp += to_string(count);
        comp += c;
        return comp;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
