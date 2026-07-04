class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int, vector<pair<int, int>>> adj;

        for (auto& vec : roads) {
            int u = vec[0];
            int v = vec[1];
            int c = vec[2];

            adj[u].push_back({v, c});
            adj[v].push_back({u, c});
        }

        vector<bool> visited(n, false);
        int ans = INT_MAX;
        dfs(adj, 1, visited, ans);

        return ans;
    }

private:
    void dfs(unordered_map<int, vector<pair<int, int>>>& adj, int u,
             vector<bool>& visited, int& ans) {

        visited[u] = true;

        for (auto& vec : adj[u]) {
            int v = vec.first;
            int c = vec.second;

            ans = min(ans, c);

            if (!visited[v])
                dfs(adj, v, visited, ans);
        }
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
