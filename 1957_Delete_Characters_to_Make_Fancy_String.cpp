class Solution {
public:
    string makeFancyString(string s) {
        int n = s.length(), count = 1;
        string ans = "";

        for (int i = 0; i < n; i++) {
            if (i > 0 && s[i] == s[i - 1])
                count++;
            else
                count = 1;

            if (count <= 2)
                ans += s[i];
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
