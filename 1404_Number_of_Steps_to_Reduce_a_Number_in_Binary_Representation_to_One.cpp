class Solution {
public:
    int numSteps(string s) {
        int ans = 0;
        while (s != "1") {
            int n = s.length();
            if (s[n - 1] == '1') {
                int i = n - 1;
                while (i >= 0 && s[i] == '1') {
                    s[i] = '0';
                    i--;
                }

                if (i >= 0)
                    s[i] = '1';
                else
                    s = '1' + s;
            } else {
                s.pop_back();
            }
            ans++;
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
