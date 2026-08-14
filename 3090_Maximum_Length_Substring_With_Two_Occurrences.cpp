class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.length();
        int i = 0, j = 0;
        int ans = 0;
        vector<int> freq(26, 0);

        while (j < n) {
            int idx = s[j] - 'a';
            freq[idx]++;

            while (freq[idx] > 2) {
                freq[s[i] - 'a']--;
                i++;
            }

            ans = max(ans, j - i + 1);
            j++;
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
