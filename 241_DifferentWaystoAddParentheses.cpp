class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> ans;
        for (int i = 0; i < expression.length(); i++) {
            if (expression[i] == '-' || expression[i] == '+' ||
                expression[i] == '*') {
                string l = expression.substr(0, i);
                string r = expression.substr(i + 1);
                vector<int> leftAns = diffWaysToCompute(l);
                vector<int> rightAns = diffWaysToCompute(r);

                for (auto x : leftAns) {
                    for (auto y : rightAns) {
                        if (expression[i] == '-')
                            ans.emplace_back(x - y);
                        else if (expression[i] == '*')
                            ans.emplace_back(x * y);
                        else
                            ans.emplace_back(x + y);
                    }
                }
            }
        }
        if (ans.size() == 0)
            ans.emplace_back(stoi(expression));
        return ans;
    }
};

static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
