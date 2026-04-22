class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries,
                                vector<string>& dictionary) {
        vector<string> ans;
        int n = queries.size(), m = dictionary.size();

        int maxLen = queries[0].length();

        for (auto& query : queries) {
            for (auto& word : dictionary) {
                int diff = 0;
                for (int i = 0; i < maxLen; i++) {
                    if (query[i] != word[i])
                        diff++;
                }
                if (diff <= 2) {
                    ans.push_back(query);
                    break;
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
