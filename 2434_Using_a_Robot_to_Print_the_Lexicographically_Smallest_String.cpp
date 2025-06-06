class Solution {
public:
    string robotWithString(string s) {
        int n = s.length();
        vector<char> smallestRight(n);

        smallestRight[n - 1] = s[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            smallestRight[i] = min(s[i], smallestRight[i + 1]);
        }

        stack<char> t;
        string p = "";

        for (int i = 0; i < n; i++) {
            t.push(s[i]);

            char minChar = s[i];
            if (i + 1 < n)
                minChar = smallestRight[i + 1];

            while (!t.empty() && t.top() <= minChar) {
                p += t.top();
                t.pop();
            }
        }

        while (!t.empty()) {
            p += t.top();
            t.pop();
        }

        return p;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
