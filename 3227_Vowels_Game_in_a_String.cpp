class Solution {
public:
    bool doesAliceWin(string s) {
        int n = s.length();

        int vowelCnt = 0;

        for(char ch:s){
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
                vowelCnt++;
            }
        }

        if(vowelCnt == 0)
            return false;

        return true;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
