class Solution {
public:
    string getHappyString(int n, int k) {
        vector<string> vec;
        string s = "";

        solve(vec, s, n, k);

        return k > vec.size() ? "" : vec[k - 1];
    }

private:
    void solve(vector<string>& vec, string& s, int n, int k) {
        if (s.length() == n) {
            vec.emplace_back(s);
            return;
        }
        if (vec.size() == k)
            return;

        for (char ch = 'a'; ch <= 'c'; ch++) {
            if (!s.empty() && s.back() == ch)
                continue;

            s += ch;

            solve(vec, s, n, k);

            s.pop_back();
        }
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
