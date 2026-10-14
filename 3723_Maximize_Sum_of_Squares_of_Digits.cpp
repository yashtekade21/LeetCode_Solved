class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum > 9 * num || sum < 0)
            return "";

        int nine = sum / 9, left = sum % 9;
        string ans;

        ans.append(nine, '9');
        if (left > 0)
            ans.push_back(left + '0');

        ans.append(num - ans.length(), '0');

        return ans;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
