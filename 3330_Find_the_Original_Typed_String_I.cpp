class Solution {
public:
    int possibleStringCount(string word) {
        int ans = 1;

        for (int i = 1; i < word.length(); i++) {
            if (word[i] == word[i - 1])
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
