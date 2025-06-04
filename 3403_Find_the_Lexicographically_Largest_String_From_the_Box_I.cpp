class Solution {
public:
    string answerString(string word, int numFriends) {
        if (numFriends == 1)
            return word;

        int n = word.size();
        string ans = "";

        int maxLen = n - numFriends + 1;

        for (int i = 0; i < n; i++)
            ans = max(ans, word.substr(i, maxLen));

        return ans;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
