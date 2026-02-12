class Solution {
public:
    int longestBalanced(string s) {
        int n = s.length();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            vector<int> mp(26, 0);

            for (int j = i; j < n; j++) {
                mp[s[j] - 'a']++;

                if (isSameChars(mp))
                    ans = max(ans, j - i + 1);
            }
        }
        return ans;
    }

private:
    bool isSameChars(vector<int>& mp) {
        int prev = 0;
        for (int i = 0; i < 26; i++) {
            if (mp[i] == 0)
                continue;
            else if (prev == 0)
                prev = mp[i];
            else if (prev != mp[i])
                return false;
        }
        return prev != 0;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
