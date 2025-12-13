class Solution {
public:
    vector<string> validateCoupons(vector<string>& code,
                                   vector<string>& businessLine,
                                   vector<bool>& isActive) {
        int n = code.size();
        vector<pair<string, string>> valids;
        vector<string> ans;

        for (int i = 0; i < n; i++) {
            if (isActive[i] && isValidCode(code[i]) &&
                isValidBusinessLine(businessLine[i]))
                valids.push_back({businessLine[i], code[i]});
        }

        sort(valids.begin(), valids.end());

        for (auto& validCode : valids)
            ans.push_back(validCode.second);

        return ans;
    }

private:
    bool isValidCode(string code) {
        regex pattern("^[a-zA-Z0-9_]+$");
        return regex_match(code, pattern);
    }

    bool isValidBusinessLine(string line) {
        unordered_set<string> st = {"electronics", "grocery", "pharmacy",
                                    "restaurant"};
        return st.find(line) != st.end();
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
