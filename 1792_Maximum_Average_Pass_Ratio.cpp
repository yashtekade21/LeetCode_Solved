class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();
        double ans = 0;

        priority_queue<pair<double, int>> pq;

        for (int i = 0; i < n; i++) {
            double curPR = (double)classes[i][0] / classes[i][1];
            double newPR = (double)(classes[i][0] + 1) / (classes[i][1] + 1);
            double diff = newPR - curPR;

            pq.push({diff, i});
        }

        while (extraStudents--) {
            double diff = pq.top().first;
            int idx = pq.top().second;
            pq.pop();

            classes[idx][0]++;
            classes[idx][1]++;

            double curPR = (double)classes[idx][0] / classes[idx][1];
            double newPR =
                (double)(classes[idx][0] + 1) / (classes[idx][1] + 1);
            double newDiff = newPR - curPR;

            pq.push({newDiff, idx});
        }

        for (int i = 0; i < n; i++) {
            double PR = (double)classes[i][0] / classes[i][1];

            ans += PR;
        }

        return (double)ans / n;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
