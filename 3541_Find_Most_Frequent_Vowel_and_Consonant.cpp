class Solution {
public:
    int maxFreqSum(string s) {
        int n = s.length();

        vector<int> freq(26, 0);

        for (auto& ch : s) {
            freq[ch - 'a']++;
        }

        int maxVowel = 0, maxCons = 0;

        for (int i = 0; i < 26; i++) {
            char ch = i + 'a';
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
                maxVowel = max(maxVowel, freq[i]);
            else
                maxCons = max(maxCons, freq[i]);
        }

        return maxVowel + maxCons;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
