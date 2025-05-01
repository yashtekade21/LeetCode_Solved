class Solution {
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills,
                      int strength) {
        int n = tasks.size();
        int m = workers.size();
        int ans = 0;

        sort(tasks.begin(), tasks.end());
        sort(workers.begin(),workers.end(),greater<int>());

        int l = 0, r = min(m, n);
        while (l <= r) {
            int mid = (l + r) / 2;

            if (solve(tasks, workers, pills, strength, mid)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }

private:
    bool solve(vector<int>& tasks, vector<int>& workers, int& pills,
               int& strength, int maxTasks) {
        int totalPills = 0;
        multiset<int> st(workers.begin(), workers.begin() + maxTasks);

        for (int i = maxTasks - 1; i >= 0; i--) {
            auto maxWorker = prev(st.end());
            if (tasks[i] <= *maxWorker)
                st.erase(maxWorker);
            else if (totalPills >= pills)
                return false;
            else {
                auto weakestWorker = st.lower_bound(tasks[i] - strength);
                if (weakestWorker == st.end())
                    return false;
                st.erase(weakestWorker);
                totalPills++;
            }
        }
        return true;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
