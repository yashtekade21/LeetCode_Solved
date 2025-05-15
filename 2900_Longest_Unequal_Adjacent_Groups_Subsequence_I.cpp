class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words,
                                         vector<int>& groups) {
        int n = words.size();
        vector<string> ans;
        ans.emplace_back(words[0]);
        for (int i = 1; i < n; i++) {
            if (groups[i] != groups[i - 1])
                ans.emplace_back(words[i]);
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
