class Solution {
public:
    string makeLargestSpecial(string s) {
        int sum = 0, start = 0;
        vector<string> special;
        for (int i = 0; i < s.length(); i++) {
            sum += s[i] == '1' ? 1 : -1;
            if (sum == 0) {
                string part = s.substr(start + 1, i - start - 1);
                special.push_back("1" + makeLargestSpecial(part) + "0");
                start = i + 1;
            }
        }
        sort(special.begin(), special.end(), greater<string>());

        string ans;
        for (auto& str : special)
            ans += str;

        return ans;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
