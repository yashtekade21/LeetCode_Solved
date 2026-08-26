class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.length();
        int i = 0, oneCnt = 0;
        string ans;

        for (int j = 0; j < n; j++) {
            oneCnt += (s[j] == '1' ? 1 : 0);

            while (oneCnt > k || s[i] == '0') {
                oneCnt -= (s[i] == '1' ? 1 : 0);
                i++;
            }

            if (oneCnt == k) {
                string subString = s.substr(i, j - i + 1);
                if (ans.empty() || j - i + 1 < ans.length() ||
                    (j - i + 1 == ans.length() && subString < ans)) {

                    ans = subString;
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
