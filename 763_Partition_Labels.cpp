class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.length();

        vector<int> mp(26, 0);

        for (int i = 0; i < n; i++)
            mp[s[i] - 'a'] = i;

        int i = 0, j = 0;
        vector<int> ans;

        while (i < n) {
            int end = mp[s[i] - 'a'];

            while (j <= end) {
                if (mp[s[j] - 'a'] > end)
                    end = mp[s[j] - 'a'];
                j++;
            }

            ans.emplace_back(end - i + 1);
            i = j;
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
