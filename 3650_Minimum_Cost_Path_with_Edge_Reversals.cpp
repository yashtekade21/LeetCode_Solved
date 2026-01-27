class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<int> ans(n, INT_MAX);
        ans[0] = 0;
        unordered_map<int, vector<pair<int, int>>> adj;

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, 2 * w});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        pq.push({0, 0});

        while (!pq.empty()) {
            int u = pq.top().first;
            int w = pq.top().second;
            pq.pop();

            if (u == n - 1)
                return ans[n - 1];

            for (auto& ngbr : adj[u]) {
                int v = ngbr.first;
                int w_nxt = ngbr.second;

                if (w + w_nxt < ans[v]) {
                    ans[v] = w + w_nxt;
                    pq.push({v, w + w_nxt});
                }
            }
        }
        return -1;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
