class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.length();
        int sufY = 0, prefN = 0, minPenalty = n, ans = 0, penalty = 0;

        for (int i = 0; i < n; i++)
            sufY += customers[i] == 'Y' ? 1 : 0;

        for (int j = 0; j < n; j++) {
            penalty = prefN + sufY;

            if (minPenalty > penalty) {
                minPenalty = penalty;
                ans = j;
            }

            prefN += customers[j] == 'N' ? 1 : 0;
            sufY -= customers[j] == 'Y' ? 1 : 0;
        }

        penalty = prefN + sufY;

        return minPenalty > penalty ? n : ans;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
