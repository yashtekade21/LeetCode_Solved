class Solution {
public:
    int maxScore(string s) {
        int n = s.length();
        int zero=0,one=0,max_score=INT_MIN;

        one = count(s.begin(),s.end(),'1');

        for(int i=0;i<n-1;i++){
            if(s[i] == '0')
                zero++;
            else
                one--;

            max_score = max(max_score,zero+one);
        }
        return max_score;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
