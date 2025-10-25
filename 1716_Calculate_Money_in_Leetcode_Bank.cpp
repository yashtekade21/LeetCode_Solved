class Solution {
public:
    int totalMoney(int n) {
        int completeWeeks = n / 7;
        int partialDays = n % 7;
        int first = 28;

        int last = first + (completeWeeks - 1) * 7;

        int ans = completeWeeks * (first + last) / 2;

        for (int day = 1; day <= partialDays; day++)
            ans += (completeWeeks + day);

        return ans;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
