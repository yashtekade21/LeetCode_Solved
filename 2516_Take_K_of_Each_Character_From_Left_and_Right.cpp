class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.length(), ans = INT_MAX;
        vector<int> cnt(3, 0);

        for (auto i : s)
            cnt[i - 'a']++;

        if (cnt[0] < k || cnt[1] < k || cnt[2] < k)
            return -1;

        int l = 0;
        for (int r = 0; r < n; r++) {
            cnt[s[r] - 'a']--;
            while (cnt[0] < k || cnt[1] < k || cnt[2] < k) {
                cnt[s[l] - 'a']++;
                l++;
            }
            ans = min(ans, n - (r - l + 1));
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
