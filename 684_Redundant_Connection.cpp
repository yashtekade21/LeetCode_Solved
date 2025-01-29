class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size(), m = edges[0].size();

        unordered_map<int, vector<int>> graph;

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            vector<bool> vis(n, false);
            if (graph.find(u) != graph.end() && graph.find(v) != graph.end() &&
                dfs(graph, u, v, vis))
                return edge;

            graph[u].emplace_back(v);
            graph[v].emplace_back(u);
        }
        return {};
    }

private:
    bool dfs(unordered_map<int, vector<int>>& graph, int u, int v,vector<bool>& vis) {
        vis[u] = true;
        if (u == v)
            return true;

        for (int& nei : graph[u]) {
            if (!vis[nei] && dfs(graph, nei, v, vis))
                return true;
        }
        return false;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
