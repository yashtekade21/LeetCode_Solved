class Solution {
public:
    const int MOD = 1e9 + 7;

    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n);

        for (auto& road : roads) {
            int u = road[0], v = road[1], t = road[2];
            adj[u].push_back({v, t});
            adj[v].push_back({u, t});
        }

        int ans = dijkstrasAlgo(n, adj);
        return ans;
    }

private:
    int dijkstrasAlgo(int n, vector<vector<pair<int, int>>>& adj) {
        vector<int> ways(n, 1);
        vector<long long> minTime(n, LLONG_MAX);

        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                       greater<pair<long long, int>>>
            pq;

        minTime[0] = 0;
        pq.push({minTime[0], 0}); // time, currentNode

            while (!pq.empty()) {
            long long curTime = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if (curTime > minTime[u]) {
                continue;
            }

            for (auto& nei : adj[u]) {
                int v = nei.first;
                int t = nei.second;

                if (minTime[u] + t < minTime[v]) {
                    minTime[v] = minTime[u] + t;
                    ways[v] = ways[u];
                    pq.push({minTime[v], v});
                } else if (minTime[u] + t == minTime[v]) {
                    ways[v] = (ways[v] + ways[u]) % MOD;
                }
            }
        }
        return ways[n - 1];
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
