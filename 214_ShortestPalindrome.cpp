class Solution {
public:
    string shortestPalindrome(string s) {
        long long base =29, mod = (long)1e9+7,fh=0,rh=0,power = 1;
        int index = -1;

        for(int i=0;i<s.length();i++){
            fh = (fh*base + (s[i]-'a'+1))%mod;
            rh = (rh + (s[i]-'a'+1)*power)%mod;
            power = (power*base)%mod;

            if(rh == fh)
                index=i;
        }
        string ans = s.substr(index+1);
        reverse(ans.begin(),ans.end());

        ans.append(s);

        return ans;
    }
};
static const auto kds = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();
