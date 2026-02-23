class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.length();
        int bCodes = pow(2, k);

        unordered_set<string> st;

        int i = 0, j = 0;
        string binCode;
        while (j < n) {
            binCode += s[j];
            if (j - i + 1 == k) {
                st.insert(binCode);
                if (!binCode.empty())
                    binCode.erase(binCode.begin());
                i++;
            }
            j++;
        }
        return st.size() == bCodes;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
