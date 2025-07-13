class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();

        unordered_set<char> st;
        int i = 0, j = 0;
        int ans = 0;

        while (j < n) {
            st.insert(s[j]);

            while (st.size() != j - i + 1) {
                if (s[i] != s[j])
                    st.erase(s[i]);

                i++;
            }

            if (st.size() == j - i + 1)
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
