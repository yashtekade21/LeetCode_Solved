class Solution {
public:
    bool checkValidString(string s) {
        int open = 0, close = 0;

        for (auto& ch : s) {
            if (ch == '(' || ch == '*')
                open++;
            else
                open--;

            if (open < 0)
                return false;
        }

        for (int i = s.length() - 1; i >= 0; i--) {
            int ch = s[i];
            if (ch == ')' || ch == '*')
                close++;
            else
                close--;

            if (close < 0)
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
