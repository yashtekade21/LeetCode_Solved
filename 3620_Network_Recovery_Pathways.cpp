class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online,
                         long long k) {
        int n = online.size();
        int l = INT_MAX, r = 0;
        unordered_map<int, vector<vector<int>>> adj;

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            if (!online[u] || !online[v])
                continue;

            adj[u].push_back({v, w});
            l = min(l, w);
            r = max(r, w);
        }

        int ans = -1;

        while (l <= r) {
            int m = l + (r - l) / 2;

            if (check(m, n, k, adj)) {
                ans = m;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

        return ans;
    }

private:
    bool check(int mid, int n, long long k,
               unordered_map<int, vector<vector<int>>>& adj) {
        vector<long long> ans(n, LLONG_MAX);

        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                       greater<pair<long long, int>>>
            pq;

        ans[0] = 0;

        pq.push({0, 0});

        while (!pq.empty()) {
            long long d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (d > k)
                return false;

            if (node == n - 1)
                return true;

            if (d > ans[node])
                continue;

            for (auto& vec : adj[node]) {
                int adjNode = vec[0];
                int edgeCost = vec[1];

                if (edgeCost < mid)
                    continue;

                if (d + edgeCost < ans[adjNode]) {
                    ans[adjNode] = d + edgeCost;
                    pq.push({d + edgeCost, adjNode});
                }
            }
        }

        return false;
    }
};
