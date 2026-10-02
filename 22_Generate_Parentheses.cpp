class Solution {
public:
    vector<string> ans;

    vector<string> generateParenthesis(int n) {
        string curr = "";
        solve(n, curr, 0, 0);
        return ans;
    }

private:
    void solve(int n, string curr, int open, int close) {
        if (curr.length() == 2 * n) {
            ans.push_back(curr);
            return;
        }

        if (open < n) {
            curr.push_back('(');
            solve(n, curr, open + 1, close);
            curr.pop_back();
        }
        if (close < open) {
            curr.push_back(')');
            solve(n, curr, open, close + 1);
            curr.pop_back();
        }
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
