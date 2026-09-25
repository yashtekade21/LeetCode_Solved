class Solution {
public:
    string s;
    int n;
    int idx = 0;

    vector<string> braceExpansionII(string expression) {
        n = expression.length();
        s = expression;
        idx = 0;

        set<string> st = performUnion();
        vector<string> ans(begin(st), end(st));

        return ans;
    }

private:
    set<string> getUnit() {
        set<string> ans;

        if (s[idx] == '{') {
            idx++;
            ans = performUnion();
        } else {
            ans = {string(1, s[idx])};
        }

        idx++;
        return ans;
    }

    set<string> performConcat() {
        set<string> ans = {""};

        while (idx < n && (s[idx] == '{' || isalpha(s[idx]))) {
            set<string> temp = getUnit();

            set<string> concatans;
            for (const string& left : ans) {
                for (const string& right : temp) {
                    concatans.insert(left + right);
                }
            }

            ans = concatans;
        }

        return ans;
    }

    set<string> performUnion() {
        set<string> ans;

        while (true) {
            set<string> temp = performConcat();
            ans.insert(begin(temp), end(temp));

            if (idx < n && s[idx] == ',')
                idx++;
            else
                break;
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
