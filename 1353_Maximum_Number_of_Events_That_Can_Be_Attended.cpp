class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n = events.size();
        sort(events.begin(), events.end());

        int day = events[0][0];
        int i = 0;
        int ans = 0;

        priority_queue<int, vector<int>, greater<int>> pq;

        while (!pq.empty() || i < n) {
            while (i < n && events[i][0] == day) {
                pq.push(events[i][1]);
                i++;
            }

            if (!pq.empty()) {
                pq.pop();
                ans++;
            }

            day++;

            while (!pq.empty() && pq.top() < day) {
                pq.pop();
            }
        }
        return ans;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
