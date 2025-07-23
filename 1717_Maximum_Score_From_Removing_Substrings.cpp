class Solution {
public:
    int maximumGain(string s, int x, int y) {
        return x > y ? solve(s, 'a', 'b', x, y) : solve(s, 'b', 'a', y, x);
    }

private:
    int solve(string& s, char first, char second, int firVal, int secVal) {
        stack<char> st;
        int score = 0;
        string temp = "";

        for (auto& ch : s) {
            if (!st.empty() && ch == second && st.top() == first) {
                st.pop();
                score += firVal;
            } else
                st.push(ch);
        }

        while (!st.empty()) {
            temp += st.top();
            st.pop();
        }
        reverse(temp.begin(), temp.end());

        for (auto& ch : temp) {
            if (!st.empty() && ch == first && st.top() == second) {
                st.pop();
                score += secVal;
            } else
                st.push(ch);
        }
        return score;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
