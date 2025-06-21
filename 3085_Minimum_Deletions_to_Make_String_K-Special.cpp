class Solution {
public:
    int minimumDeletions(string word, int k) {
        int n = word.length();

        vector<int> freq(26, 0);
        for (auto& ch : word)
            freq[ch - 'a']++;

        sort(freq.begin(), freq.end());

        int ans = INT_MAX;
        int cumDel = 0;
        for (int i = 0; i < 26; i++) {
            if (freq[i] == 0)
                continue;

            int curDel = cumDel;
            for (int j = 25; j > i; j--) {
                if (freq[i] + k < freq[j])
                    curDel += freq[j] - freq[i] - k;
                else
                    break;
            }
            ans = min(ans, curDel);
            cumDel += freq[i];
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
