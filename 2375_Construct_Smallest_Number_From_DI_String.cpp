class Solution {
public:
    string smallestNumber(string pattern) {
        int n = pattern.length();

        string result = "", st = "";
        int counter = 1;
        for (int i = 0; i <= n; i++) {
            st += ((counter++) - '0');

            if (i == n || pattern[i] == 'I') {
                while (!st.empty()) {
                    result += st.back();
                    st.pop_back();
                }
            }
        }
        return result;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
