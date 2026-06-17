class Solution {
public:
    char processStr(string s, long long k) {
        int n = s.length();
        long long len = 0;

        for (auto& ch : s) {
            if (ch == '*') {
                if (len > 0)
                    len--;

            } else if (ch == '#')
                len *= 2;
            else if (ch == '%')
                continue;
            else
                len++;
        }

        if (k >= len)
            return '.';

        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '#') {
                len = len / 2;
                k = (k >= len) ? k - len : k;
            } else if (s[i] == '%')
                k = len - k - 1;
            else if (s[i] == '*')
                len++;
            else
                len--;

            if (len == k)
                return s[i];
        }
        return '.';
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
