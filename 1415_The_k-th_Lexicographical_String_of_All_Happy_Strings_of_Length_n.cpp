class Solution {
public:
    string getHappyString(int n, int k) {
        string s, ans;
        int idx = 0;
        solve(s, ans, n, k, idx);

        return ans;
    }

private:
    void solve(string& s, string& ans, int n, int k, int& idx) {
        if (s.length() == n) {
            idx++;
            if (idx == k)
                ans = s;

            return;
        }

        for (char ch = 'a'; ch <= 'c'; ch++) {
            if (!s.empty() && s.back() == ch)
                continue;

            s += ch;

            solve(s, ans, n, k, idx);

            s.pop_back();
        }
        return;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
