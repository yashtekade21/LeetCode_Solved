class Solution {
public:
    vector<vector<int>> dirs = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    typedef pair<int, pair<int, int>> P;

    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();

        priority_queue<P, vector<P>, greater<P>> pq;
        vector<vector<int>> ans(n, vector<int>(m, INT_MAX));

        ans[0][0] = 0;
        pq.push({0, {0, 0}});

        while (!pq.empty()) {
            auto curTime = pq.top().first;
            auto cell = pq.top().second;

            pq.pop();

            if (cell.first == n - 1 && cell.second == m - 1)
                return curTime;

            for (auto& dir : dirs) {
                int i_next = cell.first + dir[0];
                int j_next = cell.second + dir[1];

                if (i_next >= 0 && i_next < n && j_next >= 0 && j_next < m) {
                    int waitTime = max(moveTime[i_next][j_next] - curTime, 0);
                    int totalTime =
                        waitTime + curTime + 1; // 1 for time travel btw rooms

                    if (ans[i_next][j_next] > totalTime) {
                        ans[i_next][j_next] = totalTime;
                        pq.push({totalTime, {i_next, j_next}});
                    }
                }
            }
        }
        return 0;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
