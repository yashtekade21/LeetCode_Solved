class Solution {
public:
    string generateString(string str1, string str2) {
        int n = str1.length(), m = str2.length();
        int len = n + m - 1;

        string ans(len, '.');
        vector<bool> canUpdate(len, false);

        for (int i = 0; i < n; i++) {
            if (str1[i] == 'T') {
                int i_ = i;
                for (int j = 0; j < m; j++) {
                    if (ans[i_] != '.' && ans[i_] != str2[j])
                        return "";

                    ans[i_] = str2[j];
                    i_++;
                }
            }
        }

        for (int i = 0; i < len; i++) {
            if (ans[i] == '.') {
                ans[i] = 'a';
                canUpdate[i] = true;
            }
        }

        for (int i = 0; i < n; i++) {
            if (str1[i] == 'F') {
                string partStr = ans.substr(i, m);
                if (partStr == str2) {
                    bool changed = false;
                    for (int j = i + m - 1; j >= i; j--) {
                        if (canUpdate[j]) {
                            ans[j]++;
                            changed = true;
                            break;
                        }
                    }

                    if (!changed)
                        return "";
                }
            }
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
