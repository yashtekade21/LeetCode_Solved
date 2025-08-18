class Solution {
public:
    const double EPS = 1e-5;
    bool judgePoint24(vector<int>& cards) {
        sort(cards.begin(), cards.end());

        if (solve(cards))
            return true;

        while (next_permutation(cards.begin(), cards.end())) {
            if (solve(cards))
                return true;
        }
        return false;
    }

private:
    bool solve(vector<int>& cards) {
        double num1 = cards[0], num2 = cards[1], num3 = cards[2],
              num4 = cards[3];

        if (solve(num1 + num2, num3, num4) || solve(num1 - num2, num3, num4) ||
            solve(num1 * num2, num3, num4) || solve(num1 / num2, num3, num4))
            return true;

        if (solve(num1, num2 + num3, num4) || solve(num1, num2 - num3, num4) ||
            solve(num1, num2 * num3, num4) || solve(num1, num2 / num3, num4))
            return true;
            
        if (solve(num1, num2, num3 + num4) || solve(num1, num2, num3 - num4) ||
            solve(num1, num2, num3 * num4) || solve(num1, num2, num3 / num4))
            return true;

        return false;
    }

    bool solve(double num1, double num2, double num3) {
        if (solve(num1 + num2, num3) || solve(num1 - num2, num3) ||
            solve(num1 * num2, num3) || num2 && solve(num1 / num2, num3))
            return true;

        if (solve(num1, num2 + num3) || solve(num1, num2 - num3) ||
            solve(num1, num2 * num3) || num3 && solve(num1, num2 / num3))
            return true;

        return false;
    }

    bool solve(double num1, double num2) {
        if (abs(num1 + num2 - 24) <= EPS || abs(num1 - num2 - 24) <= EPS ||
            abs(num1 * num2 - 24) <= EPS ||
            num2 && abs(num1 / num2 - 24) <= EPS)
            return true;

        return false;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
