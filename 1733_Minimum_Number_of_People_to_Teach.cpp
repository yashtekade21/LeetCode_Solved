class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages,
                         vector<vector<int>>& friendships) {
        int m = languages.size();

        unordered_set<int> sadFriends;
        for (auto& friends : friendships) {
            int u = friends[0] - 1, v = friends[1] - 1;
            bool isSad = true;

            unordered_set<int> langSet(languages[u].begin(),
                                       languages[u].end());

            for (int lang : languages[v]) {
                if (langSet.find(lang) != langSet.end()) {
                    isSad = false;
                    break;
                }
            }

            if (isSad) {
                sadFriends.insert(u);
                sadFriends.insert(v);
            }
        }

        vector<int> languageCnt(n + 1, 0);
        int mostKnownLang = 0;
        for (int user : sadFriends) {
            for (auto& lang : languages[user]) {
                languageCnt[lang]++;
                mostKnownLang = max(mostKnownLang, languageCnt[lang]);
            }
        }

        return sadFriends.size() - mostKnownLang;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
