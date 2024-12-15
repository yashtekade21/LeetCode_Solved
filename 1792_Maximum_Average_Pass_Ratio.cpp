class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();
        priority_queue<pair<double, pair<int, int>>> pq;

        for (auto one_class : classes) {
            double pass_ratio = diff_inc(one_class[0], one_class[1]);
            pq.push({pass_ratio, {one_class[0], one_class[1]}});
        }

        for (int i = 0; i < extraStudents; i++) {
            auto class_detail = pq.top();
            pq.pop();

            int pass_stu = class_detail.second.first;
            int total_stu = class_detail.second.second;
            double new_pass_ratio = diff_inc(pass_stu + 1, total_stu + 1);

            pq.push({new_pass_ratio, {pass_stu + 1, total_stu + 1}});
        }

        double avg_pass_ratio = 0;
        while (!pq.empty()) {
            pair<int, int> p = pq.top().second;
            pq.pop();
            avg_pass_ratio += (double)p.first / (double)p.second;
        }
        return (double)avg_pass_ratio / n;
    }

private:
    double diff_inc(int pass, int total) {
        return (double)(pass + 1) / (double)(total + 1) - (double)pass / (double)total;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
