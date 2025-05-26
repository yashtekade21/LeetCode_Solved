class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.length();
        vector<vector<int>> adj(n);
        vector<vector<int>> dp(n, vector<int>(26, 0));
        int ans = 0;

        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].emplace_back(v);
        }

        if (solve(adj, n, dp, ans, colors))
            return -1;

        return ans;
    }

private:
    bool solve(vector<vector<int>>& adj, int V, vector<vector<int>>& dp,
                 int& ans, string& colors) {
        vector<int> inDegree(V, 0);
        queue<int> q;
        int nodes = 0;

        for (int u = 0; u < V; u++) {
            for (int& v : adj[u])
                inDegree[v]++;
        }

        for (int v = 0; v < V; v++) {
            if (inDegree[v] == 0) {
                q.push(v);
                dp[v][colors[v] - 'a'] = 1;
            }
        }

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            ans = max(ans, dp[u][colors[u] - 'a']);
            nodes++;

            for (int& v : adj[u]) {
                if (--inDegree[v] == 0)
                    q.push(v);

                for (int i = 0; i < 26; i++)
                    dp[v][i] = max(dp[v][i], dp[u][i] + (colors[v] - 'a' == i));
            }
        }
        return nodes != V;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
