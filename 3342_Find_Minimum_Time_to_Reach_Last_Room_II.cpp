class Solution {
public:
    vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    typedef pair<int, pair<int, int>> P;
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();

        vector<vector<int>> ans(n, vector<int>(m, INT_MAX));
        priority_queue<P, vector<P>, greater<P>> pq;

        ans[0][0] = 0;
        pq.push({0, {0, 0}});

        while (!pq.empty()) {
            auto curTime = pq.top().first;
            auto cell = pq.top().second;
            pq.pop();

            if (cell.first == n - 1 && cell.second == m - 1)
                return curTime;

            for (auto& dir : dirs) {
                int i_next = dir[0] + cell.first;
                int j_next = dir[1] + cell.second;

                if (i_next >= 0 && i_next < n && j_next >= 0 && j_next < m) {
                    int waitTime = max(moveTime[i_next][j_next] - curTime, 0);
                    int totalTime = curTime + waitTime;
                    totalTime += (i_next + j_next) % 2 == 0 ? 2 : 1;

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
