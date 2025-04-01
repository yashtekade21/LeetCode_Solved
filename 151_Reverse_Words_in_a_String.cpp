class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();

        reverse(s.begin(),s.end());

        int l=0,r=0,i=0;

        while(i<n){
            while(i < n && s[i] == ' ')
                i++;

            if(i == n)
                break;
            
            while(i<n && s[i] != ' '){
                s[r] = s[i];
                r++;
                i++;
            }

            reverse(s.begin()+l,s.begin()+r);
            s[r] = ' ';
            r++;
            i++;
            l = r;
        }
        s.resize(r-1);
        return s;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
