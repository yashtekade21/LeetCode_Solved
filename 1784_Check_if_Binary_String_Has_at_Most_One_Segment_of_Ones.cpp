class Solution {
public:
    bool checkOnesSegment(string s) {
        int n = s.length();
        int cntOnesSeg = 1;

        for (int i = 1; i < n; i++) {
            if (s[i - 1] == '1' && s[i] == '1')
                continue;
            else if (s[i - 1] == '0' && s[i] == '1')
                cntOnesSeg++;
        }
        return cntOnesSeg == 1;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
