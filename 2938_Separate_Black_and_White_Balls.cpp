class Solution {
public:
    long long minimumSteps(string s) {
        int cur = 0,prev = 0;
        long long min_swap = 0;
        for(int i=0;i<s.length();i++){
            if(s[cur] == '0'){
                min_swap += cur - prev;
                prev++;
            }
            cur++;
        }
        return min_swap;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
