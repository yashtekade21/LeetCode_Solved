class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> mp;
        for (auto& word : words)
            mp[word]++;

        bool oddFreqUsed = false;
        int ans = 0;

        for (auto& word : words) {
            string revWord = word;
            reverse(revWord.begin(), revWord.end());
            int wordLen = word.length(), revWordLen = revWord.length();

            if (word != revWord) {
                if (mp[word] > 0 && mp[revWord] > 0) {
                    mp[word]--;
                    mp[revWord]--;
                    ans += (wordLen + revWordLen);
                }
            } else {
                if (mp[word] >= 2) {
                    mp[word] -= 2;
                    ans += (revWordLen + wordLen);
                } else if (mp[word] == 1 && !oddFreqUsed){
                        mp[word]--;
                        ans += wordLen;
                        oddFreqUsed = true;
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
