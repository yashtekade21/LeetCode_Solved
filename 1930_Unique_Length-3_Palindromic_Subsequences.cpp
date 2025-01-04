class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.length();
        vector<pair<int, int>> left_right_most(26, {-1, -1});

        for (int i = 0; i < n; i++) {
            char ch = s[i];
            int idx = ch - 'a';
            if (left_right_most[idx].first == -1)
                left_right_most[idx].first = i;

            left_right_most[idx].second = i;
        }

        int ans = 0;
        for (int i = 0; i < 26; i++) {
            int left_occ = left_right_most[i].first;
            int right_occ = left_right_most[i].second;

            if (left_occ == -1)
                continue;

            unordered_set<char> st;
            for (int j = left_occ + 1; j <= right_occ - 1; j++)
                st.insert(s[j]);

            ans += st.size();
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
