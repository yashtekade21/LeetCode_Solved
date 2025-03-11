class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();

        int cntA = 0, cntB = 0, cntC = 0;
        int i = 0, j = 0;
        int ans = 0;

        while (j < n) {
            if (s[j] == 'a')
                cntA++;
            else if (s[j] == 'b')
                cntB++;
            else
                cntC++;

            while (i < n && cntA != 0 && cntB != 0 && cntC != 0) {
                ans += (n - j);
                if (s[i] == 'a')
                    cntA--;
                else if (s[i] == 'b')
                    cntB--;
                else
                    cntC--;
                i++;
            }
            j++;
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
