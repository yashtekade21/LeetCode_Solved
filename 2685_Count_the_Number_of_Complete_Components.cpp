class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> vis(n, false);
        int completeGraph = 0;
        for (int node = 0; node < n; node++) {
            if (!vis[node]) {
                int Edges = 0, Nodes = 0;
                dfs(node, adj, vis, Edges, Nodes);
                Edges /= 2;
                if ((Nodes * (Nodes - 1)) / 2 == Edges) {
                    completeGraph++;
                }
            }
        }
        return completeGraph;
    }

private:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& vis, int& Edges,
             int& Nodes) {
        vis[node] = true;
        Nodes++;

        for (auto& nei : adj[node]) {
            Edges++;
            if (!vis[nei]) {
                dfs(nei, adj, vis, Edges, Nodes);
            }
        }
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
