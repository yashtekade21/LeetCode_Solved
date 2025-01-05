class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.length();

        vector<int> diff_arr(n,0);

        for(auto& shift:shifts){
            int l = shift[0];
            int r = shift[1];
            int dir = shift[2] == 0 ? -1 : 1;

            diff_arr[l] += dir;
            if(r+1 < n)
                diff_arr[r+1] += (-1*dir);
        }

        for(int i=1;i<diff_arr.size();i++){
            diff_arr[i] += diff_arr[i-1];
        }

        for(int i=0;i<n;i++){
            int shift_val = diff_arr[i]%26;
            if(shift_val < 0)
                shift_val += 26;

            s[i] = (((s[i]-'a') + shift_val)%26) + 'a';
        }
        return s;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
