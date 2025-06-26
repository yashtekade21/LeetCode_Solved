class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n = s.length();
        int maxLen = 0;
        int bitVal = 1;

        for (int i = n - 1; i >= 0; i--) {
            int bit = s[i] - '0';

            if (bit == 0)
                maxLen++;
            else if (bitVal <= k) {
                k -= bitVal;
                maxLen++;
            }
            if (bitVal <= k)
                bitVal *= 2;
        }

        return maxLen;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
