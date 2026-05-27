class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char, int> mp;
        unordered_set<char> st;
        int ans = 0;

        for (int i = 0; i < word.length(); i++) {
            char ch = word[i];
            if (islower(ch)) {
                st.insert(ch);
                mp[ch] = i;
            } else if (isupper(ch) && mp.find(ch) == mp.end())
                mp[ch] = i;
        }

        for (auto& ch : st) {
            char capCh = toupper(ch);
            if (mp.find(capCh) != mp.end() && mp[ch] < mp[capCh])
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
