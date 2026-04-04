class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n = encodedText.length();

        int cols = n / rows;
        string ans = "";
        for (int i = 0; i < cols; i++) {
            int j = i;
            while (j < n) {
                ans += encodedText[j];
                j += (cols + 1);
            }
        }

        int len = ans.length() - 1;
        while (!ans.empty() && ans[len--] == ' ')
            ans.pop_back();

        return ans;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
