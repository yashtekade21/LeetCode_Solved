class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mp;

        for (auto& list : knowledge)
            mp[list[0]] = list[1];

        string key = "", ans = "";
        bool flag = false;

        for (char ch : s) {
            if (ch == '(') {
                flag = true;
            } else if (ch == ')') {
                if (mp.find(key) != mp.end()) {
                    ans += mp[key];
                } else {
                    ans += "?";
                }

                flag = false;
                key = "";
            } else if (flag) {
                key += ch;
            } else {
                ans += ch;
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
