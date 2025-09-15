class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        vector<bool> isBroken(26, false);
        int ans = 0;

        for (auto& ch : brokenLetters)
            isBroken[ch - 'a'] = true;

        stringstream ss(text);
        string word;
        while (ss >> word) {
            bool flag = false;
            for (char ch : word) {
                if (isBroken[ch - 'a']) {
                    flag = true;
                    break;
                }
            }
            if (!flag)
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
