class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> ans;

        for(int i=0;i<words.size();i++){
            for(char& ch:words[i]){
                if(ch == x){
                    ans.emplace_back(i);
                    break;
                }
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
