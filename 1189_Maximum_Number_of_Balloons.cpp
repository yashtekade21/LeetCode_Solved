class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> mp(26, 0);
        for (auto& ch : text)
            mp[ch - 'a']++;

        return min({mp['b' - 'a'], mp['a' - 'a'], mp['l' - 'a'] / 2,
                    mp['o' - 'a'] / 2, mp['n' - 'a']});
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
