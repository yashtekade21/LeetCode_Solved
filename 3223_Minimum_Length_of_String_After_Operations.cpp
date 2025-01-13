class Solution {
public:
    int minimumLength(string s) {
        vector<int> freq(26, 0);
        int n = s.length();

        if (n < 3)
            return n;
        int ans = n;

        for (auto& ch : s) {
            freq[ch - 'a']++;
        }

        for (int i = 0; i < 26; i++) {
            if (freq[i] >= 3 && freq[i] % 2 == 0) {
                int rem = freq[i] - 2;
                ans -= rem;
            } else if (freq[i] >= 3 && freq[i] % 2 != 0) {
                int rem = freq[i] - 1;
                ans -= rem;
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
