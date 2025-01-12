class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.length();
        if(n%2 != 0)
            return false;
            
        int open_cnt = 0;
        int close_cnt = 0;

        // iteration for open brackets
        for (int i = 0; i < n; i++) {
            if (locked[i] == '0' || s[i] == '(')
                open_cnt++;
            else
                open_cnt--;

            if (open_cnt < 0)
                return false;
        }

        // iteration for closed brackets
        for (int i = n - 1; i >= 0; i--) {
            if (locked[i] == '0' || s[i] == ')')
                close_cnt++;
            else
                close_cnt--;

            if (close_cnt < 0)
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
