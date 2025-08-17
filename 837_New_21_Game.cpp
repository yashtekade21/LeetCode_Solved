class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        vector<double> prob(n + 1, 0.0);
        prob[0] = 1;

        double curProbSum = (k == 0) ? 0 : 1;

        for (int i = 1; i <= n; i++) {
            prob[i] = curProbSum / maxPts;

            if (i < k)
                curProbSum += prob[i];

            if (i - maxPts >= 0 && i - maxPts < k)
                curProbSum -= prob[i - maxPts];
        }

        return accumulate(prob.begin() + k, prob.end(), 0.0);
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
