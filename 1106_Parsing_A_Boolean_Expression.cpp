class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> s;
        int n = expression.length();

        for (int i = 0; i < n; i++) {
            char ch = expression[i];
            if (ch == ')') {
                vector<char> temp;
                while (s.top() != '(') {
                    temp.emplace_back(s.top());
                    s.pop();
                }
                s.pop();
                char op = s.top();
                s.pop();

                char ans = calc(temp, op);
                s.push(ans);
            } else {
                if (ch == ',')
                    continue;
                else
                    s.push(ch);
            }
        }
        return s.top() == 't';
    }

private:
    char calc(vector<char>& arr, char op) {
        if (op == '|') {
            if (iterate(arr, 't'))
                return 't';
            else
                return 'f';
        } else if (op == '&') {
            if (iterate(arr, 'f'))
                return 'f';
            else
                return 't';
        } else {
            if (arr[0] == 'f')
                return 't';
            else
                return 'f';
        }
    }

    bool iterate(vector<char>& arr, char val) {
        for (auto i : arr) {
            if (i == val)
                return true; 
        }
        return false;
    }
};

static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
