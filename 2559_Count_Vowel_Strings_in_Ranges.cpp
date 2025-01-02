class Solution {
public:
    vector<int> vowelStrings(vector<string>& words,
                             vector<vector<int>>& queries) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        int vowel_cnt = 0;
        vector<int> prefix_cnt;

        for (auto word : words) {
            int len = word.length();
            if (vowels.find(word[0]) != vowels.end() &&
                vowels.find(word[len - 1]) != vowels.end())
                vowel_cnt++;
            prefix_cnt.emplace_back(vowel_cnt);
        }

        int n = queries.size();
        vector<int> ans(n);

        for (int i = 0; i < n; i++) {
            pair<int, int> range;

            range.first = queries[i][0];
            range.second = queries[i][1];

            ans[i] = prefix_cnt[range.second] - (range.first > 0 ?prefix_cnt[range.first-1] : 0);
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
