class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_set<char> stL, stU;

        for (auto& ch : word) {
            if (islower(ch))
                stL.insert(ch);
            else
                stU.insert(ch);
        }

        int ans = 0;

        for (auto& ch : stL) {
            if (stU.find(toupper(ch)) != stU.end())
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
