class Solution {
public:
    vector<string> getWordsInLongestSubsequence(vector<string>& words,
                                                vector<int>& groups) {
        int n = words.size();

        vector<int> dp(n, 1), parent(n, -1);
        int maxSubseqLen = 0, maxLenIdx = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (words[i].length() == words[j].length() &&
                    groups[i] != groups[j] &&
                    calcHammingDist(words[i], words[j])) {

                    if (dp[i] < dp[j] + 1) {
                        dp[i] = dp[j] + 1;
                        parent[i] = j;
                        
                        if (maxSubseqLen < dp[i]) {
                            maxSubseqLen = dp[i];
                            maxLenIdx = i;
                        }
                    }
                }
            }
        }

        vector<string> ans;
        while (maxLenIdx != -1) {
            ans.push_back(words[maxLenIdx]);
            maxLenIdx = parent[maxLenIdx];
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

private:
    bool calcHammingDist(string a, string b) {
        int hammingDistance = 0;
        for (int i = 0; i < a.length(); i++) {
            hammingDistance += (a[i] != b[i]) ? 1 : 0;
            if (hammingDistance > 1)
                return false;
        }
        return true;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
