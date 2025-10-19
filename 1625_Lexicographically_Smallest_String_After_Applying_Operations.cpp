class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        string ans = s;

        unordered_set<string> vis;
        queue<string> q;
        q.push(s);
        vis.insert(s);

        while (!q.empty()) {
            string cur = q.front();
            q.pop();

            ans = min(ans, cur);

            // Add a to odd indices
            string newStr = cur;
            for (int i = 1; i < newStr.length(); i += 2)
                newStr[i] = ((newStr[i] - '0' + a) % 10) + '0';

            if (vis.find(newStr) == vis.end()) {
                vis.insert(newStr);
                q.push(newStr);
            }

            // Rotate by b indices
            rotateStr(cur, b);
            if (vis.find(cur) == vis.end()) {
                vis.insert(cur);
                q.push(cur);
            }
        }
        return ans;
    }

private:
    void rotateStr(string& s, int n) {
        reverse(s.begin(), s.end());
        reverse(s.begin(), s.begin() + n);
        reverse(s.begin() + n, s.end());
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
