class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int size = rolls.size() + n;
        long long sum = 0;
        sum = accumulate(rolls.begin(), rolls.end(), 0);

        long long reqSum = (mean * size) - sum;

        if ((reqSum / n == 6 && reqSum % n > 0) || (reqSum / n > 6) ||
            (reqSum / n == 0) || (reqSum < 0))
            return {};

        vector<int> ans;

        int quotient = reqSum / n;
        int remainder = reqSum % n;

        for (int i = 0; i < n - remainder; i++)
            ans.emplace_back(quotient);

        for (int i = 0; i < remainder; i++)
            ans.emplace_back(quotient + 1);

        return ans;
    }
};

static const auto kds = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();
