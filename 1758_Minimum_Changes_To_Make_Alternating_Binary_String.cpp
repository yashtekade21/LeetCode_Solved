class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        int ansZero = (s[0] == '0' ? 0 : 1), ansOne = (s[0] == '1' ? 0 : 1);

        char req = '1'; // starts with '0'
        for (int i = 1; i < n; i++) {
            if (s[i] != req)
                ansZero++;

            req = (req == '0' ? '1' : '0');
        }

        req = '0'; // starts with '1'
        for (int i = 1; i < n; i++) {
            if (s[i] != req)
                ansOne++;

            req = (req == '0' ? '1' : '0');
        }
        return min(ansZero, ansOne);
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
