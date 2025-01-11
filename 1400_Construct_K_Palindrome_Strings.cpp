class Solution {
public:
    bool canConstruct(string s, int k) {
        int n=s.length();
        if(n < k)
            return false;
        if(n==k)
            return true;

        vector<int> freq(26,0);
        for(auto& ch:s){
            freq[ch-'a']++;
        }

        int cnt_odd=0;
        for(int i=0;i<26;i++){
            if(freq[i]%2)
                cnt_odd++;
            if(cnt_odd > k)
                return false;
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
