class Solution {
public:
    string clearDigits(string s) {
        string result = "";

        for (int i = 0; i < s.length(); i++) {
            if (isdigit(s[i])) {
                result.pop_back();
            } else
                result += s[i];
        }
        return result;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
