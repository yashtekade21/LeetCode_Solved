class Solution {
public:
    int minimumPushes(string word) {
        if (word.length() <= 8)
            return word.length();

        sortFreq(word);
        unordered_map<int, unordered_set<char>> setMp;
        unordered_map<char, pair<int, int>> mp;
        int ans = 0;
        int assign = 2;

        for (char& ch : word) {
            if (assign > 9)
                assign = 2;

            if (mp.find(ch) == mp.end()) {
                setMp[assign].insert(ch);
                mp[ch] = {assign, (int)setMp[assign].size()};

                ans += mp[ch].second;
                assign++;
            } else {
                ans += mp[ch].second;
            }
        }

        return ans;
    }

private:
    void sortFreq(string& word) {
        unordered_map<char, int> mp;

        for (const char& ch : word)
            mp[ch]++;

        auto lambda = [&](const char& ch1, const char& ch2) {
            return mp[ch1] > mp[ch2];
        };

        sort(begin(word), end(word), lambda);
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
